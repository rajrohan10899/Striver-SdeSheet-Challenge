// https://leetcode.com/problems/maximal-square/description/

class Solution {
public:
     vector<int> nextSmallerElement(vector<int> &arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
     } 
    vector<int> prevSmallerElement( vector<int> &arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }    
  int largestSquareArea(vector<int> &heights, int n) {
        //int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int p;
            p= min(l,b);
            int newArea = p*p;
            area = max(area, newArea);
        }
        return area;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
      int m=matrix[0].size(); 
      int n=matrix.size();
      vector<vector<int>> M(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')  M[i][j]=0;
                
                else M[i][j]=1;       
            }
        }
        int area = largestSquareArea(M[0], m);
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                
                //row udpate: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                
                // if   M[i][j] ==0 then height will be 0;
              
            }
            //entire row is updated now
            area = max(area, largestSquareArea(M[i],m));
            
        }
        return area;
    }
};
