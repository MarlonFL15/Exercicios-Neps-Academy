#include<iostream>
#include<vector>

using namespace std;

long long int N,M;
vector<int> pontos, faixa;
	
int busca(int num){
	int ini=0;
	int fim = N-2;
	int meio;
	while(fim>=ini){
		meio = (ini+fim)/2;
		
		if(faixa[meio]<=num and num <faixa[meio+1]){
			return pontos[meio+1];
		}
		if(faixa[meio]<num){
			ini = meio+1;
		}
		else
			fim = meio-1;
	}
	
}

int main(){
	cin >> N >> M;
	int aux;
	int ogros[M];
	for(int i = 0; i < N-1; i++){
		cin >> aux;
		faixa.push_back(aux);
	}
	
	for(int i = 0; i < N; i++){
		cin >> aux;
		pontos.push_back(aux);
	}
	
	for(int i = 0; i < M; i++){
		cin >> ogros[i];
		if(ogros[i]<faixa[0])
			cout << pontos[0];
		else if(ogros[i]>=faixa[N-2])
			cout << pontos[N-1];
		else{
			cout << busca(ogros[i]);
		}
		cout << " ";
	}
	
	
	return 0;
}
