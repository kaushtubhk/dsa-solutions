class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        //  Har element fix karo
        for(int i = 0; i < n - 2; i++) {

            // Duplicate i skip karo
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            //  teen positive numbers kabhi 0 nahi bana sakte
            if(nums[i] > 0)
                break;

            int left  = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {

                    result.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    // Duplicate left skip karo
                    while(left < right &&
                          nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Duplicate right skip karo
                    while(left < right &&
                          nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }

                else if(sum < 0) {

                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return result;
    }
};
//TC = O(n^2)
//SC = O(1)