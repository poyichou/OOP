#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;

class Complex
{
	float real;
	float im;
	public:
		void set(double n1, double n2)
		{
			real = n1;
			im = n2;
		}
		Complex(){}
		void operator = (Complex n)
		{
			real = n.real;
			im = n.im;
		}
		Complex operator + (Complex n)
		{
			Complex result;
			result.set(real + n.real, im + n.im);
			return result;
		}
		Complex operator - (Complex n)
		{
			Complex result;
			result.set(real - n.real, im - n.im);
			return result;
		}
		Complex operator * (Complex n)
		{
			Complex result;
			result.set(real * n.real - im * n.im, real * n.im + im * n.real);
			return result;
		}
		
		Complex operator / (Complex n)
		{
			Complex result, t1, t2, t3;
			t1.set(real, im);
			t2.set(n.real, -(n.im));
			t3 = t1 * t2;
			result.set(t3.real/(n.real * n.real + n.im * n.im), t3.im / (n.real * n.real + n.im * n.im));
			return result;
		}
		double getr()
		{
			return real;
		}
		double geti()
		{
			return im;
		}
};

int main(void)
{
	double real[2], im[2];
	Complex num[10];
	cin >> real[0];
	cin >> im[0];
	num[0].set(real[0], im[0]);
	
	cout << "Complex A: " ;
	if(num[0].getr() > 0.0){
		cout <<num[0].getr() ;
	}else if(num[0].getr() < 0.0){
		cout <<num[0].getr() ;
	}
	if(num[0].geti() > 0.0){
		cout << " + " <<num[0].geti() << "i" << endl;
	}else if(num[0].geti() < 0.0){
		cout <<num[0].geti() << "i" << endl;
	}
	cin >> real[1];
	cin >> im[1];
	num[1].set(real[1], im[1]);
	
	cout << "Complex B: " ;
	if(num[1].getr() > 0.0){
		cout <<num[1].getr() ;
	}else if(num[1].getr() < 0.0){
		cout  <<num[1].getr() ;
	}
	if(num[1].geti() > 0.0){
		cout << " + " <<num[1].geti() << "i" << endl;
	}else if(num[1].geti() < 0.0){
		cout <<num[1].geti() << "i"<< endl;
	}
	num[2] = num[0] + num[1];
	cout << "ComplexA + ComplexB= ";
	if(num[2].getr() > 0.0){
		cout <<num[2].getr() ;
	}else if(num[2].getr() < 0.0){
		cout <<num[2].getr() ;
	}
	if(num[2].geti() > 0.0){
		cout << " + " <<num[2].geti() << "i" << endl;
	}else if(num[2].geti() < 0.0){
		cout <<num[2].geti() << "i"<< endl;
	}
	num[3] = num[0] - num[1];
	cout << "ComplexA - ComplexB= ";
	if(num[3].getr() > 0.0){
		cout <<num[3].getr() ;
	}else if(num[3].getr() < 0.0){
		cout  <<num[3].getr() ;
	}
	if(num[3].geti() > 0.0){
		cout << " + " <<num[3].geti() << "i" << endl;
	}else if(num[3].geti() < 0.0){
		cout <<num[3].geti() << "i"<< endl;
	}
	
	num[4] = num[0] * num[1];
	cout << "ComplexA * ComplexB= ";
	if(num[4].getr() > 0.0){
		cout <<num[4].getr() ;
	}else if(num[4].getr() < 0.0){
		cout <<num[4].getr() ;
	}
	if(num[4].geti() > 0.0){
		cout << " + " <<num[4].geti() << "i" << endl;
	}else if(num[4].geti() < 0.0){
		cout <<num[4].geti() << "i"<< endl;
	}
	
	num[5] = num[0] / num[1];
	cout << "ComplexA / ComplexB= ";
	if(num[5].getr() > 0.0){
		printf("%.2f", num[5].getr());
	}else if(num[5].getr() < 0.0){
		printf("%.2f", num[5].getr());
	}
	if(num[5].geti() > 0.0){
		cout << " + " ;
		printf("%.2f", num[5].geti());
		cout<< "i" << endl;
	}else if(num[5].geti() < 0.0){
		printf("%.2f", num[5].geti());
		cout<< "i" << endl;
	}
	
	
}
