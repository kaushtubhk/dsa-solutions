class Solution {
public:
    vector<int> parent ;
    int find(int x){
        if(parent[x] == x){
            return x ;
        }else{
            return parent[x] = find(parent[x]);
        }
    }
    void unite (int a , int b){
        a = find(a) ;
        b = find(b) ;

        if(a == b){
            return ;
        }
        if(a < b){
            parent[b] = a ;
        }else{
            parent[a] = b ;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26) ;

        for(int i = 0 ; i < 26 ; i++){
            parent[i] = i ;
        } 

        for(int i = 0 ; i < s1.size() ; i++){
            int a = s1[i] - 'a' ;
            int b = s2[i] - 'a' ;

            unite(a,b) ;
        }
        string ans = "" ;
        for(char ch : baseStr){
            int x = ch - 'a' ;
            ans += char(find(x) + 'a');
        }
        return ans ;
        
    }
};