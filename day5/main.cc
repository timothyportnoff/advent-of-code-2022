#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <deque>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

void die(string s = "BAD INPUT!") {
	cout << s << endl;
	exit(1);
}

int main(int argc, char** argv) {
	cout << "Day 5: Supply Stacks" << endl;
	string s, s1, s2, s3, s4;
	int count = 0, to = 0, from = 0, total_stacks = 9;
	stack<char> stacks[9];
	deque<char> deques[9];
	fstream ins("input");

	//Read the initial crate stacks
	while (ins) {
		int column = 0;
		//Grab the line to parse by stringstream
		getline(ins, s);
		if (s == "") break;
		stringstream sts(s);

		//Read 4 characters as a time through the stringstream
		while (sts) {
			char c[4];
			//Grab the characters
			for (int i = 0; i < 4; i++) {
				c[i] = sts.get();
			}
			//Add the characters to our deque. If there's something in [0], then add whatever's in [1]
			if (c[0] != ' ') {
				deques[column].push_back(c[1]);
				//cout << "Pushing back " << c[1] << " to deque at column " << column << endl;
			}
			//Print out our crate stacks
			for (int i = 0; i < 4; i++) {
				cout << c[i] << flush;
			}
			column++;
		}
		cout << endl;
	}

	//Read control commands
	while (ins) {
		ins >> s >> count;//Read COUNT
		ins >> s >> from;//Read FROM
		ins >> s >> to;//Read TO

		//cout << count << " " << from << " " << to << " " << endl;

		for (int i = 0; i < count; i++) {
			cout << "FROM: " << from << endl;
			int crate = deques[from].front();
			//deques[to].push_front(crate);
			//deques[from].pop_front();
		}
	}

	//cout << "Total Complete Overlaps: " << << endl; 
	//cout << "Total Partial Overlaps: " << << endl; 
	return 0;
}
