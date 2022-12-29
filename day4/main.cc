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

bool is_complete_overlap (int n1, int n2, int n3, int n4) {
	//if first set is within second set
	if (n1 >= n3 && n2 <= n4) return 1;
	//if second set is within first set
	if (n3 >= n1 && n4 <= n2) return 1;
	return 0;
}

bool is_partial_overlap (int n1, int n2, int n3, int n4) {
	if (n1 >= n3 && n1 <= n4) return 1;
	if (n2 >= n3 && n2 <= n4) return 1;
	if (n3 >= n1 && n3 <= n2) return 1;
	if (n4 >= n1 && n4 <= n2) return 1;
	return 0;
}

int main(int argc, char** argv) {
	cout << "Day 4: Camp Cleanup" << endl;
	string s1, s2, s3, s4;
	int n1, n2, n3, n4, partial_overlap = 0, complete_overlap = 0;
	fstream ins("input");
	while (ins) {
		getline(ins, s1, '-');
		if (!ins) break;
		n1 = stoi(s1);
		getline(ins, s2, ',');
		if (!ins) break;
		n2 = stoi(s2);
		getline(ins, s3, '-');
		if (!ins) break;
		n3 = stoi(s3);
		getline(ins, s4);
		if (!ins) break;
		n4 = stoi(s4);
		if (is_complete_overlap(n1, n2, n3, n4)) complete_overlap++;
		if (is_partial_overlap(n1, n2, n3, n4)) partial_overlap++;
	}

	cout << "Total Complete Overlaps: " << complete_overlap << endl; 
	cout << "Total Partial Overlaps: " << partial_overlap << endl; 
	return 0;
}
