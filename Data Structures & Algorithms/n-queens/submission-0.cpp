class Solution {
public:
    vector<vector<string>>ans;
    bool isSafe(vector<string> & board, int row,int col,int n){
        // check same column have the queen
        // check chek above because e placing the queen from the above
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')return false;
        }
        //check upper left diagonal
        for(int r=row-1,c=col-1;r>=0 && c>=0;r--,c--){
            if(board[r][c]=='Q')return false;
        }
        //check upper right diagonal
        for(int r=row-1,c=col+1;r>=0 && c<n;r--,c++){
            if(board[r][c]=='Q')return false;
        }
        return true;

    }
    void solve(vector<string> & board, int row,int col,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        if(col==n)return;

        //pick
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(board,row+1,0,n);
            board[row][col]='.';
        }
        solve(board,row,col+1,n);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(board,0,0,n);
        return ans;
    }
};
