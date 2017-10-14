#include <iostream>
#include <math.h>
#include <cassert>

using namespace std;

// s = start of range to sort
// e = end of range to sort
void msort(int a[], int x[], int s, int e) {

	int amount = e - s + 1;
	int n = 0;
	int placeholderCount = 0;

	while (a[n] >= -50 && a[n] <= 50) {
		n++;
	}

	for (int i = 0; i<n; i += amount)
	{
		int j = amount*placeholderCount;
		int sortEnd = j + amount - 1;
		int sortMiddle = j + (amount / 2);

		if (sortEnd > n) {
			sortEnd = n;
		}

		for (int k = amount*placeholderCount; k<(sortEnd + 1); k++) {

			if (j == (placeholderCount*amount) + (amount / 2)) {
				x[k] = a[sortMiddle];
				sortMiddle++;
				continue;
			}

			else if (sortMiddle == (sortEnd + 1)) {
				x[k] = a[j];
				j++;
				continue;
			}

			if ((a[sortMiddle]< a[j])) {
				x[k] = a[sortMiddle];
				sortMiddle++;
			}
			else if ((a[sortMiddle] >= a[j])) {
				x[k] = a[j];
				j++;
			}
		}
		placeholderCount++;
	}

	for (int y = 0; y<n; y++) {
		a[y] = x[y];
	}

}

void mergesort(int a[], int n) {

	int tempCount = 1;
	int sortMax = 0;

	while (tempCount < n) {
		tempCount *= 2;
		sortMax++;
	}

	int sortCount = 0;
	int newArray[n];

	while (sortCount < sortMax)
	{
		int amount = pow(2, sortCount + 1);
		int placeholderCount = 0;
		int end = amount - 1;

		for (int i = 0; i<n; i += amount)
		{
			int j = amount*placeholderCount;
			int sortEnd = j + amount - 1;
			int sortMiddle = j + (amount / 2);

			if (sortEnd > n) {
				sortEnd = n;
			}

			for (int k = amount*placeholderCount; k<(sortEnd + 1); k++) {

				if (j == (placeholderCount*amount) + (amount / 2)) {
					newArray[k] = a[sortMiddle];
					sortMiddle++;
					continue;
				}

				else if (sortMiddle == (sortEnd + 1)) {
					newArray[k] = a[j];
					j++;
					continue;
				}

				if ((a[sortMiddle]< a[j])) {
					newArray[k] = a[sortMiddle];
					sortMiddle++;
				}
				else if ((a[sortMiddle] >= a[j])) {
					newArray[k] = a[j];
					j++;
				}
			}
			placeholderCount++;
		}

		for (int x = 0; x<n; x++) {
			a[x] = newArray[x];
		}


		sortCount++;
	}
}

bool sorted(int a[], int n) {
	for (int i = 0; i<(n - 1); i++) {
		if (a[i]>a[i + 1]) return false;
	}
	return true;
}

int main(int argc, char * args[])
{
	/*
	const int MAX = 1001;
	for(int i=0; i<10; i++) cout<<a[i]<<"\n";
	cout<<"\n\n\n\n\n";


	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a, 1000);

	assert(sorted(a, 1000));

	*/
	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));

	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));
	int d[] = { 1, 2, 3, 4, 5 };
	mergesort(d, 5);
	assert(sorted(d, 5));

	cout << "All tests passed." << endl;

	return 0;
}