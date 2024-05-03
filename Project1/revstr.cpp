//revstr.cpp

#include <iostream>
#include <string>

using namespace std;
void revstr(string& str, int start, int end) {
	if (start >= end) // ±âº» »ç·Ê
		return;

	char temp = str[start];
	str[start] = str[end];
	str[end] = temp;

	revstr(str, start + 1, end - 1);

}


int main() {
	string str;
	cout << "Enter a stirng: ";
	cin >> str;
	revstr(str, 0, str.length() - 1);
	cout << "Reversed string: " << str << endl;
	return 0;
}