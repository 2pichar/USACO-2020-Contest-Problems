#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string text){
	vector<string> words;
	string current;
	for(int i = 0; i < text.length(); i++){
		if(text[i] == ' '){
			words.push_back(current);
			current = "";
		} else {
			current += text[i];
		}
	}
	return words;
}

int main(){
	ifstream ifile("word.in");
	ofstream ofile("word.out");
	string firstline;
	getline(ifile, firstline);
	vector<string> firstlineWords = split(firstline);
	int N = stoi(firstlineWords[0]);
	for(int i = 0; i < firstlineWords.size(); i++){
		cout << firstlineWords[i] << "\n";
	}
	string essay;
	getline(ifile, essay);
	vector<string> essayWords = split(essay);
	string cLine;
	string line;
	/*
	int tChars = 0;
	for(int i = 0; i < K; i++){
		if(tChars != K && tChars + essayWords[i].length() <= K){
			cLine += essayWords[i] + " ";
			tChars += essayWords[i].length();
		} else {
			vector<string> words = split(cLine);
			for(int i = 0; i < words.size(); i++){
				line += words[i];
				if(i != words.size()-1){
					line += " ";
				}
			}
			ofile << line << endl;
			tChars = 0;
			cLine = "";
		}
	}*/
}