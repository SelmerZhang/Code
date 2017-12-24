import java.util.*;


/**
* Filename:003
* title:operateVector
* @date ����ʱ�䣺2017��12��24�� ����8:55:03 
* @version 1.0 
* @parameter  
* Description: vector
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/

public class operateVector 
{
	/**
	 * ���� һ��4*4�Ķ�ά����vector
	 * �������
	 * �������
	 */
	public Vector buildVector() {
		Vector vTemps=new Vector();
		//System.out.println("������һ��4*4 �Ķ�ά����");
		for (int i = 0; i < 4; i++) {
			Vector vTemp =new Vector();
			for (int j = 0; j < 4; j++) {
				vTemp.addElement("Vector("+i+")("+j+")");
			}
			vTemps.addElement(vTemp);
		}
		return vTemps;
	}
	
	/**
	 * ��������
	 * vTemp:������Ķ���iTemp���������ݵ�λ�ã�OTemp���������ݵ�ֵ
	 * ���vector���
	 * ˵�����������λ�ó���ʵ��ʵ��λ�ý�����NULL
	 */
	public Vector insert(Vector vTemp,int iTemp,Object oTemp) {
		if (iTemp>vTemp.size()) {
			System.out.println("����Խ�磡");
			return null;
		}
		else
		{
			vTemp.insertElementAt(oTemp, iTemp);//insertElementAt(Object obj, int index)objҪ�����Ԫ�أ�indexҪ�����λ��
		}
		return vTemp;
	}
	
	/**
	 * �Ƴ�����
	 * Vector vTemp��ɾ���Ķ���int iTemp ɾ�������ݵ�λ��
	 * �������vector
	 * ���ɾ�����罫����null;
	 */
	public Vector delete(Vector vTemp,int iTemp) {
		if (iTemp>vTemp.size()) {
			return null;
		}
		else {
			vTemp.removeElementAt(iTemp);
		}
		return vTemp;
	}
	
	/**
	 * �޸�����
	 * Vector vtemp :���޸õ����ݶ���int iTemp�޸ĵ�����λ�ã�object OTemp�޸ĵ����ݵ�ֵ��
	 * ����޸ĳ��罫����null
	 */
	public Vector update(Vector VTemp,int iTemp,Object oTemp) {
		if (iTemp>VTemp.size()) {//�������
			return null;
		}
		else
		{
			VTemp.setElementAt(oTemp, iTemp);
		}
		return VTemp;
	}
	
	/**
	 * �����Ϣ
	 * String STemp�����Ϣ����
	 * object OTemp �����Ϣ��ֵ
	 * �޷��ر���
	 */
	public void print(String sTemp,Vector oTemp)
	{
		System.out.println(sTemp+"���ݣ�");
	    for(int i=0;i<oTemp.size();i++)	
	    {
	    	System.out.println(oTemp.elementAt(i));
	    }
	    System.out.println();
	    System.out.println();
	}
	
	/**
	 * ������
	 */
    public static void main(String[] args) {
		operateVector ov=new operateVector();
		Vector vTemp=ov.buildVector();
		ov.print("�����4*4�Ķ�ά����vTemp0", vTemp);
		Vector vResult=ov.insert(vTemp, 2, "add the list");
		ov.print("�����4*4�Ķ�ά����vTemp1", vResult);
		Vector vreset=ov.update(vResult, 3, "update list");
		ov.print("�����4*4�Ķ�ά����vTemp1", vreset);
		Vector vDalete=ov.delete(vreset, 1);
		ov.print("ɾ���˵�һ������",vDalete);
		
	}
	
	
	
	
	
	
	
	
	
}












