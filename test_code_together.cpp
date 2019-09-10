#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string.h>

using namespace std;


//*******************************0-1背包问题，动态规划 构建表格+递归回溯！！！*****************************************//
//0-1背包问题，动态规划 构建表格+回溯！！！
//输入T个样例，每个样例有N个物品，背包容量为X,而后按行输入第i个物品的价值a和重量b；求所能装物品的最大价值，及物品号

//void findWhat(vector<vector<int> > &dp, vector<int> &item, vector<int> &w, vector<int> &v, int i, int j) {//最优解情况	
//	if (i > 0) {
//		if (dp[i][j] == dp[i - 1][j]) {
//			item[i] = 0;
//			findWhat(dp, item, w, v, i - 1, j);
//		}
//		else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
//			item[i] = 1;
//			findWhat(dp, item, w, v, i - 1, j - w[i]);
//		}
//	}
//}
//
//int main() {
//	int T;
//	cin >> T; 
//	for (int i = 0; i < T; i++) {
//		int N, X;
//		cin >> N >> X;
//		vector<int> A;
//		A.push_back(0);
//		vector<int> B;
//		B.push_back(0);
//		//按行输入各物品价值a和重量b
//		for (int j = 0; j < N; j++) {
//			int a, b;
//			cin >> a >> b;
//			A.push_back(a);
//			B.push_back(b);
//		}
//		int size = A.size();
//		vector< vector<int> > dp(size, vector<int>(X + 1, 0));
//		//构建表格
//		for (int m = 1; m < size; m++) {
//			for (int n = 1; n <= X; n++) {
//				if (n < B[m]) {
//					dp[m][n] = dp[m - 1][n];   //不装入第m个物品
//				}
//				else {
//					dp[m][n] = max(dp[m - 1][n], dp[m - 1][n - B[m]] + A[m]);
//				}
//			}
//		}
//		//动态规划表格输出(N * X)
//		for (int m = 1; m < size; m++) { //省略了第一行第一列(全0)
//			for (int n = 1; n <= X; n++) {
//				cout << dp[m][n] << ' ';
//			}
//			cout << endl;
//		}
//
//		//回溯法确定最优解情况(递归调用)
//		vector<int> item(size, 0);
//		findWhat(dp, item, B, A, N, X);  //从表格最后一个开始递归
//		//最优解输出
//		for (int k = 0; k < size; k++)
//			cout << item[k] << ' ';
//		cout << endl;
//	}
//
//	getchar();
//	getchar();
//}



//***********************************网易互娱模拟笔试******************************************************************//
//字符串缩写，连续升序的字母位数超过4位(>=4)则缩写
//例：ABCDEEFRGHIJKWW  ==》   A-EEFRG-KWW

//int main() {
//	string str;
//	cin >> str;
//	int len = str.length();
//	int pos = 0;
//	while (pos < len) {
//		int next;
//		//用两个下标数pos和next来进行字符串遍历：
//		//next来记录每段连续升序的字串的截至位置(+1),
//		//pos来记录每段连续升序的字串的开始位置,
//		//一旦连续升序超过4位(>=4)，则进行缩写: str[pos] << '-' << str[next - 1];
//		//否则，按顺序输出
//		for (next = pos + 1; next < len; ++next) {
//			if (str[next] != str[next - 1] + 1)
//				break;
//		}
//
//		if (next - pos >= 4) {
//			cout << str[pos] << '-' << str[next - 1];
//		}
//		else {
//			for (int i = pos; i < next; ++i)
//				cout << str[i];
//		}
//		pos = next;
//	}
//	cout << endl;
//	getchar();
//	getchar();
//}




//*************************************网易互娱模拟笔试****************************************************************//
//进制组合，缺少空格分割同一个数字的两种字符串表示方式，输入两种进制和一串数字，输出该数字的10进制表示形式。
//>> 5  2    
//>> 113221101000101     
//<< 837

//int main() {
//	int x, y; //分别代表x进制与y进制
//	cin >> x >> y;
//	string str;
//	cin >> str;
//	int len = str.length();
//	int a = 0, b = 0, k = 1;
//	//思路：从字符串两端向中间遍历，一位一位取数字，
//	//每取一位就比较当前x进制和y进制的两个数字大小
//	//如果x进制更小，就从头部取出一位数字加入x进制数字尾巴
//	//如果y进制更小，就从尾部取出一位数字加入y进制数字头部
//	//直到遍历完成，一定可以得出该数字
//	for (int i = 0, j = len - 1; i < j; ) {
//		if (a <= b) {
//			a = a * x + str[i++] - '0';  //x进制更小，从头部取出一位数字加入x进制数字尾
//		}
//		else {
//			b = b + (str[j--] - '0') * k; //y进制更小，从头部取出一位数字加入y进制数字头部
//			k *= y;                       //每次从头部加一位，得用k值来暂存进制权重值
//		}
//	}
//	cout << a << endl;
//
//	getchar();
//	getchar();
//}




