package text8;

import java.sql.DriverManager;
import java.sql.SQLException;

import javax.print.attribute.standard.MediaName;

import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;

/**
* Filename:
* title:
* @date ����ʱ�䣺2018��4��16�� ����7:44:01 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class conner {  
	  
	    private static final String URL="jdbc:mysql://localhost:3306/song";//���ݿ������ַ����������deomΪ���ݿ���  
	    private static final String NAME="bobby";//��¼��  
	    private static final String PASSWORD="520lkl";//����  
	      
	    public java.sql.Connection open()  
	    {  
	        //1.��������  
	        try {  
	            Class.forName("com.mysql.jdbc.Driver");  
	        } catch (ClassNotFoundException e) {  
	            System.out.println("δ�ܳɹ������������������Ƿ�����������");  
	                        //���һ��println��������������쳣������Ƿ����������������������ַ����Ƿ����  
	            e.printStackTrace();  
	        } 

	        java.sql.Connection conn = null; 
	        
	        try {  
	            conn = DriverManager.getConnection(URL, NAME, PASSWORD);  
	                System.out.println("��ȡ���ݿ����ӳɹ���");  
	        } catch (SQLException e) {  
	            System.out.println("��ȡ���ݿ�����ʧ�ܣ�");  //���һ��println���������ʧ�ܣ���������ַ������ߵ�¼���Լ������Ƿ���� 
	                         
	            e.printStackTrace();  
	        }  
	        return conn;    
	  }
	    
	    //���ݿ�򿪺��Ҫ�ر�  
	    public void close(Connection conn) {
			
	        if(conn!=null)  
	        {  
	            try {  
	                conn.close();  
	            } catch (SQLException e) {  
	                // TODO Auto-generated catch block  
	                e.printStackTrace();  
	                conn=null;  
	            }  
	        }  
	    } 
//	    public static void main(String[] args) {
//			
//		}

		
	} 