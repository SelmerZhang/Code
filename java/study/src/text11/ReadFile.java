package text11;
import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��4��28�� ����4:37:42 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:��ȡ���������ļ�������һ�� URL ����Ȼ���� URL ���󷵻���������ͨ������������ȡ URL ����������Դ�ļ���
*/
public class ReadFile {

}

public class ReadURLSource
{ public static void main(String args[])
 {
 new NetWin();
 }
}
class NetWin extends Frame implements ActionListener,Runnable
{ Button button;
 URL url;
 TextField text;
 TextArea area;
 byte b[]=new byte[118];
 Thread thread;
 NetWin()
 { text=new TextField(20);
 area=new TextArea(12,12);
 button=new Button("ȷ��");
 button.addActionListener(this);
 thread=new Thread(this);
 Panel p=new Panel();
 p.add(new Label("������ַ:"));
 p.add(text);
 p.add(button);
 add(area,BorderLayout.CENTER);
 add(p,BorderLayout.NORTH);
 setBounds(60,60,360,300);
 setVisible(true);
 validate();
 addWindowListener(new WindowAdapter()
 { public void windowClosing(WindowEvent e)
 { System.exit(0);
}
 });
 }
 public void actionPerformed(ActionEvent e)
 {
 if(!(thread.isAlive()))
 thread=new Thread(this);
 try{
 thread.start();
 }
 catch(Exception ee)
 { text.setText("�����ڶ�ȡ"+url);
 }
 }
 public void run()
 { try { int n=-1;
 area.setText(null);
 String name=text.getText().trim();
 ������ 1�� //ʹ���ַ��� name ���� url ����
 String hostName=������ 2�� //url ���� getHost()
 int urlPortNumber=������ 3�� //url ���� getPort()
 String fileName=������ 4�� //url ���� getFile()
 InputStream in=������ 5�� //url ���÷�������һ��������
 area.append("\n ����:"+hostName+"�˿�:"+urlPortNumber+
"�������ļ�����:"+fileName);
 area.append("\n �ļ�����������:");
 while((n=in.read(b))!=-1)
 { String s=new String(b,0,n);
 area.append(s);
 }
 }
 catch(MalformedURLException e1)
 { text.setText(""+e1);
 return;
 }
 catch(IOException e1)
 { text.setText(""+e1);
 return;
 }
 }