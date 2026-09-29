class Solution {
public:
// If you need time / number of steps / number of levels
// Use level-order BFS.
// If you need the distance for each cell
// You usually don't need level-order BFS.
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>qe;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    qe.push({i,j});
                }
            }
        }
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        int count=0;
        //level order
        while(!qe.empty()){
            int size=qe.size();
            bool changed = false;
            for(int j=0;j<size;j++){
                auto [row,col]=qe.front();
                qe.pop();
                for(int i=0;i<4;i++){
                    int nr=row+drow[i];
                    int nc=col+dcol[i];

                    if(nr<0 || nc<0 || nc>=m || nr>=n)continue;

                    if(grid[nr][nc]!=1)continue;

                    grid[nr][nc]=2;

                    qe.push({nr,nc});
                    changed=true;
                }
            }
            if(changed)count++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        for(int i=0;i<n;i++){
            cout<<"------------------"<<endl;
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<",";
            }
            cout<<endl<<"------------------";
        }
        return count;
    }
};
