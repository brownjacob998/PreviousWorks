import java.io.Serializable;
import java.io.*;
import java.util.Date;
import java.util.StringTokenizer;
import javax.jms.*;
import javax.naming.*;

public class LoanProposalData implements Serializable {
	private String bank;
	private double loan;
	private double rate;
	private double income;
	private int scheme;
	private boolean approval = true;
	private String loanReason;
	private String HomeBank = "TrustCo";
	
	public LoanProposalData(double loanAmt, double interest, double salary, String name, int scheme) {
		this.setBankName(name);
		this.setInterestRate(interest);
		this.setLoanAmount(loanAmt);
		this.setPaymentScheme(scheme);
		income = salary;
	}
	
	public void setBankName(String bankName) {
		bank = bankName;
	}
	public void setReason(String reason) {
		loanReason = reason;
	}
	public void setLoanAmount(double loanAmount) {
		loan = loanAmount;
	}
	public void setPaymentScheme(int paymentScheme) {
		scheme = paymentScheme;
	}
	public void setInterestRate(double interestRate) {
		rate = interestRate;
	}
	public void setApprovedFlag(boolean bool) {
		if (bank.equals(HomeBank))
			approval = false;
		if (loan >500000)
			approval = false;
		if (loan/income > 3)
			approval = false;
		
	}
	public String getBankName() {
		return bank;
	}
	public String getReason() {
		return loanReason;
	}
	public double getLoanAmount() {
		return loan;
	}
	public int getPaymentScheme() {
		return scheme;
	}
	public double getInterestRate() {
		return rate;
	}
	public boolean getApprovedFlag() {
		return approval;
	}
}
