class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   // stores indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // 1️⃣ remove out of window
            if (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();

            // 2️⃣ remove smaller elements
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // 3️⃣ add current index
            dq.push_back(i);

            // 4️⃣ window complete
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
