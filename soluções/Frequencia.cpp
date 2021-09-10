#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 100001

using namespace std;

int vetor[MAX];

int main(){
	int N,input;
	int resp = 0;
	cin >> N;
	vector<int> vetor;
	
	for(int i = 0; i < N; i++){
		cin >> input;
		vetor.push_back(input);
		
	}
	
	sort(vetor.begin(), vetor.end());
	
	for(int i = 0; i < N; i++){
		if(i == 0 || vetor[i] != vetor[i-1])
			resp++;
	}
	
	cout << resp;
	return 0;
}
