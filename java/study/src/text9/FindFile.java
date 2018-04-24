package text9;
import java.io.File;
/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��4��17�� ����9:04:32
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com *
 * demand:1.�����ࣺFindFile.java��������ǰĿ¼����ӡĿ¼���ļ����ƣ�Ŀ¼��ӡ��is Directory��,�ļ���ӡ��is file����
 * �޸ĳ����ӡ��ǰĿ¼�� ��Ŀ¼��Ϣ�� ��ʾ����ǰĿ¼���á�.����ʾ 
 * 3.дһ������,�г�ĳĿ¼�����е�.java �ļ�(������Ŀ¼)
 *  
 */
public class FindFile {
	public static void main(String[] args) {
		String path = System.getProperty("user.dir");//��ǰ�ļ�����·��
		//��ǰ�ļ������ļ���Ŀ¼
		FindFile file=new FindFile();
		System.out.println("��ǰĿ¼"+path+"�������ļ���");
		file.getFileName(path);
		//��ӡָ��Ŀ¼�µ�java�ļ�
		
		String fileName=path+"\\src\\text7";
		System.out.println();
		System.out.println("ָ��Ŀ¼ "+fileName+"������java�ļ�");
		file.listJavaFile(fileName);
		
	}

	public void getFileName(String path) {
		File f = new File(path);

		File fa[] = f.listFiles();
		for (int i = 0; i < fa.length; i++) {
			File fs = fa[i];
			if (fs.isDirectory()) {
				System.out.println(fs.getName() + " is Directory");
			} else {
				System.out.println(fs.getName()+"is file");
			}
		}
	}
	
	 public void listJavaFile(String fileName) {  
	        File file = new File(fileName);  
	        if (file.isDirectory()) {  
	            File[] files = file.listFiles();  
	            for (int i = 0; i < files.length; i++) {  
	                String name = files[i].getName();  
	                if (name.trim().toLowerCase().endsWith(".java")) {  
	                    System.out.println(name + "\t");  
	                }  
	                if (files[i].isDirectory()) {  
	                    String path = files[i].getPath();  
	                    listJavaFile(path);  
	                }  
	            }  
	        }  
	    }  
}
