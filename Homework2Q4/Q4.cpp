#include<iostream>

using namespace std;
//Find max number
int maxn(int A[], int size) {
	int i = A[0];
	for (int j = 1; j < size; j++) {
		if (A[j] > i)
			i = A[j];
	}
	return i;
}
void Radixsort(int A[], int size) {
	int maxnumber = maxn(A, size);
	for (int radix = 1; maxnumber / radix > 0; radix *= 10) {
		int* B = new int[size];
		int* C = new int[10];
		int m;
		int n;
		for (int i = 0; i < 10; i++)
			C[i] = 0;
		for (int i = 0; i < size; i++) {
			m = (A[i] / radix) % 10;
			C[m] = C[m] + 1;
		}
		for (int j = 1; j < 10; j++) {
			C[j] = C[j] + C[j - 1];
		}
		for (int k = size - 1; k >= 0; k--) {
			n = (A[k] / radix) % 10;
			B[C[n] - 1] = A[k];
			C[n] = C[n] - 1;
		}
		for (int l = 0; l < size; l++)
			A[l] = B[l];
	}
}

void print(int A[], int n) {
	cout << "{";
	for (int i = 0; i < n; i++) {
		if (i + 1 != n)
			cout << A[i] << ",";
		else
			cout << A[i];
	}
	cout << "}";
}
int main() {
	int A[7] = {329,457,657,839,436,720,353};
	cout << "Input array is A = ";
	print(A, 7);
	Radixsort(A, 7);
	cout << "\nOutput array is A = ";
	print(A, 7);
	return 0;
}