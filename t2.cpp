#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;


int quickfind(vector<int>& a, int left, int right, int k) {
	int i = left;
	int j = right;
	int mark = a[left];

	//快排的方法实现哨兵mark左边都是小于它的，右边都是大于它的 
	while (i < j) {
		while (i < j && a[j] >= mark)
			--j;
		if (i < j)
			a[i++] = a[j];

		while (i < j && a[i] <= mark)
			++i;
		if (i < j)
			a[j--] = a[i];
	}
	a[i] = mark;

	//哨兵右侧比他大的数字个数
	int big_num = right - i;

	//如果哨兵刚好是第K大的数
	if (k - big_num - 1 == 0)
		return mark;
	else if (k - big_num - 1 > 0) {
		//如果右侧数字个数不够K个，则从左侧找第k-big_num-1大的数
		return quickfind(a, left, i - 1, k - big_num - 1);
	}
	else {
		//如果右侧数字个数比K多，则在右侧找第K大的数
		return quickfind(a, i + 1, right, k);
	}
}

int findKth(vector<int> a, int n, int K) {
	return quickfind(a, 0, n - 1, K);
}


int main() {
	int temp;
	vector<int> num;
	int k;
	while (cin.peek() != '\n') {
		cin >> temp;
		num.push_back(temp);
	}
	cin >> k;
	int n = num.size();
	cout << findKth(num, n, k) << endl;

	return 0;

}



void quickSort(vector<int> &num, int l, int r);
int main()
{
	int array[] = { 34,65,12,43,67,5,78,10,3,70 }, k;
	int len = sizeof(array) / sizeof(int);
	cout << "The orginal arrayare:" << endl;
	vector<int> num(array, array + len);
	for (k = 0; k<num.size(); k++)
		cout << num[k] << ",";
	cout << endl;
	quickSort(num, 0, len - 1);
	cout << "The sorted arrayare:" << endl;
	for (k = 0; k<num.size(); k++)
		cout << num[k] << ",";
	cout << endl;
	system("pause");
	return 0;
}

void quickSort(vector<int> &num, int l, int r) {
	if (l >= r)     //先检查左右条件
		return;
	int i = l, j = r, x = num[l];
	while (i < j) {
		while (i < j && num[j] >= x)//从右向左找到第一个小于x的
			j--;
		if (i < j)
			num[i++] = num[j];//填坑之后i++
		while (i < j && num[i] <= x)//从左向右找第一个大于x的数
			i++;
		if (i < j)
			num[j--] = num[i];
	}
	num[i] = x;     //把最开始取出来的x放到i处
	quickSort(num, l, i - 1);//以i为中间值，分左右两部分递归调用
	quickSort(num, i + 1, r);
}