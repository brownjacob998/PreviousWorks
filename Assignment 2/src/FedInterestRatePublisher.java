import java.time.Instant;
import java.time.ZonedDateTime;
import java.util.Random;
import java.util.Vector;
import java.util.logging.Logger;

import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.MessageProducer;
import javax.jms.Session;
import javax.jms.StreamMessage;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class FedInterestRatePublisher {
	private static final Logger Jlog = Logger.getLogger("fedInterestRate");
    String      cfName       = "ECSU.CSC360.CF";
    String      topicName     = "fed.interest";
    String      userName        = null;
    String      password        = null;  
    
    public FedInterestRatePublisher() {
        try
        {
        	// InitialContext parameters are obtained from jndi.properties
            InitialContext ctx = new InitialContext();
            // Look up a JMS connection factory
            ConnectionFactory factory = 
        		  (ConnectionFactory)ctx.lookup(cfName);
            // Create a JMS connection
            Connection connection = (Connection) factory.createConnection();
            // Create publisher session objects
            Session session =  connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
            /*
             * 
             */
            Destination dest = (Destination)ctx.lookup(topicName);

            MessageProducer pub = (MessageProducer) session.createProducer(dest);

            /* publish Fed interest rate stream messages */
            Random rnd = new Random();
            rnd.setSeed(100);
            Double min = 0.08;
            Double max = 0.01;
            
            while (true)
            {
            	Jlog.info("Fed Interest Rate Published: " + new java.util.Date());
            	long millis = Instant.now().toEpochMilli();
            	// long millis = new java.util.Date.getTime();
                Double a = rnd.nextDouble();
                Double flux = (max - min) * a + min;
                StreamMessage rate = session.createStreamMessage();
                rate.writeLong(millis);
                rate.writeDouble(0.97 + a); // 1-year
                rate.writeDouble(1.04 + a); // 2-year
                rate.writeDouble(1.11 + a); // 3-year
                rate.writeDouble(1.17 + a); // 4-year
                rate.writeDouble(1.18 + a); // 5-year
                rate.writeDouble(1.20 + a); // 7-year
                rate.writeDouble(1.25 + a); // 10-year
                rate.writeDouble(1.96 + a); // 30-year                
                pub.send(rate);
                try {
					Thread.sleep(10000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}  // wait for one minute
            }
        }
        catch(JMSException e)
        {
            e.printStackTrace();
            System.exit(0);
        } catch (NamingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }

	
    public static void main(String args[])
    {
        FedInterestRatePublisher t = new FedInterestRatePublisher();
    }

}
