#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

void connect( string word )
{    
    string base_URL = "http://";
    string search_URL = base_URL + word;
    ShellExecuteA(NULL, "open", search_URL.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

int main()
{
	string line;
	ifstream IPFile;
	int offset; 
	string search0 = "Default Gateway . . . . . . . . . : ";
	system("ipconfig > ip");

	// Create ipconfig lines to read from it.
	IPFile.open ("ip"); 
	if(IPFile.is_open())
 	{
    	while(!IPFile.eof())
    	{
 			getline(IPFile,line);
 		
 			// Gets the pointer to the position that ends the search0 array
 			if ((offset = line.find(search0, 0)) != string::npos)
 			{
 				// Delete all the characters of the line but the adress
 				line.erase(0,39);
 				cout << "Opening gateway [ "<<  line <<" ]." <<  endl;
				connect(line);
 				IPFile.close();
 				
 				// Delete file, only used for reading.
 				remove("ip");
 			}
 		}
	}
	return 0;
}

