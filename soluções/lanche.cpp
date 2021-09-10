#include<iostream>

#define MAX 251

using namespace std;

int adj[MAX][MAX];

int main(){
	int N,M;
	int i1, i2, i3;
	int atual, resp=9999999, index=-1;
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(i == j)
				adj[i][j] = 0;
			else
				adj[i][j] = resp;
		}
	}
	
	for(int i = 0; i < M; i++){
		cin >> i1 >> i2 >> i3;
		adj[i1][i2] = i3;
		adj[i2][i1] = i3;
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= N; k++){
				adj[j][k] = min(adj[j][k], adj[j][i]+adj[i][k]);
			}
		}
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(j==1 || adj[i][j]>atual)
				atual = adj[i][j];
		}
		if(atual < resp){
			resp = atual;
			index = i;
		}
	}
	
	cout << resp;
	
	return 0;
}

