#include <iostream>
#include <windows.h>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

string excludeletters(string str, string format = "") {
	string newstr = "";
	for (int i = 0; i < str.length(); i++)
    {
		bool match = false;
		for (int x = 0; x < format.length(); x++) {
			if (str[i] == format[x])
			{
				match = true;
			}
		}
		if (match == false) {
			newstr.push_back(str[i]);
		}
    }
	return newstr;
}
string checkletters(string str, string include = "") {
	string badletters = "";
	for (int i = 0; i < str.length(); i++) {
		bool isletter = false;
		for (int x = 0; x < include.length(); x++) {
			if (str[i] == include[x]) {
				isletter = true;
			}
		}
		if (isletter == false) {
			badletters.push_back(str[i]);
		}
	}
	return badletters;
}
string checkfloat(string str, bool percent = false) {
	string badchar = "";
	string good = "1234567890.-";
	int p;
	if (percent == true) {
		p = 0;
	}
	else {
		p = 1;
	}
	bool dot = false;
	for (int i = 0; i < str.length(); i++) {
		bool isgood = false;
		for (int x = 0; x < good.length(); x++) {
			if (str[i] == good[x]) {
				isgood = true;
			}
		}
		if (isgood = false) {
			badchar.push_back(str[i]);
		}
		if ((i >= p) && (str[i] == '-')) {
			badchar.push_back(str[i]);
		}
		if ((i >= ) && (str[i] == '-')) {				// HERE
			badchar.push_back(str[i]);
		}
		if (str[i] == '.') {
			if (dot == true) {
				badchar.push_back(str[i]);
			}
			else {
				dot = true;
			}
		}
	}
	return badchar;
}
tuple<int, int, int> parenthesis(string inp) {
	int start = -1;
	for (int i = 0; i < inp.length(); i++) {
		if (inp[i] == '(') {
			start = i + 1;
		}
		if (inp[i] == ')') {
			if (start == -1) {
				return make_tuple(-1, 0, 0);
			}
			return make_tuple(1, start, i - 1);
		}
	}
}/*
tuple<int, int, int> scan(string inp) {
	for (int i = 0; i < inp.length(); i++) {
		if (inp[i] == '^') {
			//scan for terms ahead and behind. ex: A^B
		}
	}
}*/

void test() {
	string s = "9.321.02";
	cout << stof(s) << endl << endl << endl;
}

int main() {
	test();

	string input;
	float value1;
	string value1s;
	float value2;
	string value2s;
	bool percent;
	vector<tuple<char, float, float, bool>> values;

	cout << "(No numbers, only these symbols: +, -, *, /, ^, (, ), A, B, C...)\nEnter error problem:\n";
	getline(cin, input);
	string badletters = checkletters(input, "+-*/^() ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	while (badletters.length() > 0) {
		cout << "Input invalid - found unwanted characters: " << badletters << endl << endl
			<< "(No numbers, only these symbols: +, -, *, /, ^, (, ), A, B, C...)\nEnter error problem:\n";
		getline(cin, input);
		badletters = checkletters(input, "+-*/^() ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	}
	input = excludeletters(input, " ");
	for (int i = 0; i < input.length(); i++) {
		if ((((char)input[i] >= 65) && ((char)input[i] <= 90)) || (((char)input[i] >= 97) && ((char)input[i] <= 122))) {
			cout << input[i] << " = ";
			cin >> value1s;
			string badletters = checkletters(value1s, "1234567890.-");
			badletters.append(checkfloat(value1s));
			while (badletters.length() > 0) {
				cout << "Input invalid - found unwanted characters: " << badletters << endl << endl
					<< "(No letters or commas, only numbers and '.' )\n" << input[i] << " = ";
				cin >> value1s;
				badletters = checkletters(input, "1234567890.-");
				badletters.append(checkfloat(value1s));
			}
			cout << input[i] << " error = ";
			cin >> value2s;
			string badletters = checkletters(value2s, "1234567890.%");
			badletters.append(checkfloat(value2s));
			while (badletters.length() > 0) {
				cout << "Input invalid - found unwanted characters: " << badletters << endl << endl
					<< "(No letters or commas, only numbers and '.' )\n" << input[i] << " = ";
				cin >> value1s;
				badletters = checkletters(input, "1234567890.-");
				badletters.append(checkfloat(value1s));
			}
			values.push_back(make_tuple((char)input[i], value1, value2, percent));
		}
	}
	int status, start, end;
	tie(status, start, end) = parenthesis(input);
	for (int i = start; i <= end; i++) {
		cout << input[i];
		//find and resolve ^
		//find and resolve * /
		//find and resolve + -
		//remember to convert between percent and number
	}
	//(), ^, * /, + -
}