#include <bits/stdc++.h>
#define MOD 1000000007

/*this question is asked you have given fance and color paint the fence if two fence is not adjacecnt*/

/*approach is fence is divided into two part same and diffrent paint
same = f(n-2)*(k-1)
          +
diffrent = f(n-1)*(k-1)

*/
int add(int a, int b)
{

    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b)
{

    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

/*recursive funtion
T.c = O(n^2)
s.c = O(n)
*/

int recursive_solve(int n, int k)
{

    if (n == 1)
    {

        return k;
    }

    if (n == 2)
    {

        return add(k, mul(k, k - 1));
    }

    // concept have avobe line no : 6 - 11
    int ans = add(mul(recursive_solve(n - 2, k), k - 1), mul(recursive_solve(n - 1, k), k - 1));

    return ans;
}

/*Memoization funtion
T.c = O(n)
s.c = O(n)+O(n)
*/

int solveMem(int n, int k, vector<int> &dp)
{

    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(mul(solveMem(n - 2, k, dp), k - 1), mul(solveMem(n - 1, k, dp), k - 1));
    return dp[n];
}

/*Tabulation funtion
T.c = O(n)
s.c = O(n)
*/

int solveTab(int n, int k)
{

    vector<int> dp(n + 1, 1);

    dp[1] = k;

    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {

        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }

    return dp[n];
}

/*Memory save funtion
T.c = O(n)
s.c = O(1)
*/
int save_memory(int n, int k)
{

    int pre1 = k;

    int pre2 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {

        int totel = add(mul(pre1, k - 1), mul(pre2, k - 1));

        pre1 = pre2;
        pre2 = totel;
    }

    return pre2;
}

int numberOfWays(int n, int k)
{

    return save_memory(n, k);
}
