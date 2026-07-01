class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        int n = nums.size();
        for( int i = 0 ; i < n-1 ; i++){
            if(nums[i] == nums[i+1]){

            
            nums[i] *= 2;
            nums[i+1] = 0;
            }
        }
        int slow = 0;
        for(int fast = 0 ; fast < n ; fast++){
            if(nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        while(slow < n){
            nums[slow] = 0;
            slow++;
        }
        return nums;

    }
};
//TC = O(n)
//SC = O(n)