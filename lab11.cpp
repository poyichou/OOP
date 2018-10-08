#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
class student
{
private:
    char * name;
    int height;
public:
	student(){}
	
	student(const student& s)
	{
		name = new char [strlen(s.name) + 1];
		strcpy(name, s.name);
		
		height = s.height;
	}
	
	void seth(int h)
	{
		height = h;
	}
	void setname(char* name)
	{
		this -> name = new char[strlen(name) + 1];
		strcpy(this -> name, name);
		
	}
	char* getname()
	{
		return name;
	}
	int geth()
	{
		return height;
	}
	int operator > (student s)
	{
		if(height > s.height){
			return 0;
		}else{
			return 1;
		}
	}
};
template<class T>
void your_sort(vector<T>& v)
{
//	typename vector<T>::iterator i;
//	typename vector<T>::iterator j;
	int i , j;
	T temp;
	for(i = 0 ; i < v.size() - 1 ; i++){
		for(j = 0 ; j < (v.size() - i - 1) ; j++){
			if(v[j] > v[j + 1]){
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}
/**
your_sort with template
**/

int main()
{
    /**********part A***********/
    vector<int> part_a_int;
    vector<int>::iterator i;
    vector<double> part_a_double;
    vector<double>::iterator j;
    /// random 10 integer numbers yourself from 0 to 100
    srand(time(NULL));
    for(int i = 0 ; i < 10 ; i++){
    	int a;
    	a = rand() % 101 + 0;
    	part_a_int.push_back(a);
    }
	/**
    your code here
    **/
    your_sort(part_a_int);
    for(i = part_a_int.begin() ; i != part_a_int.end() ; i++){
    	cout << *i << " ";
    }cout << endl;

    /// random 10 double numbers yourself
    /// hint put (double) before rand()
    /**
    your code here
    **/
    for(int i = 0 ; i < 10 ; i++){
    	double a;
    	a = ((double)rand()) / 100;
    	part_a_double.push_back(a);
    }
    your_sort(part_a_double);
    for(j = part_a_double.begin() ; j != part_a_double.end() ; j++){
    	cout << *j << " ";
    }cout << endl;

    /**********part B***********/
    /// set 10 students A B C D E F G H I J
    /// set their height using random function from 150 to 180
    /// show the data
    /// delete the shortest one /// find the function in the c++ reference
    /// sort the result and show
    vector<student> data;
    vector<student>::iterator it;
    srand(time(NULL));
    for(int i = 0 ; i < 10 ; i++){
    	student s;
    	char ch;
    	char* p;
    	
    	int temp = rand() % 31 +150;
    	ch = 'A' + i;
    	p = &ch;
    	s.setname(p);
    	s.seth(temp);
    	data.push_back(s);
    	
//    	cout << s.getname()[0] << " ";
    }
    int p, n = 0;
    p = data[0].geth();
    for(int i = 0 ; i < data.size() ; i++){
    	if(p > data[i].geth()){
    		p = data[i].geth();
    		n = i;
    	}
    }
    
    
    for(it = data.begin() ; it != data.end() ; it++){
    	cout << (*it).getname()[0] << " " << (*it).geth() << endl;;
    }cout << endl;
    data.erase(data.begin() + n);
    your_sort(data);
    for(it = data.begin() ; it != data.end() ; it++){
    	cout << (*it).getname()[0] << " " << (*it).geth() << endl;;
    }cout << endl;
//    for(int i = 0 ; i < data.size() - 1 ; i++){
//    	for(int j = 0 ; j < data.size() - i - 1 ; j++)
//    }
    /**
    your code
    **/
    return 0;
}
