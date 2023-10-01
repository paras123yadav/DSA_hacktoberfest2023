int solve(int idx, int wt[], int val[],int n,int W,vector<vector<int>> &dp){
        // Base Cases
        if(W<0) 
            return INT_MIN;
        if(idx>=n) 
            return 0;
        
        //If sub-problem's answer already calculated
        if(dp[idx][W] != -1) 
            return dp[idx][W];
        
        //notpicking the current element
        int notPick = solve(idx+1,wt,val,n,W,dp);
        
        //picking the current element
        int pick = val[idx] + solve(idx+1,wt,val,n,W-wt[idx],dp);
        
        //memoize and return the max
        return dp[idx][W] = max(notPick , pick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //initialize dp vector
       vector<vector<int>> dp(n,vector<int> (W+1,-1));
       
       return solve(0,wt,val,n,W,dp);
    }
