#include<iostream>

using namespace std;

long long int calcula(string);

int main(){
	int T;
	string c;
	cin >> T;
	
	while(T--){
		cin.ignore();
		cin >> c;
		//getline(cin, c);
		//cout << "\nvalor da string: " << c << "\n";
		cout << calcula(c);
	}
	
	return 0;
}

long long int calcula(string c){
	int numero=0;
	long long int resp = 1;
	int k;
	int j=0;
	for(int i = 0; i < c.size(); i++){
		if(c[i]!='!')
			numero = numero*10+c[i]-'0';
		else{
			k = c.size()-i;	
			break;
		}
	}
	
	while(numero+k*j>=1){
		resp*= (numero+k*j);
		j--;
	}
	return resp;
}
