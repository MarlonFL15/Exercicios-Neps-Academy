#include<iostream>
#include<set>

using namespace std;

int main(){
	int N,input,resp=0;
	set<int> tacos;
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> input;
		
		if(tacos.find(input)==tacos.end()){
			resp+=2;
			tacos.insert(input);
		}
		else
			tacos.erase(input);
	}
	
	cout << resp;
	
	return 0;
}
