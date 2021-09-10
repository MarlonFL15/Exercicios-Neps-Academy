#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int N,K;
	int pontos;
	int time_atual=0;
	string nome;
	vector<pair<int, string> > nomes;
	
	cin >> N >> K;
	vector<string> vetor[K+1];
	
	for(int i = 0; i < N; i++){
		cin >> nome >> pontos;
		nomes.push_back(make_pair(pontos, nome));
	}
	
	sort(nomes.begin(), nomes.end());
	
	for(int i = N-1; i >= 0; i--){
		cout << "adicionou o nome " << nomes[i].second << "\n";
		if(time_atual==K){
			time_atual=0;
		}
		vetor[time_atual].push_back(nomes[i].second);
		time_atual++;
	}
	
	for(int i = 0; i < K; i++){
		cout << "Time " << i+1 << "\n";
		sort(vetor[i].begin(), vetor[i].end());
		for(int j = 0; j < vetor[i].size(); j++){
			cout << vetor[i][j] << "\n";
		}
		
		cout << "\n";
	}
}
