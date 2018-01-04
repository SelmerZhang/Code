package collection;
import java.util.*;
/**
* Filename:
* title:SteTest
* @date ����ʱ�䣺2017��12��26�� ����11:44:31 
* @version 1.0 
* @parameter set 
* Description: set ����ϰ
* ˵����set�е�Ԫ���ǲ����ظ��ģ��ҿ�����ӿն��� 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/


 

public class SetTest {
	public List<Course> coursesToSelect;
	public SetTest() {
		coursesToSelect =new ArrayList<Course>();
	}
	
	/**
	 * add
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
	 * list ��contains ����
	 * @param args
	 */
	public void testListcontains() {
		//ȡ�ñ�ѡ�γ̵ĵ�0 ��Ԫ��
		Course course = coursesToSelect.get(0);
		//��ӡ���coursesToSelect�Ƿ����course
		System.out.println("ȡ�ÿγ̣�"+course.name);
		System.out.println("��ѡ�γ��Ƿ�����γ�:"+course.name+","+coursesToSelect.contains(course));
	}
	
	

	
	public static void main(String[] args) {
		SetTest sT=new SetTest();
		sT.testADD();
		sT.testListcontains();
//		sT.testForeach();
//		//����һ��ѧ������
//		Student student=new Student("1", "С��");
//		System.out.println("��ӭѧ����"+student.id+":"+student.name+"ѡ��");
//		//����һ��ѧ�����󣬲��Ӽ�������
//		Scanner scanner=new Scanner(System.in);
//		for(int i=0;i<3;i++)
//		{
//			System.out.println("������γ�id");
//			String courseId=scanner.next();
//			for (Course cr:sT.coursesToSelect) {
//				if (cr.id.equals(courseId)) {
//					student.courses.add(cr);
//				}
//			}
//			for(Course course : student.courses)
//			{
//				System.out.println("ѡ���˿γ̣�"+course.id+":"+course.name);
//			}
//		}
		
	}	
	
}




















