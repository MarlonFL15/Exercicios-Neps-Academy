#include<iostream>

#define MAX 100001

using namespace std;

int vetor[MAX];
int arv[MAX*4];
int lazy[MAX*4];

int N,Q;

void create(int no, int i, int j){
	if(i == j){
		lazy[no] = 0;
		arv[no] = vetor[i];
	}
	else{
		int left, right, middle;
		left = no*2;
		right = no*2+1;
		middle = (i+j)/2;
		create(left, i, middle);
		create(right, middle+1, j);
		lazy[no] = 0;
		arv[no] = arv[left]+arv[right];
	}
}

void alter(int no, int i, int j, int novo, int a, int b){
	//se ele chegar no nó, calcule o lazy dele (Se tiver)
	
	if(lazy[no] != 0){
		arv[no] = (j-i+1)*lazy[no];
		
		if(i != j){
			lazy[no*2] = lazy[no];
			lazy[no*2+1] = lazy[no];
		}
		lazy[no] = 0;
		
	}
	
	//prossiga com a alteração normal
	
	if(i > b || j < a)
		return ;
	
	if(i>=a && j<=b){
		arv[no] = novo*(j-i+1);
		
		if(i != j){
			lazy[no*2] = novo;
			lazy[no*2+1] = novo;	
		}
	}
	
	else{
		int l, r, m;
		m = (i+j)/2;
		l = no*2;
		r = no*2+1;
		
		alter(l,i,m,novo,a,b);
		alter(r,m+1,j,novo,a,b);
		arv[no] = arv[l] + arv[r];
	}
}

int search(int no, int i, int j, int a, int b){
	
	if(lazy[no] != 0){
		arv[no] = (j-i+1)*lazy[no];
		
		if(i != j){
			lazy[no*2] = lazy[no]; 
			lazy[no*2+1] = lazy[no];
		}
		lazy[no] = 0;
	}
	
	if(i>=a && j<=b)
		return arv[no];
	if(i > b || j < a)
		return 0;
	
	else{
		int left, right, middle;
		left = no*2;
		right = no*2+1;
		middle = (i+j)/2;
		
		return search(left, i, middle, a, b) + search(right, middle+1, j, a, b);
	}
}

int main(){
	int O,A,B,K;
	cin >> N >> Q;
	
	for(int i = 1; i <= N; i++){
		cin >> vetor[i];
		lazy[i] = 0;
	}	

	create(1,1,N);
	
	for(int i = 0; i < Q; i++){
		cin >> O;
		
		if(O == 1){
			cin >> A >> B >> K;
			alter(1, 1, N, K, A,B);
		}
		else{
			cin >> A >> B;
			cout << search(1, 1, N, A,B);
			
		}
	}	
	
	
	return 0;
}
