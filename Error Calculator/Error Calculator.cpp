#include <iostream>
#include <windows.h>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

string removestr(string str) {
	for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.erase(str.begin() + i);
            i--;
        }
    }
	return str;
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
			return make_tuple(1, (int)start, i - 1);
		}
	}
}/*
tuple<int, int, int> findoperator(string inp) {
	for (int i = 0; i < inp.length(); i++) {
		if (inp[i] == '^') {
			//scan for terms ahead and behind. ex: A^B
		}
	}
}*/

int main() {
	string input;
	float value1;
	float value2;
	vector<tuple<char, float, float>> values;
	cout << "(symbols: +, -, *, /, ^, (, ), A, B, C...)\nEnter error problem:\n";
	cin >> input;
	cout << removestr(input);
	for (int i = 0; i < input.length(); i++) {
		if ((((char)input[i] >= 65) && ((char)input[i] <= 90)) || (((char)input[i] >= 97) && ((char)input[i] <= 122))) {
			cout << input[i] << " = ";
			cin >> value1;
			cout << input[i] << " error = ";
			cin >> value2;
			values.push_back(make_tuple((char)input[i], value1, value2));
		}
	}
	int status, start, end;
	tie(status, start, end) = parenthesis(input);
	for (int i = start; i <= end; i++) {
		cout << input[i];
		//find and resolve ^
		//find and resolve */
		//find and resolve +-
		//remember to convert between percent and number
	}
	//(), ^, * /, + -
}