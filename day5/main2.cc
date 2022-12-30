#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <deque>
using std::cout;
using std::endl;
using std::string;
constexpr int total_stacks = 9; //Constexpr so it works with our arrays

void die(std::string s = "BAD INPUT!") {
	cout << s << endl;
	exit(1);
}

//Prints our crates in a horizontal fashion. (Not sure if this starts printing with deque.front() or deque.back())
void print_crates(std::deque<char> crates [total_stacks]) {
	cout << "All Crates: " << endl;
	for (size_t i = 0; i < total_stacks; i++) {
		cout << "Stack " << i+1 << ":";
		for (size_t j = 0; j < crates[i].size(); j++) {
			cout << " [" << crates[i][j] << "]";
		}
		cout << endl;
	}
	
	cout << "Tops of Crates: " << endl;
	for (size_t i = 0; i < total_stacks; i++) {
		cout << crates[i].front();
	}
	cout << endl;
}

int main(int argc, char** argv) {
	cout << "Day 5: Supply Stacks" << endl;
	string s, s1, s2, s3, s4;
	int count = 0, to = 0, from = 0;
	std::deque<char> crates[total_stacks];
	std::fstream ins("input");

	//Read the initial crate stacks
	while (ins) {
		int column = 0;
		//Grab the line to parse by stringstream
		getline(ins, s);
		if (s == "") break;
		std::stringstream sts(s);

		//Read 4 characters as a time through the stringstream
		while (sts) {
			char c[4];
			//Grab the characters
			for (int i = 0; i < 4; i++) c[i] = sts.get();
			//Add the characters to our deque. If there's something in [0], then add whatever's in [1]
			if (c[0] != ' ') crates[column].push_back(c[1]);
			//Print out our crate stacks
			for (int i = 0; i < 4; i++) std::cout << c[i] << std::flush;
			column++;
		}
		cout << endl;
	}

	//Read control commands
	while (ins) {
		ins >> s >> count;//Read COUNT
		if (!ins) break;
		ins >> s >> from;//Read FROM
		if (!ins) break;
		ins >> s >> to;//Read TO
		if (!ins) break;

		std::deque<char> ordered_stack;
		for (int i = 0; i < count; i++) {
			char crate = crates[from-1].front();
			ordered_stack.push_back(crate);
			crates[from-1].pop_front();
		}
		for (int i = 0; i < count; i++) {
			char crate = ordered_stack.back();
			crates[to-1].push_front(crate);
			ordered_stack.pop_back();
		}
	}

	print_crates(crates);
	return 0;
}
