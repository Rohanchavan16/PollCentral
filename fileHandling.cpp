
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class FileWritting
{

public:
  
    void write(string fileName, string data);
    void appendNewLine(string fileName, string data);

};

// rewrite the whole file
void FileWritting::write(string fileName, string data)
{
    ofstream out(fileName);
    out << data;
    out.close();
}

// append a new line to the file
void FileWritting::appendNewLine(string fileName, string data)
{
    ofstream out(fileName, std::ios_base::app);
 
    out << data;
    out.close();
}



