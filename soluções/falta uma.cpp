#include<iostream>

#define MAX 100

using namespace std;

int N;
int mat[MAX][MAX]=  {0};

int fatorial(int n){
	int resp = 1;
	for(int i = 2; i<= n; i++)
		resp*=i;
	return resp;
}

int main(){
	int input;
	int pivo;
	cin >> N;
	
	for(int i = 1; i <= N;i++){
		for(int j = 1; j <= N; j++)
			mat[i][j] = 0;
	}
	
	
	for(int i = 0; i < fatorial(N)-1; i++){
		for(int j = 1; j <= N; j++){
			cin >> input;
			mat[input][j]++;
		}
	}
	
	pivo = max(mat[1][1], mat[2][1]);
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(mat[j][i]<pivo){
				cout << j << " ";
				continue;
			}
			
		}
	}
}
