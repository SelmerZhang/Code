
/**
* Filename:abstract
* title:player
* @date ����ʱ�䣺2017��12��25�� ����12:08:35 
* @version 1.0 
* @parameter  
* Description: �ӿ���,������
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
*/

   
	//�ӿ�,�ӿ���

	interface play
	{
		int flag=1;
		void playeer();
		void pause();
		void stop();
	}
	
	/**
	 * ������:����������ʵ�����࣬���������ɶ�����࣬��һ�����Ʒ����
	 */
	abstract class playing
	{
		public void diaplay(Object oPara)
		{
			System.out.println(oPara);
		}
		abstract void winRun();
	}
	
	
	
	public class player extends playing implements play//������player�̳���playing����ʵ����play����
	{
	    public void playeer() {
	    	diaplay("newPlay.paly()");
	    }
		public void pause() {
			diaplay("newPlay.pause()");
		}
		public void stop() {
			diaplay("newPlay.stop()");
		}
	    void winRun()
	    {
	    	diaplay("newPlay.winRun()");
	    }
	
	public static void main(String[] args) {
		player p=new player();
		p.playeer();
		p.pause();
		p.stop();
		p.winRun();
	}
	

	
}
