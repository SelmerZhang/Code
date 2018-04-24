import javax.swing.plaf.basic.BasicComboPopup;

/**
 * Filename:CheckEmile title:�����������
 * 
 * @date ����ʱ�䣺2017��12��23�� ����7:15:43
 * @version 1.0
 * @parameter charAt(),indexOf(),substring() Description:һά����Ͷ�ά����Ĳ���
 * @author Liu Keling ���� E-mail: 1194380923@qq.com
 */
public class CheckEmile {
	char[] cNum = { '1', '2', '3', '4', '5', '6', '8', '9', '0' };
	char[] cStr = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
			'u', 'v', 'w', 'x', 'y', 'z' };
	int[] iMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	String[] sMail = { "@", "." };

	/**
	 * У������ʼ�
	 */
	public boolean isMail(String sPara) {
		for (int i = 0; i < sMail.length; i++) {
			if (sPara.indexOf(sMail[i]) == -1) {// ����sMail[i]��SPara�е�λ�ã����û���ҵ��ͷ���-1
				return false;
			}
		}
		return true;
	}

	/**
	 * �ж��Ƿ�Ϊ����
	 */
	public boolean isNumber(String sPara) {
		int iPLength = sPara.length();
		int key = 0;
		int i = 0;
		for (; i < iPLength; i++) {
			char cTemp = sPara.charAt(i);

			for (int j = 0; j < cNum.length; j++) {
				if (cTemp == cNum[j]) {
					key++;
					break;
				}
			}
		}
		if (key == i)
			return true;
		else
			return false;
	}

	/**
	 * �ж��Ƿ�ΪӢ���ַ�
	 */

	public boolean isString(String sPara) {
		int iPLength = sPara.length();
		for (int i = 0; i < iPLength; i++) {
			char cTemp = sPara.charAt(i);// SPara.charAt(i)�õ�SPara�ĵ�i��Ԫ��
			boolean bTemp = false;
			for (int j = 0; j < cStr.length; j++) {
				if (cTemp == cStr[j]) {
					bTemp = true;
					break;
				}
			}
			if (!bTemp)
				return false;
		}
		return true;
	}

	/**
	 * �ж��Ƿ�Ϊ����
	 */
	public boolean chickDay(int iPara) {
		return iPara % 100 == 0 && iPara % 4 == 0;
	}

	/**
	 * ��������Ƿ���ȷ
	 * 
	 * @param sPara
	 * @return
	 */
	public int chickDate(String sPara) {
		boolean bTemp = false;
		// ȷ����������ڵĳ���
		if (sPara.length() != 10) {
			return -2;
		}
		// ��ȡ��
		String sYear = sPara.substring(0, 4);
		// �ж����Ƿ�Ϊ����
		if (!isNumber(sYear)) {
			return -2;
		}
		// ��ȡ�·�
		String sMonth = sPara.substring(5, 7);
		// �ж��·��Ƿ�Ϊ����
		if (!isNumber(sMonth)) {
			return -2;
		}
		// ��ȡ����
		String sDate = sPara.substring(8, 10);
		// �ж������Ƿ�Ϊ����
		if (!isNumber(sDate)) {
			return -2;
		}
		int iYear = Integer.parseInt(sYear);
		int iMon = Integer.parseInt(sMonth);
		int iDate = Integer.parseInt(sDate);
		if (iMon > 12) {
			return -1;
		}
		// �����
		if (iMon == 2 && chickDay(iYear)) {
			if (iDate > 29) {
				return 2;
			} else {
				if (iDate > iMonth[iMon - 1]) {
					return -1;
				}
			}

		}
		return 0;
	}

	/**
	 * ������
	 * 
	 * @param args
	 */

	public static void main(String[] args) {
		CheckEmile check = new CheckEmile();
		boolean bMail = check.isMail("tom@163.com");
		System.out.println("1 bMail is:" + bMail);

		// ��ʾ�Ƿ�������
		boolean bIsNum = check.isNumber("12354");
		System.out.println("bIsNum:" + bIsNum);

		// ��ʾ�Ƿ���Ӣ���ַ�
		boolean bisStr = check.isString("liukeling");
		System.out.println("bIsStr:" + bisStr);

		// ��ʾ�������
		int iIsTime = check.chickDate("2017-12-24");
		System.out.println("iIstime:" + iIsTime);

	}

}
