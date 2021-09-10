#include<iostream>
#include<vector>

using namespace std;

vector<int> primos;

bool isPrime(long long int n){
	bool prime = true;
	
	for(int i = 0; i < primos.size(); i++){
		if(n % primos[i]==0)
			return false;
		if(primos[i]*primos[i]>n)
			break;
	}
	if(prime){
		primos.push_back(n);
	}
	return true;
}

int main(){
	long long int n, input1;
	bool prime = true;
	long long int i = 1;
	
	cin >> n;
	
	for(long long int i = 2; i <= n ; i++){
		if(isPrime(i))
			cout << i << " ";
	}
	return 0;
}
