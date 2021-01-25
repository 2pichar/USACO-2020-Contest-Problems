#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream ifs("word.in");
	ofstream ofs("word.out");
	int N = 0;
	int K = 0;
	ifs >> N;
	ifs >> K;
	string cWord = "";
	string cLine = "";
	for(int i = 0; i <= N; i++){
		ifs >> cWord;
		if((cLine + cWord).length() > K){
			ofs << cLine << endl;
			cLine = cWord + " ";
		} else if((cLine + cWord).length() == K){
			cLine += cWord;
			ofs << cLine << endl;
			cLine = "";
		} else {
			cLine += cWord + " ";
		}
	}
}