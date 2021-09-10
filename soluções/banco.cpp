#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
	int N,M;
	int hora_atual=0;
	int resp=0;
	int prox=0;
	int input1, input2;
	pair<int, int> aux;
	queue<pair <int, int> > fila;
	priority_queue <int, vector<int>, greater<int> > func;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		func.push(0);
	}
	
	for(int i = 0; i < M; i++){
		cin >> input1 >> input2;
		fila.push(make_pair(input1, input2));
	}
	
	do{
		aux = fila.front();
		fila.pop();
		hora_atual=func.top();
		if(hora_atual - aux.first > 20){
			resp++;
		}
		
		func.pop();
		func.push(max(hora_atual, aux.first)+aux.second);

	}while(!fila.empty());
	
	cout << resp;
	return 0;
}
