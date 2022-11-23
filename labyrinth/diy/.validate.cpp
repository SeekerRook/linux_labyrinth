#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv){
    char* h1 = argv[1];
    char* h2 = argv[2];
    if (strcmp(h1, h2) == 0 && (argv[3][0] == '7')){
        cout << "bu7\n";
    }
    else{
        if (strcmp(h1, h2) != 0) {
        cout << h1 << '\n';
        cout << h2 << '\n';}
        else
        cout << argv[3] << '\n';
    }
}