#include<iostream>
#include<vector>
#include "common.h"
#include "quick_sort.h"

using namespace std;


int main() {
	//std::vector<int> v = {8,7,6,5,4,3,2,1};
	std::vector<int> v = {4,9,16,5};
	DS::quicksort2(begin(v), end(v), DS::lt<int>);
	for (auto a : v) {
		cout << a << " ";
	}
	cout << endl;
}