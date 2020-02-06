import java.util.ArrayList;
import java.lang.Math;

public class TimeGenerator {
	static ArrayList<Integer> IAtimes = new ArrayList<Integer>();
	static ArrayList<Integer> Atimes = new ArrayList<Integer>();
	static ArrayList<Integer> Stimes = new ArrayList<Integer>();
	int ATimeMax = 9;
	int ATimeMin = 4;
	int STimeMax = 6;
	int STimeMin = 2;
	public TimeGenerator(int num) {
		
		
		Arrival(num);
		serviceTime(num);
	}
	public TimeGenerator(int num, int smin, int smax, int amin, int amax) {
		
		this.ATimeMax = amax;
		this.ATimeMin = amin;
		this.STimeMax = smax;
		this.STimeMin = smin;
		Arrival(num);
		serviceTime(num);
	}
	public void Arrival(int num) 
	{
		int a = 0;
		int y = 0;
		for(int x = 0;x<num;x++)
		{
			if (x!=0) {
				a= (int)(ATimeMin+(ATimeMax-ATimeMin)*Math.random());
				y += a;
				Atimes.add(y);
				IAtimes.add(a);
			}
			else {
				Atimes.add(y);
				IAtimes.add(a);
			}
		}
	}
	public void serviceTime(int num)
	{
		int s = 0;
		for(int x = 0;x<num;x++)
		{
			s= (int) (STimeMin+(STimeMax-STimeMin)*Math.random());
			Stimes.add(s);
		}
	}
	public ArrayList<Integer> getAtimes()
	{
		return Atimes;
	}
	public ArrayList<Integer> getIAtimes()
	{
		return IAtimes;
	}
	public ArrayList<Integer> getStimes()
	{
		return Stimes;
	}
}
