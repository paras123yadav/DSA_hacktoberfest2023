#include <iostream>
using namespace std;

int MaxSubarray(int arr[], int size) {
	int high = -100 *1000;
	// For highest value from the array without sum
	for (int x = 0; x < size; x++)
	{
		if (arr[x] > high)
		{
			high = arr[x];
		}
	}

	int total = 0;
	// Loop for doing the sum
	// Takes each value and adds to the continuous value until the sum is the highest possible
	for (int y = 0; y < size - 1; y++)
	{
		total = arr[y];
		for (int z = y + 1; z < size; z++)
		{
			total += arr[z];

			if (total > high)
			{
				high = total;
			}
		}
	}

	return high;
}

int main() {

	// keep this function call here
	/* Note: In C++ ,first have to initialize an array and set
	it equal to the stdin to test code with arrays. */

	int A[] = { 1, -2, 0, 3 };
	int B[] = { 3, -1, -1, 4, 3, -1 };
	int C[] = { -2, 5, -1, 7, -3 };
	int D[] = { -4, -5, -6 };
	cout << MaxSubarray(A, sizeof(A) / sizeof(A[0])) << endl; // 3
	cout << MaxSubarray(B, sizeof(B) / sizeof(B[0])) << endl; // 8
	cout << MaxSubarray(C, sizeof(C) / sizeof(C[0])) << endl; // 11
	cout << MaxSubarray(D, sizeof(D) / sizeof(D[0])) << endl; // -4
	return 0;

}