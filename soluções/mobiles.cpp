#include<iostream>
#include<vector>

#define MAX 100001

using namespace std;

int pecas[MAX] = {0};
vector<int> mobiles[MAX];
bool balanced = true;
int N;

int check(int x){
	int num;
	
	for(int i = 0; i < mobiles[x].size(); i++){
		if(i==0)
			num = pecas[mobiles[x][i]];
		else{
			if(num != pecas[mobiles[x][i]])
				return 0;
		}
	}
	return 1;
}

int dfs(int x){
	if(pecas[x] != 0)
		return pecas[x];
	if(mobiles[x].size()==0)
		return 1;
	else{
		int resp=0;
		for(int i = 0; i < mobiles[x].size(); i++){
			resp += dfs(mobiles[x][i]);
		}
		return pecas[x]=resp+1;
	}
}

int main(){
	int input1, input2;
	cin >> N;	
	
	for(int i = 0; i < N; i++){
		cin >> input1 >> input2;
		mobiles[input2].push_back(input1);
	}
	
	for(int i = 1; i <= N;i++){
		pecas[i] = dfs(i);
	}
	
	for(int i = 1; i <= N; i++){
		if(!check(i)){
			balanced = false;
			break;
		}
	}
	
	if(balanced)
		cout << "bem";
	else
		cout << "mal";
	return 0;
}
