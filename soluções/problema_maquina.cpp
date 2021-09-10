#include<iostream>
#include<cmath>

using namespace std;


int i1, i2, i3;
	

/*int simula(int i){
	int qtd=0;
	
	qtd+= (fabs(i-1)*i1)*2;
	qtd+= (fabs(i-2)*i2)*2;
	qtd+= (fabs(i-3)*i3)*2;
}
*/
int main(){
	cin >> i1;
	cin >> i2;
	cin >> i3;
	int resp=0;
	
	resp = i2*2 + i3*4;
	resp = min(resp, i1*2+i3*2);
	resp = min(resp, i1*3+i2*2);
	
	cout << resp;
	
	return 0;
}
