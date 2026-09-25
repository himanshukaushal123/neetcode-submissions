class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int j,vector<vector<int>>& visited,int drow[], int dcol[]
,int n,int m,int row,int col){
        if(j == word.size()-1){
            return true;
        }
        if(row > n && col > m){
            return false;
        }
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && board[nrow][ncol]==word[j+1]){
                visited[nrow][ncol]=1;
                if (solve(board, word, j+1,visited, drow, dcol, n, m,nrow,ncol))return true;
                // Backtrack
                visited[nrow][ncol] = 0;
            }
            
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m+1,0));
        int dcol[]={-1,1,0,0};
        int drow[]={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]==word[0]){
                    visited[i][j] = 1;
                    if(solve(board,word,0,visited,drow,dcol,n,m,i,j))return true;
                     // Backtrack
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};
