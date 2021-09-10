#include<iostream>
#include<vector>

#define MAX 1001

using namespace std;

int amigos[MAX]={0};
vector<int> reuniao;
int N,M;
int qtd;
int input;
bool inf;
int total=1;
int infectado, nReuniao;
int main(){
	
	cin >> N >> M;
	cin >> infectado >> nReuniao;
	amigos[infectado] = 1;
	
	for(int d = 1; d <= M; d++){
		cin >> qtd;
		inf = false;
		reuniao.clear();
		
		for(int i = 0; i < qtd; i++){
			cin >> input;
			if(d < nReuniao)
				continue;	
			if(amigos[input] && !inf){
				//ele volta para infectar todos os outros
				inf=true;
				for(int j = 0; j < i; j++){
					amigos[reuniao[j]] = 1;
					total++;
				}
			}
			else if(!amigos[input] && !inf){
				reuniao.push_back(input);
			}
			else if(!amigos[input] && inf){
				amigos[input] = 1;
				total++;
			}
		}	
	}
	
	cout << total;
	return 0;
}
