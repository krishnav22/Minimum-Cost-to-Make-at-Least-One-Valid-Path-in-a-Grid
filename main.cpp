class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq; 

        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dist[0][0] = 0;
        pq.push({0,0,0});
        vector<int> dir = {0,1,0,-1,0};
        
        map<pair<int,int>,int> dirVal;
        dirVal[{0,1}] = 1;
        dirVal[{0,-1}] = 2;
        dirVal[{1,0}] = 3;
        dirVal[{-1,0}] = 4;
        while(!pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();
            if (top[1]==row-1 && top[2] == col-1) return dist[row-1][col-1]; 
            if (dist[top[1]][top[2]] < top[0]) continue; 

            for (int i = 0 ; i < 4 ; i++ ) 
            {
                int x = top[1] + dir[i];
                int y = top[2] + dir[i+1]; 
                if (x>=0 && x <grid.size() && y>=0 && y <grid[0].size())
                {
                    int dirCost = 0;
                    if (grid[top[1]][top[2]] != dirVal[{dir[i],dir[i+1]}]) 
                    {
                        dirCost = 1;
                    }
                    int currDist = top[0]+dirCost;
                    if (currDist < dist[x][y] ) 
                    {
                        dist[x][y] = currDist;
                        pq.push({currDist,x,y});
                    }
                }
            }
        }
        return dist[row-1][col-1];  
    }
};
