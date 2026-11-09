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
	int count = 0;
	
	while (fin >> s)
		if (s[0] == 'a' && s[s.size() - 1] == 'a')
			count++;
		
	fout << count << endl;
	
	return 0;
}
