#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

void die(string s = "BAD INPUT!") {
	cout << s << endl;
	exit(1);
}

char locate_discrepancy(string &s) {
	for (size_t i = 0; i < s.size()/2; i++) {
		for (size_t j = s.size()/2; j < s.size(); j++) {
			cout << "comparing " << s.at(i) << " with " << s.at(j) << endl;
			if (s.at(i) == s.at(j)) return s.at(i);
		}
	}
	//If we reach the end of our function, quit.
	die();
}

char locate_common(string &s1, string &s2, string &s3) {
	for (size_t i = 0; i < s1.size(); i++) {
		if (s2.find(s1.at(i)) != string::npos) {
			if (s3.find(s1.at(i)) != string::npos) {
				return s1.at(i);
			}
		}
	}
	//If we reach the end of our function, quit.
	die();
}

int point (char &c) {
	//azAZ
	if (c < 91) return (c - 38);
	else return (c - 96);
}

int main(int argc, char** argv) {
	cout << "Day 3: Rucksack Reorganization" << endl;
	string s1, s2, s3;
	int sum = 0;
	fstream ins("input");
	while (ins) {
		getline(ins, s1);
		if (!ins) break;
		getline(ins, s2);
		if (!ins) break;
		getline(ins, s3);
		if (!ins) break;
		char c = locate_common(s1, s2, s3);
		sum += point(c);
	}

	//Previous level 1 solution
	//while (ins) {
	//getline(ins, s);
	//if (!ins) break;
	//char c = locate_discrepancy(s);
	//sum += point(c);
	//}
	
	cout << "Discrepancy Total: " << sum << endl; 
	return 0;
}
