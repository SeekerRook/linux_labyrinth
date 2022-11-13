#include <iostream>
using namespace std;
int main(){

	char i;
	int count = 77;
	do{
		i = getchar();
		count ++;
	}while(i != '%');
	cout << count;
}
