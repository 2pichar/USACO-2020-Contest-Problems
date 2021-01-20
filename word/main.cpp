#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool isNotSpace(unsigned char ch) {
    return !isspace(ch);
}

void trim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), &isNotSpace).base(), s.end());
}

void saveAndWrapLines(const char *ifs, const char *ofs) {
    ifstream input(ifs, ios::in);
    ofstream output(ofs, ofstream::trunc);

    int numLines, colsPerLine;
    string line;
    string word;
    
    // first line has formatting settings
    input >> numLines;
    input >> colsPerLine;
    
    // clear the empty spaces in preparation to read the file
    getline(input, line);
    line.clear();

    // trying to make the variables more descriptive
    long totalChars = 0;
    for(int i = 0; i < numLines && getline(input, word, ' '); i++) {
        trim(word);
        if(totalChars < colsPerLine && totalChars + word.length() <= colsPerLine){
            totalChars += word.length();
        } else {
            output << line << endl;
            line.clear();
            totalChars = word.length();
        }
        
        if (!word.empty()) {
            line.append(word).append(" ");
        }
        
        word.clear();
    }
    if (!line.empty()) {
        output << line << endl;
    }
}

int main(){
    saveAndWrapLines("word.in", "word.out");
    return 0;
}