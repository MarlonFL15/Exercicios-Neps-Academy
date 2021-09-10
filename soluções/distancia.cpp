#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int resp=0;
	int n1, n2, n3, n4;
	
	cin >> n1 >> n2 >> n3 >> n4;
	
	resp = fabs(n3-n1) + fabs(n4-n2);
	cout << resp;
	
	return 0;
}
