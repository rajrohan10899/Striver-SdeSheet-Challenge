// https://www.codingninjas.com/codestudio/problems/1058184?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

 #include<bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
    int maxi = 0;
        stack<int> st1, st2;
        vector<int> lse(heights.size(),0), rse(heights.size(),0);

        for(int i=0; i<heights.size(); i++)
        {
            while(!st1.empty() && heights[st1.top()] >= heights[i])
            {
                st1.pop();
            }
            if(st1.empty())
            {
                lse[i]=0;
            }
            else{
                lse[i] = st1.top()+1;
            }
            st1.push(i);
        }
         for(int i=heights.size()-1; i>=0; i--)
        {
            while(!st2.empty() && heights[st2.top()] >= heights[i])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                rse[i]=heights.size()-1;
            }
            else{
                rse[i] = st2.top()-1;
            }
            st2.push(i);
        }
        for(int i = 0; i<heights.size(); i++)
        {
            int ans = (rse[i]- lse[i] + 1) * heights[i];
            maxi = max(maxi, ans);
        }
        return maxi;
 }
