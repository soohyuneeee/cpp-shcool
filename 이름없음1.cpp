#include <iostream>
using namespace std;
int numlist[100];
int fibo(int n){
	if (n==1) numlist[1]=1;
	else if (n==2 )numlist[2]=1;
	else numlist[n]=numlist[n-1]+numlist[n-2];
	return numlist[n];
}
int main(){
	for(int i=1;i<=10;i++){
		cout<<i<<"¹ø¤Š Ç× : "<<fibo(i)<<endl;
	}
	return 0;
}

