// https://www.codingninjas.com/studio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

void subset(int idx, int sum, vector<int> &num, vector<int> &ans)
{

    // Completely traverse the whole array, insert the 'sum' in the 'ans' vector.
    if (idx == num.size())
    {
        ans.push_back(sum);
        return;
    }

    // Insert the element in the sum.
    subset(idx + 1, sum + num[idx], num, ans);
    
    // Don't take the element in the sum.
    subset(idx + 1, sum, num, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // 'ans' vector contains all the subset sums.
    vector<int> ans;

    subset(0, 0, num, ans);
    // Sort the vector and finally return it.
    sort(ans.begin(), ans.end());
    return ans;
}
