#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
//120 a hour
//2000 day
//full ab 4 over35
using namespace std;
int main()
{
	ifstream fin("workinghours.txt");
	ofstream fout("salary.txt");
	if(fin == NULL){
 		cout << "can't open file!!" << endl;
 		return 1;
	}
	while(fin != NULL)
	{
//		cout <<"f " << endl;
		string str1, str2;
		string type, temp;
		int i , j;
		int over = 0;
		string inday, day[7];
		int hour[5][7], totaltime = 0, totalsal = 0, ab = 0;
		
		getline(fin , str1);
		istringstream Instr(str1);
		if(str1 != " "){
//			fin >> type;
			Instr >> temp;
			Instr >> type;
//			fout << str1 << endl;
			if(type == "parttime"){
				fout << temp << " part-time" <<endl;
			}else if(type == "fulltime"){
				fout << temp << " full-time" <<endl;
			}
			getline(fin, inday);
			istringstream Instr2(inday);
			for(i = 0 ; i < 7 ; i++){
				Instr2 >> day[i];
			}
			for(i = 0 ; i < 4 ; i++){
				for(j = 0 ; j < 7 ; j++){
					fin >> hour[i][j];
//					cout << hour[i][j] << " ";
					totaltime += hour[i][j];
					if(type == "parttime"){
						if(hour[i][j] == 0){
							ab++;
						}
						totalsal += hour[i][j] *120;
					}else if(type == "fulltime"){
						if(day[j] == "Sun." || day[j] == "Sat."){
							if(hour[i][j] <= 4 && hour[i][j] > 0){
								totalsal += 300 * hour[i][j];
							}else if(hour[i][j] > 4){
								totalsal += 1200;
							}
							over += hour[i][j];
						}
						if(day[j] != "Sun." && day[j] != "Sat."){
							if(hour[i][j] == 0){	
								ab++;
							}else if(hour[i][j] < 8){
								totalsal += 1600;
							}else if(hour[i][j] >= 8){
								totalsal += 2000;
							}
							if(hour[i][j] > 8){
								totalsal += 200;
								over += hour[i][j] - 8;
							}
						}
						
						
					}
					
				}
//				cout << endl;
			}
			for(i = 4, j = 0 ; j < 2 ; j++){
				fin >> hour[i][j];
				totaltime += hour[i][j];
				if(type == "parttime"){
					if(hour[i][j] == 0){
						ab++;
					}
					totalsal += hour[i][j] *120;
				}else if(type == "fulltime"){
					if(hour[i][j] == 0){
						ab++;
					}else if(hour[i][j] < 8){
						totalsal += 1600;
					}else if(hour[i][j] <= 8){
						totalsal += 2000;
					}
					if(hour[i][j] > 8){
						totalsal += 200;
						over += hour[i][j] - 8;
					}
					
				}
			}
			cout << type << endl;
			fout << "Working hour:" << totaltime << " hours" << endl;
			fout << "Absence:" << ab << " days." << endl;
			if(type == "parttime"){
				fout << "Hourly wage:120" << endl;
				fout << "Salary:NY$" << totalsal - ab * 500 << endl << endl << endl;
			}else if(type == "fulltime"){
				fout << "Overtime hours:" << over <<" hours" << endl;
				fout << "Daily wage:2000" << endl;
				fout << "Salary:NT$" << totalsal << endl << endl << endl;
			}
		}
	}
}
