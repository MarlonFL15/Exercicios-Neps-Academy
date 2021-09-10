#include<iostream>

#define MAX 1000

using namespace std;

string mapa[MAX];
int N, M;
bool check(int i, int j){
	if(i>0){
		if(mapa[i-1][j] == '.')
			return true;
	}
	else
		return true;
	if(i < N-1){
		if(mapa[i+1][j] == '.')
			return true;
	}
	else
		return true;
	if(j>0){
		if(mapa[i][j-1] == '.')
			return true;
	}
	else
		return true;
	if(j < M-1){
		if(mapa[i][j+1] == '.')
			return true;
	}
	else
		return true;
	return false;
}

int main(){
	
	int resp=0;
	cin >> N >> M;
	
	for(int i = 0; i < N ;i++){
		cin >> mapa[i];
		cin.ignore();
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(mapa[i][j] == '#'){
				if(check(i,j)){
					resp++;
				}
			}
		}
	}
	
	cout << resp;
	return 0;
}
