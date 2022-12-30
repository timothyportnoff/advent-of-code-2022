#include <set>
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

bool is_unique (char c [14]) {
	//create set
	std::set<char> setto;
	//Add characters to our set, if it contains it, return 0
	for (int i = 0; i < 14; i++) {
		if (setto.contains(c[i])) return 0;
		else setto.insert(c[i]);
	}
	//Else return 1
	return 1;
}

int main(int argc, char** argv) {
	cout << "Day 6: Tuning Trouble" << endl;
	string s, s1, s2, s3, s4;
	int marker = 14;
	std::fstream ins("input");
	//Read the initial crate stacks
	while (ins) {
		//Grab the line to parse by stringstream
		getline(ins, s);
		if (!ins) break;
		std::stringstream sts(s);
		//Read 4 characters  initially
		char c[14];
		for (int i = 0; i < 14; i++) c[i] = sts.get();
		while (sts) {
			//Shift the characters
			//Yes, I know this is disgusting and I should have created a function for it
			c[0] = c[1];
			c[1] = c[2];
			c[2] = c[3];
			c[3] = c[4];
			c[4] = c[5];
			c[5] = c[6];
			c[6] = c[7];
			c[7] = c[8];
			c[8] = c[9];
			c[9] = c[10];
			c[10] = c[11];
			c[11] = c[12];
			c[12] = c[13];
			//Grab the next character
			c[13] = sts.get();
			if (!sts) break;
			marker++;
			//Print out our four characters
			for (int i = 0; i < 14; i++) cout << c[i];
			cout << endl;
			//check to see if the character array is unique
			if (is_unique(c)) { break; }
		}
	}
	cout << "Marker: " << marker << endl;
	return 0;
}
