#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class course
{
	friend class Users;
	private:
		char* coursename;
		char* coursetime;
	public:
		course(){};
		void setcourse(char* name, char* time)
		{
			coursename = new char [strlen(name + 1)];
			strcpy(coursename, name);
			coursetime = new char [strlen(time + 1)];
			strcpy(coursetime, time);
		}
		char* getcoursename(){return coursename;}
		char* getcoursetime(){return coursetime;}
};
class Users
{
	private:
		char* username;
		int coursenum;
		course user_course[6];
	public:
		Users(){};
		void set(char* name)
		{
			username = new char [strlen(name + 1)];
			strcpy(username, name);
		}
		char* getname(){return username;}
		int getcoursenum(){return coursenum;}
		void setcourse(int i, char* name/*, char* time*/)
		{
			user_course[i].coursename = new char [strlen(name + 1)];
			strcpy(user_course[i].coursename, name);
			/*user_course[i].coursetime = new char [strlen(time + 1)];
			strcpy(user_course[i].coursetime, time);*/
		}
		void setcoursetime(int i, char* time)
		{
			user_course[i].coursetime = new char [strlen(time + 1)];
			strcpy(user_course[i].coursetime, time);
		}
		char* getcoursename(int i){return user_course[i].coursename;}
		char* getcoursetime(int i){return user_course[i].coursetime;}
		void setcoursenum(int num){coursenum = num;}
};
int main(void)
{
	course fixcourse[6];
	fixcourse[0].setcourse((char*)"CO", (char*)"MON 123");
	fixcourse[1].setcourse((char*)"NP", (char*)"MON 345");
	fixcourse[2].setcourse((char*)"DS", (char*)"WED 345");
	fixcourse[3].setcourse((char*)"PL", (char*)"WED 567");
	fixcourse[4].setcourse((char*)"LA", (char*)"FRI 567");
	fixcourse[5].setcourse((char*)"OS", (char*)"FRI 678");
	Users user[100];
	int th_user = 0;
	while(1)
	{
		int th_course = 0;
		char *tempname, *tempcourse;
		int command1, command2;
		onemoretime:
		cout << "Press 0 for new user register.Press 1 for login:" << endl;
		cin >> command1;
		if(command1 == 0){
			cout << "Enter name:" << endl;
			tempname = new char [100];
			cin >> tempname;
			user[th_user++].set(tempname);
			cout << "User " << tempname << " has been created~!" << endl;
			delete [] tempname;
		}else if(command1 == 1){
			cout << "name:";
			tempname = new char [100];
			cin >> tempname;
			for(int i = 0 ; i < th_user ; i++){
				if(strcmp(tempname, user[i].getname()) == 0){
					cout << "Welcome ! " << tempname << endl;
					delete [] tempname;
					end:
					cout << "Press 2 for choose course. Press 3 for showing course. Press 4 to logout:" << endl;
					cin >> command2;
					while(1)
					{
						if(command2 == 1){
							cout << "Allow one user at the same time!" << endl;
							goto end;
						}else if(command2 == 2){
							cout << "Enter course name:";
							tempcourse = new char [100];
							cin >> tempcourse;
							for(int j = 0 ; j < th_course ; j++){
								if(strcmp(tempcourse, user[i].getcoursename(j)) == 0){
									cout << "Can't choose what had chosen!" << endl;
									goto gogo;
								}
							}
							if(strcmp(tempcourse, "END") == 0){
								goto end;
							}else if(strcmp(tempcourse, "CO") == 0){
								for(int j = 0 ; j < th_course ; j ++){
									if(strcmp(user[i].getcoursename(j), "NP") == 0){
										cout << "Course overlap!" << endl;
										goto gogo;
									}
								}
							}else if(strcmp(tempcourse, "NP") == 0){
								for(int j = 0 ; j < th_course ; j ++){
									if(strcmp(user[i].getcoursename(j), "CO") == 0){
										cout << "Course overlap!" << endl;
										goto gogo;
									}
								}
							}else if(strcmp(tempcourse, "DS") == 0){
								for(int j = 0 ; j < th_course ; j ++){
									if(strcmp(user[i].getcoursename(j), "PL") == 0){
										cout << "Course overlap!" << endl;
										goto gogo;
									}
								}
							}else if(strcmp(tempcourse, "PL") == 0){
								for(int j = 0 ; j < th_course ; j ++){
									if(strcmp(user[i].getcoursename(j), "DS") == 0){
										cout << "Course overlap!" << endl;
										goto gogo;
									}
								}
							}else if(strcmp(tempcourse, "LA") == 0){
								for(int j = 0 ; j < th_course ; j ++){
									if(strcmp(user[i].getcoursename(j), "OS") == 0){
										cout << "Course overlap!" << endl;
										goto gogo;
									}
								}
							}else if(strcmp(tempcourse, "OS") == 0){
								for(int j = 0 ; j < th_course ; j ++){
									if(strcmp(user[i].getcoursename(j), "LA") == 0){
										cout << "Course overlap!" << endl;
										goto gogo;
									}
								}
							}
							user[i].setcourse(th_course++, tempcourse);
							user[i].setcoursenum(th_course);
							for(int j = 0 ; j < 6 ; j++){
								if(strcmp(fixcourse[j].getcoursename(), user[i].getcoursename(th_course - 1)) == 0){
									user[i].setcoursetime(th_course - 1, fixcourse[j].getcoursetime());
								}
							}
							cout << tempcourse <<" chosen!" <<endl;
							gogo:;
						}else if(command2 == 3){
							cout << user[i].getname() << "'s course:" << endl;
							for(int j = 0 ; j < user[i].getcoursenum() ; j++){
								cout << user[i].getcoursename(j) << " " << user[i].getcoursetime(j) << endl;
							}
							goto end;
						}else if(command2 == 4){
							cout << "Logout!" << endl;
							break;
						}
					}
					goto gogogo;
				}
				cout << "There's no that user!" << endl;
				gogogo:;
			}
		}else if(command1 != 0 && command1 != 1){
			goto onemoretime;
		}
	}
}
