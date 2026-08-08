class Solution {
public:
    bool checkValidString(string s) {
        int mx=0,mn=0;
        for(auto it:s){
            if(it=='('){
                mx++;
                mn++;
            }
            else if(it==')'){
                mx--;
                mn--;
            }
            else {
                mn--;
                mx++;
            }
            mn=max(0,mn);
            if(mx<0)return false;
        }
        return mn==0;
        
    }
};
