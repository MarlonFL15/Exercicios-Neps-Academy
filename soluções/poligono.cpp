#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n, input;
	vector<int> palitos;
	int resp=0;
	cin >> n;
	int soma[n+1];
	for(int i = 0; i < n; i++){
		cin >> input;
		palitos.push_back(input);
	}
	sort(palitos.begin(), palitos.end());
	
	for(int i = 0; i < n; i++){
		if(i==0)
			soma[i] = palitos[i];
		else
			soma[i] = palitos[i]+soma[i-1];
		//cout << soma[i] << " ";
	}
	
	for(int i = n-1;i>=0; i--){
		if(soma[i]-palitos[i]>palitos[i]){
			resp = i;
			break;
		}
	}
	
	if(resp>1)
		cout << resp+1;
	else
		cout << 0;
	return 0;
}
