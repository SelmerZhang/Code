package frame;
import javax.swing.*;
import java.awt.*;
/**
* Filename:frame
* title:mainframe
* @date ����ʱ�䣺2017��12��26�� ����10:00:57 
* @version 1.0 
* @parameter  Toolkit.getDefaultToolkit().getScreenSize()������toolkit��һ�������࣬Toolkit getDefaultToolkit()��ȡĬ�Ϲ��߰�
* 
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class mainFrame extends JFrame
{
	/**
	 * ���캯��ͨ�����ݲ�������ɴ��ڻ��ƣ�
	 * ����String STitle���ڱ��⣬int IWidth ���ڿ�ȣ�int IHeight ���ڸ߶�
	 */
	public mainFrame(String sTitle,int iWidth,int iHeight)
	{
		Dimension dim=Toolkit.getDefaultToolkit().getScreenSize();//��ȡ��Ļ�ߴ缴�ֱ���
		//ImageIcon ii=new ImageIcon("img14.jpg");	//����ͼƬ
		setTitle(sTitle);//���ô������
		//setIconImage(ii.getImage());//���ô����ͼ��
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);//���ùرմ���ʱ�˳�����
		setSize(iWidth, iHeight);//���ô����С
		int w=getSize().width;//��ȡ�����
		int h=getSize().height;
		//System.out.println("�����"+w+"�����:"+h);
		//�������Ƶ���Ļ�м�
		int x=(dim.width-w)/2;
		int y=(dim.height -h)/2;
		setLocation(x, y);//�������Ƶ���Ļ�м�
		setVisible(true);//��ʾ����		
	}
	
	/**
	 * main
	 */
	public static void main(String[] args) {
		JFrame.setDefaultLookAndFeelDecorated(true);//ʹ�����µ�swing���
		mainFrame mainFrame=new mainFrame("main frame Demo", 400, 300);
	}
	
	
	
	
	
	
}























