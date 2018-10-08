#include<iostream>
using namespace std;
class Poly
{
	int term;
	float *coe;
	float *exp;
	public:
		void set(int t, float *c, float *e)
		{
			float hh = 0;
			term = t;
			coe = new float [sizeof(c) / sizeof(hh)];
			coe = c;
			exp = new float [sizeof(e) / sizeof(hh)];
			exp = e;
		}
		Poly(){}
		void setterm(int t)
		{
			term = t;
		}
		void setcoe(int t ,float n)
		{
			coe[t] = n;
		}
		void setexp(int t ,float n)
		{
			exp[t] = n;
		}
		int getterm()
		{
			return term;
		}
		float* getcoe(){return coe;}
		float* getexp(){return exp;}
		float getcoe(int i){return coe[i];}
		float getexp(int i){return exp[i];}
		friend Poly operator + (Poly num1,Poly num);
		
		Poly operator * (Poly num)
		{
			int i = 0 ,j = 0, k;
			int n = 0;
			Poly result;
			result.setterm(exp[0] + num.exp[0] + 1);
			for(i = 0 ; i < result.getterm() ; i++){
				result.setexp(i, exp[0] + num.exp[0] - i);
			}
			for(i = 0 ; i < term ; i++){
				for(j = 0 ; j < num.term ; j++){
					for(k = 0 ; k < result.getterm() ; k++){
						if(result.exp[k] == exp[i] + num.exp[j]){
							result.coe[k] = coe[i] * num.coe[j];
						}
						
					}
				}
			}
			return result;
		}
		void operator = (Poly num)
		{
			float hh = 0 ;
			term=num.term;
			coe = new float [sizeof(num.coe) / sizeof(hh)];
			coe = num.coe;
			exp = new float [sizeof(num.exp) / sizeof(hh)];
			exp = num.exp;
		}
			
		
		Poly diff()
		{
			Poly result;
			int i;
			result.setterm(term);
			for(i = 0 ; i < term ; i++){
				if(exp[i] == 0){
					break;
				}
				result.coe[i] = coe[i] * exp[i];
				result.exp[i] = exp[i] - 1;
			}
			if(exp[i] == 0){
				result.setterm(term - 1);
			}
			return result;
		}
		float getvalue(int num)
		{
			float tempcoe = 1;
			float total = 0;
			for(int i = 0 ; i < term ; i++){
				for(int j = 0 ; j < exp[i] ; j++){
					tempcoe *= num;
				}
				total += tempcoe * coe[i];
				tempcoe = 1;
			}
			return total;
		}
		float Int(int low, int high)
		{
			Poly result;
			result.setterm(term);
			for(int i = 0 ; i < term ; i++){
				result.coe[i] = coe[i] * (1 / (exp[i] + 1));
				result.exp[i] = exp[i] + 1;
			}
			return result.getvalue(high) - result.getvalue(low);
		}
		
};
Poly operator + (Poly num1,Poly num)
{
	{
//			cout<<num1.exp[0];
			int i = 0 ,j = 0;
			int n = 0;
			Poly result;
			result.term = ((int)num1.exp[0] + 1);
			if(num1.exp[0] < num.exp[0]){
				result.term = ((int)num.exp[0] + 1);
			}
			
			
			
			
			result.coe = new float [result.term];
			result.exp = new float [result.term];
			for(i = 0 ; i < result.term ; i++){
				result.exp[i] = (float)(result.term - 1 - i);
			}
			for(i = 0 ; i < result.term ; i++){
				result.coe[i] = 0;
			}
			for(; i < num1.term || j < num.term; ){
				if(i >= num1.term && j < num.term){
					for(int k = 0 ; k < result.term ; k++){
						if(result.exp[k] == num.exp[j]){
							result.coe[k] = (num.coe[j]);
						}
					}
					j++;
				}else if(i < num1.term && j >= num.term){
					for(int k = 0 ; k < result.term ; k++){
						if(result.exp[k] == num1.exp[i]){
							result.coe[k] = num1.coe[i];
						}
					}
					i++;
				}else if(num1.exp[i] > num.exp[j] && i < num1.term){
					for(int k = 0 ; k < result.term ; k++){
						if(result.exp[k] == num1.exp[i]){
							result.coe[k] = num1.coe[i];
						}
					}
					i++;
				}else if(num1.exp[i] < num.exp[j] && j < num.term){
					for(int k = 0 ; k < result.term ; k++){
						if(result.exp[k] == num.exp[j]){
							result.coe[k] = (num.coe[j]);
						}
					}
					j++;
				}else if(num1.exp[i] == num.exp[j] && j < num.term && i < num1.term){
					for(int k = 0 ; k < result.term ; k++){
						if(result.exp[k] == num1.exp[i]){
							result.coe[k] = (num1.coe[i] + num.coe[j]);
						}
					}
					i++;
					j++;
				}
			}
			return result;
		}
}
int main()
{
	int term;
	int test = 0;
	float *coe1,*coe2, *exp1,*exp2;
	Poly n1,n2,n3,n4, n5, n6;
	int x1, x2;
	cin >> term;
	coe1 = new float [100];
	for(int i = 0 ; i < term ; i++){
		cin >> coe1[i];
	}
	exp1 = new float [100];
	for(int i = 0 ; i < term ; i++){
		cin >> exp1[i];
	}
	n1.set(term, coe1, exp1);
	
	for(int i = 0 , test = 0; i < n1.getterm() ; i++){
		if(n1.getcoe(i) != 0){
			if(test){
				cout << "+";
			}
			cout << n1.getcoe(i);
			test = 1;
			if(n1.getcoe(i) != 0 && n1.getexp(i) > 0){
				cout << "x^" << n1.getexp(i);
			}
		}
	}cout << endl;
	
	
	
	
	delete [] coe1;
	delete [] exp1;
	
	
//	cout << n1.getexp(0);
	
	
	
	
	cin >> term;
	coe2 = new float [100];
	for(int i = 0 ; i < term ; i++){
		cin >> coe2[i];
	}
	exp2 = new float [100];
	for(int i = 0 ; i < term ; i++){
		cin >> exp2[i];
	}
	n2.set(term, coe2, exp2);
	
	
	
	
	for(int i = 0 , test = 0; i < n2.getterm() ; i++){
		if(n2.getcoe(i) != 0 ) {
			if(test){
				cout << "+";
			}
			cout << n2.getcoe(i);
			test = 1;
			if(n2.getexp(i) > 0){
				cout << "x^" << n2.getexp(i);
			}
		}
	}cout << endl;
//	cout << n1.getexp(0);
	
	
	
	cin >> x1;
	cin >> x2;
//	cout << n1.getexp(0);





/*for(int i = 0 , test = 0; i < n1.getterm() ; i++){
		if(n1.getcoe(i) != 0){
			if(test){
				cout << "+";
			}
			cout << n1.getcoe(i);
			test = 1;
			if(n1.getcoe(i) != 0 && n1.getexp(i) > 0){
				cout << "x^" << n1.getexp(i);
			}
		}
	}cout << endl;*/
	
	
	
	
	
//	n3 = n1 + n2;
	
	
	
//	cout << n1.getexp(0);
	
	
	
/*	for(int i = 0 , test = 0; i < n3.getterm() ; i++){
		if(n3.getcoe(i) != 0 ) {
			if(test){
				cout << "+";
			}
			cout << n3.getcoe(i);
			test = 1;
			if(n3.getexp(i) > 0){
				cout << "x^" << n3.getexp(i);
			}
		}
	}cout << endl;*/
	
	

	
//	n4 = n1 * n2;
	/*for(int i = 0 ; i < n3.getterm() ; i++){
		if(n3.getcoe(i) != 0 ) {
			cout << n3.getcoe(i);
			if(n3.getexp(i) > 0){
				cout << "x^" << n3.getexp(i);
			}
		}
	}*/
//	cout << endl;
//	cout << n3.getvalue(x1) << endl;
/*	for(int i = 0 ; i < n4.getterm() ; i++){
		if(n4.getcoe(i) != 0 ) {
			cout << n4.getcoe(i);
			if(n4.getexp(i) > 0){
				cout << "x^" << n4.getexp(i);
			}
		}
	}
	cout << endl;
	cout << n4.getvalue(x1) << endl;
	n5 = n1.diff();
	cout << n5.getvalue(x1) << endl;
	cout << n2.Int(x1, x2) << endl;*/
}
