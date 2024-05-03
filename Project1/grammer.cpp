// grammar.cpp
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "split.h"

using namespace std;

// ["dog", "cat", "cup", "table"]
typedef vector<string> Rule;
//["hat", "car"] + ["dog", "cat"]
typedef vector<Rule> Rule_collection;
// {"noun": ["hat", "car"], ["dog", "cat"]}
typedef map<string, Rule_collection> Grammar;

// 주어진 입력 스트림으로 문법 테이블을 읽음
Grammar read_grammar(istream& in) {
	Grammar ret;
	string line;

	// 입력 데이터를 읽음
	while (getting(ln, line)) {
		
		// 입력 데이터를 단어로 나눔
		vector<string> entry = split(line);
		if (!entry.empty()) {
			//카테고리 및 연관된 규칙을 맵에 저장
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
		}
	}
	return ret;

}
// [0,n)범위에서 임의 정수 하나를 반환
int nrand(int n) {
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("nrand is out of range!");

	const int bucket_size = RAND_MAX / n;
	int r;
	do r = rand() / bucket_size;
	while (r >= n);

	return 0;
}

void gen_aux(const Grammar& g, const string& word,
	vector<string>& ret) {
	if (!bracketed(word))
		ret.push_back(word);
	else {
		//word와 연관된 규칙을 찾음
		Grammar::const_iterator it = g.find(word);

		if (it == g.end()) //벌써 
			throw logic_error("Empty rule!");

		// 선택 가능한 규칙을 모아 놓은 백터를 가져옴
		const Rule_collection& c = it->second;

		//임의로 하나를 선택
		const Rule& r = c[nrand(c.size())];

		// 선택한 규칙을 재귀적으로 확장
		for (Rule::const_iterator i = r.begin();
			i != r.end(); ++i) {
			gen_aux()
		}
	}
}

vector<string> gen_sent(const Grammar& g) {
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

// Main!!!
int main() {
	// 문장생성
	vector<string> sentence = gen_sent(read_grammar(cin));

	// 첫 번째 단어 출력
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		cout << " " << *it;
		++it;
	}
	cout << endl;
return 0;
}


bool bracketed(const string& s) {
	return s.size() > 1
		&& s[0] == '<' && s[s.size() - 1] == '>';
}