#include<iostream>
#include<stdio.h>
#define MAX 500

using namespace std;

char array[MAX][MAX];
int N, M;

bool check();

int main(){
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			cin >> array[i][j];
	}	
	
	while(check()){};
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << array[i][j];
		}
		cout << "\n";
	}
	
		
	return 0;
}


bool check(){
	int calc = 0;
	bool change = false;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(array[i][j] == '.'){
				if(i-1 >= 0 && array[i-1][j] == 'o'){
					array[i][j] = 'o';
					change = true;
						
				}
				if(array[i][j-1] == 'o' && j-1 >= 0 && i < N-1 && array[i+1][j-1] == '#'){
					array[i][j] = 'o';
					change = true;
					
				}
				
				if(i+1 < N && j+1 < M && array[i][j+1]=='o' && array[i+1][j+1]=='#'){
					array[i][j] = 'o';
					change = true;
				}
					
				
			}
		}
	}
	return change;
}
