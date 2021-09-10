#include<iostream>
#include<map>

using namespace std;

int main(){
	int N,C;
	int input1, input2;
	cin >> N >> C;
	map<int,int> programs;
	map<int,int> att;
	
	for(int i = 0; i < N; i++){
		cin >> input1 >> input2;
		programs[input1] = input2;
	}
	
	for(int i = 0; i < C; i++){
		cin >> input1 >> input2;
		
		if(programs[input1] < input2){
			programs[input1] = input2;
			att[input1] = input2;	
		}
	}
	
	for(map<int,int>::iterator i = att.begin(); i != att.end(); i++){
		cout << i->first << " " << i->second << "\n";
	}
	
	return 0;
}
