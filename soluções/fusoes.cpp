#include<iostream>

using namespace std;

#define MAX 100001

int bancos[MAX];

void create(int,int);
char select(int,int);
int find(int);

int main(){
	int N,K;
	char op;
	int input1, input2;
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++){
		bancos[i] = i;
	}
	
	while(K--){
		cin >> op >> input1 >> input2;
		
		if(op == 'F')
			create(input1, input2);
		else
			cout << select(input1, input2);
		
	}
	
	return 0;
}

int find(int x){
	if(bancos[x]==x)
		return x;
		
	return find(bancos[x]);
}

void create(int b1, int b2){
	int x = find(b1);
	int y = find(b2);
	bancos[y] = x;
}

char select(int b1, int b2){
	if(find(b1)==find(b2))
		return 'S';
	else
		return 'N';
}
