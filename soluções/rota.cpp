#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

#define INF 9999
#define MAX 250

using namespace std;

int N,M,C,K;
int dist[MAX];
vector<pair<int, int> > adj[MAX];

void percorre(int v){
	queue<int> fila;
	int atual = v;
	fila.push(v);
	do{
		atual = fila.front();
		fila.pop();
		for(int i = 0; i < adj[atual].size(); i++){
			int c = adj[atual][i].first;
			if(dist[c] > dist[atual]+adj[atual][i].second){		
				dist[c] = dist[atual]+adj[atual][i].second;
				fila.push(c);
				
			}
		}	
	}while(!fila.empty());
	
}


int main(){
	int c1, c2, d;
	cin >> N >> M >> C >> K;
	
	do{
		for(int i = 0; i < N; i++){
			dist[i] = INF;
			adj[i].clear();
		}
		dist[K] = 0;
		
		for(int i = 0; i < M; i++){
			cin >> c1 >> c2 >> d;
			if(c1 >= C && c2 >= C){	
				adj[c1].push_back(make_pair(c2, d));
				adj[c2].push_back(make_pair(c1, d));
			}
			else if(c1 < C && c2 >= C){
				adj[c2].push_back(make_pair(c1, d));
			}
			else if(c2 < C && c1 >= C){
				adj[c1].push_back(make_pair(c2, d));
			}
			else{
				if(abs(c1 - c2) == 1){
					if(c1 < c2)
						adj[c1].push_back(make_pair(c2, d));
					else
						adj[c2].push_back(make_pair(c1, d));
				}
			}
		}	
		
		percorre(K);
		cout << dist[C-1] << "\n";
		
		cin >> N >> M >> C >> K;
	}while(N != 0);
	return 0;
}
