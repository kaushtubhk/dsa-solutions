class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); //if k>n use k%n=m and then rotate array m times (edge case)
        k = k % n ;
        reverse(nums.begin(), nums.end());// Poora reverse karo
        reverse(nums.begin(), nums.begin()+k);//Pehle k elements reverse karo
        reverse(nums.begin() + k, nums.end());//Baaki elements reverse karo
       
    }
};
//TC = O(n)
//SC = O(1)