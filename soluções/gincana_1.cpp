#include<iostream>
#include<vector>
#include<queue>

#define MAX 1001

using namespace std;

vector<int> alunos[MAX];
bool check[MAX] = {0};
vector<int> grupos;

int N, M;

int dfs(int x){
	int qtd=0;
	
	queue<int> fila;
	fila.push(x);
	
	while(!fila.empty()){
		int v = fila.front();
		fila.pop();
		check[v] = true;
		for(int i = 0; i < alunos[v].size(); i++){
			
			if(!check[alunos[v][i]])
				fila.push(alunos[v][i]);
		}
		qtd++;
	}
	grupos.push_back(qtd);
}

int mdc(int a, int b){
	if(b==0)
		return a;
	else
		return mdc(b, a%b);
}

int main(){
	int input1, input2;
	int number=0;
	cin >> N >> M;
	
	while(M--){
		cin >> input1 >> input2;
		alunos[input1].push_back(input2);
		alunos[input2].push_back(input1);
	}	
	
	for(int i = 1; i<=N; i++){
		if(!check[i]){
			number++;
			dfs(i);
		}
	}
	cout << number;
	return 0;
}
