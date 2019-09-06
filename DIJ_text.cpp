#include <iostream>
#include <vector>
#include <algorithm>
#include <stddef.h>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	int num = 0;
	bool flag[10] = { 0 };
	for (size_t i = 0; i < len; i++) {
		int tmp = s[i] - '0';
		if (!flag[tmp]) {
			num *= 10;
			num += tmp;
		}
		flag[tmp] = true;
	}
	cout << num << endl;
	getchar();
	getchar();
}