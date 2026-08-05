class Solution {
public:

   
    int uniquePaths(int m, int n) {
        vector<int>ahead(m,0),curr(n,0);
       ahead[m-1]=1;
       curr[n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1)continue;
                int down = (i + 1 < m) ? ahead[j] : 0;
                int right = (j + 1 < n) ? curr[j + 1] : 0;

                curr[j] = down + right;


            }
            ahead=curr;
        }

       
      return curr[0];
        
        
    }
};