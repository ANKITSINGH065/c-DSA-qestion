/*

    link:- https://leetcode.com/problems/domino-and-tromino-tiling/description/


    intution is that number is depend the previos number like: i toking about n = 4 so 4 depend 3 and 1
    v[4]  = (2*v[3]+v[1]) than return the v[n] number|

    fomula:- v[i] = (2*v[i-1]+v[i-3])
*/

class Solution
{
public:
    int MOD = 1e9 + 7;
    int numTilings(int n)
    {

        vector<long long> v(1001, 0);

        v[1] = 1;
        v[2] = 2;
        v[3] = 5;

        if (n <= 3)
        {

            return v[n];
        }

        for (int i = 4; i <= n; i++)
        {

            v[i] = 2 * v[i - 1] + v[i - 3];

            v[i] = v[i] % MOD;
        }

        return v[n];
    }
};