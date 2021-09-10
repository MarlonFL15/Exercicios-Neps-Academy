#include<iostream>

#define MAX 10000

using namespace std;


int N;
int vetor[MAX];

int buscaleft(int i){
	for(int j = i-1; j >= 0; j--){
		if(vetor[j] == 0)
			return i-j;
	}
	return -1;
}	

int buscaright(int i){
	for(int j = i+1; j < N; j++){
		if(vetor[j] == 0)
			return j-i;
	}
	return -1;
}	

int main(){
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> vetor[i];
	}
	
	for(int i = 0; i < N; i++){
		if(vetor[i] != 0){
			int l = buscaleft(i);
			int r = buscaright(i);
			
			if(l  == -1 || r == -1){
				if(max(l,r)>=9)
					vetor[i] = 9;
				else
					vetor[i] = max(l,r);
			}
			else if(min(l,r) >= 9){
				vetor[i] = 9;
			}
			else
				vetor[i] = min(l,r);
		}
	}
	
	for(int i = 0; i < N; i++)
		cout << vetor[i] << " ";
	return 0;
}
