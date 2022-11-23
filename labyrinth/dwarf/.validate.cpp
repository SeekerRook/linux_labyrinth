#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string read(string filename){
    string res;

	fstream my_file;
	my_file.open(filename, ios::in);
	if (!my_file) {
		exit(1);
	}
	else {
		string ch;
		while (1) {
			my_file >> ch;
			if (my_file.eof())
				break;

			res.append(ch) ;
		}

	}
	my_file.close();
	return res;

}



string run(string s){
    // string s = "diff wrong correct";
    s += "> i";
    char command[s.length() +1] ;
    strcpy(command,s.c_str());
    system (command);
    string res = read("i");
    string rm = "rm i";
    char rmc[rm.length() +1] ;
    strcpy(rmc,rm.c_str());
    system (rmc);  
    return res;
}
int main(){
    string res = run ("diff wrong correct > i");
    if (res  == ""){
        cout << "the files are the same\n";
        cout << "The flag is : \n L1nux\n";
    
    }
    else cout << "the files are not the same\n";
    
}
