#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	if (!fin) {cout << "error file" << endl; return 1;}
	
	ofstream fout("output.txt");
	if (!fout) {cout << "error file" << endl; return 2;}
	
	string s;
	size_t point;
	
	while (fin >> s)
	{
		point = s.find("ab");
	
		while(point != string::npos)
		{
			s.replace(point, 2, "klm");
			point = s.find("ab");
		}
	
		fout << s << " ";
	}
	
	return 0;
}