//*************************************网易互娱2018笔试--电话号码归属地****************************************************************//
//前缀规则与电话号码 




//**************************************牛生小牛问题**********************************************************//
//一开始有1对牛，小牛成长x个月后可生一对小牛

//int getTotalCount(int init, int monthCount) {
//	int m4 = init, m3 = 0, m2 = 0, m1 = 0;
//	while (monthCount--) {
//		m4 += m3;
//		m3 = m2;
//		m2 = m1;
//		m1 = m4;
//	}
//	return m4 + m3 + m2 + m1;
//}
//
//int main() {
//	int N;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int init;
//		cin >> init;
//		int mon;
//		cin >> mon;
//		int number = getTotalCount(init, mon);
//		cout << number << endl;
//
//	}
//	getchar();
//	getchar();
//}


//**********************************华为2019.8.21笔试--找质数并求这些数十位数之和与个位数之和的最小值**********************************//

//vector<int> def_prms;  //先定义一个默认的素数数组
//bool isprime(int x)
//{
//	if (x <= 1)
//		return false;
//	else if (x == 2)
//		return true;
//	for (auto i : def_prms)
//	{
//		if (x % i == 0)
//			return false;
//		if (i > sqrt(x))
//			break;
//	}
//	def_prms.push_back(x);
//	return true;
//}
//
//vector<int> getAllPrimes(int low, int high) {
//	vector<int> res;
//	if (low < 2 || high < 2)
//		return res;
//	for (int i = low; i < high; ++i) {
//		if (isprime(i))
//			res.push_back(i);
//	}
//	return res;
//}
//
//int main() {
//	int low, high;
//	cin >> low >> high;
//	def_prms.push_back(2);
//	def_prms.push_back(3);
//	def_prms.push_back(5);
//	def_prms.push_back(7);
//	def_prms.push_back(11);
//	def_prms.push_back(13);
//	def_prms.push_back(17);
//	def_prms.push_back(19);
//	def_prms.push_back(23);
//	vector<int> prms = getAllPrimes(low, high);
//	int d_sum = 0, g_sum = 0; //分别为10位与个位之和
//	for (auto it : prms) {
//		int a = it / 10 % 10;
//		d_sum += a;
//		int b = it % 10;
//		g_sum += b;
//	}
//	cout << min(d_sum, g_sum) << endl;
//
//	getchar();
//	getchar();
//
//}




//**************************************为一个偶数寻找两个素数，这两个素数之和等于该偶数***********************************************//

//void fun(int a, int * b, int * c)
//{
//	int i, j, d, y;
//	for (i = 3; i <= a / 2; i = i + 2)
//	{
//		y = 1;
//		for (j = 2; j <= sqrt((double)i);j++)
//			if (i% j == 0)
//				y = 0;
//		if (y == 1)
//		{
//			d = a - i;
//			for (j = 2; j <= sqrt((double)d); j++)
//				if (d% j == 0) 
//					y = 0;
//			if (y == 1)
//			{
//				*b = i;
//				*c = d;
//			}
//		}
//	}
//}
//
//int main() {
//	int a, b, c;
//	cin >> a;
//	fun(a, &b, &c);
//	cout << b << ' ' << c << endl;
//
//	getchar();
//	getchar();
//}




//**********************************动态规划：N元钱，找零，最少几张钞票，并输出各种面额钞票数量****************************************//
//例：输入N = 100, 共有20，10，5，1四种面额；
//    输出： 5，[5,0,0,0]      因为20张的5张即可

//int main(){
//	int n = 126;
//	int RMB[] = { 1,5,10,20 };
//	vector<vector<int> > s(2, vector<int>(n + 1, 0));
//	s[0][0] = 0;
//
//	for (int i = 1; i <= n; i++) {
//		int q = n;
//		int k = 0;
//		for (k = 3; k >= 0 && RMB[k] > n; k--);   // 找到最大的可找零钱的下标
//		for (int j = 0; j <= k; j++) {
//			if (i >= RMB[j] && q >= 1 + s[0][i - RMB[j]]) {
//				q = 1 + s[0][i - RMB[j]];
//				s[1][i] = RMB[j];
//			}
//		}
//		s[0][i] = q;
//	}
//
//	int v20 = 0, v10 = 0, v5 = 0, v1 = 0;
//	while (n > 0) {
//		if (s[1][n] == 20)
//			v20++;
//		else if (s[1][n] == 10)
//			v10++;
//		else if (s[1][n] == 5)
//			v5++;
//		else if (s[1][n] == 1)
//			v1++;
//
//		n = n - s[1][n];
//	}
//	cout << v20 << ' ' << v10 << ' ' << v5 << ' ' << v1 << ' ' << endl;
//
//	getchar();
//}




