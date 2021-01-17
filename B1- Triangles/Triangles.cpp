#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream ifs("1.in");
	ofstream ofs("1.out", ofstream::app);
	string line;
	getline(ifs, line);
};