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
    void solve(vector<string> & board, int row,int col,int n,vector<int>&left_row,vector<int>&left_diagonal,vector<int>&right_diagonal){
        if(row==n){
            ans.push_back(board);
            return;
        }
        if(col==n)return;

        //pick
        if(!left_row[col] && !left_diagonal[row+col] && !right_diagonal[n-1+col-row]){
            board[row][col]='Q';
            left_row[col]=1;
            left_diagonal[row+col]=1;
            right_diagonal[n-1+col-row]=1;
            solve(board,row+1,0,n,left_row,left_diagonal,right_diagonal);
            board[row][col]='.';
            left_row[col]=0;
            left_diagonal[row+col]=0;
            right_diagonal[n-1+col-row]=0;
        }
        solve(board,row,col+1,n,left_row,left_diagonal,right_diagonal);
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string>board(n,string(n,'.'));
        vector<int>left_diagonal(2*n-1,0);
        vector<int>right_diagonal(2*n-1,0);
        vector<int>left_row(n,0);
        solve(board,0,0,n,left_row,left_diagonal,right_diagonal);
        return ans;
    }
};
