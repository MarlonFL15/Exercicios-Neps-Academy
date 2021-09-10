#include<iostream>
#include<cstring>
using namespace std;

#define MAX 1001
long long int vetor[MAX] = {-1};
long long int a[MAX] = {0};
long long int N,M,K;

long long int calcula(long long int);

int main(){
	cin >> N >> K >> M;
	memset(vetor, -1, sizeof(vetor));
	for(int i = 1 ; i <=N; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= N; i++){
		cin >> vetor[i];
	}
	
	for(int i = N+1; i <= K; i++){
		vetor[i] = calcula(i);
	}
	
	cout << vetor[K];
	return 0;
}

long long int calcula(long long int k){
	long long int resp=0;
	if(vetor[k] != -1)
		return vetor[k];
		
	for(int i = 1; i <= N; i++){
		resp+=a[i]*calcula(k-i);
	}
	vetor[k] = resp%M;
	return vetor[k];
}
