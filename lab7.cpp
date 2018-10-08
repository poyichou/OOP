#include<iostream>
#include<cstdlib>
#include"vec.h"
using namespace std;
///
///Stack & Queue must inherit protected vec
///
class Stack : protected vec
{
	private:
		int top;
	public:
		Stack(int n) : vec(n)
		{
			top = 0;
		}
		void Push(int n)
		{
			if(top < get_size()){
				set(top, n);
				top++;
			}else{
				cout << "full" << endl;
			}
			
		}
		int isEmpty()
		{
			if(top <= 0){
				return 1;
			}else{
				return 0;
			}
		}
		void Pop()
		{
			if(!isEmpty())
			top -= 1;
			else{
				cout << "Empty";
			}
		}
		int Top()
		{
			return get_data(top - 1);
		}
};
class Queue : protected vec
{
	private:
		int front, rear, count;
	public:
		Queue(int n) : vec(n)
		{
			front = 0;
			rear = 0;
			count = 0;
		}
		Queue(Queue &q) : vec(q.get_size())
		{
			for(int i = 0 ; i < get_size() ; i++){
				set(i, q.get_data(i));
//				cout << "get_data(i) = " <<get_data(i);
			}
			front = q.front;
			rear = q.rear;
			count = q.count;
		}
		void Push(int n)
		{
			if(count < get_size()){
				set(front, n);
				if(front < get_size() - 1){
					front++;
					count++;
				}else if(front >= get_size() - 1){
					front = 0;
					count++;
				}
				
			}else if(count >= get_size()){
				cout << "full" << endl;
			}
		}
		void Pop()
		{
			if(count > 0){
				set(rear, -100);
				if(rear < get_size() - 1){
					rear ++;
					count--;
				}else if(rear >= get_size() - 1){
					rear = 0;
					count--;
				}
			}else if(count <= 0){
				cout << "Empty" << endl;
			}
		}
		int Front()
		{
			return get_data(rear);
		}
		int isEmpty()
		{
			if(count <= 0){
				return 1;
			}else{
				return 0;
			}
		}
		int getf()
		{
			return front;
		}
		int getr()
		{
			return rear;
		}
};
int main()
{
cout<<"Test Stack"<<endl;
	Stack s(5);
	// Push 0~5 into Stack s
	for(int i=0;i<6;i++)
		s.Push(i);
	// Print Stack s
	while(!s.isEmpty()){
		cout<<s.Top()<<" ";
		s.Pop();
	}
	cout<<endl;
	s.Pop();
	cout<<endl;
	
	cout<<"Test Queue"<<endl;
	Queue test(10); 
	// Push 1~3 into Queue test
	for (int i = 1; i < 4; i++){test.Push(i);/*cout << test.getf() <<"  " << test.getr() << endl;*/}
	Queue test1(test); // content of test1 are 1~3 by copy constructor
	// Push 4~11 into Queue test1
	for (int i = 4; i <= 11; i++){test1.Push(i);/*cout << test1.getf() <<"  " << test1.getr() << endl;*/}/*cout <<"fuck2";*/
	test1.Pop(); test1.Pop(); test1.Push(11);
	// Print Queue test1
//	cout << "isempty = "<< test1.isEmpty();
	while(!test1.isEmpty()){
//		cout <<"rear = "<< test1.getr() << endl;
		cout<<test1.Front()<<" ";
		test1.Pop();
	}
	cout<<endl;
	test1.Pop();

    system("pause");
    return 0;
}
