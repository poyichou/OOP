#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
using namespace std;
template<class T>
class vector
{
	private:
		T *vect;
		int size;
		int posi;
	public:
		vector()
		{
			size = 0;
			posi = -1;
		}
		void push(T t)
		{
			if(size > 0){
				if(posi = size - 1){
					T *temp;
					int i;
					temp = new T [vect.getsize() + 1];
					for(i = 0 ; i <= posi ; i++){
						temp[i] = vect[i];
					}
					
					vect = new T [size * 2];
					size *= 2;
					for(i = 0 ; i <= posi ; i++){
						vect[i] = temp[i];
					}
				}
				vect[++posi] = t;
			}else if(size == 0){
				vect = new T [1];
				*vect = t;
				posi = 0;
				size = 0;
			}
		}
		void pop()
		{
			if(posi < size / 2){
				T *temp;
				temp = new T [size / 2];
				for(int i = 0 ; i <= posi - 1 ; i++){
					temp[i] = vect[i];
				}
				vect = new T [size / 2];
				size /= 2;
				for(int i = 0 ; i <= posi - 1 ; i++){
					vect[i] = temp[i];
				}
				posi--;
			}else{
				T *temp;
				temp = new T [strlen(vect)];
				for(int i = 0 ; i <= posi - 1 ; i++){
					temp[i] = vect[i];
				}
				 vect =new T [size];
				for(int i = 0 ; i <= posi - 1 ; i++){
					vect[i] = temp[i];
				}
				posi--;
			}
		}
		void sort()
		{
			T temp;
			for(int i = 0 ; i <= posi - 1 ; i++){
				for(int j = 0 ; j < posi - i -1 ; j++){
					if(vect[j] > vect[j + 1]){
						temp = vect[j];
						vect[j] = vect[j + 1];
						vect[j + 1] = temp;
					}
				}
			}
		}
		void sortstr()
		{
			T temp;
			for(int i = 0 ; i <= posi - 1 ; i++){
				for(int j = 0 ; j < posi - i -1 ; j++){
					if((vect[j])[2] > (vect[j + 1])[2] || ((vect[j])[2] == (vect[j + 1])[2] && (vect[j])[3] > (vect[j + 1])[3])){
						temp = vect[j];
						vect[j] = vect[j + 1];
						vect[j + 1] = temp;
					}
				}
			}
		}
		int getposi()
		{
			return posi;
		}
		T getval(int i)
		{
			return vect[i];
		}
		int getsize()
		{
			return size;
		}
};

int main()
{
	ifstream fin("input.txt");
	ofstream fout("[Student_ID]_output.txt");
	vector<int> v1;
	int in;
	vector<double> v2;
	double dou;
	vector<string> v3;
	string str1, str2, str3;
	string in_t = "haha";
	string i_nt = "ha", name = "oh";
	getline(fin, str1);
	istringstream Instr1(str1);
	for(;in_t != "end";){
		Instr1 >> in_t;
		if(in_t != "end"){
			istringstream tt(in_t);
			tt >> in;
			v1.push(in);
		}
		
	}
	v1.sort();
	
	for(int i = 0 ; i <= v1.getposi() ; i++){
		fout << v1.getval(i) << " ";
	}fout << endl;
	v1.pop();
	v1.pop();
	v1.pop();
	v1.pop();
	v1.pop();
	v1.pop();
	v1.pop();
	fout << "after pop 7 time:" ;
	for(int i = 0 ; i <= v1.getposi() ; i++){
		fout << v1.getval(i) << " ";
	}
	fout << "("<< v1.getposi() + 1 << "/" << v1.getsize() << ")" << endl;
	in_t = "haha";
	getline(fin, str2);
	istringstream Instr2(str2);
	for(;in_t != "end";){
		Instr2 >> in_t;
		if(in_t != "end"){
			istringstream ttt(in_t);
			ttt >> dou;
			v2.push(dou);
		}
	}
	
	v2.sort();
	
	for(int i = 0 ; i <= v2.getposi() ; i++){
		fout << v2.getval(i) << " ";
	}fout << endl;
	v2.pop();
	v2.pop();
	fout << "after pop 2 time:" ;
	for(int i = 0 ; i <= v1.getposi() ; i++){
		fout << v1.getval(i) << " ";
	}
	fout << "("<< v1.getposi() + 1 << "/" << v1.getsize() << ")" << endl;
	
	
	
	
	getline(fin, str3);
	istringstream Instr3(str3);
	for(;in_t != "end";){
		Instr3 >> i_nt;
		if(in_t != "end") 
			Instr3 >> name;
		v3.push(i_nt + name);	
	}
	
	v3.sortstr();
	
	for(int i = 0 ; i <= v3.getposi() ; i++){
		fout << v3.getval(i) << " ";
	}fout << endl;
	v3.pop();
	v3.pop();
	fout << "after pop 2 time:" ;
	for(int i = 0 ; i <= v3.getposi() ; i++){
		fout << v3.getval(i) << " ";
	}
	fout << "("<< v3.getposi() + 1 << "/" << v3.getsize() << ")" << endl;
	
	
	
	
	
}
