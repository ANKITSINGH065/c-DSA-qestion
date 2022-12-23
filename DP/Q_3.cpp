/*
link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
Ask by:- Google,amazon,mata...
*/

class Solution
{
public:
    // Approach:-1 (recursion ) || T.C = O(n^2) S.C = O(N) || T.L.E solution

    /* recursive approach intution is that in every recusive call cheak if is it buy or sell like in buy condition cheak this price is consider or not and find out maximum profit
     */

    int max_profit(vector<int> price, int n, int day, bool buy, vector<vector<int>> &dp)
    {

        if (day >= n)
        {

            return 0;
        }
        int profit = 0;

        if (buy)
        { // buy

            int consider = max_profit(price, n, day + 1, false, dp) - price[day];

            int not_consider = max_profit(price, n, day + 1, true, dp);

            profit = max({profit, consider, not_consider});
        }
        else
        {
            // sell
            int consider = max_profit(price, n, day + 2, true, dp) + price[day];

            int not_consider = max_profit(price, n, day + 1, false, dp);

            profit = max({profit, consider, not_consider});
        }

        return profit;
    }

    // Approach:-2 (recursion + memoization)  || T.C = O(N) S.C = O(N)
    int max_profit(vector<int> price, int n, int day, bool buy, vector<vector<int>> &dp)
    {

        if (day >= n)
        {

            return 0;
        }
        int profit = 0;

        if (dp[day][buy] != -1)
        {

            return dp[day][buy];
        }
        if (buy)
        { // buy

            int consider = max_profit(price, n, day + 1, false, dp) - price[day];

            int not_consider = max_profit(price, n, day + 1, true, dp);

            profit = max({profit, consider, not_consider});
        }
        else
        {
            // sell
            int consider = max_profit(price, n, day + 2, true, dp) + price[day];

            int not_consider = max_profit(price, n, day + 1, false, dp);

            profit = max({profit, consider, not_consider});
        }

        return dp[day][buy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return max_profit(prices, n, 0, true, dp);
    }
};