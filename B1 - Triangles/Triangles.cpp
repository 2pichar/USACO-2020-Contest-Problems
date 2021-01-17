#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
	string file = argv[0];
	ifstream ifs(file + ".in.txt");
	ofstream ofs(file + ".out.txt", ofstream::app);
	string np;
	getline(ifs, np);
	int numPoints = stoi(np);
	vector<vector<int>> points;
	for(int i = 0; i < numPoints; i++){
		string point;
		getline(ifs, point);
	}
};