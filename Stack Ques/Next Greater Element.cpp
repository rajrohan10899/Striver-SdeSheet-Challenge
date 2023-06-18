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

// OPTIMAL SOLUTION. USING SATCK

#include <bits/stdc++.h> 
    
    vector<int> nextGreaterElement(vector <int>& arr, int n) {
        // Write your code here.
    vector<int> ans(n);

    // Stack, to keep track of next greater element.
    stack<int> s;

     // Traverse in reverse fashion in the array.
    for (int i = n - 1; i >= 0; i--) {

      /* 
          If current element is greater than stack's top 
          element, we can pop it since now it will never get 
          picked as the next greater, because current element 
          is greater and appear earlier. 
      */
      while (!s.empty() && arr[i] >= s.top()) {
          s.pop();
      }

      /*
          If stack is not empty, stack's top element is 
          the next greater element, else there is none.
      */
      if (!s.empty()) {
          ans[i] = s.top();
      } 

      else {
          ans[i] = -1;
      }

      // Push current element onto stack.
      s.push(arr[i]);
  }

  return ans;
    
}
