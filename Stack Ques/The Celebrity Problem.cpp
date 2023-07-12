//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

************BRUTE APPROACH***************
//TIME COMPLEXITY = O(N^2). SPACE COMPLEXITY = O(1).

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
public:
    //Helper function to check if person 'a' knows person 'b'
    bool knows(int a, int b, vector<vector<int>>& M) {
        return M[a][b] == 1;
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        for (int i = 0; i < n; i++) {
            bool isCelebrity = true;

            //Check if person 'i' is known by others or doesn't know anyone
            for (int j = 0; j < n; j++) {
                if (i != j && (knows(i, j, M) || !knows(j, i, M))) {
                    isCelebrity = false;
                    break;
                }
            }

            if (isCelebrity)
                return i; // Celebrity found at index 'i'
        }

        return -1; // No celebrity found
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
