package tree;
/**
* Filename:
* title:
* @date ����ʱ�䣺2017��12��25�� ����11:14:07 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
/**
 * ����
 */
class osier extends tree
{
/**
 * ����������Ҷ
 */
public void left() {
	super.left();
	String sShape="����";
	super.print("��״"+sShape);
}

/**
 * ��չ���Ļ�
 */
public void flower() {
	System.err.println("����û�л�");
}

/**
 * main
 */
public static void main(String[] args) {
	osier o= new osier();
	o.print("�����ĸ���");
	o.root();
	o.print("����������");
	o.bolo();
	o.print("��������֦");
	o.branch();
	o.print("��������Ҷ");
	o.left();
	o.print("�����Ļ�");
	o.flower();
}






}
