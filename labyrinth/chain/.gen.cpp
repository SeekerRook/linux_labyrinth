#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string input;
	char in;
	do {
	in = getchar();
	input += in;
	}while(in != '%');
	

	cout << input;
}
