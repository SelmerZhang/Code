package text6;
import javax.swing.JOptionPane;
import java.util.Calendar;
import java.sql.Date;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��26�� ����7:09:18 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:��дһ�� Java Ӧ�ó����û�������Ի����������������ڣ������ж��������ڵĴ�С��ϵ���Լ���������֮��ļ��������
*/
public class JudgeDate {
	public static void main(String args[ ]) {
		 String str=JOptionPane.showInputDialog("�����һ�����ڵ����:");
		 int yearOne=Integer.parseInt(str);
		 str=JOptionPane.showInputDialog("���������·�:");
		 int monthOne=Integer.parseInt(str);
		 str=JOptionPane.showInputDialog("������·ݵ�����:");
		 int dayOne=Integer.parseInt(str);
		 str=JOptionPane.showInputDialog("����ڶ������ڵ����:");
		 int yearTwo=Integer.parseInt(str);
		 str=JOptionPane.showInputDialog("���������·�:");
		 int monthTwo=Integer.parseInt(str);
		 str=JOptionPane.showInputDialog("������·ݵ�����:");
		 int dayTwo=Integer.parseInt(str);
		 
		 
		 Calendar calendar=Calendar.getInstance();
		 calendar.set(yearOne,monthOne,dayOne);
		 long timeOne=calendar.getTimeInMillis();
		 calendar.set(yearTwo,monthTwo,dayTwo);
	     long timeTwo=calendar.getTimeInMillis();
	       
	     Date date1=new Date(timeOne);
	     Date date2=new Date(timeTwo); 
	     if(date2.equals(date1))
	     {System.out.println("�������ڵ��ꡢ�¡�����ȫ��ͬ");}
	     else if(date2.after(date1))
	     {System.out.println("������ĵڶ������ڴ��ڵ�һ������");}
	     else if(date2.before(date1))
	     {System.out.println("������ĵڶ�������С�ڵ�һ������");}
	       
	     long days=(timeOne-timeTwo)/(1000*60*60*24);
	     System.out.println(yearOne+"��"+monthOne+"��"+dayOne+"�պ�"+yearTwo+"��"+monthTwo+"��"+dayTwo+"���"+days+"��");      
		 }
		
		

}
