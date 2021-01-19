#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string text, char delim){
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

ifstream ifile("word.in");
ofstream ofile("word.out", ofstream::app);
string firstline;
vector<string> firstlineWords;
string essay;
vector<string> essayWords;

int main(){
	getline(ifile, firstline);
	firstlineWords = split(firstline, ' ');
	int N = stoi(firstlineWords[0]);
	int K = stoi(firstlineWords[1]);
	getline(ifile, essay);
	essayWords = split(essay, ' ');
	string cLine;
	string line;
	int tChars = 0;
	for(int i = 0; i < N; i++){
		if(tChars < K && tChars + essayWords[i].length() <= K){
			cLine += essayWords[i] + " ";
			tChars += essayWords[i].length();
			if(tChars == K || (tChars + essayWords[i+1].length()) > K){
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
				line = "";
			}
			if(i == N-1){
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
				line = "";
			}
		} else {
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
			line = "";
		}
	}
}