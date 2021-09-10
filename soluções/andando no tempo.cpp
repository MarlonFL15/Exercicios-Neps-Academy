#include<iostream>

using namespace std;

int main(){
	int a,b,c;
	
	cin >> a >> b >> c;
	
	if(a == b || b == c || c == a)
		cout << "S";
	else if(a+b == c || a+c == b || b+c == a){
		cout << "S";
	}
	else
		cout << "N";
	
	
	return 0;
}
