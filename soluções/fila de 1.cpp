#include<iostream>

using namespace std;

int main(){
	long long int n;
	int aux;
	cin >> n;
	
	if(n==0){
		cout << "N";
		return 0;
	}
	
	while(n>0){
		aux = n%2;
		n/=2;
		if(!aux){
			cout << "N";
			return 0;
		}
	}
	
	cout << "S";
	return 0;
}
