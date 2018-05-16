package text10;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��4��28�� ����4:06:45 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand :��дһ��Ӧ�ó��򣬳������߳��⣬���������̣߳�first �� second��first ����ģ��һ����ɫ�İ�ť������(10��60)�˶���(100��60)��
* second ����ģ��һ����ɫ�İ�ť������(100��60)�˶���(200��60)��
*/

import java.awt.Button;
import java.awt.Color;
import java.awt.Component;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MoveButton extends Frame implements Runnable, ActionListener {
	Thread first, secend; // �� Thread ������ first,second �����̶߳���
	Button redButton, greenButton, startButton;
	int distance = 10;

	MoveButton() {
		first = new Thread(this); // ���� first �̣߳���ǰ������Ϊ���̵߳�Ŀ�����
		secend = new Thread(this); // ���� first �̣߳���ǰ������Ϊ���̵߳�Ŀ�����
		redButton = new Button();
		greenButton = new Button();
		redButton.setBackground(Color.red);
		greenButton.setBackground(Color.green);
		startButton = new Button("start");
		startButton.addActionListener(this);
		setLayout(null);
		add(redButton);
		redButton.setBounds(10, 60, 15, 15);
		add(greenButton);
		greenButton.setBounds(100, 60, 15, 15);
		add(startButton);
		startButton.setBounds(10, 100, 30, 30);
		setBounds(0, 0, 300, 200);
		setVisible(true);
		validate();
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
	}

	public void actionPerformed(ActionEvent e) {
		try {
			first.start();
			secend.start();
		} catch (Exception exp) {
		}
	}

	public void run() {
		while (true) {
			if (Thread.currentThread() == first) // �жϵ�ǰռ�� CPU ��Դ���߳��Ƿ��� first
			{
				moveComponent(redButton);
				try {
					Thread.sleep(20);
				} catch (Exception exp) {
				}
			}
			if (Thread.currentThread() == secend) // �жϵ�ǰռ�� CPU ��Դ���߳��Ƿ��� second
			{
				moveComponent(greenButton);
				try {
					Thread.sleep(5);
				} catch (Exception exp) {
				}
			}
		}
	}

	public synchronized void moveComponent(Component b) {
		if (Thread.currentThread() == first) {
			while (distance > 100 && distance <= 200)
				try {
					wait();
				} catch (Exception exp) {
				}
			distance = distance + 1;
			b.setLocation(distance, 60);
			if (distance >= 100) {
				b.setLocation(10, 60);
				notifyAll();
			}
		}
		if (Thread.currentThread() == secend) {
			while (distance >= 10 && distance < 100)
				try {
					wait();
				} catch (Exception exp) {
				}
			distance = distance + 1;
			b.setLocation(distance, 60);
			if (distance > 200) {
				distance = 10;
				b.setLocation(100, 60);
				notifyAll();
			}
		}
	}
}
