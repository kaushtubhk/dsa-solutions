class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int num : nums) {
            ans += mp[num - k];
            ans += mp[num + k];

            mp[num]++;
        }

        return ans;
    }
};
//TC = O(n)
//SC = O(n)