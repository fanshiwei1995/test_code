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


//*******************************0-1�������⣬��̬�滮 �������+�ݹ���ݣ�����*****************************************//
//0-1�������⣬��̬�滮 �������+���ݣ�����
//����T��������ÿ��������N����Ʒ����������ΪX,�����������i����Ʒ�ļ�ֵa������b��������װ��Ʒ������ֵ������Ʒ��

//void findWhat(vector<vector<int> > &dp, vector<int> &item, vector<int> &w, vector<int> &v, int i, int j) {//���Ž����	
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
//		//�����������Ʒ��ֵa������b
//		for (int j = 0; j < N; j++) {
//			int a, b;
//			cin >> a >> b;
//			A.push_back(a);
//			B.push_back(b);
//		}
//		int size = A.size();
//		vector< vector<int> > dp(size, vector<int>(X + 1, 0));
//		//�������
//		for (int m = 1; m < size; m++) {
//			for (int n = 1; n <= X; n++) {
//				if (n < B[m]) {
//					dp[m][n] = dp[m - 1][n];   //��װ���m����Ʒ
//				}
//				else {
//					dp[m][n] = max(dp[m - 1][n], dp[m - 1][n - B[m]] + A[m]);
//				}
//			}
//		}
//		//��̬�滮������(N * X)
//		for (int m = 1; m < size; m++) { //ʡ���˵�һ�е�һ��(ȫ0)
//			for (int n = 1; n <= X; n++) {
//				cout << dp[m][n] << ' ';
//			}
//			cout << endl;
//		}
//
//		//���ݷ�ȷ�����Ž����(�ݹ����)
//		vector<int> item(size, 0);
//		findWhat(dp, item, B, A, N, X);  //�ӱ�����һ����ʼ�ݹ�
//		//���Ž����
//		for (int k = 0; k < size; k++)
//			cout << item[k] << ' ';
//		cout << endl;
//	}
//
//	getchar();
//	getchar();
//}



//***********************************���׻���ģ�����******************************************************************//
//�ַ�����д�������������ĸλ������4λ(>=4)����д
//����ABCDEEFRGHIJKWW  ==��   A-EEFRG-KWW

//int main() {
//	string str;
//	cin >> str;
//	int len = str.length();
//	int pos = 0;
//	while (pos < len) {
//		int next;
//		//�������±���pos��next�������ַ���������
//		//next����¼ÿ������������ִ��Ľ���λ��(+1),
//		//pos����¼ÿ������������ִ��Ŀ�ʼλ��,
//		//һ���������򳬹�4λ(>=4)���������д: str[pos] << '-' << str[next - 1];
//		//���򣬰�˳�����
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




//*************************************���׻���ģ�����****************************************************************//
//������ϣ�ȱ�ٿո�ָ�ͬһ�����ֵ������ַ�����ʾ��ʽ���������ֽ��ƺ�һ�����֣���������ֵ�10���Ʊ�ʾ��ʽ��
//>> 5  2    
//>> 113221101000101     
//<< 837

//int main() {
//	int x, y; //�ֱ����x������y����
//	cin >> x >> y;
//	string str;
//	cin >> str;
//	int len = str.length();
//	int a = 0, b = 0, k = 1;
//	//˼·�����ַ����������м������һλһλȡ���֣�
//	//ÿȡһλ�ͱȽϵ�ǰx���ƺ�y���Ƶ��������ִ�С
//	//���x���Ƹ�С���ʹ�ͷ��ȡ��һλ���ּ���x��������β��
//	//���y���Ƹ�С���ʹ�β��ȡ��һλ���ּ���y��������ͷ��
//	//ֱ��������ɣ�һ�����Եó�������
//	for (int i = 0, j = len - 1; i < j; ) {
//		if (a <= b) {
//			a = a * x + str[i++] - '0';  //x���Ƹ�С����ͷ��ȡ��һλ���ּ���x��������β
//		}
//		else {
//			b = b + (str[j--] - '0') * k; //y���Ƹ�С����ͷ��ȡ��һλ���ּ���y��������ͷ��
//			k *= y;                       //ÿ�δ�ͷ����һλ������kֵ���ݴ����Ȩ��ֵ
//		}
//	}
//	cout << a << endl;
//
//	getchar();
//	getchar();
//}




