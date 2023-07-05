// https://www.codingninjas.com/studio/problems/1112626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
//************BOTH "CODING NINJAS" AND "LEETCODE" SAME***************
string kthPermutation(int n, int k) {
    // Write your code here.
        int fact = 1;
        vector<int> num;

        for(int i=1; i<n; i++) {
            fact = fact * i;
            num.push_back(i);
        }
        num.push_back(n);
        string ans = "";
        k = k-1;
        while(true) {
            ans = ans + to_string(num[k / fact]);
            num.erase(num.begin() + k / fact);

            if(num.size() == 0) {
                break;
            }
            k = k % fact;
            fact = fact / num.size();
        }
        return ans;
}
