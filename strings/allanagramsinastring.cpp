class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans ;
        int n = s.size();
        int m = p.size() ;

        if(m>n){
            return ans ;
        }

        vector<int> pFreq(26,0);
        vector<int> windowFreq(26,0);

        for(char ch : p){
            pFreq[ch - 'a']++;
        }
        for(int i = 0 ; i < m ; i++){
            windowFreq[s[i] - 'a']++;

        }
        if(windowFreq == pFreq){
            ans.push_back(0) ;
        }
        int left = 0 ;
        for(int right = m ; right < n ; right++){
            windowFreq[s[right] - 'a']++ ;
            windowFreq[s[left] - 'a']-- ;
            left++ ;
            if(windowFreq == pFreq){
                ans.push_back(left);
            }
        }
        
        return ans ;
        
    }
};