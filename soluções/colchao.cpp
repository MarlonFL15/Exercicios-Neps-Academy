#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int a,b,c;
	int h,l;
	int resp = 0;
	cin >> a >> b >> c;
	cin >> h >> l;
	
	if(max(a,b)<=max(h,l) && min(h,l) >= min(a,b))
		resp = 1;
	if(max(a,c)<=max(h,l) && min(h,l) >= min(a,c))
		resp = 1;
	if(max(c,b)<=max(h,l) && min(h,l) >= min(c,b))
		resp = 1;
		
	if(resp)
		cout << "S";
	else
		cout << "N";
		
	
	return 0;
}
