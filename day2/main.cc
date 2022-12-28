#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int point (char &c) {
	if (c == 'A' || c == 'X') return 1;
	if (c == 'B' || c == 'Y') return 2;
	if (c == 'C' || c == 'Z') return 3;
	cout << "BAD INPUT!" << endl;
	exit(1);
}

string convert (char &c) {
	if (c == 'A' || c == 'X') return "ROCK";
	if (c == 'B' || c == 'Y') return "PAPER";
	if (c == 'C' || c == 'Z') return "SCISSORS";
	cout << "BAD INPUT!" << endl;
	exit(1);
}

int battle (char &c, char &s) {
	//If our throws are the same
	if (convert(c) == convert(s)) return 3;
	//If we choose rock
	if (c == 'C' && s == 'X') return 6;
	if (c == 'B' && s == 'X') return 0;
	//If we choose paper
	if (c == 'A' && s == 'Y') return 6;
	if (c == 'C' && s == 'Y') return 0;
	//If we choose scissors
	if (c == 'B' && s == 'Z') return 6;
	if (c == 'A' && s == 'Z') return 0;
	cout << "BAD INPUT!" << endl;
	exit(1);
}

char calculate (char &c, char &s) {
	//If we need to lose
	if (c == 'A' && s == 'X') return 'Z';
	if (c == 'B' && s == 'X') return 'X';
	if (c == 'C' && s == 'X') return 'Y';
	//If we need to draw
	if (c == 'A' && s == 'Y') return 'X';
	if (c == 'B' && s == 'Y') return 'Y';
	if (c == 'C' && s == 'Y') return 'Z';
	//If we need to win
	if (c == 'A' && s == 'Z') return 'Y';
	if (c == 'B' && s == 'Z') return 'Z';
	if (c == 'C' && s == 'Z') return 'X';
	cout << "BAD INPUT!" << endl;
	exit(1);
}

//*****LEGEND*****
//A - X - ROCK
//B - Y - PAPER
//C - Z - SCISSORS
int main(int argc, char** argv) {
	cout << "Rock, Paper, Scissors!" << endl;
	fstream ins("input");
	int total_score = 0;
	while (ins) {
		char throw1;
		char throw2;
		ins >> throw1;
		if (!ins) break;
		ins >> throw2;
		if (!ins) break;
		int round_score = 0;
		throw2 = calculate(throw1, throw2); //Throw 2 compensation for the second part of the challenge
		round_score = point(throw2) + battle(throw1, throw2);
		total_score += round_score;
	}
	cout << "Total Score: " << total_score << endl;

	return 0;
}
