package counter;

import java.awt.*;
import java.time.*;
import java.awt.event.*;
import java.sql.Time;
import java.util.*;

import javax.print.attribute.standard.RequestingUserName;
import javax.swing.*;
import javax.swing.text.html.HTMLDocument.Iterator;

import com.mysql.jdbc.log.Slf4JLogger;

import text7.Arr;

/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��5��12�� ����10:27:13
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com
 * �ܽ᣺�ݴ�!!!!!!!
 * ���㣺δ��ʵ�������ţ���������������
 */
public class comput implements ActionListener {
	private JFrame f;
	private String string;
	JTextField display1 = new JTextField("0");// ��ʼ����
	JTextField display2 = new JTextField(" ");
	ArrayList list_gobel = new ArrayList();
	double sum_last = 0.0;

	public void init()// ��ʼ�� ,�����������list����
	{
		f = new JFrame("������");
		f.setBounds(400, 150, 260, 360); // ��ʼλ�ã�X,Y������
		// f.setResizable(false);//���ɸı��С
		String[] str = { "CE", "(", ")", "��", "9", "8", "7", "+", "6", "5", "4", "-", "3", "2", "1", "*", ".", "0", "=",
				"/" };
//		JTextField display1 = new JTextField("0");// ��ʼ����
//		JTextField display2 = new JTextField(" ");
		display1.setHorizontalAlignment(JTextField.RIGHT);
		display2.setHorizontalAlignment(JTextField.RIGHT);
		// display2.setBounds(0, 0, 250, 10);
		Container contentPane = f.getContentPane();
		JButton[] buttons = new JButton[str.length];
		JPanel panel = new JPanel();

		panel.setLayout(new GridLayout(5, 4));
		for (int j = 0; j < str.length; j++) {
			buttons[j] = new JButton(str[j]);
			panel.add(buttons[j]);
		}
		panel.setPreferredSize(new Dimension(0, 250));// ���ò��ִ�С
		contentPane.add(display2, BorderLayout.NORTH);
		contentPane.add(display1, BorderLayout.CENTER);
		contentPane.add(panel, BorderLayout.SOUTH);
		myEvent(); // �رմ���
		f.setVisible(true); // ���ڿɼ�
		for (int i = 0; i < buttons.length; i++) {
			buttons[i].addActionListener(this);
		}
	} // init()����


	public void actionPerformed(ActionEvent e) {
		string = e.getActionCommand();		
		ArrayList number = new ArrayList();
		for (int i = 0; i < 10; i++) {
			number.add("" + i);
		}
		ArrayList operator = new ArrayList();
		operator.add("+");
		operator.add("-");
		operator.add("*");
		operator.add("/");
		

		if (string.equals("CE")) {
			display1.setText("0");
			display2.setText("0");
			list_gobel.clear();

		}
		display1.setText(string);
		if (string.equals("=") == false || string.equals("CE") == false) { //System.out.println(string);
			ArrayList temp = new ArrayList();// ��������
			temp.addAll(list_gobel);
			list_gobel.clear();
			list_gobel.addAll(conformity_input(temp, string));// �������
			
//			for (int i = 0; i < list_gobel.size(); i++) {
//				System.out.println(list_gobel.get(i));
//			}
			display1.setText(list_gobel.get(list_gobel.size()-1).toString());
			String S="";
			for (int i = 0; i < list_gobel.size(); i++) {
				S=S+list_gobel.get(i);//��list����װ��S
			}
			display2.setText(S);
		}
		
		if (string.equals("=")) {
			try {
				display2.setText(display2.getText() + string);// �����żӵ�������ı���
				boolean key;
				ArrayList temp = new ArrayList();// ��������
				temp.addAll(list_gobel);
				list_gobel.clear();
				list_gobel.addAll(conformity_list(temp));// ���listĩβ�Ĵ�������
				String s = "";
				if (list_gobel.size() == 1) {// ��������ֻ��һ����û�в�����ʱֱ�ӽ��˲�������Ϊ���
					sum_last = Double.parseDouble(list_gobel.get(0).toString());
				} else {
					key = breaket(list_gobel);// �ж�����������Ƿ�ɶ�
					// �ж��Ƿ���Լ��㣬������������������һ�������
					if (key) {// ������ųɶԣ���������ȷ����������
						sum_last = get_stack(list_gobel);
					}
				}
				for (int i = 0; i < list_gobel.size(); i++) {
					s = s + list_gobel.get(i).toString();
				}
				display2.setText(s + "=" + (sum_last + ""));
				display1.setText(sum_last + "");
				list_gobel.clear();// ׼����һ�μ���
				// ��list�����ݼ���
				// list ���㲢�ȴ���һ������
			} catch (Exception e2) {
				e2.printStackTrace();
			}
			
		}
	}

