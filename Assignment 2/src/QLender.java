import java.io.*;
import javax.jms.*;
import javax.naming.*;

public class QLender implements MessageListener {
	
    private Connection Connect = null;    
    private Session Session = null;
    private Topic requestT = null;
    private Topic fedInterest = null;
    private Session Session2 = null;
    private MessageConsumer rateReceiver;
    private double F1;
    private double F2;
    private double F3;
    private double F4;
    private double F5;
    private double F7;
    private double F10;
    private double F30;
    

    public QLender(String queuecf, String requestTopic) {    	
    	try {
    		// Connect to the provider and get the JMS connection
			Context ctx = new InitialContext();
			ConnectionFactory Factory = (ConnectionFactory)
				ctx.lookup(queuecf);
			
			Connect = Factory.createConnection();
			Connect.setClientID("bank.10253120");
			// Create the JMS Session
			Session = Connect.createSession(
				false, Session.AUTO_ACKNOWLEDGE);

			// Lookup the request queue
			requestT = (Topic)ctx.lookup(requestTopic);
			fedInterest = (Topic)ctx.lookup("fed.interest");
			Session2 = Connect.createSession(false, Session2.AUTO_ACKNOWLEDGE);
            // Now that setup is complete, start the Connection
			Connect.start();
			// Create the message listener
			
			MessageConsumer Consumer = Session.createDurableSubscriber(requestT, "bank.10253120");
			Consumer.setMessageListener(this);
			rateReceiver = Session2.createConsumer(fedInterest);
			System.out.println("Waiting for loan requests...");
			
    	} catch (JMSException jmse) {
    		jmse.printStackTrace( ); 
    		System.exit(1);
        } catch (NamingException jne) {
            jne.printStackTrace( ); 
            System.exit(1);
        }
    }

    public void onMessage(Message message) {

    	try {

        	// Get the data from the message
        	MapMessage msg = (MapMessage)message;
        	String BankName = msg.getString("BankName");
        	double salary = msg.getDouble("Salary");
        	double loanAmt = msg.getDouble("LoanAmount");
        	int scheme = msg.getInt("PaymentScheme");
        	
        	
        	LoanProposalData loanRequest = new LoanProposalData(loanAmt,this.getFedRate(scheme),salary,BankName,scheme);
        	if (scheme == 1 || scheme == 2 || scheme == 3 || scheme == 4 || scheme == 5 || scheme == 7 || scheme == 10 || scheme == 30) {
        		if (loanRequest.getApprovedFlag()) {
        			MessageProducer Sender = Session.createProducer(msg.getJMSReplyTo());
        			ObjectMessage omsg = Session.createObjectMessage();
        			omsg.setObject(loanRequest);
        			omsg.setJMSExpiration(7*86400000);
        			omsg.setJMSReplyTo(msg.getJMSReplyTo());
        			omsg.setJMSCorrelationID(msg.getJMSMessageID());
        			Sender.send(omsg);
        		}
            }
        	
        	// debug
        	System.out.println("LoanAmount: " + loanAmt + " Salary Amount: " + salary + " Scheme: " + scheme + " Approval: " + loanRequest.getApprovedFlag());
        	
        	// Create the sender and send the message
			String filter = "JMSCorrelationID = '" + msg.getJMSMessageID() + "'";
			MessageConsumer receiver = Session2.createConsumer(msg.getJMSReplyTo(), filter);
			Message app = receiver.receive();
			while (!(app instanceof TextMessage)) {
				app = receiver.receive();
			}
			System.out.print("Loan Proposal: ");
			System.out.println(((TextMessage)app).getText());
			
        	System.out.println("\nWaiting for loan requests...");

    	} catch (JMSException jmse) {
    		jmse.printStackTrace( ); 
    		System.exit(1);
    	} catch (Exception jmse) {
    		jmse.printStackTrace( ); 
    		System.exit(1);
    	}
    }
    public double getFedRate(int years) throws JMSException, InterruptedException {
    	
    	StreamMessage smsg = null;
    	smsg = (StreamMessage)rateReceiver.receive();
    	long millis = smsg.readLong();
    	F1 = smsg.readDouble();
    	F2 = smsg.readDouble();
    	F3 = smsg.readDouble();
    	F4 = smsg.readDouble();
    	F5 = smsg.readDouble();
    	F7 = smsg.readDouble();
    	F10 = smsg.readDouble();
    	F30 = smsg.readDouble();
    	if (years == 1)
    		return F1;
    	else if (years == 2)
    		return F2;
    	else if (years == 3)
    		return F3;
    	else if (years == 4)
    		return F4;
    	else if (years == 5)
    		return F5;
    	else if (years == 7)
    		return F7;
    	else if (years == 10)
    		return F10;
    	else return F30;
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
    	if (argv.length == 2) {
    		queuecf = argv[0];
    		requestq = argv[1];
    	} else {
    		System.out.println("Invalid arguments. Should be: ");
    		System.out.println
               ("java QLender factory request_queue");
    		System.exit(0);
    	}
      
    	QLender lender = new QLender(queuecf, requestq);
      
    	try {
    		// Run until enter is pressed
    		BufferedReader stdin = new BufferedReader
            	(new InputStreamReader(System.in));
    		System.out.println ("QLender application started");
    		System.out.println ("Press enter to quit application");
    		stdin.readLine();
            lender.exit();
    	} catch (IOException ioe) {
    		ioe.printStackTrace( );
    	}
   }
}
