#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
class IntArray {
public:
	IntArray(int size);
	~IntArray();
	int & operator[](int i) const;
	int size() const;
	void fill(int k);
	int * begin();
	int * end();
	void insertion_sort();
private:
	int len;
	int * data;
};

IntArray::IntArray(int size) {
	len = size;
	data = new int(size);
	for (int i = 0; i < len; i++)
		data[i] = 0;
}

IntArray::~IntArray() {
	data = nullptr;
	delete[] data;
}

int & IntArray::operator[](int i) const {
	return data[i];
}

int IntArray::size() const {
	return len;
}

void IntArray::fill(int k) {
	for (int i = 0; i<len; i++)
		data[i] = k;
}

int * IntArray::begin() {
	return data;
}

void IntArray::insertion_sort() {
	int temp;
	for (int i = 0; i < len; i++) {
		for (int j = i; j >= 1; j--) {
			if (data[j] < data[j - 1]) {
				temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
			else break;
		}
	}
}

int * IntArray::end() {
	for (int i = 0; i < len; i++)
		data++;
	return data;
}

int main() {
	IntArray a(3);
	a[0] = 10;
	a[1] = 11;
	a[2] = 12;
	assert(a[0] == 10);
	assert(a[1] == 11);
	assert(a[2] == 12);
	assert(a.size() == 3);
	a.fill(5);
	assert(a[0] == 5);
	assert(a[1] == 5);
	assert(a[2] == 5);
	a[0] = 3;
	a[1] = 1;
	a[2] = 2;
	//std::sort(a.begin(), a.end());
	a.insertion_sort();
	assert(a[0] == 1);
	assert(a[1] == 2);
	assert(a[2] == 3);
	int * it = a.begin();
	assert(*it == 1);
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(it == a.end());
	cout << "All tests passed.\n";
	return 0;
}
