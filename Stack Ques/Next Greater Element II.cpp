// https://www.codingninjas.com/studio/problems/next-greater-element-ii_6212757?leftPanelTab=1

vector<int> nextGreaterElementII(vector<int>& nums) {
    // Write your code here.
     vector<int> ans(nums.size(), -1);
        stack<int> st;

        for(int i=0; i<2 * nums.size(); i++)
        {
            int num = nums[i % nums.size()];

            while(!st.empty() && nums[st.top()] < num)
            {
                ans[st.top()] = num;
                st.pop();
            }
            if(i < nums.size())
                 st.push(i);
        }
        return ans;
}
