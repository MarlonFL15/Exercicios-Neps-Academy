#include<iostream>

using namespace std;

int main(){
	int n, a, b, c, d, e, f, g;
	
	cin >> n;
	
	cin >> a >> b >> c >> d >> e >> f >> g;
	
	if(a+b+c-d-e-f+g==n)
		cout << "N";
	else
		cout << "S";

	return 0;
}
