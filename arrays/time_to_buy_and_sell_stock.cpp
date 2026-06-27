// 121. Best Time to Buy and Sell Stock(easy)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int n = prices.size();

        for(int i = 0; i < n ; i++){

            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            int profit = prices[i] - minPrice;
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit; 
    }
};
//TC = O(n)
//SC = O(1)