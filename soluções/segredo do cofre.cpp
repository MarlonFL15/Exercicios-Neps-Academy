#include<iostream>

#define MAX 100001

using namespace std;

int N,M;
int barra[MAX];
int arv[MAX*4];

int resp[10] = {0};

void create(int no, int i, int j){
	if(i == j){
		arv[no] = 0;
	}
	else{
		int left, right, middle;
		left = no*2;
		right = no*2+1;
		middle = (i+j)/2;
		
		create(left,i,middle);
		create(right,middle+1,j);
		
		arv[no] = 0;
		
	}
}

void update(int no, int i, int j, int a, int b){
	
	if(i>=a && j<=b){
		arv[no]++;
		return;
	}
	if(i > b || j < a)
		return;
	else{
		int left,right,middle;
		left = no*2;
		right = no*2+1;
		middle = (i+j)/2;
		
		update(left,i,middle,a,b);
		update(right,middle+1,j,a,b);
	}
	
}

int search(int no, int i, int j, int a){
	if(i == j)
		return arv[no];
	else{
		int left,right, middle;
		middle = (i+j)/2;
		left = no*2;
		right = no*2+1;
		
		if(middle >= a)
			return arv[no]+search(left,i,middle,a);
		else
			return arv[no]+search(right,middle+1,j,a);
	}
}
int main(){
	int ult=1,pen=-1;
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		cin >> barra[i];
	}	
	
	create(1,1,N);
	update(1,1,N,1,1);
	
	for(int i = 1; i <= M; i++){
		pen = ult;
		cin >> ult;
		
		if(pen == ult){
			continue;
		}
	
		if(pen > ult){
			update(1,1,N,ult,pen-1);
			
		}
		else{
			update(1,1,N,pen+1,ult);
			
		
		}
		
	}	

	for(int i = 1; i <= N; i++){
		resp[barra[i]] += search(1,1,N,i);
	}
	
	for(int i = 0; i < 10; i++)
		cout << resp[i] << " ";
	cout << endl;
	return 0;
}


