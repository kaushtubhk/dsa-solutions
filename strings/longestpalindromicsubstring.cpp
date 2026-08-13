class Solution {
public:
    pair<int, int> expand(string& s , int l , int r){
        int n = s.size() ;
        while(l >=0 && r<n && s[l] == s[r]){
            l--;
            r++;
        }
        return {l+1 , r-l-1} ;
    }
    string longestPalindrome(string s){
        int n = s.size() ;
        int start = 0 ;
        int maxlen = 1 ;

        for(int i = 0; i<n ; i++){
            auto [l1,len1] = expand(s,i,i) ;
            auto [l2,len2] = expand(s,i,i+1) ;

            if(len1 > maxlen){
                maxlen = len1 ;
                start = l1 ;
            }
            if(len2 > maxlen){
                maxlen = len2 ;
                start = l2 ;
            }
        }
        return s.substr(start , maxlen) ;

    }
   
};
