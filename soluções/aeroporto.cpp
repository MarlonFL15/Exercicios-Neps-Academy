#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> maximo(int aero[], int N){
	vector<int> maiores;
	int maior = 0;
	
	for(int i = 1; i <= N; i++){
		if(i==1 or aero[i]>maior){
			maior = aero[i];
			maiores.erase(maiores.begin(), maiores.end());
			maiores.push_back(i);
		}
		else if(aero[i]==maior){
			maiores.push_back(i);
		}
	}
	return maiores;
}

int main(){
	int N,V;
	int teste=1;
	int aero[101];
	int input1, input2;
	do{
		memset(aero, 0, sizeof(aero));
		cin >> N >> V;
		
		for(int i = 0; i < V; i++){
			cin >> input1 >> input2;
			aero[input1]++;
			aero[input2]++;
		}
		if(N!=0 or V != 0){
			cout << "Teste " << teste << "\n";
			vector<int> maior = maximo(aero, N);
			
			for(int j = 0; j < maior.size(); j++){
				cout << maior[j] << " ";
			} 
			cout << "\n\n";
		}
		teste++;
	}while(N!=0 or V != 0);
	
}
