package text4;
import java.lang.Math;
/**
* Filename:
* title:
* @date ����ʱ�䣺2018��3��19�� ����9:08:51 
* @version 1.0 
* @parameter  
* Description: 
* @author Liu Keling
* ���� E-mail: 1194380923@qq.com 
* demand:����һ����״�ࣨShape�������������ܳ�������������ࣺ�����ࣨRectangle�� ������ķ�����differ���� ���㳤���Բ����
* ��Circle���������ࣨTriangle���������ࣨSquare�� ���ε��������ɼ�����ͬ����״���󣬷���һ�� Shape ���͵�������ֱ���ÿ��
* ��״���ܳ�������������״������һ�����Σ��Ҳ��������Σ�����㳤�� 
*/
public class Count {
	public static void main(String[] args) {
				
		Rectangle rectangle =new Rectangle();
		Circle circle = new Circle();
		Triangle triangle = new Triangle();
		Square square=new Square();	
		Shape[] shape = {rectangle, circle,triangle,square};
		
		for(int i=0;i<4;i++)
		{
			System.out.println(shape[i].length());
			System.out.println(shape[i].area());
			System.out.println();
		}
		
	}
}

class Shape {	
	public int length() {
		return 1;
	}
	
	public double length(double a) {
		return 1;
	}
	
	
	public double area(double a) {	
		return 1;
	}
	
	public int area() {	
		return 1;
	}
}

class Rectangle extends Shape {
	private int len;
	private int width;
	public Rectangle()
	{
		this.len = 1;
		this.width = 1;
	}
	
	public Rectangle(int l,int w) {
		this.len=l;
		this.width =w;
	}
	
	public int length() {
		System.out.println("the length of Rectangle");
		return 2*(this.width+this.len);
	}
	
	public int area() {
		System.out.println("the area of Rectangle");
		return this.width*this.len;
	}

}

class Circle extends Shape{
	private int radius;
	public Circle() {
		this.radius=1;
	}
	public Circle(int c) {
		this.radius=c;
	}
	
	
	public int length () {
		System.out.println("the length of Circle");
		return(int) Math.PI*2*this.radius;
	}
	
	public int area() {
		System.out.println("the area of circle");
		return (int)Math.PI*this.radius*this.radius;
	}	
	
}

class Triangle extends Shape{
	private int a,b,c;
	public Triangle() {
		this.a=1;
		this.b=1;
		this.c=1;
	}
	
	public Triangle(int A,int B,int C)
	{
		this.a=A;
		this.b = B;
		this.c = C;
	}
	
	
	public int length() {
		System.out.println("the length of Triangle");
		return this.a+this.b+this.c;
	}
	
	/* (non-Javadoc)
	 * @see text4.Shape#area()
	 */
	@Override
	public int area() {
		System.out.println("the area of Triangle");
		int len = this.a+this.b+this.c;
		int area =(int)(Math.sqrt(len*(len-this.a)*(len-this.b)*(len-this.c)));				
		return area;
	}
	
//	public double area(double a) {
//		System.out.println("the area of Triangle");
//		int len = this.a+this.b+this.c;
//		double area =(Math.sqrt(len*(len-this.a)*(len-this.b)*(len-this.c)));				
//		return area;
//	}	
}

class Square extends Rectangle{
	private int side;
	public Square()
	{
		this.side=1;
	}
	
	public Square(int len) {
		this.side = len;
	}
	
	
	public int length() {
		System.out.println("the length of Squiare");
		return 4*this.side;
	}
	public int area() {
		System.out.println("the area of square");
		return this.side*this.side;
	}
}


