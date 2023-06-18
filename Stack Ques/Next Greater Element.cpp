// https://www.codingninjas.com/codestudio/problems/next-greater-element_920451

T.C = O(N^2).
S.C = O(1)
#include <bits/stdc++.h> 
vector<int> nextGreaterElement(vector<int>& arr, int n){
    // Write your code here.
    vector<int> ans(n, -1);

    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}
