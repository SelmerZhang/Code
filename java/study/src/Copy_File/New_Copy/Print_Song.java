package text8;

import java.util.HashMap;
import java.util.Map;

/**
* Filename:
* title:
* @date ����ʱ�䣺2018��4��17�� ����12:45:56 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class Print_Song {
	public void print_map(Map<String,String> map) {
		for(Map.Entry<String, String>entry : map.entrySet())
		{
			System.out.print(entry.getKey() + ":" + entry.getValue()+"   "); 
		}
		System.out.println();
	}
}
