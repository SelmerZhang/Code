package text9;
import java.io.BufferedReader;  
import java.io.FileInputStream;  
import java.io.FileNotFoundException;  
import java.io.IOException; 
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��4��18�� ����9:10:32 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:
* 4.  ��дһ�� Java Ӧ�ó��򣬸ó���ʹ�� FileInputStream�࣬ʵ�ִӴ��̶�ȡ��Ӧ�ó���Դ�����ļ��������ļ�������ʾ����Ļ�ϡ�
*/
public class FileInput {
	public static void main(String[] args) { 
		String path = System.getProperty("user.dir");//��ǰ�ļ�����·��
		String Javapath=path+"\\src\\text2\\alphabet.java";
        //�����ֽ�����  
        byte[] buf = new byte[2056];  
          
        try {  
            FileInputStream fileInputStream = new FileInputStream(Javapath);            
            int bytes = fileInputStream.read(buf, 0, 2056);               
            String str = new String(buf, 0, bytes);  
            System.out.println(str);  
        } catch (Exception e) {  
            e.printStackTrace();  
        }  
    } //main ����
}
