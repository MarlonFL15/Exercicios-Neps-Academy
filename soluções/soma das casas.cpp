#include<iostream>
#include <vector>

using namespace std;

long long int N, K, input;
long long int vetor[100000]={0};

pair<int, int> busca(int, int);

int main(){
	int davez=0;
	pair<int, int> resp; 
	cin >> N;
	int a,b;
	for(int i = 0 ; i < N; i++){
		cin >> vetor[i];
		
	}	
	a = 0;
	b = N-1;
	cin >> K;
	
	while(true){
		if(vetor[a]+vetor[b]==K){
			cout << vetor[a] << " " << vetor[b];
			break;
		}
		else if(vetor[a]+vetor[b]>K)
			b--;
		else
			a++;
	}
	return 0;
}

