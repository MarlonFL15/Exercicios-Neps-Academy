#include<iostream>
#include<vector>

using namespace std;

#define MAX 10001

int N,M;
int dist[MAX] = {-1};
vector<pair<int, int> > adj[MAX];

int percorre(int v){
	pair<int, int> aux;
	
	for(int i = 0; i < adj[v].size(); i++){
		aux = adj[v][i];
		
		if(dist[aux.first]==-1){
			dist[aux.first] = aux.second+dist[v];
			percorre(aux.first);
		}
		else if(aux.second+dist[v]<dist[aux.first]){
			dist[aux.first] = aux.second+dist[v];
			percorre(aux.first);
		}
	}
	return 0;
}

int main(){
	int i1, i2, i3;
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		cin >> i1 >> i2 >> i3;
		dist[i1] = -1;
		dist[i2] = -1;
		adj[i1].push_back(make_pair(i2, i3));
		adj[i2].push_back(make_pair(i1, i3));	
	}
		
	dist[0] = 0;
	
	percorre(0);
	
	cout << dist[N+1];
	return 0;
}
