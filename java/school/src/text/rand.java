package text;
import java.util.Random;
import java.util.Scanner;

import text2_2.judge_number;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��19�� ����5:09:50 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:�������������ͻ�һ�� 1��100 ֮����������û�������Ի����������Լ��Ĳ²⡣����
������ʾ��Ϣ����ʾ��Ϣ�ֱ��ǣ����´��ˡ�������С�ˡ��͡��¶��ˡ����û��ɸ�����ʾ
��Ϣ�ٴ�����²⣬ֱ����ʾ��Ϣ�ǡ��¶��ˡ���
*/
public class rand {
	public static Scanner sc = new Scanner(System.in);
	public String guss(int a) {
		String s = " ";
		
		while(true)
		{
			System.out.println("������һ����");
			int n=sc.nextInt();
			if(n>a)
			{
				return "�´���";
			}
			else 
			{
				if(n==a)
			{
				return "������";
			}
				else
				{
					return "��С��";
				}
			}
		}
		
	} 
	public static void main(String[] args) {
		Random random = new Random();
		int a=random.nextInt(100);
		rand r = new rand();
		while (true) {
			System.out.println(r.guss(a));
			System.out.println("�Ƿ�������룬���������밴1 ������������˳�");
			int key=sc.nextInt();
			if (key!=1) {
				break;
			}
		}
		
	}
}
