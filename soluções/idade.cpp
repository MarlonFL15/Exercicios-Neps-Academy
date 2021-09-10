#include<iostream>

using namespace std;

int main(){
	int M, A, B, C;
	
	cin >> M >> A >> B;
	
	C = M-A-B;
	
	if(A > B && A > C){
		cout << A;
	}
	else if(B>C)
		cout << B;
	else
		cout << C;
	
	return 0;
}
