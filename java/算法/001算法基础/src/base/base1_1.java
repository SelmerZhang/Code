package base;
/**
* Filename:001base
* title:base1_1
* @date ����ʱ�䣺2017��12��27�� ����8:51:25 
* @version 1.0 
* @parameter  
* Description: ���������ǵ����Լ��
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class base1_1 {
	
	public static int  gcd(int p,int q) {
		if (q==0) {
			return p;		
		}
		int i=p%q;
		return gcd(q,i);
	}
	public static void main(String[] args) {
		base1_1 b=new base1_1();
		int k=b.gcd(42, 36);
		System.out.println("������Լ��"+k);
	}
}
