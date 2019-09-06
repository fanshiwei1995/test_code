#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

void query(int n, int *A, float *out) {
	for (int i = 0; i < n; i++) {
		int num_nbt_i = 0;
		for (int j = 0; j < n; j++)
			if (A[j] <= A[i])
				num_nbt_i++;
		out[i] = (float)(num_nbt_i - 1) / n * 100;
	}
}


int main() {
	//input
	int n, q, *A, *idx, *Q;
	float *out;
	cin >> n;
	if (n<1)
		return -1;
	A = (int*)malloc(sizeof(int)*n);
	idx = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] < 0 || A[i]>150)
			return -1;
	}

	cin >> q;
	if (q > 1000)
		return -1;
	Q = (int*)malloc(sizeof(int)*q);
	for (int i = 0; i < q; i++) {
		cin >> Q[i];
	}
	cout << " start manage" << endl;

	//manage
	out = (float*)malloc(sizeof(float)*n);
	query(n, A, out);

	//output
	for (int i = 0; i<q; i++) 
		cout << out[Q[i]-1] << endl;
	getchar();
	getchar();
	return 0;
}