package text3;

import javax.crypto.interfaces.PBEKey;

/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��19�� ����6:35:02 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:
* 1. ��дһ�� Java ��������һ�����飬��Ԫ���磺{12, 23, 456, 222, 768, 93245}���������Ԫ�صĺͣ�SumArray.java
* 2. ��дһ�� Java ��������һ�����飬��Ԫ���磺{12, 23, 456, 222, 768, 93245}��ӡ����Ԫ�ص�ֵ������ӡ�����Ԫ�ص�ֵ:MaxArray.java
*/
public class Sum_Max {
	public int sum(int[] arr) {
		int s=0;
		for(int i:arr)
		{
			s+=i;
		}
		return s;
	}
	
	public void print(int[] arr)
	{
		System.out.println("�����е�Ԫ��Ϊ��");
		for(int i:arr)
		{
			System.out.print(i);
			System.out.print(" ");
		}
	}
	
	public int max(int[] arr) {
		int max_number=0;
		for(int i:arr)
		{
			if(max_number<i)
			{
				max_number=i;
			}
		}
		return max_number;
	}
	public static void main(String[] args) {
		Sum_Max sm=new Sum_Max();
		int[] arr ={12, 23, 456, 222, 768, 93245};
		System.out.print("�����ܵ�ֵΪ��");
		System.out.println(sm.sum(arr));
		sm.print(arr);
		System.out.println();
		System.out.println("������������Ϊ��");
		System.out.println(sm.max(arr));
		
		
	}
}
