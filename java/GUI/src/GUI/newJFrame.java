package GUI;
import java.awt.*;
import javax.swing.*;
import javax.swing.text.StyledEditorKit.BoldAction;
/**
* Filename:
* title:
* @date ����ʱ�䣺2017��12��27�� ����6:51:22 
* @version 1.0 
* @parameter  Jbutton
* Description: ������frame,��ť��ָ��λ����
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class newJFrame extends JFrame{
	JButton an1,an2,an3,an4,an5;
	public static void main(String[] args) {
		newJFrame frame=new newJFrame();
	}
	
	public newJFrame() {
		// TODO Auto-generated constructor stub
		this.setTitle("�û�����߽粼��");
		this.setSize(750, 500);
		this.setLocation(250, 110);
		an1 =new JButton("��ť");
		an2=new JButton("��");
		an3=new JButton("��");
		an4=new JButton("��");
		an5=new JButton("��");
		/**
		 * ��ӵ�λ��
		 * 
		 */
		this.add(an1,BorderLayout.CENTER);
		this.add(an2, BorderLayout.EAST);
		this.add(an3, BorderLayout.SOUTH);
		this.add(an4, BorderLayout.WEST);
		this.add(an5, BorderLayout.NORTH);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
		
	}
}















