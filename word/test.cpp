#include <fstream>
#include <iostream>

using namespace std;

string readfile(string file){
	ifstream ifs(file, ios::in);
	string text;
	string ct;
	while(!ifs.eof()){
		getline(ifs, ct);
		text += ct + '\n';
	}
	return text;
}

int main(){
	string word = readfile("word.in");
	string text;
	ifstream ifs("word.in");
	getline(ifs, text);
	//cout << text << endl;
	getline(ifs, text);
	//cout << text;
	cout << word;
}