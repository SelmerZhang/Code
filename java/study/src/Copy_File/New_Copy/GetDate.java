package text8;

import com.mysql.jdbc.Connection;

import text4.Count;

import java.sql.ResultSet;
import java.awt.Window.Type;
//import com.mysql.jdbc.Statement;
import java.sql.*;

import javax.naming.spi.DirStateFactory.Result;

/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��4��17�� ����8:33:03
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com
 */
public class GetDate {
	public Music[] date() {
		conner conn = new conner();
		java.sql.Connection con = conn.open();
		String sql = "select * from music_ifo";
		Statement statement;
		Music[] music = null;
		int count=0;//�õ�����������ݵ�����
		try {
			statement = con.createStatement();
			ResultSet resultSet = statement.executeQuery(sql);
			while(resultSet.next())
			{
				count++;
			}	
			resultSet.close();
		} catch (Exception e) {
			System.out.println("�õ�����������ݵ�����ʧ��");
		}
		// �����ݿ�����װ����
		try {
			statement = con.createStatement();
			ResultSet resultSet = statement.executeQuery(sql);	
			music = new Music[count];// ��ʼ����������
			int i = 0;

			while (resultSet.next()) {//�����ݽ��װ�������������
				Music sing = new Music(
						""+resultSet.getInt("num"), 
						resultSet.getString("name"),
						resultSet.getString("lauage"), 
						resultSet.getString("type"), 
						resultSet.getString("singeer"));
				music[i] = sing;
				i++;
			}
			resultSet.close();
			con.close();
			return music;
		} catch (Exception e) {
			System.out.println("��ȡ����ʧ��");
			e.printStackTrace();
			return null;
		}		
	}
//	public static void main(String[] args) {
//		GetDate da=new GetDate();
//		da.date();
//	}
}
