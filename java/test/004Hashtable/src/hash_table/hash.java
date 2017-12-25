package hash_table;
import java.util.*;
/**
* Filename:004hash_table
* title:hash
* @date ����ʱ�䣺2017��12��24�� ����7:16:51 
* @version 1.0 
* @parameter  
* Description: ��ϣ��ļ�Ӧ��
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/
public class hash {
    private static Hashtable rightList=new Hashtable();
    
    /**
     * ��ʼ������
     * �����������������
     */
    public void init() {
		String[] accRoleList=
			{"admin","satrap","manager","user","guest"};
		String[] rightCodeList=
			{"10001","10011","10021","20011","24011"};
		for (int i = 0; i < accRoleList.length; i++) {
			rightList.put(accRoleList[i],rightCodeList[i]);//ǰ����value��������key
		}
	}
    
    /**
     * ��ȡ��ɫȨ�޴���
     * �����ɫ����
     * ����stringȨ�޴���
     */
    public String getRight(String accRole) {
		if (rightList.containsKey(accRole)) {
			return (String)rightList.get(accRole);//���ص���mapӦ��valueֵ
		}
		else {
			return null;
		}
	}
    
    /**
     * ��ӽ�ɫ�ʹ�����Ϣ
     * ����accRole�Ľ�ɫ���ƣ�rightCode�Ľ�ɫȨ��
     * �޷�������
     */
    public void insert(String accRole,String RightCode) {
		rightList.put(accRole, RightCode);
	}
    
    /**
     *ɾ����ɫȨ�ޣ�
     *����accRole��ɫ����
     *�޷�������
     */
    public void delete(String accRole) {
		if (rightList.containsKey(accRole)) {
			rightList.remove(accRole);
		}
	}
    
    /**
     * �޸Ľ�ɫȨ�޴���
     * �����ɫaccRole���Լ���ɫȨ�޴���rightCode
     * �޷�������
     */
    public void update(String accRole,String rightCode) {
		this.insert(accRole, rightCode);
	}
    
    /**
     * ��ӡ��ɫ����ӦȨ�޴���
     */
    
    public void print() {//�������
		Enumeration RlKey =rightList.keys();//����ÿö��
		while(RlKey.hasMoreElements())//�жϱ����Ƿ���ֵ
		{
			String accRole=RlKey.nextElement().toString();
			System.out.println(accRole+"="+this.getRight(accRole));
		}
	}
    
    /**
     * ��ӡ��Ϣ����
     */
    
    public void print(Object oPara) {
		System.out.println(oPara);
	}
    
    
    /**
     * ����
     */
    
    public void find(String index) {
		String key=(String)rightList.get(index);
		if (key!=null) {
			System.out.println(index+"="+key);
		}
	}
    /**
     * main
     */
    public static void main(String[] args) {
		hash RR=new hash();
		RR.init();
		System.out.println("---init---");
		RR.print();
		RR.print("--------------------------------");
		RR.insert("presider", "10110");
		System.out.println("---insert---");
		RR.print();
		RR.print("--------------------------------");
		RR.update("presider", "10100");
		System.out.println("---update---");
		RR.print();
		RR.print("--------------------------------");
		RR.delete("presider");
		System.out.println("---delete---");
		RR.print();
		RR.print("--------------------------------");
		System.out.println("---find---");
		RR.find("manager");
	}
    
}
