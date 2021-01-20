#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void split(string const &text, char const &delim, vector<string> &vect){
	vect = {};
	string cWord = "";
	char empty = ""[0];
	char letter = ""[0];
	if(delim == empty){
		for(int i = 0; i < text.length(); i++){
			letter = text[i];
			cWord += letter;
			vect.push_back(cWord);
			cWord = "";
		}
	} else {
		for(int i = 0; i < text.length(); i++){
			letter = text[i];
			if(letter != delim){
				cWord += letter;
				
			} else {
				vect.push_back(cWord);
				cWord = "";
			}
		}
		vect.push_back(cWord);
	}
}

void dumpfile(string const &file, string &out){
	ifstream ifs(file, ios::in);
	string text = "";
	string ct = "";
	while(!ifs.eof()){
		getline(ifs, ct);
		text += ct + '\n';
	}
	ifs.close();
	out = text;
}

void output(int &tChars, string &cLine){
	ofstream ofile("word.out", ofstream::app);
	string line = "";
	vector<string> words;
	split(cLine, ' ', words);
				for(int i = 0; i < words.size(); i++){
					line += words[i];
					if(i != words.size()-1){
						line += " ";
					}
				}
	ofile << line << endl;
	tChars = 0;
	cLine = "";
	ofile.close();
}

int main(){
	string text = "";
	dumpfile("word.in", text);
	vector<string> vect = {};
	split(text, '\n', vect);
	const string l1 = vect[0];
	const string l2 = vect[1];
	split(l1, ' ', vect);
	const int N = stoi(vect[0]);
	const int K  = stoi(vect[1]);
	split(l2, ' ', vect);
	string cLine = "";
	int tChars = 0;
	for(int i = 0; i < N; i++){
		if(tChars < K && tChars + vect[i].length() <= K){
			cLine += vect[i] + " ";
			tChars += vect[i].length();
			if(tChars == K || (tChars + vect[i+1].length()) > K){
				output(tChars, cLine);
			}
			if(i == N-1){
				output(tChars, cLine);
			}
		} else {
			output(tChars, cLine);
		}
	}
}