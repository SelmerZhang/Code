import java.util.*;

/**
* Filename:
* title:
* @date ����ʱ�䣺2018��1��3�� ����8:35:08 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class Josephus {
	public static void main(String[] args) {
		int m=Integer.parseInt(args[0]);
		int n=Integer.parseInt(args[1]);
		
		Queue<Integer> queue = new LinkedList<Integer>();
		int [] a=new int[n];
		for (int i = 0; i < n; i++) {		
			queue.add(i);
		}
		
//		for(Object o:queue)
//		{
//			System.out.println(o);
//		}
		while(queue.size()!=1)
		{			
			int t=m-1;
			while(m-1>queue.size()||m-1==queue.size())
			{
				t=m-1-queue.size();
			}
			
			queue.remove(t);
			int p=0;
			for (Object o:queue) {
				
				a[p]=(int)o;
				p++;
			}
			
			while(!queue.isEmpty())//���
			{
				queue.poll();
			}
			
			//���ö���
			for(int j=t;j<a.length-1;j++)
			{
				queue.add(a[j]);
			}

			for(int k=0;k<t;k++)
			{
				queue.add(a[k]);
			}
		}
		System.out.println("lalalalallala");
		System.out.println("queue�Ĵ�СΪ"+queue.size()+"���ʣ�µ�Ԫ��Ϊ"+queue.element());
	}
}
