import java.util.ArrayList;

public class PCB {
	int quantCONST= 2;
	int clocktime = 0;
	int overflow = 0;
	int quantum = quantCONST;
	int CS = 0;
	double avgturn;
	double avgservice;
	double avgwait;
	int procCount;
	process lastProcess;
	ArrayList<process> pcb = new ArrayList<process>();
	ArrayList<process> inputs;
	
	public PCB(ArrayList<process> inc)
	{
		inputs = inc;
		procCount = inc.size();
		arrivalCheck(inputs);
		lastProcess = pcb.get(0);
		while (pcb.size()!=0 || inputs.size()!=0)
		{
			roundrobin();
			if (pcb.size() == 0 && inputs.size()!=0)
			{
				clocktime+=(quantum+overflow);
				arrivalCheck(inputs);
			}
		}
	}
	public void roundrobin()
	{
		quantum = quantCONST+overflow;
	    for (int y=0;y<pcb.size();y++)
	    {
	    	arrivalCheck(inputs);
			if(checkProcesses())
				break;
	    	//getClocktime();
	    	//getPCB();
	        if (lastProcess != pcb.get(y))
	        {
	            clocktime=clocktime+CS;
	        	//System.out.println("ContextSwitch");
	        }
	        if ((pcb.get(y).getServiceTime()-quantum)<=0)
	        {
	            overflow = quantum-(pcb.get(y).getServiceTime());
	            //System.out.println("Overflow: " + overflow);
	            pcb.get(y).processWork(pcb.get(y).getServiceTime());
	            clocktime = clocktime + (quantum - overflow);
	        }
	        else
	        {
	        	pcb.get(y).processWork(quantum);
	            overflow=0;
	            clocktime =clocktime + quantum;
	        }
	        lastProcess=pcb.get(y);
	        quantum = quantCONST;
	    }
	}
	public boolean checkProcesses()
	{
		boolean flag = false;
		for (int y=0;y<pcb.size();y++)
		{
	        if(pcb.get(y).getServiceTime()==0)
	        {
	        	pcb.get(y).setEnd(clocktime);
	        	System.out.println("Process: "+pcb.get(y).getID()+"\t ServiceTime: "+pcb.get(y).getInitServiceTime()+ "\t Arrival: "+pcb.get(y).getArrival() + "\t Start: "+pcb.get(y).getStart()+"\t InitWait: "+pcb.get(y).getInitWait() +"\t End: "+pcb.get(y).getEnd() +"\t TurnAround: " + pcb.get(y).getTurnAround(clocktime) + " \t TotalWait: "+pcb.get(y).getWait(clocktime));
	            avgservice +=pcb.get(y).getInitServiceTime();
	            avgturn +=pcb.get(y).getTurnAround(clocktime);
	            avgwait +=pcb.get(y).getWait(clocktime);
	        	pcb.remove(y);
	            checkProcesses();
	            flag = true;
	            break; 
	        }
		}
		return flag;
	}
	public void arrivalCheck(ArrayList<process> newProc)
	{
		inputs = newProc;
		for (int y=0;y<newProc.size();y++)
	        if (pcb.contains(newProc.get(y)))
	            inputs.remove(y);
	    for (int x=0;x<newProc.size();x++)
	        if (newProc.get(x).getArrival()<=clocktime)
	        {
	        	if (pcb.size() == 0)
	        		clocktime = newProc.get(x).getArrival();
	        	newProc.get(x).setStart(clocktime);
	            pcb.add(newProc.get(x));
	            newProc.remove(x);
	            arrivalCheck(newProc);
	            break;
	        }
	}
	public void getPCB()
	{
		for(process x:pcb)
		{
			System.out.println(x.getID()+ ", " + x.getServiceTime());
		}
	}
	public void getClocktime()
	{
		System.out.println("Clocktime: "+clocktime);
	}
	public double getAvgService()
	{
		return avgservice/procCount;
	}
	public double getAvgTurnAround()
	{
		return avgturn/procCount;
	}
	public double getAvgWait()
	{
		return avgwait/procCount;
	}
	
	public static void main(String[] args)
	{
		//int num = (int)(100+(200-100)*Math.random());
		int num = 100;
		TimeGenerator tg = new TimeGenerator(num);
		//TimeGenerator tg = new TimeGenerator(num, 4, 11, 4, 9);
		//TimeGenerator tg = new TimeGenerator(num, 1, 3, 4, 9);
		ArrayList<process> inputs = new ArrayList<process>(num);
		for (int q=0;q<num;q++)
		{
			process P = new process(q,tg.getStimes().get(q),tg.getAtimes().get(q));
			inputs.add(P);
		}
		PCB x = new PCB(inputs);
		System.out.println("Total Number of Processes: " + num);
		System.out.println("Average Service Time: " + x.getAvgService());
		System.out.println("Average Turn Around: " + x.getAvgTurnAround());
		System.out.println("Average Wait: " + x.getAvgWait());
	}
}
