#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;

class Users
{
	private:
		char* username;
		int zipcode1,zipcode2;
	public:
		void set(char * name, int n1, int n2)
		{
			username = new char(strlen(name)+1);
			strcpy(username, name);
			zipcode1 = n1;
			zipcode2 = n2;
		}
		void add_code(int n1, int n2)
		{
			zipcode1 += n1;
			zipcode2 += n2;
		}
		void operator + (Users u1);
		char* get_name()
		{
			return username;
		}
		int get_code1()
		{
			return zipcode1;
		}
		int get_code2()
		{
			return zipcode2;
		}
		int sum()
		{
			int value =0;
			int tempcode1 = zipcode1, tempcode2 = zipcode2;
			for(; tempcode1 > 0 ; tempcode1 /= 10){
				value += tempcode1 % 10;
			}
			for(; tempcode2 > 0 ; tempcode2 /= 10){
				value += tempcode2 % 10;
			}
			return value;
		}
		
}user[100],sort[100];
void Users::operator + (Users u1)
{
	zipcode1 += u1.get_code1();
	zipcode2 += u1.get_code2();
}

int main(void)
{
	int i=0, j;
	int usernum=0, command, member1, member2, max = 0;
	int test = 0;
	int n1, n2;
	char *tempname,*tempname1,*tempname2;
	while(1)
	{
		cin >> command;
		if(command == 0){
			tempname = new char[100];
			cin>>tempname;
			user[usernum].set(tempname, 0, 0);			
			usernum++;
			delete [] tempname;
			cout<<"User created!!"<<endl;
		}else if(command == 1){
			tempname = new char[100];
			cin>>tempname;
			for(i = 0 ; i < usernum ; i++){
				if(strcmp(user[i].get_name(), tempname) == 0){
					scanf("%3d-%2d", &n1, &n2);
					user[i].set(tempname, n1, n2);
					member1 = i;
					cout << "User Name : " << user[i].get_name() << endl;
					cout << "Zip Code : " << user[i].get_code1() << "-" << user[i].get_code2() << endl;
					delete [] tempname;
					goto success;
				}
			}
			cout << "There's no that user!!" << endl;
			success:;
		}else if(command == 2){
			tempname1 = new char[100];
			tempname2 = new char[100];
			cin >> tempname1;
			cin >> tempname2;
			for(i = 0 ; i < usernum ; i++){
				if(strcmp(user[i].get_name(), tempname2) == 0){
					n1 = user[i].get_code1();
					n2 = user[i].get_code2();
					member2 = i;
				}
			}
			for(i = 0 ; i < usernum ; i++){
				if(strcmp(user[i].get_name(), tempname1) == 0){
					user[i] + user[member2];
					member1 = i;
					
				}
			}
			cout << "User Name : " << user[member1].get_name() << endl;
			cout << "Zip Code : " << user[member1].get_code1() << "-" << user[member1].get_code2() << endl;
			cout << "User Name : " << user[member2].get_name() << endl;
			cout << "Zip Code : " << user[member2].get_code1() << "-" << user[member2].get_code2() << endl;
		}else if(command == 3){
			for(i = 0 ; i < usernum ; i++){
				cout << "User Name : " << user[i].get_name() << endl;
				cout << "Sum : " << user[i].sum() << endl;
			}
			for(i = 0; i < 100 ; i++){
				sort[i].set("ERROR", 0, 0);
			}
			for(i = 0 ; i < usernum ; i++){
				for(j = max ; j >=0 ; j--){
					if(user[i].sum() > sort[j].sum()){
						sort[j+1].set(sort[j].get_name(), sort[j].get_code1(), sort[j].get_code2());
						sort[j].set(user[i].get_name(), user[i].get_code1(), user[i].get_code2());
						max++;
					}
				}
			}
			cout << "Comparison : ";
			for(i = 0 ; i < max ; i++){
				if(test == 0){
					cout << sort[i].get_name();
					test = 1;
				}else if(test == 1){
					cout << " > " << sort[i].get_name();
				}
			}
			cout << endl;
			max = 0;
			for(i = 0; i < 100 ; i++){
				sort[i].set("ERROR", 0, 0);
			}
		}else if(command == 4){
			return 0;
		}
	}
}
