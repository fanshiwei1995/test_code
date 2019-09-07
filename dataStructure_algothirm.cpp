//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
///*s[i:m] merge s[m+1:n] -> TR[i:n]*/
//void Merge(int s[], int TR[], int i, int m, int n)
//{
//	int j, k, l;
//	for (k = i, j = m + 1; i <= m && j <= n; k++) {
//		if (s[i] < s[j])
//			TR[k] = s[i++];
//		else
//			TR[k] = s[j++];
//	}
//	if (i <= m) {     //s[i:m]还有没入的元素，s[m+1:n]已全入
//		for (; i <= m; i++) {
//			TR[k++] = s[i];
//		}
//
//	}
//	/*
//	while(i <= m)  TR[k++] = s[i++];
//	*/
//
//	if (j <= n) {     //s[i:m]已全入，s[m+1:n]还有没入的元素
//		for (; j <= n; j++) {
//			TR[k++] = s[j];
//		}
//	}
//	/*
//	while(j <= n)  TR[k++] = s[j++];
//	*/
//}
//
//void MergeSort2(SqList *L) {  //非递归
//	int* TR = (int*)malloc(L->length * sizeof(int));
//	int k = 1;
//	while (k < L->length)
//	{
//		MergePass(L->r, TR, k, L->length);
//		k *= 2;
//		MergePass(TR, L->r, k, L->length);
//		k *= 2;
//	}
//}
//
//void MergePass(int SR[], int TR[], int s, int n) {
//	int i = 1;
//	int j;
//	while (i <= n - 2 * s + 1)
//	{
//		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
//		i += 2 * s;
//	}
//	if (i < n - s + 1)
//		Merge(SR, TR, i, i + s - 1, n);
//	else
//		for (j = i; j <= n; j++)
//			TR[j] = SR[j];
//}
