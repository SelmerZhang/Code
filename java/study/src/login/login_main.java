package login;

/**
* Filename:
* title:
* @date ����ʱ�䣺2018��5��21�� ����4:10:12 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
import javax.swing.*;

import java.awt.*; //�����Ҫ�İ�
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Date;

public class login_main implements ActionListener {
	static String string;
	JTextField jTextField;// �����ı������
	JPasswordField jPasswordField;// ������������
	JLabel jLabel1, jLabel2;
	JPanel jp1, jp2, jp3, jp4;
	JButton jb1, jb2, jb3; // ������ť
	String username = "bobby";
	String password = "123";
	JFrame frame = new JFrame("��½");
	JRadioButton r1 = new JRadioButton("����");
	JRadioButton r2 = new JRadioButton("�Ϻ�");
	JRadioButton r3 = new JRadioButton("�ൺ");
	static String location = "llll";

	public login_main() {//login

		jTextField = new JTextField(12);
		jPasswordField = new JPasswordField(13);
		jLabel1 = new JLabel("�û���");
		jLabel2 = new JLabel("����");
		jb1 = new JButton("��½");
		jb2 = new JButton("ȡ��");

		jb3 = new JButton("��ѡ���ַ");
		jp1 = new JPanel();
		jp2 = new JPanel();
		jp3 = new JPanel();
		jp4 = new JPanel();
		jb1.addActionListener(this);
		jb2.addActionListener(this);
		// jb3.addActionListener(this);
		// ���ò���
		frame.setLayout(new GridLayout(4, 1));

		jp1.add(jLabel1);
		jp1.add(jTextField);// ��һ���������û������ı���

		jp2.add(jLabel2);
		jp2.add(jPasswordField);// �ڶ�����������������������

		jp3.add(jb1);
		jp3.add(jb2);

		ButtonGroup bg = new ButtonGroup();// ����һ��ButtonGroup����
		bg.add(r1);
		bg.add(r2);
		bg.add(r3);
		jp4.add(r1);
		jp4.add(r2);
		jp4.add(r3);

		frame.add(jp1);
		frame.add(jp2);
		frame.add(jp4);
		frame.add(jp3); // �����������ӵ���½������
		// ������ʾ
		frame.setSize(300, 200);
		// this.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

	}

	public void actionPerformed(ActionEvent e) {//actionlister login
		string = e.getActionCommand();
		if (string.equals("��½")) {
			if (r1.isSelected()) {
				location = r1.getText();
			}
			if (r2.isSelected()) {
				location = r2.getText();
			}
			if (r3.isSelected()) {
				location = r3.getText();
			}
			String name = jTextField.getText().toString();
			String admin = new String(jPasswordField.getPassword());
			login_check(name, admin, location);
		}
		if (string.equals("ȡ��")) {// �˳�
			frame.setVisible(false);// ���ش���
			System.exit(0);// �˳�����
		}
	}

	public void login_check(String name, String admin, String location) {
		if (name.equals(username) && admin.equals(password)) {
			// ��ת
			Myfram(location, username);
		} else {// ��ʾ�Ƿ��������룬������λ
			prompt();
			if (string.equals("��������")) {
			}
			if (string.equals("�˳�"))
				;
		}
	}

	public void Myfram(String Sitting, String username) {
		frame.setVisible(false);//���ص�¼����		
		JFrame f = new JFrame("�û�����");
		f.setSize(200, 300);
		f.setLayout(new GridLayout(2,1));
		JPanel jp5 = new JPanel();
		JButton jb5 = new JButton("�˳�");
		JPanel jp6 = new JPanel();
		jp6.add(jb5);
		JTextArea readonly =new JTextArea();
		Date date = new Date();
		SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd :hh:mm:ss");
		String time = dateFormat.format(date);
		String helloword = "  wellcome "+ username+ " from " + Sitting  ;
		jp5.add(readonly);
		f.add(jp5);
		readonly.append("��¼ʱ��:  " + time + "\r\n"+helloword);
		readonly.setEditable(false);//ֻ��
		jp6.add(jb5);//�˳���ť
		jb5.addActionListener(new ActionListener() {//�˳���Ӧ			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				f.setVisible(false);
			}
		});
		f.add(jp6);
		
		//����

		JPanel jp7 = new RePanel();		
		f.add(jp7);
     
		
		
		f.setSize(300, 200);
		// this.pack();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
	}
	


	public void prompt() {// ���������ʾ
		JFrame f = new JFrame("��ʾ");
		JPanel jp5 = new JPanel();
		JButton jb4, jb5, jb6;
		jb4 = new JButton("������û�������ȷ���Ƿ���������");
		jb5 = new JButton("��������");
		jb6 = new JButton("�˳�");

		jb5.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {// ��������
				f.setVisible(false);
				jTextField.setText("");
				jPasswordField.setText("");
				jTextField.requestFocus();// ������Ƶ��ı���
			}
		});
		jb6.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {// �˳�����
				// TODO Auto-generated method stub
				f.setVisible(false);
				frame.setVisible(false);

			}
		});
		jp5.add(jb4);
		jp5.add(jb5);
		jp5.add(jb6);
		f.add(jp5);
		f.setSize(300, 200);
		// this.pack();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
	}

	public static void main(String[] args) {
		login_main login = new login_main();

	}
}



class  RePanel extends JPanel{
	ImageIcon icon;  
	Image img;

	public RePanel() {
		icon = new ImageIcon(getClass().getResource("/login/img12.jpg"));
		img = icon.getImage();
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		// ����������Ϊ�˱���ͼƬ���Ը��洰�����е�����С�������Լ����óɹ̶���С
		g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), this);
	}
//    public void paintComponent(Graphics g){
//        super.paintComponent(g);
//        g.drawImage(new ImageIcon("img12.jpg").getImage(), 0, 0, 200, 200, this);
//     }
}