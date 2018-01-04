package collection;
import java.util.*;
import java.util.Map.Entry;



/**
* Filename:
* title:MapTest
* @date ����ʱ�䣺2017��12��26�� ����1:24:56 
* @version 1.0 
* @parameter  
* Description: hashmap
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/



public class MapTest {
	/**
	 * ������װѧ�����Ͷ���
	 */
	public Map<String, Student>students;
	
	/**
	 * �ڹ������г�ʼ��student����
	 */
	public MapTest()
	{
		this.students=new HashMap<String,Student>();
	}
	
	/**
	 * ��map�������Ϣ
	 * ����ѧ��id���ж��Ƿ�ռ�ã���Ϊ��ռ�ã�������ѧ�������������µĶ��󣬲�����ӵ�map��
	 */
	public void testPut() {
		//����һ��scanner����
		Scanner console=new Scanner(System.in);
		int i=0;
		while (i<3) {
			System.out.println("������ѧ��ID");
			String ID =console.next();
			//�ж�ID�Ƿ�ռ��
			Student st = students.get(ID);
			if (st==null) {
				//��ʾ����ѧ������
				System.out.println("������ѧ������");
				String name=console.next();
				//�������ڶ���
				Student newstudent=new Student(ID, name);
				//ͨ������put������map���������������
				students.put(ID, newstudent);
				System.out.println("�ɹ����ѧ��"+students.get(ID).name);
				i++;
			}
			else {
				System.out.println("��ѧ��ID�ѱ�ռ��");
				continue;
			}
			
		}
	}
	
	/**
	 * ����map�Ŀ���set����
	 */
	public void testKeySet() {
		//ͬkeyset������map�����м��ļ���
		Set<String> keySet=students.keySet();
		//����keyset������ȡ��map �е�ÿһ��������ͨ��get����ȡ��ÿһ��������Ӧ�ĵ�ֵ
		for(String string:keySet)
		{
			Student st =students.get(string);
			if (st!=null) {
				System.out.println("ѧ����"+st.name);
			}
		}
	}
	
	/**
	 * ɾ��ӳ��
	 */
	public void testRemove() {
		Scanner scanner=new Scanner(System.in);
		while(true)
		{
			System.out.println("������Ҫɾ����ѧ����ID");
			//�Ӽ��̻�ȡid
			
			String ID=scanner.next();
			//�ж��Ƿ��д�ѧ������
			Student student=students.get(ID);
			if (student==null) {
				System.out.println("��ѧ��������");
				continue;
			}
			students.remove(ID);
			System.out.println("�ɹ�ɾ����ѧ��");
			break;
		}				
	}
	
	/**
	 * ͨ��entrySet��������Map
	 */
	public void testEntrySet() {
		//ͨ��entrySet����map��ֵ��
		Set<Entry<String,Student>> entrySet=students.entrySet();
		for(Entry<String,Student> entry:entrySet)
		{
			System.out.println("ȡ�ü�"+entry.getKey());
			System.out.println("��Ӧ��ֵΪ"+entry.getValue().name);
		}
	}
	
	/**
	 * �޸�����
	 */
	public void testModify() {
		//��ʾ����Ҫ�޸ĵ�id
		System.out.println("������Ҫ�޸ĵ�ѧ����id");
		Scanner scanner=new Scanner(System.in);
		while (true){
			//�Ӽ��̻�ȡid
			String id=scanner.next();
			//����id
			Student student=students.get(id);
			if(student==null)
			{
				System.out.println("���û�������,����������");
				continue;
			}
			//��ʾ��ǰҪ�޸ĵ�ѧ��������ʲô
			System.out.println("��ǰҪ�޸ĵ�ѧ����id��"+student.name);
			//��ʾ�����µ�ѧ������
			System.out.println("�������µ�ѧ������");
			String name=scanner.next();
			Student newstudent=new Student(id, name);
			students.put(id, newstudent);
			System.out.println("�޸ĳɹ�");
			break;
		}
	}
	
	
	
	
	
	/**
	 * main
	 */
	public static void main(String[] args) {
		MapTest mapTest=new MapTest();
		System.out.println("��ʼ����");
		mapTest.testPut();
		mapTest.testKeySet();
		mapTest.testRemove();
		mapTest.testEntrySet();
		mapTest.testModify();
		mapTest.testPut();
		
	}
	
}

















