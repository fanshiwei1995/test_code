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

	//���ŵķ���ʵ���ڱ�mark��߶���С�����ģ��ұ߶��Ǵ������� 
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

	//�ڱ��Ҳ����������ָ���
	int big_num = right - i;

	//����ڱ��պ��ǵ�K�����
	if (k - big_num - 1 == 0)
		return mark;
	else if (k - big_num - 1 > 0) {
		//����Ҳ����ָ�������K�����������ҵ�k-big_num-1�����
		return quickfind(a, left, i - 1, k - big_num - 1);
	}
	else {
		//����Ҳ����ָ�����K�࣬�����Ҳ��ҵ�K�����
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
	if (l >= r)     //�ȼ����������
		return;
	int i = l, j = r, x = num[l];
	while (i < j) {
		while (i < j && num[j] >= x)//���������ҵ���һ��С��x��
			j--;
		if (i < j)
			num[i++] = num[j];//���֮��i++
		while (i < j && num[i] <= x)//���������ҵ�һ������x����
			i++;
		if (i < j)
			num[j--] = num[i];
	}
	num[i] = x;     //���ʼȡ������x�ŵ�i��
	quickSort(num, l, i - 1);//��iΪ�м�ֵ�������������ֵݹ����
	quickSort(num, i + 1, r);
}