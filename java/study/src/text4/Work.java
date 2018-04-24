package text4;

import java.sql.Date;
import java.util.Scanner;

/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��24�� ����2:36:57 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*demand:
*ĳ��˾�Ĺ�Ա��Ϊ���������ࣺ
Employee����������Ա���ܵĸ��࣬���ԣ�Ա���������·ݡ�������getSalary(int month) ��
�ݲ����·���ȷ�����ʣ��������Ա�������գ���˾����⽱�� 100 Ԫ��
SalariedEmployee��Employee �����࣬�ù̶����ʵ�Ա�������ԣ���н
HourlyEmployee��Employee �����࣬��Сʱ�ù��ʵ�Ա����ÿ�¹������� 160 Сʱ�Ĳ���
���� 1.5 �����ʷ��š����ԣ�ÿСʱ�Ĺ��ʡ�ÿ�¹�����Сʱ�� SalesEmployee��Employee
���� �࣬���� ��Ա�������� �����۶� ������ʾ��� �����ԣ� �����۶�� ����
BasePlusSalesEmployee��SalesEmployee �����࣬�й̶���н��������Ա�������ɵ�н����
������ɲ��֡����ԣ���н��
дһ�����򣬰����ɸ������͵�Ա������һ�� Employee �����дһ����������ӡ��ĳ��
ÿ��Ա���Ĺ������ע�⣺�������˽�л����ԡ�
*/
public class Work {
	public static void main(String[] args) {
		Employee employee[] = new Employee[4];
		employee[0] = new SalariedEmployee(1,"A",3000);
		employee[1] = new HourlyEmployee(3, "B", 190, 15);
		employee[2] = new SalesEmployee(8, "C", 100000, (float)0.035);
		employee[3] = new BasePlusSalesEmployee(11, "D", 100000, (float)0.022, 2000);
	
		System.out.println("���������ڵ��·ݣ�");
		Scanner scanner = new Scanner(System.in);
		int month = scanner.nextInt();
		for(int i = 0;i<4;i++)
		{
			
			System.err.println("this is "+employee[i].getname()+" salary:  "+employee[i].getSalary(month));
			System.out.println();
			
		}
	}
	
}

class Employee{
	private int month;
	private String name;
	public String getname() {
		return this.name;
	}
	public Employee(int month,String name){
		this.name = name;
		this.month = month;		
	}
	
	public float getSalary(int month) {
		if (month == this.month)
			return 100;
		else
			return 0;
	}	
}

class SalariedEmployee extends Employee{
	private int salary;
	public SalariedEmployee(int month,String name, int salary){		
		super(month,name);
		this.salary = salary;	
	}
	
	public float getSalary(int month) {
		return this.salary + super.getSalary(month);	
	}
}

class HourlyEmployee extends Employee{
	private int hour;
	private int price;
	public HourlyEmployee(int month,String name,int hour,int price){		
		super(month,name);
		this.hour = hour;
		this.price = price;
	}
	
	public float getSalary(int month) {
		if(this.hour<=160)
		{
			return this.hour*this.price + super.getSalary(month);
		}
		else
		{
			return (int)1.5*(this.hour-160)*this.price + 160*this.price+super.getSalary(month);
		}
	}
}

class SalesEmployee extends Employee{
	private int sum;
	private float percent;
	public SalesEmployee(int month,String name, int sum,float percent){		
		super(month,name);
		this.sum = sum;
		this.percent = percent;
	}
	
	public float getSalary(int month) {
		return this.sum*this.percent+super.getSalary(month);		
	}
}

class BasePlusSalesEmployee extends SalesEmployee{
	private int s;
	public BasePlusSalesEmployee(int month,String name, int sum,float percent,int salary) {
		super(month, name, sum, percent);
		this.s= salary;
	}
	
	public float getSalary(int month) {
		return this.s+super.getSalary(month);
	}
	
}
