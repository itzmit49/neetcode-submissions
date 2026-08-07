class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int t_gas=0,t_cost=0;
        int fuel=0;
        int st=0;
        for(int i=0;i<gas.size();i++){
            t_gas+=gas[i];
            t_cost+=cost[i];
            fuel+=(gas[i]-cost[i]);
            if(fuel<0){
                fuel=0;
                st=i+1;
            }
        }
        return t_cost>t_gas?-1:st;
    }
};
