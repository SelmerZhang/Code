
import java.util.Calendar;

/**
* Filename:catch
* title:catch_throw
* @date ����ʱ�䣺2017��12��25�� ����3:14:58 
* @version 1.0 
* @parameter  
* Description:�����쳣��ʵ���Լ����쳣�� 
* �ڽ��г��򿪷��Ĺ����У��Զ����쳣��ѭ�����ĸ����裺
����1�����ȴ����Զ����쳣�࣬�﷨��ʽ���Զ����쳣���� extends Exception��
����2���ڷ�����ͨ���ؼ���throw�׳��쳣����
����3�������ڵ�ǰ�׳��쳣�ķ����д����쳣��������try-catch��䲶�񲢴��������ǣ��ڷ�����������ͨ���ؼ���throwsָ��Ҫ�׳����������õ��쳣��
   4���ڳ����쳣�����ĵ����в��񲢴����쳣��
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/

class catchthrow extends Exception//�����쳣��
{
	public catchthrow() {
		
	}
	
	public catchthrow(String msg) {
		super(msg);
	}
	
	public catchthrow(String msg,int x) {
		super(msg);
		i=x;
	}
	
	public int val() {
		return i;
	}
	private int i;
}

/**
 * ʹ����
 */
public class catch_throw {
/**
 *<br>����˵����ʹ��MyException����Ĭ�ϵĹ�����
 *<br>���������
 *<br>�������ͣ�
 */
  public static void a() throws catchthrow 
  {
    System.out.println("Throwing catchthrow from a()");
    throw new catchthrow();
  }
  
  /**
   * ʹ�ô���Ϣ�Ĺ�����
   */
	public static void b() throws catchthrow{
		System.out.println("Throwing catchthrow from b()");
		throw new catchthrow("b()");
	}
  
  /**
   * ʹ���б���Ĺ�����
   */
  public static void c() throws catchthrow {
	System.err.println("Throwing catchthrow from c()");
	throw new catchthrow("c()  " ,47);
}  
  
  /**
   * main
   */
  public static void main(String[] args) {
	try {
		a();
	}catch (catchthrow e) {
		// TODO: handle exception
		e.getMessage();
	}
	try {
		b();
		
	}catch (catchthrow e) {
		// TODO: handle exception
		e.toString();
	}
	try {
		c();
	} catch (catchthrow e) {
		// TODO: handle exception
		e.printStackTrace();
		System.out.println("error code:"+e.val());
	}
	Calendar t=Calendar.getInstance();
	System.out.println(t);
}  
}











