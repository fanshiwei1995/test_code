#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//********身高升序排列，最大能分为几组，使得每组内升序，保持总体升序******//

//int maxChunks(vector<int> arr) {
//	int len = arr.size();
//	int count = 1;
//
//	int leftMax = arr[0];
//	vector<int> rightMin(len, 0);
//	rightMin[len - 1] = arr[len - 1];
//
//	for (int i = len - 2; i >= 0; --i) {
//		rightMin[i] = min(arr[i], rightMin[i + 1]);
//	}
//
//	for (int i = 1; i < len; ++i) {
//		if (rightMin[i] >= leftMax) {
//			count++;
//			leftMax = arr[i];
//		}
//		else {
//			leftMax = max(arr[i], leftMax);
//		}
//	}
//	return count;
//}
//
//int main() {
//	int N;
//	cin >> N;
//	vector<int> H;
//	for (int i = 0; i < N; ++i) {
//		int h;
//		cin >> h;
//		H.push_back(h);
//	}
//	int count = maxChunks(H);
//	cout << count << endl;
//	getchar();
//	getchar();
//}


//**********华为8.7笔试第一题：字符：数字@字符：数字；减法操作************//

//struct WordSet {
//	char word;
//	int count;
//};
//int main(){
//	int input[] = { 0 };
//	int len = input.length();
//	vector<struct WordSet> wordset1;
//	vector<struct WordSet> wordset2;
//	bool flag = false;
//	bool swithSet = false;
//	struct WordSet wordpair;
//	wordpair.count = 0;
//	for (int i = 0; i<len; i++) {
//		char tmp = input[i];
//		char word;
//		if ((tmp <= 'Z' && tmp >= 'A') || (tmp <= 'z' && tmp >= 'a')) {
//			wordpair.word = tmp;
//		}
//		else if (tmp <= '9' && tmp >= '0') {
//			wordpair.count *= 10;
//			wordpair.count += tmp - '0';
//			if (i == len - 1)
//				flag = true;
//		}
//		else if (tmp == ',' || tmp == '@') {
//			flag = true;
//		}
//
//		if (flag) {
//			if (!swithSet) {  //set1
//				wordset1.push_back(wordpair);
//			}
//			else {    //set2
//				wordset2.push_back(wordpair);
//			}
//			//cout << wordpair.word << wordpair.count <<endl;
//			flag = false;
//			wordpair.count = 0;
//		}
//		if (tmp == '@') {
//			swithSet = true;
//		}
//
//	}
//
//	if (wordset2.empty()) {
//		cout << input.substr(0, len - 1) << endl;
//	}
//	else {
//		for (int i = 0; i<wordset1.size(); i++) {
//			for (auto it : wordset2) {
//				if (wordset1[i].word == it.word) {
//					wordset1[i].count -= it.count;
//					break;
//					//wordset2.erase(it);
//				}
//			}
//		}
//		for (int i = 0; i<wordset1.size(); i++) {
//			if (wordset1[i].count != 0)
//				cout << wordset1[i].word << ':' << wordset1[i].count;
//			if (i != wordset1.size() - 1)
//				cout << ',';
//
//		}
//	}
//}



//*********分考场的问题：两个熟悉同学不能在同一考场（没验证过）*********//

//#define N 301
//
//int gxb[N][N];//关系表 
//int p[N][N];// 房间状态  
//int num = N, n;
//int out[N];
//void DFS(int x, int kcs)//x 代表当前安排了多少个人 kcs 代表考场数
//{
//	if (kcs >= num)
//		return;//剪子 
//	if (x == n + 1) { 
//		num = min(num, kcs);
//		return;
//	}//如果已经安排了n个人，进行判断  
//	int j, k;
//	for (j = 1; j <= kcs; j++)//枚举考场
//	{
//		k = 0;
//		while (p[j][k] && !gxb[x][p[j][k]])
//			k++;//找到一个空位 并且与该考场人无关系 
//		if (p[j][k] == 0) {
//			p[j][k] = x;
//			DFS(x + 1, kcs);
//			p[j][k] = 0;//满足条件 进行下一考生 
//		}
//	}
//	p[j][0] = x;
//	DFS(x + 1, kcs + 1);// 如果所有房间都不满足条件 增加房间 
//	p[j][0] = 0;
//}



//***************滴滴，第二题:宝石兑换问题（不完全AC）************************//

//int main() {
//	int n, Total, cost;
//	cin >> n >> Total >> cost;
//	vector<int> A, B;
//	for (int i = 0; i < n; i++) {
//		int a;
//		cin >> a;
//		A.push_back(a);
//	}
//	for (int i = 0; i < n; i++) {
//		int b;
//		cin >> b;
//		B.push_back(b);
//	}
//	int baoshi_A = 0;
//	int i=0, j=0;
//	for (; i < n; i++) {
//		if (j == n)
//			break;
//		while (A[i] != B[j++] && j < n);
//		baoshi_A++;
//	}
//	i = 0;
//	j = 0;
//	int baoshi_B = 0;
//	for (; i < n; i++) {
//		if (j == n)
//			break;
//		while (B[i] != A[j++] && j < n);
//		baoshi_B++;
//	}
//	
//	cout << max(baoshi_A, baoshi_B) << endl;
//
//	getchar();
//	getchar();
//}



//****数组最长上升子序列问题**********//

//int main() {
//	int n;
//	cin >> n ;
//	vector<int> A;
//	for (int i = 0; i < n; ++i) {
//		int a;
//		cin >> a;
//		A.push_back(a);
//	}
//	vector<int> dp(n, 0);
//	int max_Len = 0;
//	for (int a : A) {
//		int low = 0, high = max_Len;
//		while (low < high) {
//			int mid = low + (high - low) / 2;
//			if (dp[mid] <= a)
//				low = mid + 1;
//			else
//				high = mid;
//		}
//		dp[low] = a;
//		if (low == max_Len)
//			max_Len++;
//	}
//	cout << max_Len << endl;
//
//	getchar();
//	getchar();
//}



//字符s串1与s2，s1删除若干字符后为s2，求其第一个元素的位置，下标从1开始，若不存在则返回0
//例子：s1:abcdacd      s2:ad      返回：5

//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	int size_1 = s1.length();
//	int size_2 = s2.length();
//	int max_idx = size_1;
//	int  i, j;
//	for (int j = size_2 - 1; j >= 0; --j) {
//		for (i = max_idx - 1; i >= 0; --i) {
//			if (s1[i] == s2[j]) {
//				max_idx = i;
//				break;
//			}
//		}
//
//	}
//	if (max_idx < 0)
//		max_idx = 0;
//	else
//		max_idx += 1;
//	cout << max_idx << endl;
//	getchar();
//	getchar();
//}