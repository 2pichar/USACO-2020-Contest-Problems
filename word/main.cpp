#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string const &text, char const &delim){
	vector<string> words;
	string cWord;
	char empty = ""[0];
	char letter;
	if(delim == empty){
		for(int i = 0; i < text.length(); i++){
			letter = text[i];
			cWord += letter;
			words.push_back(cWord);
			cWord = "";
		}
	} else {
		for(int i = 0; i < text.length(); i++){
			letter = text[i];
			if(letter != delim){
				cWord += letter;
				
			} else {
				words.push_back(cWord);
				cWord = "";
			}
		}
		words.push_back(cWord);
	}
	return words;
}

string readfile(string const &file){
	ifstream ifs(file, ios::in);
	string text;
	string ct;
	while(!ifs.eof()){
		getline(ifs, ct);
		text += ct + '\n';
	}
	ifs.close();
	return text;
}

void output(int &tChars, string &cLine);

int main(){
	string text = readfile("word.in");
	vector<string> lines;
	vector<string> firstlineWords;
	vector<string> essayWords;
	lines = split(text, '\n');
	firstlineWords = split(lines[0], ' ');
	int N = stoi(firstlineWords[0]);
	int K = stoi(firstlineWords[1]);
	essayWords = split(lines[1], ' ');
	string cLine;
	int tChars = 0;
	for(int i = 0; i < N; i++){
		if(tChars < K && tChars + essayWords[i].length() <= K){
			cLine += essayWords[i] + " ";
			tChars += essayWords[i].length();
			if(tChars == K || (tChars + essayWords[i+1].length()) > K){
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

void output(int &tChars, string &cLine){
	ofstream ofile("word.out", ofstream::app);
	string line;
	vector<string> words = split(cLine, ' ');
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