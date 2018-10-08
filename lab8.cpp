#include<iostream>
#include<cstring>
using namespace std;

class Device
{
	protected:
		int mounted_ID;
		char *mounted_Name;
	public:
		virtual void show()
		{
			cout << mounted_Name;
		}
		virtual void setname(char *name)
		{
			mounted_Name = new char [strlen(name) + 1];
			strcpy(mounted_Name, name);
		}
		
};
class CD : public Device
{
	public:
		CD()
		{
			mounted_ID = 0;
			
		}
		virtual void show()
		{
			cout << "<CD>" << mounted_Name << endl;
		}
		void operator = (CD ccd)
		{
			mounted_ID = ccd.mounted_ID;
			mounted_Name = new char [strlen(ccd.mounted_Name) + 1];
			strcpy(mounted_Name, ccd.mounted_Name);
		}
};
class HD : public Device
{
	public:
		HD()
		{
			mounted_ID = 0;
		}
		virtual void show()
		{
			cout << "<HD>" << mounted_Name << endl;
		}
		void operator = (HD hhd)
		{
			mounted_ID = hhd.mounted_ID;
			mounted_Name = new char [strlen(hhd.mounted_Name) + 1];
			strcpy(mounted_Name, hhd.mounted_Name);
		}
		
};
class Host
{
	private:
		int de_num;
		int cd_num, hd_num;
		int type[200];
		CD cd[100];
		HD hd[100];
		int cd_show_order;
		int hd_show_order;
	public:
		Host()
		{
			cd_num = 0;
			de_num = 0;
			hd_num = 0;
			cd_show_order = 0;
			hd_show_order = 0;
		}
		
		int getnum()
		{
			return de_num;
		}
		void setnum(int num)
		{
			de_num = num;
		}
		void setname(int type, int num, char* name)
		{
			if(type == 0){
//				cout << "typecd";
				cd[num].setname(name);
			}else if(type == 1){
//				cout << "typehd";
				hd[num].setname(name);
			}
		}
		void set(CD ccd)
		{
			type[de_num] = 0;
			cd[cd_num++] = ccd;
			de_num++;
		}
		void set(HD hhd)
		{
			type[de_num] = 1;
			hd[hd_num++] = hhd;
			de_num++;
		}
		virtual void show(int i)
		{
			if(type[i] == 0){
//				cout << "cd_show_order= "<<cd_show_order;
				cd[cd_show_order++].show();
			}else if(type[i] == 1){
//				cout << "hd_show_order= "<<hd_show_order;
				hd[hd_show_order++].show();
			}
		}
		void reset_pr_order()
		{
			cd_show_order = 0;
			hd_show_order = 0;
		}
};
int main()
{
	Host host;
	CD ccd[10];
	HD hhd[10];
	int row = 1;
	int moun_order = 0;
	int moun_num = 0;
	int print_order = 0;
	Device* device;
	cout << "***********************************************************" << endl;
	cout << "Part1.Initiation(Using own class function to print)" << endl;
	hhd[0].setname((char*)"Western Digital-750G");
	ccd[0].setname((char*)"ASUS-E818A");
	hhd[1].setname((char*)"HITACHI-500G");
	ccd[1].setname((char*)"SONY-1642");
	ccd[2].setname((char*)"PHILIPS-SPD514");
	hhd[2].setname((char*)"SEAGATE-750G");
	cout << "[" << row++ << "]" << "The number of mounted device is " << host.getnum() <<endl;
	if(host.getnum() == 0){
		cout << "There is no any device in the host." << endl;
	}
	cout << "Device list:" << endl;
	cout << "[" << row++ << "]" << "Device<" << moun_order << ">:" ;
	hhd[0].show();
	cout << "[" << row++ << "]" << "Device<" << moun_order << ">:" ;
	ccd[0].show();
	cout << "[" << row++ << "]" << "Device<" << moun_order << ">:" ;
	hhd[1].show();
	cout << "[" << row++ << "]" << "Device<" << moun_order << ">:" ;
	ccd[1].show();
	cout << "[" << row++ << "]" << "Device<" << moun_order << ">:" ;
	ccd[2].show();
	cout << "[" << row++ << "]" << "Device<" << moun_order << ">:" ;
	hhd[2].show();
	cout << "*********************************************************" << endl;
	cout << "Part2.Mounting device(Use polymorphism method)" << endl;
	host.set(hhd[0]);
	cout << "[" << row++ << "]" << "Device<" << ++moun_order << ">:" ;
	host.show(moun_order - 1);
	host.set(ccd[1]);
	cout << "[" << row++ << "]" << "Device<" << ++moun_order << ">:" ;
	host.show(moun_order - 1);
	host.set(ccd[2]);
	cout << "[" << row++ << "]" << "Device<" << ++moun_order << ">:" ;
	host.show(moun_order - 1);
	host.set(hhd[1]);
	cout << "[" << row++ << "]" << "Device<" << ++moun_order << ">:" ;
	host.show(moun_order - 1);
	host.set(hhd[2]);
	cout << "[" << row++ << "]" << "Device<" << ++moun_order << ">:" ;
	host.show(moun_order - 1);
	host.set(ccd[0]);
	cout << "[" << row++ << "]" << "Device<" << ++moun_order << ">:" ;
	host.show(moun_order - 1);
	host.reset_pr_order();
	cout << "*********************************************************" << endl;
	cout << "Part3.Renaming(Use Host class function to print)" << endl;
	host.setname(1, 1, (char*)"MAXTOR-160G");
	host.setname(0, 2, (char*)"PHILIPS-SPD2514");
	for(int i = 0 ; i < host.getnum() ; i++){
		cout << "[" << row++ << "]" << "Device<" << ++print_order << ">:" ;
		host.show(i);
	}
}
