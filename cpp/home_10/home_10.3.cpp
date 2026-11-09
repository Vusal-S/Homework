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
	int sum = 0, a;
	size_t pos;
	
	while (fin >> s)
	{
		try
		{
			a = stoi(s, &pos);
			if (pos != s.size()) continue;
		
			sum += a;
		}
		catch(...)	{continue;}
	}
	
	fout << sum << endl;
	
	return 0;
}
