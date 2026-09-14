class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
       cost.push_back(0);
       

       for(int i = n-1 ; i>=0;i--){
        if(i<n-1){
            cost[i]=cost[i]+min(cost[i+1],cost[i+2]);
        }
        else{
            cost[i]=cost[i]+cost[i+1];
        }
       } 

       return min(cost[0],cost[1]);
    }
};
