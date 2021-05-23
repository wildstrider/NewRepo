#include <iostream>
using namespace std;
#define tab "\t"

void print(int arr[], int n){

	for (int i = 0; i < n; i++) {

		cout << arr[i] << tab;
	}
}
int main() {

	const int n = 5;
	int arr[n] = { 1,2,3,4,5 };
	print(arr, n);

}