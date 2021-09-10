#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N,S;
	vector<pair<int,int> > intervalo;
	vector<pair<int,int> > resp;
	int input1, input2;
	int last=0;
	cin >> N >> S;
	
	for(int i = 0; i < S; i++){
		cin >> input1 >> input2;
		intervalo.push_back(make_pair(input1, input2));
	}
	
	sort(intervalo.begin(), intervalo.end());
	resp.push_back(intervalo[0]);
	
	for(int i = 1; i < S; i++){
		if(intervalo[i].first <= resp[last].second)
			resp[last].second = max(intervalo[i].second,resp[last].second);
		else{
			resp.push_back(intervalo[i]);
			last++;
		}
	}
	
	for(int i = 0 ; i < last+1; i++){
		cout << resp[i].first << " " << resp[i].second << "\n";
	}
	
	return 0;
}
