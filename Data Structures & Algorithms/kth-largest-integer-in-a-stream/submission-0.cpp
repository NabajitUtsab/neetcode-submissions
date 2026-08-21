class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int pos;
    KthLargest(int k, vector<int>& nums) {
        pos = k;
        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if (pq.size() < pos) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
