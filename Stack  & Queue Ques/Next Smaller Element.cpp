// https://www.codingninjas.com/codestudio/problems/1112581?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

T.C = O(N^2).
S.C = O(1).

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n, -1); // Initialize the answer vector with -1
    
    for (int i = 0; i < n; i++)
    {
        int nextSmaller = -1; // Variable to store the next smaller element
        
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                nextSmaller = arr[j];
                break;
            }
        }
        
        ans[i] = nextSmaller;
    }

    // OPTIMAL SOLU :
    #include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n, -1); // Initialize the answer vector with -1
    stack<int> st;           // Stack to store indices
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    
    return ans;

    
    
    return ans;
}
