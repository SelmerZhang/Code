package text8;

import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.*;
import java.util.Scanner;

/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��4��17�� ����5:20:59
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com
 */
public class Add_song {
	public void add_music(int[] arr) {
		Scanner scanner = new Scanner(System.in);
		conner conn = new conner();
		java.sql.Connection con = conn.open();

		System.out.println("������������������Ϣ");
		int num;
		while (true) {//�жϸ�����ŵ�Ψһ��
			System.out.println("��ţ�");
			num = scanner.nextInt();
			boolean t=false;
			for (int i = 0; i < arr.length; i++) {
				if (num == arr[i]) {
					t=true;
					break;
				}
			}
			if (t==true) {
				System.out.println("���������������ţ��Ҳ�Ҫ�����������ͬ");
				for (int i = 0; i < arr.length; i++) {
					System.out.print("  "+arr[i]);
				}
				System.out.println();
				continue;
			}
			else {
				break;
			}
		}
		System.out.println("������");
		String name = scanner.next();
		System.out.println("���ԣ�");
		String language = scanner.next();
		System.out.println("���ͣ�");
		String type = scanner.next();
		System.out.println("���֣�");
		String singer = scanner.next();

		// �����ݿ�����װ����
		String sql="insert into music_ifo(num,name,lauage,type,singeer) values(?,?,?,?,?)";
		try {
			PreparedStatement pstmt = con.prepareStatement(sql);
			pstmt.setInt(1, num);
			pstmt.setString(2, name);
			pstmt.setString(3, language);
			pstmt.setString(4, type);
			pstmt.setString(5, singer);
			pstmt.executeUpdate();
			System.out.println("д�����ݳɹ�");
			con.close();
		} catch (Exception e) {
			System.out.println("д������ʧ��");
			e.printStackTrace();
			//return null;
		}
	}
}
