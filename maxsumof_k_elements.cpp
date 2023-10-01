#include <iostream>
#include <cmath>
#include <climits>
using namespace std;


// Sliding window technique to find sum of K consecutive elements

//Max sum fuction to implement
int maxSum(int arr[], int n, int k)
{
	int cur_sum = 0;

	for(int i = 0; i < k; i++)
		cur_sum += arr[i];

	int max_sum = cur_sum;

	for(int i = k; i < n; i++)
	{
		cur_sum += (arr[i] - arr[i - k]);

		max_sum = max(max_sum, cur_sum);
	}

	return max_sum;
}


//Driver code
int main() {
	
     int arr[] = {1, 8, 30, -5, 20, 7}, n = 6, k = 3;

     cout<<maxSum(arr, n, k);
    
}

// Output is: 45

//Time Complexity of the algorithm is:  O(n);
//Auxiliary Space : O(1)
