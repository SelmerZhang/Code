package text6;
import java.math.BigInteger;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��26�� ����7:24:28 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:���������������ĺ͡�������̣�������һ�������������Ӹ����������в����� 1 �ʹ�����������

*/
public class CountBigInt {
	public void comput(BigInteger n1,BigInteger n2) {
		 BigInteger result=null;
		 System.out.println("��������������Ϊ��");
		 System.out.println("n1:  "+n1);
		 System.out.println("n2:  "+n2);
		 result=n1.add(n2);//n1 �� n2 ���ӷ�����
		 System.out.println("��:"+result.toString());
		 result=n1.subtract(n2);//n1 �� n2 ����������
		 System.out.println("��:"+result.toString());
		 result=n1.multiply(n2);//n1 �� n2 ���˷�����
		 System.out.println("��:"+result.toString());
		 result=n1.divide(n2);//n1 �� n2 ����������
		 System.out.println("��:"+result.toString());
	}
	
	public void get_divisor(BigInteger m) {
		BigInteger COUNT=new BigInteger("0"),
				 ONE=new BigInteger("1"),
				 TWO=new BigInteger("2");
		System.out.println(m.toString()+"��������:");
		 for(BigInteger i=TWO;i.compareTo(m)<0;i=i.add(ONE))
		 { 
			 if((m.remainder(i).compareTo(BigInteger.ZERO))==0)//remainder����
			 { 
				 COUNT=COUNT.add(ONE);
				 System.out.print(" "+i.toString());
			 }
		 }
		System.out.println("");
		System.out.println(m.toString()+"һ����"+COUNT.toString()+"������");				 
	}
	
	public static void main(String args[]){
		CountBigInt bigInt = new CountBigInt();
		BigInteger n1=new BigInteger("987654321987654321987654321");
		BigInteger n2=new BigInteger("123456789123456789123456789");
		bigInt.comput(n1, n2);
		 
		BigInteger m=new BigInteger("1968957");
		bigInt.get_divisor(m);
		
	}

}
