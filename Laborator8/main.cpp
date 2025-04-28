#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <queue>
using namespace std;


map<string, int> m;
class compare {
public:
	bool operator()(string a, string b) {
		return m[a] < m[b];
	}
};

int main() {
	priority_queue<string, vector<string>, compare> p;
	string text;
	getline(cin, text);
	for (char& c : text) {
		c = tolower(c);
		if (c == '.')  c = ' ';
	}
	stringstream ss(text);
	string word;
	while (ss >> word) {
		m[word]++;
	}
	for (auto i : m) {
		p.push(i.first);
	}
	while (!p.empty()) {
		cout << p.top() << " => " << m[p.top()] << "\n";
		p.pop();
	}
	
	return 0;
}