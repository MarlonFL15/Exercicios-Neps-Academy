#include<iostream>

using namespace std;

int main(){
	int a,b;
	string oitavas = "ABCDEFGHIJKLMNOP";
	string quartas,semi,final;
	
	for(int i = 0; i < 8; i++){
		cin >> a >> b;
		
		if(a > b){
			quartas+=oitavas[i*2];
		}
		else{
			quartas+=oitavas[i*2+1];
		}
		
	}
	
	for(int i = 0; i < 4; i++){
		cin >> a >> b;
		
		if(a > b)
			semi += quartas[i*2];
		else
			semi += quartas[i*2+1];
	}
	
	for(int i = 0; i < 2; i++){
		cin >> a >> b;
		
		if(a > b)
			final += semi[i*2];
		else
			final += semi[i*2+1];
	}
	
	cin >> a >> b;
	
	if(a > b) cout << final[0];
	else cout << final[1];
	
	return 0;
}
