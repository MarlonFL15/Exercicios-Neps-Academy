#include<iostream>

using namespace std;

long long int mdc(long long int a, long long int b){
	return b==0?a:mdc(b, a%b);
}

long long int mmc(long long int a, long long int b){
	return a*b/mdc(a, b);
}


int main(){
	long long int n1, n2, d1, d2;
	long long int nR, dR;
	long long int s;
	cin >> n1 >> d1 >> n2 >> d2;
	
	dR = mmc(d1, d2);
	nR = (dR/d1*n1) + (dR/d2*n2); 
	s = mdc(nR, dR);
	dR/=s;
	nR/=s;
	
	cout << nR << " " << dR;
	return 0;
}
