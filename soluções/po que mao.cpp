#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int N;
	int i = 0;
	int vetor[3];
	cin >> N;
	int cont=0;
	cin >> vetor[0] >> vetor[1] >> vetor[2];
	
	sort(vetor,vetor+3);
	
	for(int i = 0; i < 3; i++){
		if(N >= vetor[i]){
			N -= vetor[i];
			cont++;
		}
	}
	
	cout << cont;
	
	return 0;
}