	public ArrayList conformity_input(ArrayList list, String str)// ���Ϲ淶����,�������������ֺ��������ϣ�����������ֻ�������ֻ��������ţ��ȣ�������������
	{
		ArrayList number = new ArrayList();
		for (int i = 0; i < 10; i++) {
			number.add("" + i);
		}
		ArrayList operator = new ArrayList();
		operator.add("+");
		operator.add("-");
		operator.add("*");
		operator.add("/");

		if (list.size() == 0) {
			if (number.contains(str) || str.equals("("))// ��һ������ֻ��Ϊ���ֻ�������
			{
				list.add(str);
			} else {
				return list;
			}
		} else// ���ǵ�һ������
		{
			String s=list.get(list.size() - 1).toString();
			String decimal="([1-9]+[0-9]*|0)(\\.[\\d]+)?";//ƥ��list�����С��������
			if (number.contains(s)||s.matches(decimal))// list���һλ�����֣����������������
			{
				if (number.contains(str)) {// ��ǰ����Ϊ���֣��ϲ����ִ���װ��list
					String string = list.get(list.size() - 1).toString();// ��ȡ���һ��
					list.remove(list.size() - 1);// ɾ�����һ��Ԫ��
					list.add(string + str);// ����װ�룬��Ҫװ���ˣ�������
				}
				if (operator.contains(str) || str.equals(")") || str.equals(".")) {// ��ǰ���������,����������
					list.add(str);
				}
				if (str.equals("(")) {// ���ֺ���������ţ������������
					return list;
				}
			}

			if (operator.contains(s)) {// list���һλ�ǲ�����
				if (number.contains(str) || str.equals("(")) {// ��ǰ����Ϊ����,����������
					list.add(str);
				}
				if (operator.contains(str)) {// ��ǰ���������
					list.remove(list.size() - 1);// ɾ��list���һ��Ԫ��
					list.add(str);// ����װ�뵱ǰ������
				}
				if (str.equals(")") || str.equals(".")) {// ���ֺ���������ţ������������
					return list;
				}
			}

			if (s.equals("(")) {// list���һλ��������
				if (number.contains(str)) {// ��ǰ����Ϊ��������
					list.add(str);
				} else {
					return list;// �������ⶼ�Ǵ�������
				}
			}

			if (s.equals(")")) {// list���Ϊ������
				if (operator.contains(str)) {// �����ŵĺ���һ��ֻ�ܽӲ�����
					list.add(str);
				} else {
					return list;
				}
			}
			if (s.equals(".")) {// list���ΪС����
				if (number.contains(str)) {// С�������ֻ��������
					//String symbol = list.get(list.size()-1).toString();//ȡ��С����
					list.remove(list.size()-1);// ɾ��list����С����
					String num_old = list.get(list.size() - 1).toString();// ȡ��С����ǰ��Ĳ�����
					list.remove(list.size()-1);// ɾ���ϵĲ�����					
					String num_new = num_old + "." + str;// �µĲ���					
					list.add(num_new);// ����µĲ�����
				}
				if (operator.contains(str)||str.equals(")")) {//��ǰ����Ϊ��������ȡ��ǰ���С����
					list.remove(list.size()-1);// ɾ��list����С����
					list.add(str);
				}
				if (str.equals("(")) {
					return list;
				}					
			}
		}
		return list;
	}// �������Ͻ���

