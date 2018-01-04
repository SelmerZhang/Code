package collection;
import java.util.*;

/**
* Filename:
* title:ListTest
* @date ����ʱ�䣺2017��12��25�� ����9:08:25 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/

/**
 * ��ѡ�γ�
 * @author x1c
 *
 */
public class ListTest {
	/**
	 * ���ڴ�ű�ѡ�γ̵�list
	 */
	public List coursesToSelect;//��ѡ�γ�
	
	public ListTest() {
		// TODO Auto-generated constructor stub
		this.coursesToSelect=new ArrayList();
	}
	
	/**
		 * ������courseToSelect����ӿγ�
		 */
	public void testADD() {
		/**
		 *����һ��course���󣬲���add������ӵ���ѡ�γ̵�list��
		 */
		Course cr1=new Course("1", "���ݽṹ");
		coursesToSelect.add(cr1);
		System.out.println("����˿γ�");
		Course temp1=(Course)coursesToSelect.get(0);
		System.out.println("����˿γ�"+ temp1.id+":"+temp1.name);
		Course cr2=new Course("2", "C++");
		coursesToSelect.add(0,cr2);
		Course temp2=(Course)coursesToSelect.get(0);
		System.out.println("����˿γ�"+temp2.id+":"+temp2.name);
		
		/**
		 * �ڶ�����ӷ���
		 */
		Course[] courses =
			{new Course("3", "��ɢ��ѧ"),new Course("4", "�������")	};
		coursesToSelect.addAll(Arrays.asList(courses));
		Course temp3=(Course)coursesToSelect.get(2);
		Course temp4=(Course)coursesToSelect.get(3);
		System.out.println("��ӵ����ſγ�"+temp3.id+":"+temp3.name+" ;  "+temp4.id+":"+temp4.name);
		
		/**
		 * ��������ӷ���
		 */
		Course[] courses2=
			{new Course("5", "Math"),new Course("6", "English")};
		coursesToSelect.addAll(2,Arrays.asList(courses2));
		Course temp5=(Course)coursesToSelect.get(2);
		Course temp6=(Course)coursesToSelect.get(3);
		System.out.println("��������ſγ�"+temp5.id+":"+temp5.name+"  ;  "+temp6.id+":"+temp6.name);
		
		/**
		 * ����ظ��γ�
		 */
		Course cr3=new Course("1", "���ݽṹ");
		coursesToSelect.add(cr3);
		System.out.println("����˿γ�");
		Course temp7=(Course)coursesToSelect.get(6);
		System.out.println("����˿γ�"+ temp1.id+":"+temp1.name);
		Course cr4=new Course("2", "C++");
		coursesToSelect.add(6,cr4);
		Course temp8=(Course)coursesToSelect.get(5);
		System.out.println("����˿γ�"+temp2.id+":"+temp2.name);
		
	}
	
	/**
	 * ȡ��list�е�ֵ
	 */
	public void testget() {
		int size=coursesToSelect.size();
		for (int i = 0; i < size; i++) {
			Course cr=(Course)coursesToSelect.get(i);
			System.out.println("�γ�"+cr.id+":"+cr.name);
		}
	}
	/**
	 * ͨ������������list
	 */
	public void testIterator() {
		Iterator it=coursesToSelect.iterator();
		while (it.hasNext()) {
			Course	cr=(Course) it.next();
			System.out.println("�γ̣�"+cr.id+":"+cr.name);
		}
	}
	
	/**
	 * for each ��������
	 */
	public void testForeach() {
		for(Object obj:coursesToSelect)
		{
			Course cr=(Course)obj;
			System.err.println("�γ�"+cr.id+":"+cr.name);
		}
	}
	
	/**
	 * �޸�list��Ԫ��
	 */
	public void testModfy(int Index,Course cr) {
		coursesToSelect.set(Index, cr);
	}
	
	/**
	 * ɾ��list�е�Ԫ��
	 */
	public void testRemove(int index) {
		coursesToSelect.remove(index);
	}
	
	/**
	 * main
	 */
	public static void main(String[] args) {
		ListTest iT= new ListTest();
		iT.testADD();
		System.out.println();
		System.out.println("�����¿γ̴�ѡ");
		iT.testget();
		System.out.println();
		System.out.println("������");
		iT.testIterator();
		System.out.println();
		System.out.println("Foreach ����");
		iT.testForeach();
		System.out.println();
		System.out.println("�޸�Ԫ��");
		//Course c=new Course("7", "ë��");
		iT.testModfy(6,new Course("7", "ë��"));
		iT.testIterator();
		System.out.println();
		int key;
		Scanner s= new Scanner(System.in);
		System.out.println("��������Ҫɾ����λ��");
		key=s.nextInt()-1;
		iT.testRemove(key);
		System.out.println("ɾ����λ�� "+(key+1)+" ��ֵ���list");
		iT.testForeach();
	}
	
}















