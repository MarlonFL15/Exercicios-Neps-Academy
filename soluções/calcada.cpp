#include<iostream>

#define MAX 501

using namespace std;

int N;
int vetor[MAX];
bool check[MAX];

int simula(int n1, int n2){
	
	int melhor=0;
	int ant = -1;
	int atual = 0;
	
	for(int i = 0; i < N; i++){
		if(vetor[i]==n1 || vetor[i]==n2){
			if(vetor[i]!=ant){	
				atual++;
				ant = vetor[i];
			}
		}	
		//atual = 0;
	}
	
	return atual;
}

int main(){
	cin >> N;
	int resp = 0;
	for(int i = 0; i <= N; i++){
		check[i] = false;	
	}
	
	
	for(int i = 0; i < N; i++){
		cin >> vetor[i];
		check[vetor[i]] = true;
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = i; j<=N; j++){
			if(check[i] and check[j] && i != j){
				resp = max(simula(i,j), resp);
			}
		}
		resp = max(simula(i,i), resp);
	}
	
	cout << resp;
	
	return 0;
}
