class Solution {
public:
    vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    void solve(int i,int j, string &temp,string digits){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string letters=mp[digits[i]-'0'];
        if(j==letters.size()){
            return;
        }

        temp.push_back(letters[j]);
        solve(i+1,0,temp,digits);
        temp.pop_back();

        solve(i,j+1,temp,digits);
        return;

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return ans;
        string temp;
        solve(0,0,temp,digits);
        return ans;
    }
};
