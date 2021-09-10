#include<iostream>
#include<algorithm>

using namespace std;

int dp[51][1001];
int qtd[51];
int len[51];
int N,F;
	
int calc(int i, int rest){
	
	if(i == N || rest == 0)
		return dp[i][rest] = 0;
	
	if(dp[i][rest] != -1)
		return dp[i][rest];
	
	else{
		if(len[i] <= rest)
			return dp[i][rest] = max(calc(i+1, rest-len[i])+qtd[i], calc(i+1, rest));
		else
			return dp[i][rest] = calc(i+1, rest);
	}
	
	
}
int main(){
	int cont = 0;
	do{
		cin >> F >> N;
		cont++;
		if(F == 0)
			break;
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j <= F; j++){
				dp[i][j] = -1;
			}
		}	
		
		for(int i = 0; i < N; i++){
			cin >> len[i] >> qtd[i];
		}	
		
		calc(0,F);
		cout << "Teste " << cont << endl << dp[0][F] << endl;
	}while(N != 0 || F != 0);
	
	return 0;
}
