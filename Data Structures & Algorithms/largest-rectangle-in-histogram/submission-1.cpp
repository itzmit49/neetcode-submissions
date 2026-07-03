class Solution {
public:
    vector<int>NSE(vector<int>&h){
        int n=h.size();
        vector<int>temp(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&h[st.top()]>=h[i])st.pop();
            if(st.empty())temp[i]=n;
            else temp[i]=st.top();
            st.push(i);
        }
        return temp;

    }
    vector<int>PSE(vector<int>&h){
        int n=h.size();
        vector<int>temp(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&h[st.top()]>=h[i])st.pop();
            if(st.empty())temp[i]=-1;
            else temp[i]=st.top();
            st.push(i);
        }
        return temp;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse=NSE(heights);
        vector<int>pse=PSE(heights);
        int maxArea=0;
        for(int  i=0;i<heights.size();i++){
            int h=heights[i];
            int width=nse[i]-pse[i]-1;
            maxArea=max(maxArea,h*width);
        }
        return maxArea;

        
    }
};
