#include <bits/stdc++.h>
using namespace std;

  // Initially, the pointers low and high will be 0 and n-1(where n = size of the given array) respectively.

  // Now inside a loop, we will perform the 3 steps.

        //  Step 1: Divide the search space into 2 halves:
                  // In order to divide the search space, we need to find the middle point of it. So, we will take a ‘mid’ pointer and do the following:
                  // mid = (low+high) // 2 ( ‘//’ refers to integer division)
        // Step 2: Compare the middle element with the target:
                  // In this step, we can observe 3 different cases:
                  // If arr[mid] == target: We have found the target. From this step, we can return the index of the target possibly.
                  // If target > arr[mid]: This case signifies our target is located on the right half of the array. So, the next search space will be the right half.
                  // If target < arr[mid]: This case signifies our target is located on the left half of the array. So, the next search space will be the left half.
        // Step 3: Trim down the search space:
                  // Based on the probable location of the target we will trim down the search space.

  // The loop will run until either we fount the target or any of the pointers crosses the other.

int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;
  
    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}

// Output: The target is at index: 2

// Time Complexity:

// In the algorithm, in every step, we are basically dividing the search space into 2 equal halves.
// This is actually equivalent to dividing the size of the array by 2, every time.
        // If a number n can be divided by 2 for x times:
        // 2^x = n
        // Therefore, x = logn (base is 2)
// So the overall time complexity is O(logN), where N = size of the given array.
