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



//*****************