package Botton;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.AbstractButton;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JPanel;

import javax.swing.JFrame;



/**
* Filename:ButtonDemo
* title:Button
* @date ����ʱ�䣺2017��12��27�� ����9:14:46 
* @version 1.0 
* @parameter  
* Description: ��ť��ʾ
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class Botton extends JPanel implements ActionListener{
	protected JButton b1,b2,b3;
	/**
	 * ʹ�ù��캯����ʼ������
	 */
	public Botton() {
		ImageIcon leftButtonIcon = createImageIcon("images/right.gif");//createImageIcon���Զ��庯����
		ImageIcon middleButtonIcon=createImageIcon("img2.jpg");
		ImageIcon rightButtonIcon=createImageIcon("img3.jpg");
		
		b1=new JButton("ʧЧ�м䰴ť",leftButtonIcon);
		b1.setVerticalTextPosition(AbstractButton.CENTER);//ˮƽ�м����
		b1.setHorizontalTextPosition(AbstractButton.LEADING);//�൱��left
		b1.setMnemonic(KeyEvent.VK_D);//��b1��ALT+D��
		b1.setActionCommand("disable");
		
		b2=new JButton("M�м��",middleButtonIcon);
		b2.setVerticalTextPosition(AbstractButton.BOTTOM);
		b2.setHorizontalTextPosition(AbstractButton.CENTER);
		b2.setMnemonic(KeyEvent.VK_M);
		
		b3 = new JButton("E�����м䰴ť", rightButtonIcon);
        b3.setMnemonic(KeyEvent.VK_E);//��b3�alt+E��
        b3.setActionCommand("enable");
        b3.setEnabled(false);

		
	}
	
	
	
	
	/**
	 * ����ͼ�꣬����ͼ������λ�ã�����ͼ�����
	 */
	protected static ImageIcon createImageIcon(String path) {
		java.net.URL imageurl=Botton.class.getResource(path);
		if (imageurl!=null) {
			return new ImageIcon(imageurl);
		}		
		else
		{
			System.out.println("can't find the image file:"+path);
			return null;
		}
	}
}
	
	
	
	
	















