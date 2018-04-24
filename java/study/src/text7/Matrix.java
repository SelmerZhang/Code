package text7;

import java.util.Scanner;

/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��4��13�� ����4:18:31
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com
 * demand:. ����һ�������� Matrix�����еĹ��ܣ�ת�ã���ӣ��������ȴ洢���������ȴ洢���󰰵�ȹ��ܡ�
 * 
 */
public class Matrix {
	Scanner scanner = new Scanner(System.in);
	
	//��ʼ�����
	public int[][] createMatrix(int x,int y) {
		System.out.println("������"+x+"*"+y+"�еľ������ݣ�");
		int[][] array = new int[x][y];		
		for (int i = 0; i < array.length; i++)
			for (int j = 0; j < array[i].length; j++)
			{
				array[i][j] = scanner.nextInt();
			}
		return array;
	}
	
	// ������� 
	public void output(int[][] matraix)
	{
		for (int i = 0; i < matraix.length; i++)
		{
			for (int j = 0; j < matraix[i].length; j++)			
				System.out.print(matraix[i][j] + " ");							
			System.out.println();
		}
		System.out.println();
	}	
	
	// ������� 
	public int[][] addMatrix(int[][] list1, int[][] list2)
	{
		int[][] list3 = new int[list1.length][list1[0].length];
		if (list1.length!=list2.length||list1[0].length!=list2[0].length) 
			System.out.println("��������ʽ�����������");
		else
		{
			for (int i = 0; i < list1.length; i++)
				 for (int j = 0; j < list1[0].length; j++)
					 list3[i][j] = list1[i][j] + list2[i][j];
		}
		return list3;
	}
			   
	// ����ת�� 
	public int[][] transMatrix(int[][] list) { 
		int[][] list6 = new int[list.length][list[0].length];
		for (int i = 0; i < list.length; i++)
		for (int j = 0; j < list[0].length; j++)    
			list6[i][j] = list[j][i]; 
		return list6; 
	} 
		
	//����
	public void SaddlePoint(int[][] list) {
		boolean flag=true;		
		  for(int i=0;i<list.length;i++)  
		    {  
		        int max=list[i][0];/*����ÿһ�еĵ�һ��Ԫ��������*/  
		        int maxj=0;/*��¼���Ԫ�ص��к�*/  
		        for(int j=0;j<list[i].length;j++)/*Ѱ��ÿһ��������Ԫ��*/  
		            if(list[i][maxj]<list[i][j])  
		            {  
		                maxj=j;  
		                max=list[i][j];  
		            }  
		        //flag=true;/*���λ����������Ƿ��ҵ�����*/  
		        for(int k=0;k<list.length;k++)/*�����Ԫ�ص��������жϸ�Ԫ���Ƿ�Ϊ��СԪ��*/  
		        {  
		            if(list[k][maxj]<max)/*���������С�ģ�������������ѭ��*/  
		            {  
		                flag=false;  
		                break;
		            }  
		        }  
		        if(flag)/*�������������������ɹ��ҵ�����*/  
		        {  
		            System.out.println("�ڵ� "+i+" �� "+maxj+" �У��ҵ����c�� "+max); 
		            break;  
		        }  
		  
		    }  
		    if(!flag)  
		        System.out.println("�˾�ꇛ]�а��c");
	}

	//Main�������� 
	public static void main(String[] args) { 
		Matrix matrix = new Matrix();
		Scanner input = new Scanner(System.in);
		System.out.println("��������Ҫ������һ��������������������磺3 3����");
		int x = input.nextInt();
		int y = input.nextInt(); 
		int[][] list1 =matrix.createMatrix(x, y);// ��������1 
		System.out.println("��������Ҫ������2��������������������磺3 3����");
		x = input.nextInt();
		y = input.nextInt(); 
		int[][] list2 = matrix.createMatrix(x, y);// ��������2
		int[][] list3 = matrix.addMatrix(list1, list2); // �������
		System.out.println("ԭ��ꇞ飺");
		matrix.output(list1);
		matrix.output(list2);
		System.out.println("��Ӻ�ľ�ꇞ飺");
		matrix.output(list3);
		int[][] list4 = matrix.transMatrix(list1);// ����ת��
		System.out.println("�D��ǰ�ľ���ǣ�");
		matrix.output(list1);
		System.out.println("�D�ú�ľ���� ��");
		matrix.output(list4);
		matrix.SaddlePoint(list1);
	}

}
