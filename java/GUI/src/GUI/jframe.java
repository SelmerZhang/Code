package GUI;
import java.awt.*;
import javax.swing.*;
/**
* Filename:
* title:jframe
* @date ����ʱ�䣺2017��12��27�� ����4:58:33 
* @version 1.0 
* @parameter  
* Description: ͼ�λ�����֮jframe
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class jframe {
	public static void main(String[] args) {
		JFrame aa=new JFrame();
		aa.setTitle("�û�����");//Ĭ����û�д���ʹ�С��
		
		aa.setSize(750,500);//����Ĵ�С
		aa.setLocation(250,100);//�����λ��
		
		JButton an1=new JButton("һ����ť");//�½�һ����ť
		aa.add(an1);//����ť��ӵ�������
		aa.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//�رմ����ǹرս���
		aa.setVisible(true);
	}
}














