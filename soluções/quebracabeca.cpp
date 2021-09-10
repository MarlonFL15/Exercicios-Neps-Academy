#include<iostream>
#include<algorithm>

#define MAX 100001

using namespace std;

struct peca{
	int n1,n2;
	char letra;
};

int N;
peca pecas[MAX];

bool comp(peca a, peca b){
	return a.n1 < b.n1;
}

peca search(int i,int j, int value){
	int meio = (i+j)/2;

	if(pecas[meio].n1 == value)
		return pecas[meio];
	else if(pecas[meio].n1 > value)
		return search(i,meio, value);
	else
		return search(meio+1,j,value);
	
}

int main(){
	cin >> N;
	string s;
	peca davez;
	for(int i = 1; i <= N; i++){
		cin >> pecas[i].n1 >> pecas[i].letra >> pecas[i].n2;
		
		if(pecas[i].n1 == 0)
			davez = pecas[i];
		
		
	}
	sort(pecas+1,pecas+N+1, comp);
	
	
	while(davez.n2 != 1){
		s += davez.letra;
		
		davez = search(1,N,davez.n2);
		
	}
	s += davez.letra;
	cout << s;
	return 0;
}
