class Solution {
public:
    bool isPalindrome(int x) {
        string c = to_string(x);
        string tmp="";

    
        for(int i=c.length()-1;i>-1;i--){
            tmp+=c[i];
        }
        
    if(tmp==c)
        return true;
    else
        return false;
    }
    
};