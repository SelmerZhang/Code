package collection;
import java.util.*;
/**
* Filename:
* title:Student
* @date ����ʱ�䣺2017��12��25�� ����9:04:12 
* @version 1.0 
* @parameter  set hashSet
* Description: ѧ����
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class Student {
	public String id;
	public String name;
	public Set<Course> courses;
	
	public Student(String id,String name) {
		this.id=id;
		this.name=name;
		this.courses=new HashSet<Course>();
	}
}
