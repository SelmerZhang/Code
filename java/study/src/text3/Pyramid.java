package text3;
import java.util.Scanner;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��19�� ����6:11:57 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:����Ļ����ʾһ�������ͷ��š�*����ɵĽ�����ͼ����Ҫ���û����ý������ĸ߶ȣ������ܸ����û����õĸ߶ȴ�ӡ��������
* 
*/
public class Pyramid {
	public static Scanner sc = new Scanner(System.in);
	public void print(int hight) {
		for(int i=hight;i>0;i--)
		{
			for(int j=0;j<i;j++)
			{
				System.out.print(" ");
			}
			for(int j=2*(hight-i)+1;j>0;j--)
			{
				System.out.print("*");
			}	
			System.out.println();
		}
	}
	public static void main(String[] args) {
		System.out.println("������������ĸ߶�");
		int hight = sc.nextInt();
		Pyramid pyramid = new Pyramid();
		pyramid.print(hight);
		System.out.println("��ӡ���");
	}

}
