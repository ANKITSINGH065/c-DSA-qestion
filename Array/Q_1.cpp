/*
    This question is very simple
    first subtract the capacity array to rock array beacuse tihs indicate how much rocks is recured
    second sort the array beacause first which bags is fill is requied less additional rock
    third linerly itreate the array
    if (it == 0 ) this idicate bag is already full we not need to go further
    subtract in additionalRocks rocks how much rocks is recured
    after subtracting additionalRocks is >=0 itrater requiedment is full simple ans++
    else break beacause additionalRocks<0 we not need them

*/

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {

        int cnt = 0;

        for (int i = 0; i < capacity.size(); i++)
            capacity[i] = capacity[i] - rocks[i];

        sort(begin(capacity), end(capacity));

        for (auto it : capacity)
        {
            if (it == 0)
            {
                cnt++;
                continue;
            }
            additionalRocks -= it;
            if (additionalRocks >= 0)
                cnt++;
            else
                break;
        }

        return cnt;
    }
};