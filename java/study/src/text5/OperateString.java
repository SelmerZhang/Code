package text5;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��26�� ����5:08:12 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:��д Java ���򣬷���һ��·���е��ļ������ļ����ͣ��ļ�����Ŀ¼������һ��·��Ϊ E:\eclipse\plugins\com.jcraft.jsch_0.1.28.jar��
* ��Ӧ�������ļ���Ϊ��com.jcraft.jsch_0.1.28���ļ�����Ϊ��jar���ļ�����Ŀ¼Ϊ��E:\eclipse\plugins��
*/

import java.util.Scanner;

import javax.crypto.interfaces.PBEKey;

public class OperateString {
	public void getFile(String path) {
		int position1 = path.lastIndexOf("\\");
		String file = path.substring(position1+1);		
		int position2 = file.lastIndexOf(".");
		String file_type = file.substring(position2+1);
		String file_name = file.replaceAll(file_type,"");
		System.out.println("�ļ���Ϊ��  "+file_name);
		System.out.println("�ļ�����Ϊ�� "+ file_type);
		String file_path = path.replace(file,"");
		System.out.println("�ļ�·��Ϊ�� "+file_path);
	}
	
	public void formate_string(int substr_len,String str) {
		int len=str.length();
		int c =len%substr_len==0?len/substr_len:len/substr_len+1;
		int k=1;
		for(int i=0;i<c;i++)
		{
			if(i!=c-1)
			{
				System.out.println("�� "+k+"�����"+str.substring(i*(substr_len), (i+1)*substr_len));
			}
			else
				System.out.println("�� "+k+"�����"+str.substring(i*(substr_len)));
			k++;
		}		
	}
	
	public static void main(String[] args) {
		String path="E:\\eclipse\\plugins\\com.jcraft.jsch_0.1.28.jar";
		OperateString operateString = new OperateString();
		operateString.getFile(path);
		Scanner scanner=new Scanner(System.in);		
		System.out.println("ԭ�ַ���Ϊ�� "+path);
		System.out.println("������ÿ����Ҫ������ַ�������");
		int len = scanner.nextInt();
		operateString.formate_string(len, path);
		
	}
}
