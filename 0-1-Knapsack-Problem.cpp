### Recursion Approach for 0/1 Knapsack Problem:

To solve the problem follow the below idea:

A simple solution is to consider all subsets of items and calculate the total weight and profit of all subsets. Consider the only subsets whose total weight is smaller than W. From all such subsets, pick the subset with maximum profit.

Optimal Substructure: To consider all subsets of items, there can be two cases for every item. 

Case 1: The item is included in the optimal subset.
Case 2: The item is not included in the optimal set.
Follow the below steps to solve the problem:

The maximum value obtained from ‘N’ items is the max of the following two values. 

Case 1 (include the Nth item): Value of the Nth item plus maximum value obtained by remaining N-1 items and remaining weight i.e. (W-weight of the Nth item).
Case 2 (exclude the Nth item): Maximum value obtained by N-1 items and W weight.
If the weight of the ‘Nth‘ item is greater than ‘W’, then the Nth item cannot be included and Case 2 is the only possibility.
  
Below is the implementation of the above approach: 

/* A Naive recursive implementation of
 0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
 
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 
// Driver code
int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
  }

Time Complexity: O(2N)
Auxiliary Space: O(N), Stack space required for recursion


### Dynamic Programming Approach for 0/1 Knapsack Problem

Memoization Approach for 0/1 Knapsack Problem:

Note: It should be noted that the above function using recursion computes the same subproblems again and again. See the following recursion tree, K(1, 1) is being evaluated twice. 

In the following recursion tree, K() refers  to knapSack(). The two parameters indicated in the following recursion tree are n and W.
The recursion tree is for following sample inputs.
weight[] = {1, 1, 1}, W = 2, profit[] = {10, 20, 30}

                                                     K(3, 2)  
                                          /                         \ 
                                       /                             \               
                          K(2, 2)                                K(2, 1)
                     /               \                           /               \ 
                  /                   \                       /                   \
          K(1, 2)               K(1, 1)            K(1, 1)       K(1, 0)
           /     \                  /       \                /                  \
        /         \              /           \            /                      \
K(0, 2)  K(0, 1)  K(0, 1)  K(0, 0)  K(0, 1)          K(0, 0)

Recursion tree for Knapsack capacity 2 units and 3 items of 1 unit weight.

As there are repetitions of the same subproblem again and again we can implement the following idea to solve the problem.

If we get a subproblem the first time, we can solve this problem by creating a 2-D array that can store a particular state (n, w). Now if we come across the same state (n, w) again instead of calculating it in exponential complexity we can directly return its result stored in the table in constant time.

Below is the implementation of the above approach:

// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;
 
// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int index, int** dp)
{
    // base condition
    if (index < 0)
        return 0;
    if (dp[index][W] != -1)
        return dp[index][W];
 
    if (wt[index] > W) {
 
        // Store the value of function call
        // stack in table before return
        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
        return dp[index][W];
    }
    else {
        // Store value in a table before return
        dp[index][W] = max(val[index]
                           + knapSackRec(W - wt[index], wt, val,
                                         index - 1, dp),
                       knapSackRec(W, wt, val, index - 1, dp));
 
        // Return value of table after storing
        return dp[index][W];
    }
}
 
int knapSack(int W, int wt[], int val[], int n)
{
    // double pointer to declare the
    // table dynamically
    int** dp;
    dp = new int*[n];
 
    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];
 
    // loop to initially filled the
    // table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}
 
// Driver Code
int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}

Time Complexity: O(N * W). As redundant calculations of states are avoided.
Auxiliary Space: O(N * W) + O(N). The use of a 2D array data structure for storing intermediate states and O(N) auxiliary stack space(ASS) has been used for recursion stack
