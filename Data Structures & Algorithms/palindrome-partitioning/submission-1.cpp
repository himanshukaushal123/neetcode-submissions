class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string str,int start,int end){
        while(start<=end){
            if(str[start]!=str[end])return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string s,int start,int end,int n,vector<string>&temp){
        if(start==n){
            ans.push_back(temp);
            return;
        }
        if(end==n)return;
        //pick
        if(isPalindrome(s,start,end)){
            temp.push_back(s.substr(start,end-start+1));
            solve(s,end+1,end+1,n,temp);
            temp.pop_back();

        }
        //not pick
        //extend the current substring
        solve(s,start,end+1,n,temp);
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(s,0,0,s.size(),temp);
        return ans;
    }
};
