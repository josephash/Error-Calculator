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
		if ((i < str.length() - 1) && (str[i] == '%')) {
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
bool checkformat(string str) {
	string strtype;
	char type;
	int left = 0;
	int right = 0;
	string letterlist = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string oplist = "^*/+-";
	for (int i = 0; i < str.length(); i++) {
		type = '?';
		for (int k = 0; k < letterlist.length(); k++) {
			if (str[i] == letterlist[k]) {
				type = 'v';
			}
		}
		for (int k = 0; k < oplist.length(); k++) {
			if (str[i] == oplist[k]) {
				type = 'o';
			}
		}
		if (str[i] == '(') {
			type = '(';
			left++;
		}
		else if (str[i] == ')') {
			type = ')';
			right++;
		}
		else if (type == '?') {
			return false;
		}
		strtype.push_back(type);
	}
	if (left != right) {
		return false;
	}
	for (int i = 0; i < strtype.length(); i++) {
		if (i >= 1) {
			if (strtype[i] == 'v') {
				if (strtype[i - 1] == 'v') {
					return false;
				}
				else if (strtype[i - 1] == ')') {
					return false;
				}
			}
			else if (strtype[i] == 'o') {
				if (strtype[i - 1] == '(') {
					return false;
				}
				else if (strtype[i - 1] == 'o') {
					return false;
				}
			}
			else if (strtype[i] == '(') {
				if (strtype[i - 1] == ')') {
					return false;
				}
				else if (strtype[i - 1] == 'v') {
					return false;
				}
			}
			else if (strtype[i] == ')') {
				if (strtype[i - 1] == '(') {
					return false;
				}
				else if (strtype[i - 1] == 'o') {
					return false;
				}
			}
		}
		if (i < strtype.length() - 1) {
			if (strtype[i] == 'v') {
				if (strtype[i + 1] == 'v') {
					return false;
				}
				else if (strtype[i + 1] == '(') {
					return false;
				}
			}
			else if (strtype[i] == 'o') {
				if (strtype[i + 1] == ')') {
					return false;
				}
				else if (strtype[i + 1] == 'o') {
					return false;
				}
			}
			else if (strtype[i] == '(') {
				if (strtype[i + 1] == ')') {
					return false;
				}
				else if (strtype[i + 1] == 'o') {
					return false;
				}
			}
			else if (strtype[i] == ')') {
				if (strtype[i + 1] == '(') {
					return false;
				}
				else if (strtype[i + 1] == 'v') {
					return false;
				}
			}
		}
	}
	return true;
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
			else {
				return make_tuple(1, start, i - 1);
			}
		}
	}
	if (start == -1) {
		return make_tuple(0, 0, 0);
	}
	else {
		return make_tuple(-1, 0, 0);
	}
}
int scan(string inp) {
	if (inp.find("^") != -1) {
		return inp.find("^");
	}
	else if ((inp.find("*") != -1) || (inp.find("/") != -1)) {
		if ((inp.find("*") != -1) && (inp.find("/") != -1)) {
			if (inp.find("*") < inp.find("/")) {
				return inp.find("*");
			}
			else {
				return inp.find("/");
			}
		}
		else if (inp.find("*") != -1) {
			return inp.find("*");
		}
		else if (inp.find("/") != -1) {
			return inp.find("/");
		}
	}
	else if ((inp.find("+") != -1) || (inp.find("-") != -1)) {
		if ((inp.find("+") != -1) && (inp.find("-") != -1)) {
			if (inp.find("+") < inp.find("-")) {
				return inp.find("+");
			}
			else {
				return inp.find("-");
			}
		}
		else if (inp.find("+") != -1) {
			return inp.find("+");
		}
		else if (inp.find("-") != -1) {
			return inp.find("-");
		}
	}
	else {
		return -1;
	}
}
string calc(string str, int index, vector<tuple<char, float, float, bool>> &key) {
	string sub = str.substr(index - 1, 3);
	string newstr;
	tuple<char, float, float, bool> l1;
	tuple<char, float, float, bool> l2;
	tuple<char, float, float, bool> l3;
	char newkey;
	bool found;
	for (int i = 0; i < key.size(); i++) {
		if (get<0>(key[i]) == sub[0]) {
			l1 = key[i];
		}
		if (get<0>(key[i]) == sub[2]) {
			l2 = key[i];
		}
	}
	if ((sub[1] == '^') || (sub[1] == '*') || (sub[1] == '/')) {
		if (get<3>(l1) == false) {
			get<2>(l1) = abs(100 * get<2>(l1) / get<1>(l1));
			get<3>(l1) = true;
		}
		if (get<3>(l2) == false) {
			get<2>(l2) = abs(100 * get<2>(l2) / get<1>(l2));
			get<3>(l2) = true;
		}
	}
	else if ((sub[1] == '+') || (sub[1] == '-')) {
		if (get<3>(l1) == true) {
			get<2>(l1) = abs(get<2>(l1) * get<1>(l1) / 100);
			get<3>(l1) = false;
		}
		if (get<3>(l2) == true) {
			get<2>(l2) = abs(get<2>(l2) * get<1>(l2) / 100);
			get<3>(l2) = false;
		}
	}
	for (char x = 97; x <= 122; x++) {
		found = false;
		for (int i = 0; i < key.size(); i++) {
			if (get<0>(key[i]) == x) {
				found = true;
			}
		}
		if (found == false) {
			newkey = (char)x;
			break;
		}
	}
	if (sub[1] == '^') {
		l3 = make_tuple(newkey, pow(get<1>(l1), get<1>(l2)), get<2>(l1) * get<1>(l2), true);
	}
	else if (sub[1] == '*') {
		l3 = make_tuple(newkey, get<1>(l1) * get<1>(l2), get<2>(l1) + get<2>(l2), true);
	}
	else if (sub[1] == '/') {
		l3 = make_tuple(newkey, get<1>(l1) / get<1>(l2), get<2>(l1) + get<2>(l2), true);
	}
	else if (sub[1] == '+') {
		l3 = make_tuple(newkey, get<1>(l1) + get<1>(l2), get<2>(l1) + get<2>(l2), false);
	}
	else if (sub[1] == '-') {
		l3 = make_tuple(newkey, get<1>(l1) - get<1>(l2), get<2>(l1) + get<2>(l2), false);
	}
	key.push_back(l3);
	//cout << "---" << endl;
	//cout << str << endl;
	//cout << sub << endl;
	//cout << str.substr(0, index - 1);
	//cout << newkey;
	//cout << str.substr(index + 2, str.length() - index - 2) << endl;
	//cout << "---" << endl;
	newstr = str.substr(0, index - 1) + newkey + str.substr(index + 2, str.length() - index - 1);
	return newstr;
}

