package base;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;



/**
* Filename:
* title:binary_search
* @date ����ʱ�䣺2017��12��27�� ����9:20:18 
* @version 1.0 
* @parameter  
* Description: ���ֲ���
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/


public class binary_search {
	public static int rank(int key,int[] a)
	{
		//��������������
		int lo=0;
		int hi=a.length-1;
		while(lo<=hi)
			{
				//�����ҵ���Ҫô�����ڣ�Ҫô����a[lo-hi]֮��
				int mid=lo+(hi-lo)/2;
				if (key<a[mid]) {
					hi=mid-1;
				}
				else if (key>a[mid]) {
					lo=mid+1;
				}
				else {
					return mid;
					
				}
			}
		return -1;//û���ҵ�
	}
	
	public static void main(String[] args) {
		int[] a=new int[10];
		for(int i=0;i<10;i++)
		{
			a[i]=(int)(Math.random()*100);//math.random�����������������0-1֮���˫������
			System.out.println(a[i]);
		}	
		Arrays.sort(a);//Ҫ�������ܽ��ж��ֲ���
		System.out.println("������Ҫ���ҵ������˳��밴1��");
		Scanner scanner=new Scanner(System.in);
		int key=scanner.nextInt();	
		
		while (key!=1) {
			int t=rank(key, a);
			if (t!=-1) {
				System.out.println("Ҫ���ҵ����ǣ�"+key+"  �����ҵ�");
			}
			else
				System.out.println("Ҫ���ҵ�����"+key+"û���ҵ�");
			System.out.println("������Ҫ���ҵ������˳��밴1��");
			key=scanner.nextInt();
		}
		
	}
}















