class Solution {
public:
    bool isPalindrome(string s) {

        int i=0;
        int j=s.size()-1;
        while(i<j){
            while(i<j&&!isalnum(s[i]))i++;
            while(i<j&&!isalnum(s[j]))j--;
            char a=tolower(s[i]);
            char b=tolower(s[j]);
            if(a!=b)return false;
            i++;
            j--;
           

        }
        return true;
        
    }
};
