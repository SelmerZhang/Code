package text2_2;
import java.util.Scanner;
import java.lang.String;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��19�� ����4:17:59 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:��дһ�� Java Ӧ�ó����û��Ӽ�������һ�� 1��9999 ֮������������ж�������Ǽ�λ����
* ���ж�������Ƿ��ǻ������� ��������ָ���������е������������к�õ�������ԭ����ͬ��
*���� 12121��3223 ���ǻ�������
* int n = sc.nextInt();
*/
public class judge_number {
	
	public int limit(int n) {
		//��������Ϊ1-9999
		if (n%10000!=0)	
		{
			n=n%10000;
		}
		else {
			n=1;
		}		
		return n;
	}
	
	public int digit(int n) {
		//�ж�λ��
		int count = 1;
		if(n>99)
		{
			if(n>999)
			{
				count=4;
			}
			else {
				count=3;
			}
		}
		else {
			if(n>9)
			{
				count=2;
			}
			else {
				count=1;
			}
		}
		return count;
	}
	
	public String reverse1(int n)

	{
	   String str=""+n;
	   return new StringBuffer(str).reverse().toString();
	}
	
	public boolean plalindrome(String str,int n) {
		String s=""+n;
		if(str.equals(s))
			{
				return true;
			}
			
		else {
			return false;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		judge_number judge=new judge_number();
		System.out.println("������һ����");
		int n=sc.nextInt();
		n=judge.limit(n);//�����������Ϊ1-9999
		int count=judge.digit(n);//�жϼ�λ��
		System.out.println("n��"+count+"λ��");
		String str =judge.reverse1(n);
		boolean plalindrome =judge.plalindrome(str,n);//�ж��Ƿ�Ϊ����
		if(plalindrome==true)
		{
			System.out.println("�ǻ���");
		}
		else {
			System.out.println("���ǻ���");
		}
		
	}
}