	public boolean breaket(ArrayList list) {// �鿴�����Ƿ���ȷ����
		boolean key = false;
		int right = 0, left = 0;// �����Ÿ���
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).toString().equals("(")) {
				left++;
			} 
			if (list.get(i).toString().equals(")")) {
				right++;
			}
		}
		if (right == left) {// �����Ÿ������������Ų������Ͳ�����������ȷ
			key = true;
		} else {
			key = false;
			System.out.println("�������Ų��ɶԣ��޷���ɼ���");
		}
		return key;
	}

	public ArrayList conformity_list(ArrayList list) {// ɾ��listĩβ�Ĳ���������
		ArrayList number = new ArrayList();
		for (int i = 0; i < 10; i++) {
			number.add("" + i);
		}
		ArrayList operator = new ArrayList();
		operator.add("+");
		operator.add("-");
		operator.add("*");
		operator.add("/");
		String endList = list.get(list.size() - 1).toString();
		if (number.contains(endList) || endList.equals(")")) {// �����ֻ��������Ž�β
			return list;
		}
		if (endList.equals(".") || operator.contains(endList)) {// ��С���㣬�����ţ���������β
			list.remove(list.size() - 1);// �Ƴ�
		}
		if (endList.equals("(")) {
			if (operator.contains(list.get(list.size() - 2).toString())) {// �����ڶ���Ϊ������
				list.remove(list.size() - 1);// ɾ��һ��������
				list.remove(list.size() - 1);// ��ɾ��������
			} else {
				list.remove(list.size() - 1);
			}
		}
		return list;
	}

	public double get_stack(ArrayList list) {	
		ArrayList number = new ArrayList();
		Stack<String> stack_operator = new Stack<String>();// ���ֶ���
		Stack<Double> stack_number = new Stack<Double>();// ���������
		for (int i = 0; i < 10; i++) {
			number.add("" + i);
		}
		ArrayList operator = new ArrayList();
		operator.add("+");
		operator.add("-");
		operator.add("*");
		operator.add("/");

		for (int i = list.size()-1; i>-1; i--) {
			
			if (list.get(i).toString().equals(")")) {// �����ź��ԣ���Ϊlist�ǴӺ��濪ʼ��ǰ��ջ�������������ŵĹ���������������ź��ԣ������ŵ����������������
				continue;
			}
			
			String decimal="([1-9]+[0-9]*|0)(\\.[\\d]+)?";//ƥ��list�����С��������
			if (number.contains(list.get(i).toString())||list.get(i).toString().matches(decimal))// �����������ջ,��Ҫ���Ǵ�С��������!!!!!!
			{
				stack_number.push(Double.parseDouble(list.get(i).toString()));
				continue;
			}
			
			
			if (operator.contains(list.get(i).toString())) {// �������ջ
				stack_operator.push(list.get(i).toString());
				continue;
			}
			if (list.get(i).toString().equals("("))// �����ŵ�ջ
			{
				try {
					double operand1 = Double.parseDouble(stack_number.pop().toString());// ת��Ϊ ������
					//
					double operand2 = Double.parseDouble(stack_number.pop().toString());// ת��Ϊ ������
					String operat = stack_operator.pop().toString();
					double sum = count(operand1, operand2, operat);// ��ȡ������
					stack_number.push(sum);// ��������ջ
					continue;
				} catch (Exception e) {
					e.printStackTrace();
					continue;
				}
			}			
		} // for���� ��forѭ���н������еļ������
		double result = 0.0;
		
		result = get_result(stack_number, stack_operator);
		return result;
	}// get_queue end!

	public double get_result(Stack<Double>stack_number, Stack<String>stack_operator) {// ����û�����ŵ���ʽ
		double sum = 0.0;			
		for (;stack_operator.size()>0;) {
			if (stack_operator.size()==1) {
				String operat1 = stack_operator.pop();
				double operand1 = stack_number.pop();// ת��Ϊ ������
				double operand2 = stack_number.pop();
				// ת��Ϊ ������
				sum = count(operand1, operand2, operat1);
			}
			else {
				String operat1 = stack_operator.pop();
				String operat2 = stack_operator.pop();
				double operand1 = stack_number.pop();// ת��Ϊ ������
				double operand2 = stack_number.pop();
				;// ת��Ϊ ������
				if ((operat1.equals("+") || operat1.equals("-")) && (operat2.equals("*") || operat2.equals("/")))// ǰ�����������ȼ����ں���
				{
					double operand3 = stack_number.pop();// ת��Ϊ ������
					sum = count(operand2, operand3, operat2);
					stack_number.push(sum);
					stack_number.push(operand1);
					stack_operator.push(operat1);// �����Ĳ�������ջ
				} else {// ǰ��һ���Ĳ�����
					sum = count(operand1, operand2, operat1);
					stack_number.push(sum);
					stack_operator.push(operat2);// �����Ĳ�������ջ
				}
			}
		}
		return sum;
	}

	public double count(double operand1, double operand2, String operat) {// ����
		double sum = 0.0;
		if (operat.equals("+")) {
			sum = operand1 + operand2;			
		}
		if (operat.equals("-")) {
			sum = operand1 - operand2;			
		}
		if (operat.equals("*")) {
			sum = operand1 * operand2;			
		}
		if (operand2 != 0 && operat.equals("/")) {
			sum = operand1 / operand2;			
		} 
		if (operand2 == 0 && operat.equals("/")) {
			System.out.println("��������Ϊ0");			
		}
		//System.out.println(sum);
		return sum;
	}

	public void myEvent()// �˳����
	{
		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);// ��������� �رյ�����������˳����������Ȼ���˳��˳���
			}
		});
		// �ð�ť�߱��˳�����Ĺ��ܡ�
	}

	// �����������ڲ���
	public static void main(String[] args) {
		// ArrayList list = new ArrayList();
		// boolean key;
		comput com = new comput();
		com.init();
	}
}
