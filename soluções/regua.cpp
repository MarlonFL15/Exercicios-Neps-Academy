#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int K,A,B;
	
	cin >> K;
	cin >> A >> B;
	
	if(abs(A-B) >= K)
		cout << "EH SUFICIENTE";
	else
		cout << "NAO EH SUFICIENTE";
	
	
	return 0;
}
