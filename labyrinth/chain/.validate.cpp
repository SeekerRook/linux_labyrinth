#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
int main(){
std::ifstream infile("out");
std::string line;
int count = 0;
while (std::getline(infile, line))
{	
    
    std::istringstream iss(line);
    int a, b;
    if (!(iss)) { break; } // e
    if (line.compare("I FOUND YOU IP ADDRESS"))

	count ++;

    //else std::cout << "---" << line << "---\n";
    // process pair (a,b)
}
if (count == 172)
	std::cout << "Well Done! The Flag is : \n Sys73ms \n";
}
