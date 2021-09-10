#include<iostream>

using namespace std;

long long int mdc(long long int a, long long int b){
	if(b==0)
		return a;
	else
		return mdc(b, a%b);
}
bool primo(long long int n){
	if (n == 1)
		return true;
	else{
		long long int i = 1;
		
		do{
			i+=2;
			if(n%i==0)
				return false;
		}while(i*i<=n);
		return true;
	}
}

int main(){
	long long int M, N;
	long long int resp;
	cin >> N >> M;
		
	for(long long int i = M; i >=0; i--){
		if(mdc(N, i)==1){
			resp = i;
			break;
		}
	}
	
	cout << resp;
	return 0;
}
