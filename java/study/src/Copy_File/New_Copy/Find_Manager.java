package text8;

import java.util.HashMap;
import java.util.Map;

/**
* Filename:
* title:
* @date ����ʱ�䣺2018��4��17�� ����1:10:35 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class Find_Manager {
	Print_Song print_Song=new Print_Song();
	public void found_by_name(Map<Integer, Map<String, String>> maps,String check,int len,String keyword)
	{
		boolean b=false;
		Map<Integer, Map<String, String>> maps1= new HashMap<Integer, Map<String, String>>();//maps1װ�ز��ҵĵ�Ԫ��
		int count=1;
		for(int i=0;i<len;i++)
		{
			String date=maps.get(i).get(keyword);
			if(check.equals(date))
			{
				maps1.put(count, maps.get(i));
				count++;
				b=true;
			}
		}
		if (b==false) {
			System.out.println("û���ҵ���ظ�����Ϣ");
		}
		else
		{
			System.out.println("����"+check+"��Ϣ���ҵ���Ҫ�ĸ�����"+(count-1)+"��");
			for(int i=1;i<count;i++)
			{
				print_Song.print_map(maps1.get(i));
			}
		}
	}
	
	public String choice(int key) {
		if(key==1)
		{return "name";}
		if(key==2)
		{return "lauage";}
		if (key==3) {
			return "singer";
		}
		if(key==4)
		{
			return "type";
		}
		else
			return null;
	}
}
