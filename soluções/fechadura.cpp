#include<iostream>
#include<vector>

using namespace std;


int main(){
	int N, total;
	int soma=0;
	
	cin >> N >> total;
	
	int vetor[N+1]={0};
	
	for(int i = 0; i < N; i++){
		cin >> vetor[i];
	}

	for(int i = 0; i < N; i++){
		while(vetor[i] != total){
			soma++;
			if(vetor[i] > total){
				vetor[i]-=1;
				vetor[i+1]-=1;
			}
			else{
				vetor[i]+=1;
				vetor[i+1]+=1;
			}
		}
	}
	
	cout << soma;
	return 0;
}
