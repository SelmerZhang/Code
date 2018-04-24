package text9;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��4��17�� ����9:20:31
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com 
 * demand: 2.�ö������л������� Student ����д���ļ���,�ٶ�ȡ����
 */
public class Manage_student {
	public static void main(String[] args) throws Exception {
System.out.println("********************************");
		File file = new File("student.out");
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(file));
		ObjectInputStream in = new ObjectInputStream(new FileInputStream(file));
		Student student = new Student("����", 23, "111");
		// ���л��־û�����
		try {		
		out.writeObject(student);
		out.close();
		
		// �����л������õ�����
		
		Object newStudent = in.readObject(); // û��ǿ��ת����Person����
		in.close();
		System.out.println(newStudent);}
		catch (FileNotFoundException e) {  
            e.printStackTrace();  
            System.out.println("fail");
        } catch (IOException e) {  
            e.printStackTrace();
            System.out.println("ʧ��");
        }
		

	}
}
