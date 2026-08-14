class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        vector<int> windowFreq(26,0) ;
        int n = s1.size() ;
        int m = s2.size() ;

        if(n>m){
            return false ;
        }
        for(char ch : s1){
            freq[ch - 'a']++ ;
        }
        for(int i = 0 ; i < n ; i++){
            windowFreq[s2[i] - 'a']++ ;
        }
        if(freq == windowFreq){
            return true ;
        }
        int left = 0 ;

        for(int right = n ; right < m ; right++){
            windowFreq[s2[right] - 'a']++ ;
            windowFreq[s2[left] - 'a']-- ;
            left++ ;

            if(freq == windowFreq){
                return true;
            }
        }
        return false ;



        
    }
};