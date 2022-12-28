class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;

        for (int i = 0; i < piles.size(); i++)
        {
            pq.push(piles[i]);
        }

        while (k != 0)
        {

            int top_ele = pq.top();
            pq.pop();
            int ele = top_ele - floor(top_ele / 2);
            pq.push(ele);
            k--;
        }
        int ans = 0;
        while (!pq.empty())
        {

            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};