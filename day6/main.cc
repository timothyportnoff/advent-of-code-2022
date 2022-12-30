#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

void die(std::string s = "BAD INPUT!") {
	cout << s << endl;
	exit(1);
}

bool is_unique (char c [4]) {
	return ((c[0] != c[1]) && (c[1] != c[2]) && (c[2] != c[3]) && (c[0] != c[2]) && (c[0] != c[3]) && (c[1] != c[3]));
}

int main(int argc, char** argv) {
	cout << "Day 6: Tuning Trouble" << endl;
	string s, s1, s2, s3, s4;
	int marker = 4;
	std::fstream ins("input");

	//Read the initial crate stacks
	while (ins) {
		//Grab the line to parse by stringstream
		getline(ins, s);
		if (!ins) break;
		std::stringstream sts(s);

		//Read 4 characters  initially
		char c[4];
		for (int i = 0; i < 4; i++) c[i] = sts.get();
		while (sts) {
			//Shift the characters
			c[0] = c[1];
			c[1] = c[2];
			c[2] = c[3];
			//Grab the next character
			c[3] = sts.get();
			if (!sts) break;
			marker++;
			//Print out our four characters
			for (int i = 0; i < 4; i++) cout << c[i];
			cout << endl;
			//check to see if the character array is unique
			if (is_unique(c)) { break; }
		}
		cout << endl;
	}

	cout << "Marker: " << marker << endl;
	return 0;
}
