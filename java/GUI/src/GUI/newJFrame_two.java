package GUI;
import java.awt.*;
import javax.swing.*;
import javax.swing.text.StyledEditorKit.BoldAction;
/**
* Filename:
* title:
* @date ����ʱ�䣺2017��12��27�� ����6:51:22 
* @version 1.0 
* @parameter  
* Description: ������frame,��ť��li��������
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class newJFrame_two extends JFrame{
	JButton[] an= {null,null,null,null};
	public static void main(String[] args) {
		newJFrame_two frame=new newJFrame_two();
	}
	
	public newJFrame_two() {
		// TODO Auto-generated constructor stub
		an[0]=new JButton("��");
		an[1]=new JButton("˯");
		an[2]=new JButton("��");
		an[3]=new JButton("hahahahah!");
		//this.setLayout(new FlowLayout());//���ֹ�������������Ӿ�ֻ����ʾ���һ����ť
		
		this.setLayout(new FlowLayout(FlowLayout.RIGHT));//buttond λ�ã�����left
		/**
		 * ��ӵ�λ��
		 * 
		 */
		this.add(an[0]);
		this.add(an[1]);
		this.add(an[2]);
		this.add(an[3]);
		this.setLayout(new GridLayout(2, 2,15,15));//���񲼾ֹ�����������ť����������������ʾ,��ÿ����ť�������º�����15���ء���仰��λ��һ��Ҫ����add�Ժ�
		this.setTitle("�û�����߽粼��");
		this.setSize(750, 500);
		this.setLocation(250, 110);		
		this.setResizable(false);//�����Сֻ��Ϊ���õ�ֵ������ͨ���û��ı䣬Ĭ����true
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);//Ĭ���д���
	}
}















