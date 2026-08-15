class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size() ;
        int m = s.size() ;
        if(n > m){
            return "" ;
        }
        vector<int> freq(128,0) ;
        vector<int> windowFreq(128,0);

        for(char ch : t){
            freq[ch]++ ;
        }
        int have = 0 ;
        int left = 0 ;
        int minLen = INT_MAX ;
        int start = 0 ;

        for(int right = 0 ; right < m ; right++){
            char ch = s[right] ;
            windowFreq[ch]++ ;
            if(freq[ch] >0 && windowFreq[ch] <= freq[ch]){
                have++ ;
            }
            while(have == n){
                int len = right - left + 1 ;
                if(len < minLen){
                    minLen = len ;
                    start = left ;
                }
                char leftChar = s[left] ;
                windowFreq[leftChar]-- ;
                
                if(freq[leftChar] > 0 && windowFreq[leftChar] < freq[leftChar]){
                    have-- ;
                }
                left++ ;

            }
        }
        if(minLen == INT_MAX){
            return "" ;
        }
        return s.substr(start , minLen) ;
        
    }
};