package indentifier;
/**
* Filename:indentifier
* title:indentifier
* @date ����ʱ�䣺2017��12��25�� ����2:49:23 
* @version 1.0 
* @parameter  private public protect
* Description: ��ʶ��
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class indentifier {
	/**
	 * ������
	 */
	public void mechod1() {
		System.out.println("����һ�����е��ˣ��κ��඼���Է���");
	}
	
	/**
	 * �ܱ�������	
	 */
	private void mechod2() {
		System.out.println("����һ���ܱ������ֻ࣬��������Է�����");
	}
	
	/**
	 * ˽��
	 */
	private void mechod3() {
		System.out.println("����һ��˽�еķ�����ֻ���౾����Է���");
	}
	
	public static void main(String[] args) {
		indentifier I=new indentifier();
		I.mechod1();
		I.mechod2();
		I.mechod3();
	}	
	
}
