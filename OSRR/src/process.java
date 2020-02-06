
public class process {
	int servicetime;
	int initialserv;
	int id;
	int start;
	int end;
	int arrivalTime;
	int totalWait;
	int turnAround;
	int initwait;
	public process(int d, int st, int at)
	{
		id = d;
		servicetime=st;
		initialserv = st;
		arrivalTime=at;
		totalWait = 0;
		turnAround = 0;
	}
	public void processWork(int quantum)
	{
		servicetime=servicetime-quantum;
	}
	public int getServiceTime()
	{
		return servicetime;
	}
	public int getInitServiceTime()
	{
		return initialserv;
	}
	public int getArrival()
	{
		return arrivalTime;
	}
	public int getID()
	{
		return id;
	}
	public int getTurnAround(int clocktime)
	{
		turnAround = clocktime - arrivalTime;
		return turnAround;
	}
	public int getInitWait()
	{
		initwait = start-arrivalTime;
		return initwait;
	}
	public int getWait(int clocktime)
	{
		totalWait = turnAround - initialserv;
		return totalWait;
	}
	public void setStart(int clocktime)
	{
		start = clocktime;
	}
	public void setEnd(int clocktime)
	{
		end = clocktime;
	}
	public int getStart()
	{
		return start;
	}
	public int getEnd()
	{
		return end;
	}
}
