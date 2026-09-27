class Solution {
public:
    void solve(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visited,int n,int m,int drow[],int dcol[]){
       queue<pair<int,int>>qe;
       qe.push({row,col});
       visited[row][col]=1;
       while(!qe.empty()){
         row = qe.front().first;
         col = qe.front().second;
         qe.pop();
         for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                visited[nrow][ncol]=1;
                qe.push({nrow,ncol});
            }
         }
       }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector(m+1,0));
        int drow[]={1,-1,0,0};
        int dcol[]={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    solve(i,j,grid,visited,n,m,drow,dcol);
                }
            }
        }
        return count;
        
    }
};
