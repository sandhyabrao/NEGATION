#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
  
class Matrix {
public:
	int matrix[10][10];
    Matrix(int mat[10][10])  { 
		for(int i=0;i<10;i++){
	 		for(int j=0;j<10;j++){
				matrix[i][j] = mat[i][j];	 		
			}
	 	}
	}
	
    void print() { 
    	cout<<endl<<endl;
    	cout<<"Matrix:"<<endl;
		for(int i=0;i<10;i++){
	 		for(int j=0;j<10;j++){
				cout<< matrix[i][j] << "\t";	 		
			}
			cout<<endl;
	 	}	
	}
  
// The global operator function is made friend of this class so
// that it can access private members
//friend Matrix operator - (Matrix const &);
};
  
  
Matrix operator - (Matrix const &m)
{
	 Matrix mat = Matrix(m);
	 for(int i=0;i<10;i++){
	 	for(int j=0;j<10;j++){
			mat.matrix[i][j] = -1 * mat.matrix[i][j];	 		
		 }
	 }
     return mat;
}
  
  
int main()
{
    srand(time(0));
    int mat[10][10];
    for(int i=0;i<10;i++){
    	for(int j=0;j<10;j++){
    		mat[i][j] = (int)rand();
		}
	}
	Matrix m = Matrix(mat);
	m.print();
    m = -m;
    m.print();
    return 0;
}
