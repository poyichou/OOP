#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Students_Data
{
private:
    int height;
    char* name;
public:
    /*** your code ***/
    Students_Data()
	{
		cout<<"constructor1 called!!"<<endl; 
	}
    Students_Data(int b,char* str)
	{
		height=b;
		name=str;
		cout<<"constructor2 called!!"<<endl; 
	}
	Students_Data(const Students_Data &c)
	{
		height=c.height;
		strcpy(name,c.name);
		cout<<"a copy constructor called!!"<<endl; 
	}
	int get_height()
	{
		return height;
	}
	void get_name()
	{
		cout<<name;
	}
	char* gets_name()
	{
		return name;
	}
	void set_height(int d)
	{
		height=d;
	}
	void set_name(char* str1)
	{
		name=str1;
	}
	~Students_Data()
	{
		delete[] name;
		cout<<"destructor called"<<endl;
	}
	
	
};

int main()
{
	int i,j,u;
    /*** part I ***/
    cout<<"part I"<<endl;
    Students_Data S1;
    Students_Data S2(160, "Tony");
    S2.get_name();
    Students_Data S3 = S2;

    /*** part II ***/
    cout<<"part II"<<endl;
    /// print the name and height of S3 before setting
    S3.get_name();
    cout<<" "<<S3.get_height()<<endl;
    /// change the name and height of S3 into Jeff and 180
    S3.set_name("Jeff");
    S3.set_height(180);
    /// print the name and height of S3 after setting
    S3.get_name();
    cout << "!!!" << endl;
    cout<<" "<<S3.get_height()<<endl;

    /*** part III ***/
    cout<<"part III"<<endl;
    Students_Data Data[5];
    cout << "before sorting : "  << endl;
    /***
    set Data with name A B C D E
    set their height with rand() function between 150~180
    print the name and height of students from Data[0] to Data [4];
    ***/
    /*** your code ***/
    Data[0].set_name("A");
    Data[0].set_height((rand() % 30) +150);
    Data[0].get_name();
    cout<<" "<<Data[0].get_height()<<endl;
    Data[1].set_name("B");
    Data[1].set_height((rand() % 30) +150);
    Data[1].get_name();
    cout<<" "<<Data[1].get_height()<<endl;
    Data[2].set_name("C");
    Data[2].set_height((rand() % 30) +150);
    Data[2].get_name();
    cout<<" "<<Data[2].get_height()<<endl;
    Data[3].set_name("D");
    Data[3].set_height((rand() % 30) +150);
    Data[3].get_name();
    cout<<" "<<Data[3].get_height()<<endl;
    Data[4].set_name("E");
    Data[4].set_height((rand() % 30) +150);
    Data[4].get_name();
    cout<<" "<<Data[4].get_height()<<endl;

    /*** sort 5 students with height ***/
    /*** your code ***/
    Students_Data NewData;
    
    /*for(i=0;i<5;i++){
    	for(j=0;j<5;j++){
    		
    		if(NewData[i].get_height()>Data[j].get_height()){
    			NewData[i].set_height(Data[j].get_height());
    			NewData[i].set_name(Data[j].gets_name());
    		}
    		for(u=0;u<5;u++){
    			if(NewData[i].get_height()==Data[u].get_height()){
    				Data[u].set_height(1000);
    			}
    		}
    	}
    }*/
    for(i=0;i<5;i++){
    	for(j=0;j<5;j++){
    		if(Data[i].get_height()<Data[j].get_height()){
    			NewData=Data[i];
    			Data[i]=Data[j];
    			Data[j]=NewData;
    		}
    	}
    }

    cout << "after sorting : " << endl;
    /*** print student's name and height after sorting ***/
    /*** your code ***/
    Data[0].get_name();
    cout<<" "<<Data[0].get_height()<<endl;
    Data[1].get_name();
    cout<<" "<<Data[1].get_height()<<endl;
    Data[2].get_name();
    cout<<" "<<Data[2].get_height()<<endl;
    Data[3].get_name();
    cout<<" "<<Data[3].get_height()<<endl;
    Data[4].get_name();
    cout<<" "<<Data[4].get_height()<<endl;

    return 0;
}
