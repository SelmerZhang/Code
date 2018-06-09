package Copy_File;

import java.io.*;

/**
* Filename:
* title:
* @date ����ʱ�䣺2018��5��16�� ����9:55:38 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class Deep_Copy {
	private void copyFolder(File src, File dest) throws IOException {  
	    if (src.isDirectory()) {  
	        if (!dest.exists()) {  
	            dest.mkdir();  
	        }  
	        String files[] = src.list();  
	        for (String file : files) {  
	            File srcFile = new File(src, file);  
	            File destFile = new File(dest, file);  
	            // �ݹ鸴��  
	            copyFolder(srcFile, destFile);  
	        }  
	    } else {  
	        InputStream in = new FileInputStream(src);  
	        OutputStream out = new FileOutputStream(dest);  
	  
	        byte[] buffer = new byte[1024];  
	  
	        int length;  
	          
	        while ((length = in.read(buffer)) > 0) {  
	            out.write(buffer, 0, length);  
	        }  
	        in.close();  
	        out.close();  
	    }  
	} 
	
	public static void main(String[] args) {
		String property_path = System.getProperty("user.dir");
		
//		File directory = new File("");//�趨Ϊ��ǰ�ļ��� 
//		try{ 
//		  System.out.println(directory.getCanonicalPath());//��ȡ��׼��·�� 
//		  System.out.println(directory.getAbsolutePath());//��ȡ����·�� 
//		}catch(Exception e){e.printStackTrace();}
//		System.out.println();
		String org_path = property_path + "\\src\\text8";		
		String copy_path = property_path + "\\src\\Copy_file\\New_Copy";
		File org_file = new File(org_path);
		File copy_file=new File(copy_path);
		if (!copy_file.exists()) {
			copy_file.mkdir();
		}
		Deep_Copy deep_Copy=new Deep_Copy();
		try {
			deep_Copy.copyFolder(org_file, copy_file);
			System.out.println("���Ƴɹ�");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("����ʧ��");
		}
	}
}
