//xref.cpp

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 입력에서 각 단어가 등장한 모든 행을 찾음
map<string, vector<int> > xref(
	istream& in,
	vector<string> find_words(const string&) = split)
{
	string line;
	int line_num = 0;
	map<string, vector<int> > ret;

	// 다음 행을 읽음
	while (getline(in, line)) {
		++line_num;

		// 입력한 행을 단어로 나눔.
		vector<string> words = find_words(line);
		// "Hello Hello Hello  
		
		//현재 행에 등장한 모든 단어를 저장
		for (vector<string>::const_iterator it = words.begin();
			it != words.end(); ++it) {
			ret[*it].push_back(line_num);
		}
	}
	return ret;
}

int main() {
	// 기본 인수인 split 함수를 사용하여 xref 함수를 호출
	map<string, vector<int>> ret = xref(cin);

	// 결과를 출력
	for (map<string, vector<int>>::const_iterator it = ret.begin();
		it != ret.end(); ++it) {
		// 단어를 출력
		cout << "\"" << it->first << "\" is on line(s): ";

		// 이어서 하나 이상의 행 번호를 출력
		vector<int>::const_iterator line_it = it -> second.begin();

		// 해당 단어가 등장한 첫 번째 행 번호를 출력
		cout << *line_it;
		++line_it;

		// 행 번호가 더 있으면 마저 출력
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
	}
}