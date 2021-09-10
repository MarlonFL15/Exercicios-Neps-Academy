#include<iostream>
#include<vector>

#define MAX 100001

using namespace std;

vector<int> pontes[MAX];

int find(int i1, int i2){
	for(int i = 0; i < pontes[i1].size(); i++){
		if(pontes[i1][i]==i2)
			return 1;
	}
	return 0;
}

int main(){
	int N, M;
	int type, i1, i2;
	cin >> N >> M;
	
	while(M--){
		cin >> type >> i1 >> i2;
		
		if(type){
			pontes[i1].push_back(i2);
			pontes[i2].push_back(i1);
		}
		else{
			cout << find(i1, i2) << "\n";
		}
	}
	
	return 0;
}
