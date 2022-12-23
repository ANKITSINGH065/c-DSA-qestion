// Question link:- https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// using recursion
// T.C = O(exonation) || s.c = O(hight of n)
#define MOD 1000000007

long long int countDerangements(int n)
{
    // if only one number so number of posibile derangment is zero ex:- [2] arangement- 0
    if (n == 1)
    {

        return 0;
    }
    // if only 2 number so number of posibile derangment is one ex:- [1,2] arangement-[2,1]
    if (n == 2)
    {

        return 1;
    }

    long long int ans = ((n - 1) % MOD) * (((countDerangements(n - 1) % MOD) + (countDerangements(n - 2) % MOD)) % MOD);

    return ans;
}

// using recursion + memoization
// T.C = O(n)+o(n) || s.c = O(hight of n)
long long int solveMem(int n, vector<long long int> &dp)
{

    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    // store the recursive call
    dp[n] = (((n - 1) % MOD) * ((solveMem(n - 1, dp) % MOD) + (solveMem(n - 2, dp) % MOD)) % MOD);
    return dp[n];
}
long long int countDerangements(int n)
{

    vector<long long int> dp(n + 1, -1);

    return solveMem(n, dp);
}

// soving by tabulation

// T.C = O(n) || s.c = O(hight of n)

long long int solveTab(int n)
{

    vector<long long int> dp(n + 1, 1);

    // set the value
    dp[1] = 0;

    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {

        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i - 1) * sum) % MOD;

        dp[i] = ans;
    }

    return dp[n];
}
long long int countDerangements(int n)
{

    return solveTab(n);
}

// using space optimization
// T.C = O(n) || s.c = O(1)

long long int solve_space_optimize(int n)
{

    long long int pre1 = 0;

    long long int pre2 = 1;

    for (int i = 3; i <= n; i++)
    {

        long long int ans = ((i - 1) * (((pre1 % MOD) + (pre2 % MOD)) % MOD)) % MOD;
        pre1 = pre2;
        pre2 = ans;
    }

    return pre2;
}
long long int countDerangements(int n)
{

    return solve_space_optimize(n);
}