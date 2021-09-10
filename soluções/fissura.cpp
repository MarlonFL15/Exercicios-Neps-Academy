#include<iostream>

#define MAX 501

using namespace std;

int N,F;
string mat[MAX];
int lava[MAX][MAX];

int percorre(int i, int j){
	//posição i,j tem lava
	lava[i][j]=1;
	//se o i for diferente de 0, se a erupção for maior ou igual a F e se a posição i-1,j n foi invadida
	if(i > 0 && F+'0'>=mat[i-1][j] && !lava[i-1][j]) {
		percorre(i-1,j);
	}
	if(j > 0 && F+'0'>=mat[i][j-1] && !lava[i][j-1]){
		percorre(i,j-1);
	}
	if(j < N-1 && F+'0'>=mat[i][j+1] && !lava[i][j+1]){
		percorre(i,j+1);	
	}
	if(i < N-1 && F+'0'>=mat[i+1][j] && !lava[i+1][j]){
		percorre(i+1,j);
	}

	return 0;
}

int main(){
	cin >> N >> F;
	
	for(int i = 0; i < N; i++){
		cin >> mat[i];
		
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			lava[i][j] = 0;
	}
	
	if(F+'0' >= mat[0][0]){
		percorre(0,0);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(lava[i][j] == 1)
				cout << "*";
			else
				cout << mat[i][j];
		}
		cout << "\n";
	}
	
	
	return 0;
}
