/*

  question link:- https://leetcode.com/problems/beautiful-arrangement/description/

    This question is very simple thing about recursiona and backtraking
    1.first be create a vector beacuse in the question given the n start from 1 to n so run a loop 0 to n inside the loop indexes represent the level
    2. base is level == n then return count ++ becaue indicate level are intired array cover
    3. loop is start level to n in every index to cheak this temp[i] is divisble by (level+1) or not (by (level+1) beacuse level is start from 0 and temp of 0 represent 1)
    4. condition is true swap the level ans index
    5. recursive call start again
    6. then recursive call is end mean we  have alse index or out of bound condition simple return and backtrack(swap again)
*/

class Solution
{
public:
    int count = 0;
    void solve(vector<int> temp, int n, int level)
    {

        if (level >= n)
        {
            count++;
            return;
        }

        for (int i = level; i < n; i++)
        {
            if (temp[i] % (level + 1) == 0 || (level + 1) % temp[i] == 0)
            {
                swap(temp[i], temp[level]);
                solve(temp, n, level + 1);
                swap(temp[i], temp[level]);
            }
        }
    }
    int countArrangement(int n)
    {

        vector<int> temp(n);

        for (int i = 0; i < n; i++)
        {

            temp[i] = i + 1;
        }

        solve(temp, n, 0);

        return count;
    }
};