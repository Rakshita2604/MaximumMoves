#include<bits/stdc++.h>
using namespace std;

int MaximumMoves(vector<vector<int>>& grid, int m, int n) {
    int maxm = 0;
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for(int c = n-2; c >= 0; --c){
        for(int r = 0; r < m; ++r ){
            if(r - 1 >= 0 && grid[r][c] < grid[r-1][c+1])  { 
                dp[r][c] = max(dp[r][c], 1 + dp[r-1][c+1]); 
            }
            if( grid[r][c] < grid[r][c+1]) { 
                dp[r][c] = max(dp[r][c], 1 + dp[r][c+1]); 
            }
            if(r + 1 < m && grid[r][c] < grid[r+1][c+1]) { 
                dp[r][c] = max(dp[r][c], 1 + dp[r+1][c+1]); 
            }
            if(c == 0) {
                maxm = max(maxm, dp[r][c]);
            }
        }
    }
    return maxm;
}
int main()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int> (n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            grid[i][j]=num;
        }
    }
    cout<<"Output "<<MaximumMoves(grid,m,n);
    return 0;
}

