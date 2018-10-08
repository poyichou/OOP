#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
using namespace std;
class Numbers
{
	private:
		int value[100];
		int max;
		friend Numbers operator * (Numbers n1, int n);
	public:
		void operator + (Numbers num);
		void operator - (Numbers num);
		Numbers operator * (Numbers num);
		Numbers operator / (Numbers num);
		void operator = (Numbers num);
		Numbers(){};
		void setvalue(int i, int number)
		{
			value[i] = number;
		}
		void addvalue(int i, int number)
		{
			value[i] += number;
		}
		void setmax(int number)
		{
			max = number;
		}
		int getvalue(int i)
		{
			return value[i];
		}
		int getmax()
		{
			return max;
		}
};
Numbers operator * (Numbers n1, int n)
{
	Numbers result;
	result.setmax(n1.getmax());
	for(int i = 0 ; i < n1.getmax() ; i++){
		result.value[i] = n1.value[i] * n;
	}
	return result;
}
int compare(Numbers n1,Numbers n2)
{
	int i, j;
	if(n1.getmax() > n2.getmax()){
		return 1;
	}else if(n1.getmax() < n2.getmax()){
		return -1;
	}
	for(i = n1.getmax() - 1, j = n2.getmax() - 1 ; i >= 0 && j >= 0 ; i--,j--){
		if(n1.getvalue(i) > n2.getvalue(j)){
			return 1;
		}else if(n1.getvalue(i) < n2.getvalue(j)){
			return -1;
		}
	}
	return 0;
}
void Numbers::operator + (Numbers num)
{
	int testmax;
	int i;
	testmax = max;
	if(max < num.getmax()){
		testmax = num.getmax();
	}
	for(i = 0 ; i < max && i < num.getmax() ; i++){
		value[i] += num.getvalue(i);
	}
	if(max < num.getmax()){
		for(; i < num.getmax() ; i++){
			value[i] = num.getvalue(i);
		}
	}
	for(i = 0 ; i < testmax - 1 ; i++){
		if(value[i] >=10){
			value[i] -= 10;
			value[i+1] += 1;
		}
	}
	if(value[i] >= 10){
		value[i+1] = 1;
		testmax += 1;
	}
	max = testmax;
}
void Numbers::operator - (Numbers num)
{
	int i;
	for(i = 0 ; i < num.getmax() ; i++){
		value[i] -= num.getvalue(i);
	}
	for(i = 0 ; i < this->max - 1 ; i++){
		if(value[i] < 0){
			value[i] += 10;
			value[i+1] -= 1;
		}
	}
}
void Numbers::operator = (Numbers num)
{
	for(int i = 0 ; i< num.getmax() ; i++){
		value[i] = num.getvalue(i);
	}
	max = num.getmax();
}
Numbers Numbers::operator * (Numbers num)
{
	Numbers result;
	int i, j;
	int max = this->max + num.getmax() - 1;
	for(i = 0 ; i < 100 ; i++){
		result.setvalue(i, 0);
	}
	for(i = 0 ; i < num.getmax() ; i++){
		for(j = 0 ; j < this->max ; j++){
			result.addvalue((i + j), num.getvalue(i) * this->value[j]);
		}
	}
	for(i = 0 ; i < max - 1 ; i++){
		if(result.value[i] >= 10){
			result.value[i+1] += result.value[i] / 10;
			result.value[i] %= 10;
		}
	}
	if(result.value[i] >= 10){
		result.value[i+1] = result.value[i] / 10;
		result.value[i] %= 10;
		max += 1;
	}
	result.setmax(max);
	return result;
}
int cmpfordiv(int *n1value, Numbers n2, int n, int n1max)
{
	int i, j;
	for(i = n1max - 1 - n, j = n2.getmax() - 1 ; j >= 0 ; i--, j--){
		if(n1value[i] < n2.getvalue(j)){
			return -1;
		}else if(n1value[i] > n2.getvalue(j)){
			return 1;
		}
	}
	return 0;
}
void mifordiv(int* n1value, Numbers n2, int n, int n1max)
{
	int i, j;
	for(i = n1max - 1 - n, j = n2.getmax() - 1 ; j >= 0 ; i--, j--){
		n1value[i] -= n2.getvalue(j);
		if(n1value[i] < 0){
			n1value[i] += 10;
			n1value[i + 1] -= 1;
		}
	}
	n1value[n1max - 1 - n - 1] += (n1value[n1max - 1 - n] * 10);
	

	for(i = 0 ; i < n1max - 1 - n ; i++){
		if(n1value[i] < 0){
			n1value[i] += 10;
			n1value[i+1] -= 1;
		}
	}
}
Numbers Numbers::operator / (Numbers num)
{
	Numbers result;
	int i, j, coeff, time;
	for(time = 0 ; max - time >= num.getmax() ; time++){
		for(coeff = 1 ; coeff <= 9 ; coeff++){
			if(cmpfordiv(value, (num * coeff), time, max) == -1){
				mifordiv(value, (num * (coeff - 1)), time, max);
				result.setvalue(time, coeff - 1);
				result.setmax(time + 1);
				break;
			}
		}
	}
	return result;
}
void setreal(Numbers &realn1,Numbers &n1)
{
	int i, j;
	for(i = n1.getmax() - 1, j = 0 ; i >=0 ; i--, j++){
		realn1.setvalue(j, n1.getvalue(i));
	}
	realn1.setmax(n1.getmax());
}
int main(void)
{
    FILE* fp;
    char ch;
    int thiscase;
    int test = 1, sign = 0;
    int i = 0, n = 0, j;
    Numbers n1[100], n2[100], realn1[100], realn2[100],div;
    for(i = 0 ; i < 100 ; i++){
    	for(j = 0 ; j < 100 ; j++){
    		n1[i].setvalue(j, 0);
    	}
    }
    for(i = 0 ; i < 100 ; i++){
    	for(j = 0 ; j < 100 ; j++){
    		n2[i].setvalue(j, 0);
    	}
    }
    for(i = 0 ; i < 100 ; i++){
    	for(j = 0 ; j < 100 ; j++){
    		realn1[i].setvalue(j, 0);
    	}
    }
    for(i = 0 ; i < 100 ; i++){
    	for(j = 0 ; j < 100 ; j++){
    		realn2[i].setvalue(j, 0);
    	}
    }i = 0;
    fp = fopen("test.txt","r");
    if(fp == NULL){
    	cout << "Can't open file ~ !" << endl;
    	exit(EXIT_FAILURE);
    }

    while(fscanf(fp , "%c" , &ch) != EOF)
    {
    	cout << ch;
    	if(ch >= '0' && ch <= '9' && test == 1){
    		n1[n].setvalue(i , ch - '0');
    		i++;
    	}else if(ch >= '0' && ch <= '9' && test == 2){
    		n2[n].setvalue(i , ch - '0');
    		i++;
    	}else if(ch == '+' && i != 0 && sign == 0){
			n1[n].setmax(i);
			setreal(realn1[n], n1[n]);
			i = 0;
			test = 2;
			thiscase = 1;
		}else if(ch == '+' && i != 0 && sign == 1){
			n1[n].setmax(i);
			setreal(realn1[n], n1[n]);
			i = 0;
			test = 2;
			thiscase = 2;
		}else if(ch == '-' && test == 1 && i == 0){
			sign = 1;
		}else if(ch == '-' && test == 1 && i != 0 && sign == 0){
			n1[n].setmax(i);
			setreal(realn1[n], n1[n]);
			i = 0;
			test = 2;
			thiscase = 2;
		}else if(ch == '-' && test == 2 && sign == 0){
			sign = 1;
			if(thiscase == 1){
				thiscase = 2;
			}else if(thiscase ==2){
				thiscase = 1;
			}
		}else if(ch == '-' && test == 2 && sign == 1){
			sign = 1;
			if(thiscase == 1){
				thiscase = 2;
			}else if(thiscase ==2){
				thiscase = 1;
			}
		}else if(ch == '-' && test == 2 && sign == 1 && thiscase == 3){
			thiscase = 3;
			sign = 0;
			test = 2;
		}else if(ch == '-' && test == 2 && sign == 1 && thiscase == 4){
			thiscase = 4;
			sign = 0;
			test = 2;
		}else if(ch == '-' && test == 1 && i != 0 && sign == 1){
			n1[n].setmax(i);
			setreal(realn1[n], n1[n]);
			i = 0;
			thiscase = 1;
			sign = 1;
			test = 2;
		}else if(ch == '*'){
			n1[n].setmax(i);
			setreal(realn1[n], n1[n]);
			i = 0;
			test = 2;
			thiscase = 3;
		}else if(ch == '/'){
			n1[n].setmax(i);
			setreal(realn1[n], n1[n]);
			i = 0;
			test = 2;
			thiscase = 4;
		}else if(ch == '\n'){
			n2[n].setmax(i);
			test = 1;
			setreal(realn2[n], n2[n]);
			cout << "= ";
			if(thiscase == 1){
				realn1[n] + realn2[n];
				if(sign == 1){
					cout << "-";
				}
				for(i = realn1[n].getmax() - 1 ; i >= 0 ; i--){
					cout << realn1[n].getvalue(i);
				}
				sign =0;
			}else if(thiscase == 2){
				if(compare(realn1[n],realn2[n]) == -1 && sign == 0){
					realn2[n] - realn1[n];
					cout << "-";
					for(i = realn2[n].getmax() - 1 ; i >= 0 ; i--){
						cout << realn2[n].getvalue(i);
					}
				}else if(compare(realn1[n],realn2[n]) == -1 && sign == 1){
					realn2[n] - realn1[n];
					for(i = realn2[n].getmax() - 1 ; i >= 0 ; i--){
						cout << realn2[n].getvalue(i);
					}
				}else if(compare(realn1[n],realn2[n]) >= 0 && sign == 0){
					realn1[n] - realn2[n];
					for(i = realn1[n].getmax() - 1 ; i >= 0 ; i--){
						cout << realn1[n].getvalue(i);
					}
				}else if(compare(realn1[n],realn2[n]) >= 0 && sign == 1){
					realn1[n] - realn2[n];
					cout << "-";
					for(i = realn1[n].getmax() - 1 ; i >= 0 ; i--){
						cout << realn1[n].getvalue(i);
					}
				}
				sign =0;
			}else if(thiscase == 3){
				if(sign == 1) cout << "-";
				sign = 0;
				for(i = (realn1[n] * realn2[n]).getmax() - 1 ; i >= 0 ; i--){
					cout << (realn1[n] * realn2[n]).getvalue(i);
				}
				sign =0;
			}else if(thiscase == 4){
				if(compare(realn1[n] ,realn2[n]) == -1){
					cout << "0";
				}else if(compare(realn1[n], realn2[n]) >= 0){
					if(sign == 1) cout << "-";
					sign = 0;
					div = realn1[n] / realn2[n];
					for(i = 0 ; i < div.getmax() ; i++){
						if(div.getvalue(i) != 0 || i == div.getmax() - 1)
						cout << div.getvalue(i);
					}
				}
				sign =0;
			}
			cout << endl;
			n++;
			i = 0;
		}
    }

    cout << endl;
	n2[n].setmax(i);
	test = 1;
	setreal(realn2[n], n2[n]);
	cout << "= ";
	if(thiscase == 1){
		realn1[n] + realn2[n];
		if(sign == 1){
			cout << "-";
		}
		for(i = realn1[n].getmax() - 1 ; i >= 0 ; i--){
			cout << realn1[n].getvalue(i);
		}
		sign =0;
	}else if(thiscase == 2){
		if(compare(realn1[n],realn2[n]) == -1){
			realn2[n] - realn1[n];
			cout << "-";
			for(i = realn2[n].getmax() - 1 ; i >= 0 ; i--){
				cout << realn2[n].getvalue(i);
			}
		}else if(compare(realn1[n],realn2[n]) >= 0){
			realn1[n] - realn2[n];
			for(i = realn1[n].getmax() - 1 ; i >= 0 ; i--){
				cout << realn1[n].getvalue(i);
			}
		}
		sign =0;
	}else if(thiscase == 3){
		if(sign == 1) cout << "-";
		sign = 0;
		for(i = (realn1[n] * realn2[n]).getmax() - 1 ; i >= 0 ; i--){
			cout << (realn1[n] * realn2[n]).getvalue(i);
		}
		sign =0;
	}else if(thiscase == 4){
		if(compare(realn1[n] ,realn2[n]) == -1){
			cout << "0";
		}else if(compare(realn1[n], realn2[n]) >= 0){
			if(sign == 1) cout << "-";
			sign = 0;
			div = realn1[n] / realn2[n];
			for(i = 0 ; i < div.getmax() ; i++){
				if(div.getvalue(i) != 0 || i == div.getmax() - 1)
				cout << div.getvalue(i);
			}
		}
		sign =0;
	}
	cout << endl;
	n++;
	i = 0;
	fclose(fp);
	return 0;
}
