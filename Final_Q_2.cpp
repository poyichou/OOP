#include<iostream>
using namespace std;
class matrix
{
	protected:
//	public:
		int matr[100][100];
		int row, col;
	public:
		matrix()
		{
			for(int i = 0 ; i < 100 ; i++){
				for(int j = 0 ; j < 100 ; j++){
					matr[i][j] = 0;
				}
			}
		}
		void set(int n1, int n2, int num)
		{
			matr[n1][n2] = num;
		}
		void setsize(int row, int col)
		{
			this -> row = row;
			this -> col = col;
		}
		matrix operator + (matrix m)
		{
			matrix result;
			for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < col ; j++){
					result.matr[i][j] += matr[i][j] + m.matr[i][j];
				}
			}
			result.row = row;
			result.col = col;
			return result;
		}
		matrix operator - (matrix m)
		{
			matrix result;
			for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < col ; j++){
					result.matr[i][j] = matr[i][j] - m.matr[i][j];
				}
			}
			result.row = row;
			result.col = col;
			return result;
		}
		
		matrix operator * (matrix m)
		{
			matrix result;
			for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < col ; j++){
					for(int k = 0 ;k < col ;k++)
					result.matr[i][j] += matr[i][k] * m.matr[k][j];
				}
			}
			result.row = row;
			result.col = col;
			return result;
		}
		void show()
		{
			for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < col ; j++){
					cout.width(2);
					cout << matr[i][j];
				}
				cout << endl;
			}
		}
};
class vecter
{
	protected:
//	public:
		int vect[2];
		int size;
	public:
		vecter()
		{
			for(int i = 0 ; i < 100 ; i++){
				vect[i] = 0;
			}
		}
		void set(int n1, int num)
		{
			vect[n1] = num;
		}
		void setsize(int n)
		{
			size = n;
		}
		vecter operator + (vecter v)
		{
			vecter result;
			result.size = size;
			for(int i = 0 ; i < size ; i++){
				result.vect[i] += vect[i] + v.vect[i];
			}
			return result;
		}
		vecter operator - (vecter v)
		{
			vecter result;
			result.size = size;
			for(int i = 0 ; i < size ; i++){
				result.vect[i] = vect[i] - v.vect[i];
			}
			return result;
		}
		vecter operator * (vecter v)
		{
			vecter result;
			result.size = size;
			for(int i = 0 ; i < size ; i++){
				result.vect[i] = vect[i] * v.vect[i];
			}
			return result;
		}
		
		void show()
		{
			for(int i = 0 ; i < size ; i++){
				cout.width(2);
				cout << vect[i];
				cout << " ";
			}
			cout << endl;
		}
		int getsize()
		{
			return size;
		}
		int getvect(int i)
		{
			return vect[i];
		}
};
template<class T>
T Add(T t1, T t2)
{
	return t1 + t2;
}
template<class T>
T Sub(T t1, T t2)
{
	return t1-t2;
}
template<class T>
T Mul(T t1, T t2)
{
	return t1*t2;
}


int main(void)
{
	int i1, i2;
	double d1,d2;
	int x1, x2;
	int size;
	int val;
	
	int i, j;
	matrix m1, m2;
	vecter v1, v2;
	int num;
	cin >> i1;
	cin >> i2;
	cin >> d1;
	cin >> d2;
//	cout.precision(7);
//	cout << Mul(d1,d2) << endl;
	cin >> x1;
	cin >> x2;
	v1.set(0,x1);
	v1.set(1, x2);
	v1.setsize(2);
	cin >> x1;
	cin >> x2;
	v2.set(0,x1);
	v2.set(1, x2);
	v2.setsize(2);
	cin >> size;
	m1.setsize(size, size);
	m2.setsize(size, size);
	for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			cin >> val;
			m1.set(i , j , val);
		}
	}
	for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			cin >> val;
			m2.set(i , j , val);
		}
	}
	cout << Add(i1,i2) << endl;
	cout << Sub(i1,i2) << endl;
	cout << Mul(i1,i2) << endl;
	cout << Add(d1,d2) << endl;
	cout << Sub(d1,d2) << endl;
	cout.precision(7);
	cout << Mul(d1,d2) << endl;
	
	Add(v1,v2).show();
	Sub(v1,v2).show();
	cout << Mul(v1,v2).getvect(0) + Mul(v1,v2).getvect(1) << endl;
	Add(m1,m2).show();
	Sub(m1,m2).show();
	Mul(m1,m2).show();
}
