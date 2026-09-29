class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
       queue<pair<int,int>>qe;
       int n=grid.size();
       int m=grid[0].size();

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                qe.push({i,j});
            }
        }
       }
       int drow[]={0,0,1,-1};
       int dcol[]={1,-1,0,0};
       while(!qe.empty()){
        auto [row,col]=qe.front();
        qe.pop();

        for(int i=0;i<4;i++){
            int nr=row+drow[i];
            int nc=col+dcol[i];

            if(nr<0 || nc<0 || nc>=m || nr>=n)continue;

            if(grid[nr][nc]!=INT_MAX)continue;

            grid[nr][nc]=grid[row][col]+1;

            qe.push({nr,nc});


        }
       }
    }
};