import java.io.*;
import java.util.Date;
import java.util.Enumeration;
import java.util.StringTokenizer;
import javax.jms.*;
import javax.naming.*;

public class QBorrower {
	
    private Connection Connect = null;    
    private Session Session = null;
    private Queue responseQ = null;
    private Topic requestT = null;

    public QBorrower(String queuecf, String requestTopic, 
    		        String responseQueue) {    	
    	try {
    		// Connect to the provider and get the JMS connection
			Context ctx = new InitialContext();
			ConnectionFactory Factory = (ConnectionFactory)
				ctx.lookup(queuecf);
			Connect = Factory.createConnection();
			// Create the JMS Session
			Session = Connect.createSession(
				false, Session.AUTO_ACKNOWLEDGE);

			// Lookup the request and response queues
			responseQ = (Queue)ctx.lookup(responseQueue);
			requestT = (Topic)ctx.lookup(requestTopic);
			

            // Now that setup is complete, start the Connection
			Connect.start();
			
    	} catch (JMSException jmse) {
    		jmse.printStackTrace( ); 
    		System.exit(1);
        } catch (NamingException jne) {
            jne.printStackTrace( ); 
            System.exit(1);
        }
    }

    private void sendLoanRequest(double salary, double loanAmt, String bank, int scheme) {
    	try {
        	// Create JMS message
        	MapMessage msg = Session.createMapMessage();
        	msg.setString("BankName", bank);
        	msg.setDouble("Salary", salary);
        	msg.setDouble("LoanAmount", loanAmt);
        	msg.setInt("PaymentScheme", scheme);
        	msg.setJMSReplyTo(responseQ);

        	//set the message expiration to 30 seconds
        	msg.setJMSExpiration(new Date().getTime() + 30000);
        	
        	// Create the sender and send the message
			MessageProducer Sender = Session.createProducer(requestT);
        	Sender.send(msg);
        	
        	loanReceival(); 
        	
    	} catch (JMSException jmse) {
    		jmse.printStackTrace( ); 
    		System.exit(1);
    	}
    }
    
    private void loanReceival() throws JMSException {
    	MessageConsumer receiver = Session.createConsumer(responseQ);
    	QueueBrowser queueBrowser = Session.createBrowser(responseQ);

        // browse the messages
        Enumeration e = queueBrowser.getEnumeration();

        // count number of messages
        Message checkmessage = receiver.receive();
        while (!(checkmessage instanceof ObjectMessage))
        	checkmessage = receiver.receive();
        ObjectMessage msg = (ObjectMessage) checkmessage;
        ObjectMessage tempmsg = msg;
        LoanProposalData loanProposal = (LoanProposalData) msg.getObject();
        LoanProposalData loanProposaltemp = (LoanProposalData) msg.getObject();
    	TextMessage amsg = Session.createTextMessage();
    	TextMessage rmsg = Session.createTextMessage();
    	rmsg.setText("REJECTED");
    	int proposal = 1;
        while (e.hasMoreElements()) {
        	if (loanProposal.getInterestRate() > loanProposaltemp.getInterestRate()) {
        		loanProposal = loanProposaltemp;
        		amsg.setJMSCorrelationID(msg.getJMSMessageID());
        		tempmsg=msg;
        	}
        	else {
        		if (loanProposal.getBankName().equals(loanProposaltemp.getBankName())) {
        		}
        		else {
        			MessageProducer producerrej = Session.createProducer(responseQ);
        			rmsg.setJMSCorrelationID(msg.getJMSMessageID());
        			producerrej.send(rmsg);
        		}
        	}
        	String filter = "JMSCorrelationID = '" + msg.getJMSCorrelationID() + "'";
        	System.out.println ("Proposal #: " + proposal + " Bank: " + loanProposaltemp.getBankName() + " Interest Rate: " + loanProposaltemp.getInterestRate() + "Loan Amount: " + loanProposaltemp.getLoanAmount() + "Loan Scheme: " + loanProposaltemp.getPaymentScheme());
        	Message temp2message = receiver.receive();
        	
        	while (!(temp2message instanceof ObjectMessage))
        	{
        		temp2message = receiver.receive();
        	}
        	msg = (ObjectMessage) temp2message;
    		loanProposaltemp = (LoanProposalData) msg.getObject();
    		proposal++;
        }
        System.out.println ("Chosen Proposal: " + proposal + " Bank: " + loanProposal.getBankName() + " Interest Rate: " + loanProposal.getInterestRate() + "Loan Amount: " + loanProposal.getLoanAmount() + "Loan Scheme: " + loanProposal.getPaymentScheme());
        MessageProducer producerfin = Session.createProducer(tempmsg.getJMSReplyTo());
        producerfin.send(amsg);
    }
    
    private void exit() {
    	try {
    		Connect.close( );
    		    	} catch (JMSException jmse) {
    		jmse.printStackTrace( );
    	}
    	System.exit(0);
    }

    public static void main(String argv[]) {
    	String queuecf = null;
    	String requestq = null;
    	String responseq = null;
    	if (argv.length == 3) {
    		queuecf = argv[0];
    		requestq = argv[1];
    		responseq = argv[2];
    	} else {
    		System.out.println("Invalid arguments. Should be: ");
    		System.out.println
               ("java QBorrower factory requestQueue responseQueue");
    		System.exit(0);
    	}
      
    	QBorrower borrower = new QBorrower(queuecf, requestq, responseq);
      
    	try {
    		// Read all standard input and send it as a message
    		BufferedReader stdin = new BufferedReader
            	(new InputStreamReader(System.in));
    		System.out.println ("QBorrower Application Started");
    		System.out.println ("Press enter to quit application");
    		System.out.println ("Enter: Salary, Loan_Amount, Bank Name, Scheme");
    		System.out.println("\ne.g. 50000, 120000, Bankco, 7");

    		while (true) {
        		System.out.print("> ");
    			
        		String loanRequest = stdin.readLine();
        		if (loanRequest == null || loanRequest.trim().length( ) <= 0) {
        			borrower.exit();
        		}
            
        		// Parse the deal description
        		StringTokenizer st = new StringTokenizer(loanRequest, ",") ;
        		double salary = 
        			Double.valueOf(st.nextToken().trim()).doubleValue( );
        		double loanAmt = 
        			Double.valueOf(st.nextToken().trim()).doubleValue( );
        		String bankName =
        				String.valueOf(st.nextToken().trim());
        		int scheme = 
        				Integer.valueOf(st.nextToken().trim()).intValue();
        		borrower.sendLoanRequest(salary, loanAmt,bankName,scheme);
    		}
    	} catch (IOException ioe) {
    	  ioe.printStackTrace( );
    	}
    }
}