//*********************************************！TopK问题与随机选择算法*******************************************************//

//int partition(int *arr, int low, int high, int pivotkey = -1) {  //最后的默认参数定为一个一般不出现的值，枢轴
//	int k;
//	if (pivotkey == -1)
//		k = arr[low];
//	else
//		k = pivotkey;
//
//	while (low < high) {
//		while (low < high && arr[high] <= k)  //只要更改 <= 为 >= 就是求第k小的问题了
//			high--;
//		swap(arr[low], arr[high]);
//		while (low < high && arr[low] >= k)   //同上
//			low++;
//		swap(arr[low], arr[high]);
//	}
//	return low;
//}
//
////先用RS算法找到函数中的第k大（或小）的数
//int RS(int *arr, int low, int high, int k) {
//	if (low == high) 
//		return arr[low];
//
//	int i = partition(arr, low, high);
//	int temp = i - low + 1;     //数组前半部分元素个数
//	if (k == temp) 
//		return arr[i];
//	if (temp > k)
//		return RS(arr, low, i - 1, k);         //求前半部分第k大
//	else
//		return RS(arr, i + 1, high, k - temp); //求后半部分第k-temp大
//}
//
//int main() {
//	int arr[] = { 3,2,1,6,4,5,8,9,10,7,12,14,17 };
//	int find_number = RS(arr, 0, 12, 5);  //找第5大的数字
//	partition(arr, 0, 12, find_number);   //找到了前5大的数字
//	cout << find_number << endl;
//	for (int i = 0; i < 5; i++)
//		cout << arr[i] << endl;
//	getchar();
//}




//*********************************************股票买卖问题1*******************************************************//
//给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用

//示例 1:
//输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
//	输出 : 8
//	解释 : 能够达到的最大利润 :
//	在此处买入 prices[0] = 1
//	在此处卖出 prices[3] = 8
//	在此处买入 prices[4] = 4
//	在此处卖出 prices[5] = 9
//	总利润 : ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

//int max_profit(vector<int> &prices, int fee) {
//	int size = prices.size();
//	vector<int> dpNoStack(size, 0), dpHoldStack(size, 0);
//	dpNoStack[0] = 0;
//	dpHoldStack[0] = -prices[0] - fee;
//	for (int i = 1; i < size; ++i) {
//		dpNoStack[i] = max(dpNoStack[i - 1], dpHoldStack[i - 1] + prices[i]);
//		dpHoldStack[i] = max(dpHoldStack[i - 1], dpNoStack[i - 1] - prices[i] - fee);
//	}
//	return dpNoStack[size - 1];
//}
//
//int main() {
//	vector<int> prices{ 1, 3, 2, 8, 4, 9 };
//	int fee = 2;
//	cout << max_profit(prices, fee) << endl;
//	getchar();
//}




//**************阿里一面：评测题目:  三个人玩斗地主(去掉大小鬼), 怎样判断1人手中的牌有顺子**********************//
//输入：牌号为string，如357810AKQ10AA323等，无空格隔开
//输出：bool值，true代表有顺子

//bool find_sunzi(string input) {
//	int size = input.size();
//	if (size < 0)
//		return false;
//
//	vector<int> S;
//	for (int i = 0; i < size; ++i) {
//		char a = input[i];
//		int tmp;
//		if (a == 'J') {
//			tmp = 11;
//		}
//		else if (a == 'Q') {
//			tmp = 12;
//		}
//		else if (a == 'K') {
//			tmp = 13;
//		}
//		else if (a == 'A') {
//			tmp = 14;
//		}
//		else if (input[i] == '1' && input[i + 1] == '0') {
//			tmp = 10;
//			++i;
//		}
//		else if (a >= '2'&&a <= '9')
//		{
//			tmp = a - '0';
//		}
//		else {
//			cout << "error input" << endl;
//			return false;
//		}
//
//		S.push_back(tmp);
//	}
//
//	sort(S.begin(), S.end());  //通过algorithm内的sort函数排好序（从小到大）
//
//	int max_lianxu = 0;
//	for (int i = 0; i < S.size() - 1; ++i) {
//		if (S[i] == S[i + 1])
//			continue;
//		else if (S[i] == S[i + 1] - 1) {
//			max_lianxu++;
//		}
//		else if (S[i] < S[i + 1] - 1) {
//			max_lianxu = 0;
//		}
//
//		if (max_lianxu >= 5)
//			return true;
//	}
//
//	return false;
//}
//
//int main() {
//	string str = "3978JAKQ10AA323";
//	cout << find_sunzi(str) << endl;
//	getchar();
//}



