// this problem is all about allocating the slot. we need to allocate slot after the n time period.

// first we need to take a hash vector for counting the frequency

// second we need a priority queu for storing all frequency , because max priority will go first

// Then we need a queue where available frequency and waiting time for this element will store as pair. After taking first element the frequency will minus 1 and waiting time will be time + n. This pair will go to the queue.


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