//*************************************���׻���2018����--�绰���������****************************************************************//
//ǰ׺������绰���� 




//**************************************ţ��Сţ����**********************************************************//
//һ��ʼ��1��ţ��Сţ�ɳ�x���º����һ��Сţ

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


//**********************************��Ϊ2019.8.21����--������������Щ��ʮλ��֮�����λ��֮�͵���Сֵ**********************************//

//vector<int> def_prms;  //�ȶ���һ��Ĭ�ϵ���������
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
//	int d_sum = 0, g_sum = 0; //�ֱ�Ϊ10λ���λ֮��
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




//**************************************Ϊһ��ż��Ѱ����������������������֮�͵��ڸ�ż��***********************************************//

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




//**********************************��̬�滮��NԪǮ�����㣬���ټ��ų�Ʊ�������������Ʊ����****************************************//
//��������N = 100, ����20��10��5��1������
//    ����� 5��[5,0,0,0]      ��Ϊ20�ŵ�5�ż���

//int main(){
//	int n = 126;
//	int RMB[] = { 1,5,10,20 };
//	vector<vector<int> > s(2, vector<int>(n + 1, 0));
//	s[0][0] = 0;
//
//	for (int i = 1; i <= n; i++) {
//		int q = n;
//		int k = 0;
//		for (k = 3; k >= 0 && RMB[k] > n; k--);   // �ҵ����Ŀ�����Ǯ���±�
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




//*********************************************��TopK���������ѡ���㷨*******************************************************//

//int partition(int *arr, int low, int high, int pivotkey = -1) {  //����Ĭ�ϲ�����Ϊһ��һ�㲻���ֵ�ֵ������
//	int k;
//	if (pivotkey == -1)
//		k = arr[low];
//	else
//		k = pivotkey;
//
//	while (low < high) {
//		while (low < high && arr[high] <= k)  //ֻҪ���� <= Ϊ >= �������kС��������
//			high--;
//		swap(arr[low], arr[high]);
//		while (low < high && arr[low] >= k)   //ͬ��
//			low++;
//		swap(arr[low], arr[high]);
//	}
//	return low;
//}
//
////����RS�㷨�ҵ������еĵ�k�󣨻�С������
//int RS(int *arr, int low, int high, int k) {
//	if (low == high) 
//		return arr[low];
//
//	int i = partition(arr, low, high);
//	int temp = i - low + 1;     //����ǰ�벿��Ԫ�ظ���
//	if (k == temp) 
//		return arr[i];
//	if (temp > k)
//		return RS(arr, low, i - 1, k);         //��ǰ�벿�ֵ�k��
//	else
//		return RS(arr, i + 1, high, k - temp); //���벿�ֵ�k-temp��
//}
//
//int main() {
//	int arr[] = { 3,2,1,6,4,5,8,9,10,7,12,14,17 };
//	int find_number = RS(arr, 0, 12, 5);  //�ҵ�5�������
//	partition(arr, 0, 12, find_number);   //�ҵ���ǰ5�������
//	cout << find_number << endl;
//	for (int i = 0; i < 5; i++)
//		cout << arr[i] << endl;
//	getchar();
//}




//*********************************************��Ʊ��������1*******************************************************//
//����һ���������� prices�����е� i ��Ԫ�ش����˵� i ��Ĺ�Ʊ�۸� ���Ǹ����� fee �����˽��׹�Ʊ����������

//ʾ�� 1:
//����: prices = [1, 3, 2, 8, 4, 9], fee = 2
//	��� : 8
//	���� : �ܹ��ﵽ��������� :
//	�ڴ˴����� prices[0] = 1
//	�ڴ˴����� prices[3] = 8
//	�ڴ˴����� prices[4] = 4
//	�ڴ˴����� prices[5] = 9
//	������ : ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

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





//**************����һ�棺������Ŀ:  �������涷����(ȥ����С��), �����ж�1�����е�����˳��**********************//
//���룺�ƺ�Ϊstring����357810AKQ10AA323�ȣ��޿ո����
//�����boolֵ��true������˳��

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
//	sort(S.begin(), S.end());  //ͨ��algorithm�ڵ�sort�����ź��򣨴�С����
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