void test() {
	string s = "9.321.02";
	cout << stof(s) << endl << endl << endl;
}

int main() {
	//test();

	string input;
	string value1;
	string value2;
	bool percent;
	string done;
	vector<tuple<char, float, float, bool>> values;
	int status, start, end;
	string subinput;
	bool opdone = false;
	int nextop;
	float answer;
	float answererror;

	cout << "(No numbers, only these symbols: +, -, *, /, ^, (, ), A, B, C...)\nEnter error problem:\n";
	getline(cin, input);
	input = excludeletters(input, " ");
	string badletters = checkletters(input, "+-*/^() ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	if (checkformat(input) == false) {
		badletters = "check formatting";
	}
	while (badletters.length() > 0) {
		cout << "Invalid input: " << badletters << endl << endl
			<< "(No numbers, only these symbols: +, -, *, /, ^, (, ), A, B, C...)\nEnter error problem:\n";
		getline(cin, input);
		input = excludeletters(input, " ");
		badletters = checkletters(input, "+-*/^() ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		if (checkformat(input) == false) {
			badletters = "check formatting";
		}
	}
	for (int i = 0; i < input.length(); i++) {
		if ((((char)input[i] >= 65) && ((char)input[i] <= 90)) || (((char)input[i] >= 97) && ((char)input[i] <= 122))) {
			if (((char)input[i] >= 97) && ((char)input[i] <= 122)) {
				input[i] = (char)input[i] - 32;
			}
			if (done.find(input[i]) == -1) {
				cout << input[i] << " = ";
				cin >> value1;
				badletters = checkletters(value1, "1234567890.-");
				badletters.append(checkfloat(value1));
				while (badletters.length() > 0) {
					cout << "Invalid input: " << badletters << endl << endl
						<< input[i] << " = ";
					cin >> value1;
					badletters = checkletters(input, "1234567890.-");
					badletters.append(checkfloat(value1));
				}
				cout << input[i] << " error (ex. 42, 3.5%) = ";
				cin >> value2;
				badletters = checkletters(value2, "1234567890.%");
				badletters.append(checkfloat(value2, true));
				while (badletters.length() > 0) {
					cout << "Invalid input: " << badletters << endl << endl
						<< input[i] << " = ";
					cin >> value2;
					badletters = checkletters(input, "1234567890.-");
					badletters.append(checkfloat(value2, true));
				}
				if (value2[value2.length() - 1] == '%') {
					percent = true;
				}
				else {
					percent = false;
				}
				done.push_back((char)input[i]);
				values.push_back(make_tuple((char)input[i], stof(value1), stof(value2), percent));
			}
		}
	}
	while (get<0>(parenthesis(input)) == 1) {
		//cout << input << endl;
		//cout << "1\n";
		tie(status, start, end) = parenthesis(input);
		subinput = input.substr(start, end - start + 1);
		//cout << subinput << endl;
		while (scan(subinput) != -1) {
			//cout << "2\n";
			nextop = scan(subinput);
			subinput = calc(subinput, nextop, values);
		}
		input = input.substr(0, start - 1) + subinput + input.substr(end + 2, input.length() - end - 2);
	}
	while (scan(input) != -1) {
		//cout << "3\n";
		nextop = scan(input);
		input = calc(input, nextop, values);
	}
	//cout << input << endl;
	for (int i = 0; i < values.size(); i++) {
		if (get<0>(values[i]) == input[0]) {
			answer = get<1>(values[i]);
			if (get<3>(values[i]) == true) {
				answererror = get<1>(values[i]) * get<2>(values[i]) / 100;
			}
			else {
				answererror = get<2>(values[i]);
			}
		}
	}
	cout << endl << "Result: " << answer << " +-" << answererror << endl;
	string placeholder;
	cin >> placeholder;
}