#include<iostream>

using namespace std;

#define MAX 100001

int times[MAX];
int qtd[MAX];
int pontos[MAX];
int resp = 0;
int find(int);
void join(int,int);
void combat(int,int);

int main(){
	int N,M;
	int opc, input1, input2;
	
	do{
		cin >> N >> M;
		if(N == 0 or M == 0)
			break;
		resp = 0;
		for(int i = 1; i <= N; i++){
			cin >> pontos[i];
			times[i] = i;	
			qtd[i] = 1;
		}
	
		for(int i = 1; i <= M; i++){
			cin >> opc >> input1 >> input2;
			
			if(opc==1){
				join(input1, input2);
			}
			else
				combat(input1, input2);
		}
		cout << resp;
	}while(N != 0 or M != 0);
	
	
	return 0;
}

int find(int x){
	if(times[x]==x)
		return x;
	else
		return times[x]=find(times[x]);
}

void join(int i1, int i2){
	int x = find(i1);
	int y = find(i2);
	
	
	if(qtd[x] < qtd[y]){
		times[y] = x;
		pontos[x] += pontos[y];
	}
	else{
		times[x] = y;
		pontos[y] += pontos[x];	
	}
}

void combat(int i1, int i2){
	int x = find(i1);
	int y = find(i2);
	int pos = find(1);
	
	
	if(pontos[x]>pontos[y] and pos==x)
		resp += 1;
		
	if(pontos[y]>pontos[x] and pos==y)
		resp += 1;
	
}
