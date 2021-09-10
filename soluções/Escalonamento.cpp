#include<iostream>
#include<queue>
#include<vector>

#define MAX 50000 

using namespace std;

int N,M;
int grau[MAX] = {0};

vector<int> adj[MAX];
int main(){
	int i1, i2;
	priority_queue<int, vector<int>, greater<int> > fila;
	vector<int> seq;
	cin >> N >> M;	
	
	for(int i = 0; i < M; i++){
		cin >> i1 >> i2;
		grau[i2]++;
		adj[i1].push_back(i2);
	}
	
	for(int i = 0; i <N; i++){
		if(grau[i]==0){
			fila.push(i);
			grau[i] = -1;
		}
	}
	
	while(!fila.empty()){
		int v = fila.top();
		//cout << "Valor no topo: " << v <<"\n";
		fila.pop();
		seq.push_back(v);
		for(int i = 0; i < adj[v].size(); i++){
			grau[adj[v][i]]--;
			//cout << "valor do grau do vertice " << adj[v][i] << ": " << grau[adj[v][i]] << "\n";
			if(grau[adj[v][i]] == 0){
				fila.push(adj[v][i]);
				adj[v][i] = -1;
			}
			
		}
		
	}
	
	if(seq.size()==N){
		for(int i = 0; i < N; i++){
			cout << seq[i] << "\n";
		}
	}
	else
		cout << "*";
	
	return 0;
}
