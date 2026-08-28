class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26, 0);
        priority_queue<int> pq;
        queue<pair<int, int>> que;

        int time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            hash[tasks[i] - 'A']++;
        }

        for (int it : hash) {
            if (it > 0) {
                pq.push(it);
            }
        }

        while(!pq.empty() || !que.empty()){
            time++;

            if(!pq.empty()){
                int availableThisElement = pq.top()-1;
                int waitingTime = time + n;
                pq.pop();

                if(availableThisElement > 0){
                    que.push({availableThisElement,waitingTime});
                }
            }

            if(!que.empty() && time == que.front().second){
                pq.push(que.front().first);
                que.pop();
            }
        }

        return time;
    }
};
