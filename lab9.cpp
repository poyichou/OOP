#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
class Data
{
	private:
		string name;
		int num;
	public:
		void setname(string str)
		{
			name = str;
		}
		void setnum(int num)
		{
			this -> num = num;
		}
		string getname()
		{
			return name;
		}
		int getnum()
		{
			return num;
		}
		void set(Data data)
		{
			name = data.getname();
			num = data.getnum();
		}
};
int main(void)
{
	Data data[100];
	Data temp;
	int n = 0, i, j, k; 
	string str;
	int outnum = 0 , tempnum, tempp = 0;
	int exp = 0;
	fstream fin("input.txt",fstream::in);
	fstream fout("0310030_lab9_output.txt", fstream::out);
	while(1)
	{
		if(!fin.eof()){
			getline(fin, str);
			istringstream instr(str);
			string name;
			int num;
			instr >> name >> num;
			data[n].setname(name);
			data[n].setnum(num);
			/*for(i = 0 ; i < n ; i++){
				for(j = 0 ; j < n - i - 1 ; j++){
					if(data[j].getnum() > data[j + 1].getnum()){
						/*cout << "data[j    ].getnum() = "<< data[j].getnum() << endl;
						cout << "data[j + 1].getnum() = "<< data[j + 1].getnum() << endl;
						temp.set(data[j + 1]);
						data[j + 1].set(data[j]);
						data[j].set(temp);
						/*cout << "after:" << endl;
						cout << "data[j    ].getnum() = "<< data[j].getnum() << endl;
						cout << "data[j + 1].getnum() = "<< data[j + 1].getnum() << endl;
					}
				}
			}*/
			n++;
		}else{
			break;
		}
	}
	for(i = 0 ; i < n ; i++){
		for(j = 0 ; j < n - i - 1 ; j++){
			if(data[j].getnum() > data[j + 1].getnum()){
				/*cout << "data[j    ].getnum() = "<< data[j].getnum() << endl;
				cout << "data[j + 1].getnum() = "<< data[j + 1].getnum() << endl;*/
				temp.set(data[j + 1]);
				data[j + 1].set(data[j]);
				data[j].set(temp);
				/*cout << "after:" << endl;
				cout << "data[j    ].getnum() = "<< data[j].getnum() << endl;
				cout << "data[j + 1].getnum() = "<< data[j + 1].getnum() << endl;*/
			}
		}
	}
	for(i = 0 ; i < n ; i++){
		cout << data[i].getname() << " ";
//		cout << data[i].getnum() << endl;
		tempnum = data[i].getnum();
////		101
		for(; tempnum > 0 ; tempnum /= 10){
			exp++;
		}
		exp--;
		tempnum = data[i].getnum();
		
//		cout <<"tempnum = " << tempnum<<endl;
		
		for(j = 0 ; j < exp + 1 ; j++){
			tempp = tempnum % 10;
			for(k = 0 ; k < j ; k++){
				tempp *= 2;
			}
			
//			cout <<"tempp = "<< tempp << endl;
			tempnum /= 10;
			outnum += tempp;
		}
		cout << outnum << endl;
		fout << data[i].getname() << " " << outnum << endl;
		outnum = 0;
		exp = 0;
		tempp = 0;
	}
}
