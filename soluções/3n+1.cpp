#include<iostream>

using namespace std;

int main(){
	int N;
	int total = 0;
	cin >> N;
	
	while(N != 1){
		if(N % 2)
			N = 3*N + 1;
		else
			N/=2;
		total++;
	}
	
	cout << total << endl;
	return 0;
}
