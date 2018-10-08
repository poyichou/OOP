#include<iostream>
using namespace std;

class PolySeq
{
	public:
		PolySeq(){};
		PolySeq operator * (PolySeq p);
		PolySeq operator - (PolySeq p);
		int get_num_of_terms();
		void set_num_of_terms();
		int* get_coe();
		void set_coe();
		int* get_exp();
		void set_exp();
		int Integral(int, int);
		int getvalue(int);
		int Caculate(int);
	private:
		int* coe;
		int* exp;
		int num_of_term;	
};
void PolySeq::set_num_of_terms(){
	cin>>num_of_term;
	return;
}
int PolySeq::get_num_of_terms()
{
	return num_of_term;
}
void PolySeq::set_coe()
{
	coe=new int[100];
	for(int i=0 ; i < num_of_term ; i++){
		cin>>coe[i];
	}
}
int* PolySeq::get_coe()
{
	return coe;
}
void PolySeq::set_exp()
{
	exp=new int[100];
	for(int i=0;i < num_of_term ; i++){
		cin>>exp[i];
	}
}
int* PolySeq::get_exp()
{
	return exp;
}
PolySeq PolySeq::operator - (PolySeq p1)
{
	int i, j, k=0;
	PolySeq result;
	result.num_of_term = num_of_term;
	if(num_of_term < p1.num_of_term){
		result.num_of_term =  p1.num_of_term;
	}
	result.exp = new int[100];
	result.coe = new int[100];
	for(i=0 ; i < result.num_of_term ; i++){
		result.exp[i] = result.num_of_term - i - 1;
	}
	for(i=0, j=0 ; k < result.num_of_term;){
		if(j>= p1.num_of_term){
			result.coe[k] = coe[i];
			result.exp[k] = exp[i];
			k++;
			i++;
			continue;
		}else if(i>= num_of_term){
			result.coe[k] = -p1.coe[j];
			result.exp[k] = p1.exp[j];
			k++;
			j++;
			continue;
		}
		if(exp[i] == p1.exp[j]){
			result.coe[k] = coe[i]-p1.coe[j];
			result.exp[k] = exp[i];
			i++;
			j++;
			k++;
		}else if(exp[i] < p1.exp[j] ){
			result.coe[k] = -p1.coe[j];
			result.exp[k] = p1.exp[j];
			k++;
			j++;
		}else if(exp[i] > p1.exp[j]){
			result.coe[k] = coe[i];
			result.exp[k] = exp[i];
			k++;
			i++;
		}
	}
	result.num_of_term = k;
	return result;
}
PolySeq PolySeq::operator * (PolySeq p1)
{
	PolySeq result;
	result.exp = new int[100];
	result.coe = new int[100];
	int i=0,j=0, k=0, l=0;
	result.num_of_term = exp[0]+p1.exp[0]+1;
	for(i=0 ; i<100 ;i++){
		result.coe[i]=0;
	}
	for(i=0 ; i < result.num_of_term ; i++, j++, k++){
		result.exp[i] = result.num_of_term-i-1;
	}
	
	for(j=0; j < num_of_term ; j++){
		for(k=0 ; k < p1.num_of_term ; k++){
			for(i=0 ; i<result.num_of_term ; i++){
				if(exp[j] + p1.exp[k] == result.exp[i]){
					result.coe[i] += coe[j] * p1.coe[k];
				}
			}
		}
	}
	result.num_of_term = i;
	return result;
}
ostream& operator << (ostream& out, PolySeq p)
{
	int test=0;
	for(int i=0 ; i < p.get_num_of_terms() ; i++){
		if(*(p.get_coe()+i) != 0 && (test == 0)){
			out << *(p.get_coe()+i) <<" X^" <<*(p.get_exp()+i);
			test = 1;
		}else if(*(p.get_coe()+i) != 0 && (test == 1)){
			out << " + " << *(p.get_coe()+i) <<" X^" <<*(p.get_exp()+i);
		}
	}
	return out;
}
int PolySeq::Caculate(int n)
{
	int i,j;
	int tempexp = 1;
	int value = 0;
	for(i=0 ; i < num_of_term ; i++){
		for(j=0;j < exp[i]; j++){
			tempexp *= n;
		}
		value += coe[i] * tempexp;
		tempexp=1;
	}
	return value;
}
int main(void)
{
	int x;
	PolySeq Poly1, Poly2;
	cout<<"Enter Num of Terms of Poly1:"<<endl;
	Poly1.set_num_of_terms();
	cout<<"Enter coefficients of Poly1(from high to low):"<<endl;
	Poly1.set_coe();
	cout<<"Enter Exponentials of Poly1(from high to low):"<<endl;
	Poly1.set_exp();
	cout<<"Enter Num of Terms of Poly2:"<<endl;
	Poly2.set_num_of_terms();
	cout<<"Enter coefficients of Poly2(from high to low):"<<endl;
	Poly2.set_coe();
	cout<<"Enter Exponentials of Poly2(from high to low):"<<endl;
	Poly2.set_exp();
	cout<<"Enter The Value of x:"<<endl;
	cin>>x;
	cout<<"Poly1 - Poly2: "<<(Poly1 - Poly2)<<endl;
	cout<<"Poly2 - Poly1: "<<(Poly2 - Poly1)<<endl;
	cout<<"Poly1 * Poly2: "<<(Poly1 * Poly2)<<endl;
	cout<<"(Poly1)(x): "<<Poly1.Caculate(x)<<endl;
	cout<<"(Poly2)(x): "<<Poly2.Caculate(x)<<endl;
	cout<<"(Poly1-Poly2)(x): "<<(Poly1-Poly2).Caculate(x)<<endl;
	cout<<"(Poly2-Poly1)(x): "<<(Poly2-Poly1).Caculate(x)<<endl;
	cout<<"(Poly1*Poly2)(x): "<<(Poly1*Poly2).Caculate(x)<<endl;
}
