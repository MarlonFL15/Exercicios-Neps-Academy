#include<iostream>
#include<algorithm>
#define MAX 50001

using namespace std;

int main(){
	int N;
	int vetor[MAX];
	int atual=0,melhor=0;	
	cin >> N;
	
	for(int i = 0; i < N ;i++)
		cin >> vetor[i];
	
	for(int i = 0; i < N; i++){
		atual = max(vetor[i], vetor[i]+atual);
		melhor = max(atual,melhor);
	}
	
	cout << melhor;
	
	
	return 0;
}
