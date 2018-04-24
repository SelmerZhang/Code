package text7;

import java.lang.reflect.Array;
import java.util.Arrays;

/**
 * Filename: title:
 * 
 * @date ����ʱ�䣺2018��3��26�� ����8:09:51
 * @version 1.0
 * @parameter Description:
 * @author Liu Keling ���� E-mail: 1194380923@qq.com 
 * demand:1. ���鿽�� CopyArray.java �������� int[] a = { 1��2�� 3�� 4��5�� 6�� 7�� 8��9��10 }�� b�� 
 * ��1�������� a �е�����Ԫ�ؿ��������� b ��,��ӡ b ��Ԫ�ء�����ѭ��ʵ�֣� ����ο��� 1��2��3��4��5��6��7��8��9�� 
 * ��2�������� a �дӵ� 3 ��Ԫ�������� 5 ��Ԫ�ؿ��������� b ��,��ӡ b �е�Ԫ�أ��� api �� �ṩ�����鿽������ʵ�֣�
 *  ����ο��� 3��4��5��6��7 2. ���� UpSort.java ����һ�����飬���� int[] a = { 5, 4, 9, 2, 7 } �������е�Ԫ�ذ��������С�(������sort ����ʵ��) ��
 * 
 */
public class Arr {
	public void copyArray(int[] a) {
		int len = a.length;
		int[] b = new int[len];
		for (int i = 0; i < len; i++) {
			b[i] = a[i];
		}
		System.out.println("b�е�Ԫ��Ϊ��");
		for (int i : b) {
			System.out.print(i + "  ");
		}

		System.out.println();
		System.out.println("a��3-8Ԫ�ؼ�����b��Ԫ��Ϊ��");
		for (int i = 0; i < 6; i++) {
			b[i] = a[i + 2];
			System.out.print(b[i] + " ");
		}
	}

	public int[] sortArr(int[] a) {
		Arrays.sort(a);
		return a;
	}

	public void print_Arr(int[] a) {
		for (Object i : a) {
			System.out.print(i + "  ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Arr arr = new Arr();
		int[] a = { 1, 44, 3, 12, 5, 10, 7, 59, 9, 140 };
		arr.copyArray(a);
		System.out.println();
		System.out.println("����ǰ������a:");
		arr.print_Arr(a);
		arr.sortArr(a);
		System.out.println("����������a:");
		arr.print_Arr(a);

	}
}
