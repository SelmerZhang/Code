package text2;
import java.lang.String;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��19�� ����4:05:52 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:��дһ�� Java Ӧ�ó��򣬸ó����������д��������СдӢ����ĸ��
* ascii:A-Z 65-90  a-z:97-122
*/
public class alphabet {
	public static void main(String[] args) {
		System.out.println("��ӡ��д��ĸ");
		for(int i=65;i<91;i++)
		{
			char t=(char)i;
			System.out.print(t);
			System.out.print(" ");
		}
		
		System.out.println("��ӡСд��ĸ");
		for(int i=97;i<123;i++)
		{
			char t=(char)i;
			System.out.print(t);
			System.out.print(" ");
		}	
				
		System.out.println("��ӡ���");
		
	}
}
