package text8;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Scanner;

import javax.swing.tree.DefaultTreeCellEditor.EditorContainer;

/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��4��17�� ����7:36:40
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com
 */
public class Delete_song {
	public void delete_music(int[] arr) {
		Scanner scanner = new Scanner(System.in);
		conner conn = new conner();
		java.sql.Connection con = conn.open();
		System.out.println("������ɾ���������");
		int num;
		while (true) {
			System.out.println("��ţ�");
			num = scanner.nextInt();
			boolean t = false;
			for (int i = 0; i < arr.length; i++) {
				if (num == arr[i]) {
					t = true;
					break;
				}
			}
			if (t == false) {
				System.out.println("���������Ų����ڣ�������±����ѡ�������Ŵ�������");
				for (int i = 0; i < arr.length; i++) {
					System.out.print("  " + arr[i]);
				}
				System.out.println();
				continue;
			} else {
				break;
			}
		}

		String sql1 = "select * from music_ifo where num=?";
		try {// ��ѡ�и�����Ϣ��ʾ������Ȼ��ѯ���Ƿ�ɾ��
			PreparedStatement pstmt = con.prepareStatement(sql1);
			pstmt.setInt(1, num);
			ResultSet resultSet = pstmt.executeQuery();
			System.out.println("Ҫɾ���ĸ����ǣ�");
			while (resultSet.next()) {
				System.out.println("number:" + resultSet.getInt("num") 
						+ "  name:" + resultSet.getString("name")
						+ "  language:" + resultSet.getString("lauage") 
						+ "  type:" + resultSet.getString("type")
						+ "  singer:" + resultSet.getString("singeer"));
			}
		} catch (Exception e) {
			System.out.println("��ȡҪɾ������ʧ�ܣ�");
			e.printStackTrace();
		}

		System.out.println("�Ƿ�Ҫɾ���� ���밴1 ����������˳�");
		String confirm = scanner.next();
		if (confirm.equals("1")) {// ִ��ɾ��
			String sql2 = "delete from music_ifo where num=?";
			try {
				PreparedStatement pstmt = con.prepareStatement(sql2);
				pstmt.setInt(1, num);
				pstmt.executeUpdate();
				System.out.println("�ɹ�ɾ��");
			} catch (Exception e) {
				e.printStackTrace();
				System.out.println("ɾ�����ɹ�");
			}
		}

	}
}
