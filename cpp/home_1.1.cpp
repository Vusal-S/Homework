#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("1.txt");
	ofstream fout("2.txt");
	
	if(!fout){
		cout<<"File did not opened"<<endl;
		return 1;
		}
	
	if(!fin){
		cout<<"File did not opened"<<endl;
		return 2;
		} 
		 
	char name[50];
	char surname[50];
	char otchestvo[50];
	int year;
	double ball;
	while(fin>>surname>>name>>otchestvo>>year>>ball){
		fout<<surname<<" "<<name<<" "<<otchestvo<<" "<<year<<" "<<ball<<" "<<endl;
		
		}

	if(fin.eof()) cout<<"End of file"<<endl;
	else cout<<"Error"<<endl;
	
	fin.close();
	fout.close();
	return 0;
	} 