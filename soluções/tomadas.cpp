#include<iostream>

using namespace std;

int main(){
	int a,b,c,d;
	
	cin >> a >> b >> c >> d;
	
	if(a > b && a > c && a > d)
		cout << a+(b-1)+(c-1)+(d-1);
	else if (b > c && b > d)
		cout << b + (a-1) + (c-1) + (d-1);
	else if(c > d)
		cout << c + (a-1)+(b-1)+(d-1);
	else
		cout << d + (a-1)+(b-1)+(c-1);
	
	
	return 0;
}
