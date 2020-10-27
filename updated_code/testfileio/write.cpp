#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream myFile;
    myFile.open("info.txt", fstream::app);
    myFile << "\nhello "
           << "world";
    return 0;
}