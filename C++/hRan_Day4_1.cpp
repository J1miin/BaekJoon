#include <iostream>
#include <algorithm>
using namespace std;


string gridChallenge(vector<string> grid) {
    

    for (int i=0;i<grid.size();++i){
        sort(grid[i].begin(),grid[i].end());
    }
    
    for (int i=0;i<grid.size();++i){
        for (int j=0;j<grid[i].size()-1;++j){
            if (grid[i][j] > grid[i+1][j]){
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    vector<string> grid = {"ebacd", "fghij", "olmkn", "trpqs", "xywuv"};
    // sort(grid[0].begin(),grid[0].end());
    // cout<<grid[0][0];
    gridChallenge(grid);
}
