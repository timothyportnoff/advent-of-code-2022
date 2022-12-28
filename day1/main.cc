#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct Elf {
	vector<int> snacks;
	int total_calories = 0;
	void insert (int snack) {
		snacks.push_back(snack);
		total_calories += snack;
	}
};

int main(int argc, char** argv) {
	cout << "Elf calculator" << endl;
	vector <Elf> elves;
	fstream ins("input");
	while (ins) {
		Elf elf;
		int snack = 0;
		string s;
		while (true) {
			getline(ins, s);
			//cout << s << endl;
			if (s == "") break;
			snack = stoi(s);
			elf.insert(snack);
		}
		elves.push_back(elf);
	}
	cout << "Which elf the thickest of them all?" << endl;
	int max = 0;
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	for (auto &e : elves) {
		if (e.total_calories > max3) {
			max3 = e.total_calories;
			if (max3 > max2) {
				swap(max3,max2);
				if (max2 > max1) {
					swap(max2,max1);
				}
			}
		}
	}
	cout << "First thiccest carrying " << max1 << " calories." << endl;
	cout << "Second thiccest carrying " << max2 << " calories." << endl;
	cout << "Third thiccest carrying " << max3 << " calories." << endl;
	cout << "Total: " << max3 + max2 + max1 << " calories." << endl;

	return 0;
}