//****字节跳动研发岗第三次笔试第一题：机器人排成一排只往正前看，能被看到的次数最多的机器人身高**//

//例子      4
//          6 5 3 4   （一个机器人最多只能看到一个）
//          1
//          1<1
//          1 1<<<1
//          1 1<1 1
//          1 1 1 1
//          1 1 1 1
//被看到次数1 2 0 0
//    输出：5 （5能被3和4看到）

//int main() {
//	int n;
//	cin >> n;
//	vector<int> v;
//	for (int i = 0; i < n; ++i) {
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	vector<int> dp(n, 0);
//	for (int i = n - 1; i > 0; --i) {
//		for (int j = i - 1; j >= 0; --j) {
//			if (v[j] >= v[i]) {  //第j个机器人被第i个机器人看到
//				dp[j]++;
//				break;
//			}
//		}
//	}
//	int max_idx = -1;
//	int max = 0;
//	for (int i = 0; i < n; ++i) {
//		if (dp[i] > max) {
//			max = dp[i];
//			max_idx = i;
//		}
//	}
//	cout << v[max_idx] << endl;
//	getchar();
//	getchar();
//}



//**字节跳动研发岗第三次笔试第四题：解码问题，'A'->1,'B'->2,...'Z'->26，已知数字，求所有可能解码情况//
//例子： 输入：  12
//       输出：  AB
//               L

//string s;
//void find(int i, int N, string &st) {
//	if (i == N) {
//		for (int k = 0; k < s.size(); ++k)
//			cout << s[k];
//		cout << endl;
//		return;
//	}
//	else {
//		if (st[i] != '0') {
//			s.push_back(st[i] - '1' + 'A');
//			find(i + 1, N, st);  //递归进行下一个
//			s.pop_back();
//			if (i < N - 1) {
//				int z = (st[i] - '0') * 10 + (st[i + 1] - '0');
//				char t = z - 1 + 'A';
//				if (t <= 'Z' && t >= 'A') {
//					s.push_back(t);
//					find(i + 2, N, st);  //两位数后，递归下一个
//					s.pop_back();
//				}
//			}
//		}
//	}
//}
//int main() {
//	string st;
//	cin >> st;
//	find(0, st.size(), st);
//	getchar();
//	getchar();
//
//}




//**字节跳动研发岗第三次笔试第二题：倒水问题：三个容器t[1]、t[2]、t[3]，至少需要倒几次，才能恰好d升水//

//解题思路：先将每种倒水方式全部列出，得出三叉树，再广度优先遍历，
//找到某个容器出现了d升水，其深度即为最少次数
//queue<long long> t1;
//queue<long long> t2;
//queue<long long> t3;
//queue<long long> t4;
//bool flag;
//map<pair< pair< long long, long long >, long long >, bool> b;
//long long ans, t[4], x[4], z[4], tt, d;
//void qpush(long long k1, long long k2, long long k3)
//{
//	//cout << k1 << " " << k2 <<" " << k3 << endl;
//	if (b.count(make_pair(make_pair(k1, k2), k3)) == 1)
//		return;
//	b[make_pair(make_pair(k1, k2), k3)] = true;
//	t1.push(k1);
//	t2.push(k2);
//	t3.push(k3);
//	t4.push(tt + 1);
//	if (k1 == d || k2 == d || k3 == d)
//	{
//		flag = true;
//		ans = tt + 1;
//	}
//}
//int main()
//{
//	cin >> t[1] >> t[2] >> t[3] >> d;
//	ans = -1;
//	t1.push(0);
//	t2.push(0);
//	t3.push(0);
//	t4.push(0);
//	b[make_pair(make_pair(0, 0), 0)] = true;
//	while (!t1.empty()){
//		x[1] = t1.front();
//		x[2] = t2.front();
//		x[3] = t3.front();
//		tt = t4.front();
//		qpush(0, x[2], x[3]);
//		qpush(x[1], 0, x[3]);
//		qpush(x[1], x[2], 0);
//		qpush(t[1], x[2], x[3]);
//		qpush(x[1], t[2], x[3]);
//		qpush(x[1], x[2], t[3]);
//
//		for (int i = 1; i <= 3; i++)
//			for (int j = 1; j <= 3; j++)
//				if (i != j)
//				{
//					if (x[i] <= t[j] - x[j])
//					{
//						z[1] = x[1];
//						z[2] = x[2];
//						z[3] = x[3];
//						z[i] = 0;
//						z[j] = x[i] + x[j];
//					}
//					else {
//						z[1] = x[1];
//						z[2] = x[2];
//						z[3] = x[3];
//						z[i] = x[i] - (t[j] - x[j]);
//						z[j] = t[j];
//					}
//					qpush(z[1], z[2], z[3]);
//				}
//
//		if (flag) 
//			break;
//		t1.pop();
//		t2.pop();
//		t3.pop();
//		t4.pop();
//	}
//	cout << ans << endl;
//
//	getchar();
//	getchar();
//}




