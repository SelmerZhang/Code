package text8;

import java.awt.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��4��17�� ����8:57:15
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com
 */
public class Find_song {
	public void find(Music[] musics) {
		Print_Song print_Song =new Print_Song();
		GUI gui = new GUI();// ����
		Find_Manager find_Manager = new Find_Manager();
		Class_into_Map trans=new Class_into_Map();
		int len = musics.length;
		Map<Integer, Map<String, String>> maps=new HashMap<Integer, Map<String, String>>();
		maps = trans.transClass(musics);//�õ�maps
		Scanner scanner = new Scanner(System.in);
		
		
		int key1;
		while (true) {// ��֤��źϷ���
			gui.childrenDrawing1();
			;// ����
			System.out.println("��������Ҫ���еĲ�����ţ�");
			key1 = scanner.nextInt();// ѡ��������
			
			if (key1 < 1 || key1 > 4) {// �Ƿ�����
				System.out.println(key1 + "  ������ȷѡ��");
				System.out.println("�Ƿ���������� ���밴 1������������˳�");
				try {
					int key2 = scanner.nextInt();
					if (key2 != 1) {
						System.out.println("���˳��˲���");
						break;
					}
					
				} catch (Exception e) {
					System.out.println("���˳��˲���");
					break;
				}
			} 
			else {
				
				break;
			}
		}
		
		String keyword;
		keyword=find_Manager.choice(key1);//�ж�ϵͳ�������ֲ�ѯ����
		System.out.println("��������Ҫ���ҵ�"+keyword);
		String check=scanner.next();
		find_Manager.found_by_name(maps, check, len,keyword);//���ò�ѯ���
	
	}

}
