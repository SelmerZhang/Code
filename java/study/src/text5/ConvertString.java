package text5;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��25�� ����10:24:59 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:��дһ�� Java Ӧ�ó����ж������ַ����Ƿ���ͬ���ж��ַ�����ǰ׺����׺�Ƿ��ĳ���ַ�����
* ͬ�����ֵ�˳��Ƚ������ַ����Ĵ�С��ϵ�������ַ����������ַ��������������ַ���ת��Ϊ���֣����ַ�
* ����ŵ������У����ַ����鴴���ַ���
*/

import javax.print.attribute.standard.MediaName;

import java.awt.Window.Type;
import java.util.Scanner;

public class ConvertString {
	public static void main(String[] args) {
		System.out.println("�Ƚ������ַ����Ƿ���ͬ");
		String s1=new String("you are a student");
		String s2=new String("how are you");
		if(s1.equals(s2)) // ʹ�� equals �����ж� s1 �� s2 �Ƿ���ͬ
		 {
			System.out.println(s1+"��"+s2+"  s1 �� s2 ��ͬ");
		 }
		 {
			System.out.println(s1+"�� "+s2+"  s1 �� s2 ����ͬ");
		 }
		
		System.out.println();
		String s3=new String("22030219851022024");
		System.out.println("�ж��ַ���ǰ׺���ַ���Ϊ�� "+s3);
		 
		 if(s3.startsWith("220302")) //�ж� s3 ��ǰ׺�Ƿ��ǡ�220302����
		 {
		 System.out.println("����ʡ�����֤");
		 }
		 
		 System.out.println();
		 String s4=new String("��"),
		 s5=new String("��");
		 System.out.println("�ַ���Ϊ��"+s4+"  ��     "+s5);
		 if(s4.compareTo(s5)>0)//�����ֵ��� s4 ���� s5 �ı��ʽ��compareto ���ص�����ֵ
		 {
		 System.out.println("���ֵ��� s4 ���� s5");
		 }
		 else
		 {
		 System.out.println("���ֵ��� s4 С�� s5");
		 }		 
		 
		 System.out.println();
		 String path="c:\\java\\jsp\\A.java";
		 System.out.println("�ж��ַ���λ�ã�����ȡ�ַ�����ԭ�ַ���Ϊ��  "+path);
		 int position=0;		 
		 position=path.lastIndexOf("\\");  //��ȡ path ��������Ŀ¼�ָ����ŵ�λ��
		 System.out.println("c:\\java\\jsp\\A.java ��������\\��λ��: "+position);
		 
		 String fileName=path.substring(position+1);//��ȡ path �С�A.java�����ַ�����
		 System.out.println("c:\\java\\jsp\\A.java �к��е��ļ���:"+fileName);
		 
		 System.out.println();
		 String s6=new String("100"),
		 s7=new String("123.678");
		 System.out.println("���ַ���ת��Ϊ��ֵ��ԭ�ַ���Ϊ�� "+s7);		 
		 int n1=Integer.parseInt(s6);  //�� s6 ת���� int �����ݡ�
		 double n2=Double.parseDouble(s7); //�� s7 ת���� double �����ݡ�
		 double m=n1+n2;
		 System.out.println(m);
		 
		 System.out.println();
		 System.out.println("����ֵת��Ϊ�ַ���");
		 String s8=""+m; //String ���� valuOf(int n)������ m ת��Ϊ�ַ�������		 
		 position=s8.indexOf(".");
		 String temp=s8.substring(position+1);
		 System.out.println("����"+m+"��"+temp.length()+"λС��") ;
		 
		 System.out.println();
		 String s9=new String("ABCDEF");
		 System.out.println("�ַ����Ž��ַ�����: "+s9);		 
		 char a[]= s9.toCharArray(); //�� s9 ��ŵ����� a �С�
		 for(int i=a.length-1;i>=0;i--)
		 {
		 System.out.print(" "+a[i]);
		 }		 		
	}
}