//***************哔哩哔哩第一题：两个单词之间转换的最少步骤**********************//
//注：所需最少步数，允许插入、删除、替换字母三种操作

//int main() {
//	string word1, word2;
//	cin >> word1;
//	cin >> word2;
//	int n = word1.length();
//	int m = word2.length();
//
//	if (n == 0 || m == 0)
//		return n + m;
//	vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
//	for (int i = 0; i <= n; ++i) {
//		dp[i][0] = i;
//	}
//	for (int i = 0; i <= m; ++i) {
//		dp[0][i] = i;
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			int l = dp[i - 1][j] + 1;    //left数字记录字符表中的字符进行插入 后 的最小步数
//			int d = dp[i][j - 1] + 1;    //down数字记录字符表中的字符进行删除 后 的最小步数
//			int l_d = dp[i - 1][j - 1];  //left_down数字记录字符表中的字符进行替换 前 的最小步数
//			if (word1[i - 1] != word2[j - 1]) {  
//				l_d++;                //若替换 前 的字符不等，则需要进行替换，最小步数++
//			}
//			dp[i][j] = min(l, min(d, l_d));  //求三种情况下的最小步数，保存进dp表
//		}
//	}
//	cout << dp[n][m] << endl;  //最终输出
//	getchar();
//	getchar();
//}


//***************哔哩哔哩第二题：连续整数求和为N,共有多少情况**********************//

//int main() {
//	int N;
//	cin >> N;
//	int out = 1;
//	int x = 2 * N;
//	for (int i = 2; i <= sqrt(x); ++i) {
//		if (x%i == 0) {
//			double n2 = (i + x / i - 1) / 2;
//			double n1 = x / i - n2;
//			if (n1 < n2 && (int)n1 == n1 && (int)n2 == n2)
//				if ((n1 + n2)*(n2 - n1 + 1) == x)
//					out++;
//		}
//	}
//	cout << out << endl;
//	getchar();
//	getchar();
//}



//***************哔哩哔哩第三题：字符串切分，转为键值对**********************//

//输入： 键值对分隔符pairs_delimiter, 键与值分隔符delimiter，字符串str；三者以空格' '隔开
//      如：  # : a:1#wasd:12#23:-1
//输出： 键值对个数，以及按行输出键值对，键值间空格分开
//      如：  3         ——个数
//            a 1       ——键值对1
//            wasd 12   ——键值对2
//            23 -1     ——键值对3

//int main() {
//	char pairs_delimiter, delimiter;
//	string str;
//	cin >> pairs_delimiter >> delimiter >> str;
//	
//	//输出的键值对模式的数据
//	vector<pair<string, int> > key_vals;
//	string key;
//	int val;
//	//将输入字符串str按pairs_delimiter分隔符分割为若干sub_str字串
//	stringstream f(str);
//	string sub_str;
//	while (getline(f, sub_str, pairs_delimiter)) {  //分割
//		//对每个sub_str字串，找到delimiter分隔符位置，前面部分为key,后部分为val
//		int del = sub_str.find_first_of(delimiter);
//		key = sub_str.substr(0, del);    //前面部分为key
//		string s_val = sub_str.substr(del + 1);  //后部分为val
//		stringstream ss(s_val);
//		ss >> val;   //用字节流方法转为数字（val为int型），其实也可以不转换
//		key_vals.push_back(make_pair(key, val));
//	}
//	int size = key_vals.size();
//	cout << size << endl;
//	for (int i = 0; i < size; ++i) {
//		cout << key_vals[i].first << " " << key_vals[i].second << endl;
//	}
//	getchar();
//	getchar();
//}