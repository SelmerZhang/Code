package tree;



/**
* Filename:��
* title:tree
* @date ����ʱ�䣺2017��12��25�� ����10:47:46 
* @version 1.0 
* @parameter extends  
* Description: �̳�������
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
class tree {
    /**
     * ����  
     */
	public void root() {
		String sSite="������";
		String sFunction="��������";
		System.out.println("λ��"+sSite);
		System.out.println("����"+sFunction);		
	}
	
	/**
	 * ����
	 */
	public void bolo() {
		String sSite="����";
		String sFunction="��������";
		System.out.println("λ��"+sSite);
		System.out.println("����"+sFunction);
	}
	
	/**
	 * ��֦
	 */
	public void branch() {
		String sSite="������";
		String sFunction="��������";
		System.out.println("λ��"+sSite);
		System.out.println("����"+sFunction);
	}
	
	/**
	 * Ҷ��
	 */
	public void left() {
		String sSite="����";
		String sFunction="�������";
		String sColor="��ɫ";
		System.err.println("λ��"+sSite);
		System.out.println("����"+sFunction);
		System.out.println("��ɫ"+sColor);
	}
	
	/**
	 * ��ʾ��Ϣ������ӡ
	 */
	public void print(Object oPara) {
		System.out.println();
		System.out.println(oPara);
		
	}
	
	/**
	 * ������
	 */
	public static void main(String[] args) {
		tree t=new tree();
		t.print("����һ����");
		t.print("������");
		t.root();
		t.print("����");
		t.bolo();
		t.print("��֦");
		t.branch();
		t.print("��Ҷ");
		t.left();
		System.out.println();
		System.out.println();
	}
}	

	
	
	
	
	
	
	
	
	
	





























