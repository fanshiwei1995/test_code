#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

string abbr(string s, int len) {
	if (len < 1)
		return NULL;
	char *tmp = (char *)malloc(sizeof(char) * len);
	memset(tmp, 0, len);
	int abbr_num = 0;
	int idx = 0;
	tmp[0] = s[0];
	for (int i = 1; i<len; i++) {
		if (s[i - 1] == s[i] - 1) {
			abbr_num++;
			if (abbr_num < 3)
				idx++;
		}
		else {
			abbr_num = 0;
			idx++;
		}

		if (abbr_num == 3) {
			tmp[idx - 1] = '-';
			tmp[idx] = s[i];
		}
		else {
			tmp[idx] = s[i];
		}
	}
	
	return tmp;
}

//int main() {
//	int T;
//	cin >> T;
//	if (T < 1 || T > 100)
//		return 0;
//	
//	for (int i = 0; i < T; i++) {
//		string s;
//		cin >> s;
//		int len = s.length();
//		string out = abbr(s, len);
//		cout << out << endl;
//		
//	}
//	getchar();
//	return 0;
//}

int main() {
	string data;
	vector<int> myData;
	while (getline(cin, data)) {
		int t;
		stringstream line(data);
		while (line >> t) {
			myData.push_back(t);
		}
	}
	for (int i = 0; i < myData.size(); i++) {
		cout << myData[i] << endl;
	}

	getchar();
	getchar();
}