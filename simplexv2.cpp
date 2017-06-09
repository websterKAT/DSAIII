#include <iostream>
#include <stdlib.h>
using namespace std;


void printTableau(double **T,int m,int n){   //this is for print the output table
	for (int i = 0; i <= m; i++) { 
		for (int d = 0; d <= n+m+2; d++){
			cout << T[i][d] << "     ";
		}
		cout << endl;
	}
}
int getMinFrom(double **T, int n){    //to get the Entering variable
	int minIndex = -1;
	int min = 100000;	
	for(int v=1;v <= n;v++){
		if((min > T[0][v]) && (T[0][v] < 0)){
			min = T[0][v];
			//cout << min;
			minIndex = v;
		}


	}

	return minIndex;
}

int setUpperBound(double **T,int idx,int m,int n) {  //to find the leaving variable
	int upperRowNo = 0;
	double mini = 100000;
	for (int i = 1;i <= m; i++){
		T[i][n+m+2] = T[i][n+m+1]/T[i][idx];
		if(mini > T[i][n+m+2]){
			mini = T[i][n+m+2];
			upperRowNo = i;
		}
	}
	return upperRowNo;
}

// to enter all the Basic non basic variable to the 2dArray called T
void Tablaeu(double **A,double *c,int m,int n,double **T) {  
	int count = m+n+2;
	int col,row;
	
	for(int k=0;k<=count;k++){      // Entering the 1st row of the Tablaue 
		if(k<=n){
			if(k ==0)
				T[0][k] = c[k];
			else
				T[0][k] = -1*c[k];
		}
		else{
			T[0][k] = 0;
		}
	}
	int u = n+1;	
	for(int i=1;i<=m;i++) {
		for(int j=0;j<=count;j++){
			if(j == 0)
				T[i][j] = 0;
			else if(j > 0 && j <=n)      //entering rest of the rows
				T[i][j] = A[i-1][j-1];
			else if(j>n && j <= n+m){
				if(j== u){
					T[i][j] = 1;
					
				}
				else
					T[i][j] = 0;
				
			}
			else if(j > m+n && j < count){
				T[i][j] = A[i-1][n];			
			}
			else{
				T[i][j] = 0;
			}
		}
		u++;
	}
	col = getMinFrom(T,n);
	row = setUpperBound(T,col,m,n);
	//printTableau(T,m,n);
	

}

//to do the same process untill first row(that is where the objective function's coffeciets exist )
//coeffcients all become greater than zero
//PIVOTING PROCESS
void doIteration(double **T,double *K,int colIdx,int rowIdx,int m,int n){
	for (int i = 0; i <= m;i++){
		K[i] = T[i][colIdx];
	}
	for(int q = 0; q <= m; q++){
		if(q != rowIdx)
			T[q][colIdx] = T[q][n+rowIdx];
	}
	double key = K[rowIdx];
	for (int j = 0; j < n+m+2; j++){      //fil the leaving variables row
		T[rowIdx][j] = T[rowIdx][j]/key;
	}
	for (int i = 0; i <= m; i++){
		if(i != rowIdx){
			for (int k = 0; k < m+n+2; k++){
				if(k != colIdx){
					key = -1*K[i];
					T[i][k] = T[i][k]+ key*T[rowIdx][k];
				}
			}
		}
	}

}

//mySimplex algorithm ; this is not exactly the same as the algorithm which is in the question
void simplex(double **T,double **A,double *K,double *c,int m,int n){
	Tablaeu(A,c,m,n,T);
	int enteringIdx,leavingIdx;
	enteringIdx = getMinFrom(T,m);
	while(enteringIdx >= 0){
		leavingIdx = setUpperBound(T,enteringIdx,m,n);
		doIteration(T,K,enteringIdx,leavingIdx,m,n);
		enteringIdx = getMinFrom(T,m);
		//printTableau(T,m,n);
		cout << "                " << "\n";
	}
	printTableau(T,m,n);
	
}

int main() { 
	// Instruction for the use 
	cout << "Guide to entering variables. suppose our problem is bellow" << endl;
	cout << "2x1 + x2 + x3 + s1 = 180" <<endl;
	cout << "x1 + 3x2 + 2x3 + s2 = 300" <<endl;
	cout << "2x1 + x2 + 2x3 + s3 = 240" <<endl;
	cout << "No of variables = 3, No of constraints = 3" << endl;
	cout << "then your constraints should insert this way" << endl;
	cout << "2 1 1 180" <<endl;
	cout << "1 3 2 300" <<endl;
	cout << "2 1 2 240" <<endl;
	cout << "then your coeffcient of objective function should insert this way" << endl;
	cout << " 1 6 5 4 (1 is essential)" << endl;


	int n,m,i;
	cout<<"Enter no. of variables:";
	cin>>n;
	cout<<"Enter no. of constraints:";
	cin>>m;

	double **A;
	double *K;
	double *c,**T;

	A = (double **)malloc((m)*sizeof(double *));  //memeory allocation for the first contrant arry
	for(int i=0;i < m;i++){
		A[i] = (double *)malloc((n+1)*sizeof(double)); 
	}
	cout << "Enter your contrants"<< endl;
	for(int j = 0;j < m;j++){  //getting user inputs constraints
		for(int k = 0;k <= n;k++){
			cin >> A[j][k];
		}
	}

	K=(double *)malloc((m+1)*sizeof(double));  //temperary arry
	for(int f=0;f<=m;f++){
		K[f] = 0;
	}
	
	c=(double *)malloc((n+1)*sizeof(double));  //memory allcation for coeffcient of
												//objective function
	T=(double **)malloc((m+1)*sizeof(double *));
	for(int g=0;g<=m;g++){
		T[g]=(double *)malloc((m+n+3)*sizeof(double));
	}

	cout<<"Enter coefficients of objective function: ";  //getting objective value coeffcients
	for(int y=0;y<=n;y++) cin>>c[y];

	simplex(T,A,K,c,m,n);
 
	for (int i = 0; i <= m ; ++i){ //for printing answers
	  	if(i == 0){
	  		cout << "Z =" << T[i][n+m+1] << endl;
	  	}
	  	else{
	  		cout << "variable " << i << "  =" << T[i][n+m+1] << endl;
 	  	}
	}  
	return 0;
}
