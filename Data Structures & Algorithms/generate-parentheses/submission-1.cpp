class Solution {
public:
//                    ""
        //             |
        //          add "("
        //             |
        //            "("
        //         /       \
        //    add "("     add ")"
        //      /           \
        //    "(("          "()"

    vector<string>ans;
    void solve(int open , int close , string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        if(open){
            op+="(";
            solve(open-1,close,op);
            op.pop_back(); 
        }
        if(close>open){
            op+=")";
            solve(open,close-1,op);
            op.pop_back(); 
        }
        
    }
    vector<string> generateParenthesis(int n) {
        solve(n ,n , "");
        return ans;
    }
};
