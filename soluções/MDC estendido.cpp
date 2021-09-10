#include<iostream>

using namespace std;

int mdc(int a, int b){
	return b==0?a:mdc(b, a%b);
}

int main(){
	long long int N, input1;
	long long int MDC;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> input1;
		
		if(i==0)
			MDC = input1;
		else
			MDC = mdc(input1, MDC);
		
	} 
	
	cout << MDC;
	
	return 0;
}
