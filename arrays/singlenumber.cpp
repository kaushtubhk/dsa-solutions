class Solution { //bit manipulation(XOR)
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int num : nums){
            result ^= num ;
        }
        return result;
        
    }
};
//TC = O(n)
//SC = O(1)