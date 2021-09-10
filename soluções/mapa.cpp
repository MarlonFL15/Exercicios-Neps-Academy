#include<iostream>
#include<algorithm>
#define MAX 124751

using namespace std;

struct node{
	int x,y;
	int dist;
};

int resp=0;
int N,M;
node vetor[MAX];
int pai[MAX];

bool comp(node a, node b){
	return a.dist < b.dist;
}
int find(int x){
	if(pai[x] == x)
		return x;
	else
		return pai[x] = find(pai[x]);
}

void join(int x, int y){
	int a = find(x), b = find(y);
	pai[b] = a;
}

int main(){
	
	cin >> N >> M;
	int x,y;
	for(int i = 1; i <= N; i++){
		pai[i] = i;
	}
	
	for(int j = 1; j <= M; j++){
		cin >> vetor[j].x >> vetor[j].y >> vetor[j].dist;
	}
	
	sort(vetor+1, vetor+M+1, comp);
	
	for(int i = 1; i <= M; i++){
		x = vetor[i].x;
		y = vetor[i].y;
		
		if(find(x) != find(y)){
			resp += vetor[i].dist;
			join(x,y);
		}
		
	}
	
	cout << resp;
	return 0;
}
