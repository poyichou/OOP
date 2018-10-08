#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main(int argc, char **argv)
{
	int i , j;
	int temp = 0, tempc;
	int arr[argc];
	int argtemp = argc-1;
	int size = 0;
	int countarr;
	int countemp = 0;
	int temptemp;

	for (i = 1; i < argc; i++) {
		for (j = strlen(argv[i]) - 1; j >= 0; j--){
			if (argv[i][j] >= '0' && argv[i][j] <= '9') {
				temptemp = argv[i][j] - '0';
				tempc=temp;
				for(; tempc>0 ; tempc--){
					temptemp *= 16;
				}
				countemp += temptemp;
			}else if(argv[i][j]>='A' && argv[i][j]<='F'){
				temptemp=argv[i][j]-'A'+10;
				tempc=temp;
				for(; tempc>0 ; tempc--){
					temptemp *= 16;
				}
				countemp += temptemp;
			}else if(argv[i][j]=='+' || argv[i][j]=='-' || argv[i][j]=='x' || argv[i][j]=='/'){
				countemp=argv[i][j];
			}
			temp++;
		}
		arr[size++]=countemp;
		countemp=0;
		temp=0;
	}
	while(arr[1]!=' '){
		for(size=0;arr[size]!='+' && arr[size]!='-' && arr[size]!='x' && arr[size]!='/';size++);
		switch(arr[size]){
			case '+':
				countarr=arr[size-2]+arr[size-1];
				break;
			case '-':
				countarr=arr[size-2]-arr[size-1];
				break;
			case 'x':
				countarr=arr[size-2]*arr[size-1];
				break;	
			case '/':
				countarr=arr[size-2]/arr[size-1];
				break;	
			default:
				break;
		}
		arr[size-2]=countarr;
		size++;
		for(i=size;i<argtemp;i++){
			arr[i-2]=arr[i];
		}
		arr[argtemp-1]=' ';
		arr[argtemp-2]=' ';
		argtemp--;
		argtemp--;
	}
	char hex[5];
	sprintf(hex, "%x", arr[0]);
	cout<<"Output"<<endl<<hex;
}
