#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

void reverseString(int n, ifstream& ifile);
int main(int argc, char *argv[])
{
	string file = argv[1];

	ifstream ifile;
	ifile.open(file.c_str());
	

	if(ifile.fail())
	{
		cout << "Invalid file name." << endl;
		return -1;
	}

	int n;
	ifile >> n;

	
	reverseString(n, ifile);

	ifile.close();

	return 0;

}

void reverseString(int n, ifstream& ifile)
{
	string a;
	
	

		while((!ifile.fail()) && (n > 0)){

			ifile >> a;

			reverseString(n, ifile);

			cout << a << " ";

			n--;
	}

		

	
}