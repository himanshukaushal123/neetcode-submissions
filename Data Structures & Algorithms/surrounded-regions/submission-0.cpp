class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    void dfs(int row,int col,vector<vector<char>>& board,int n,int m){
        board[row][col]='S';
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,n,m);
            }
        }
        for(int i=1;i<m;i++){
            if(board[0][i]=='O'){
                dfs(0,i,board,n,m);
            }
        }
        for(int i=1;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,n,m);
            }
        }
        for(int i=1;i<m;i++){
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='S'){
                    board[i][j]='O';
                }
                else {if(board[i][j]=='O'){
                    board[i][j]='X';
                }}

            }
        }
    }
};
