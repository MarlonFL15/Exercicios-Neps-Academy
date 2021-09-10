#include<iostream>

#define MAX 1001

using namespace std;

int s1[MAX], s2[MAX];
int dp[MAX][MAX];
int N,M;

int lsb(int a, int b){
	if(dp[a][b] != -1)
		return dp[a][b];
	if(a == 0 || b == 0)
		return dp[a][b] = 0;
	
	if(s1[a] == s2[b])
		return dp[a][b] = 1+lsb(a-1,b-1);
	else{
		return dp[a][b] = max(lsb(a,b-1), lsb(a-1,b));
	}	
}

int main(){
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		cin >> s1[i];
	}
	
	for(int i = 1; i <= M; i++){
		cin >> s2[i];
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			dp[i][j] = -1;
		}
	}
	
	int resp = lsb(N,M);
	
	cout << N - resp << " " << M-resp;
	
	return 0;
}
