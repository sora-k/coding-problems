//Island Perimeter
//started 4/12/17 5:49PM - 6:07PM
//				  8:03PM - 8:22PM
//TODO: improve efficiency

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        //at every grid cell, check up, down, left, right for neighbors
        //grid is rectangular
        int result_count = 0;
      	int i, j;
      	for(i = 0; i < grid.size(); ++i){
      		for(j = 0; j < grid[i].size(); ++j){
      			if(grid[i][j] == 1){
      				if(j - 1 >= 0) 									//look left
      					result_count = grid[i][j - 1] == 1 ? result_count : result_count + 1;
      				else
      					result_count++;
      				if(j + 1 < grid[i].size())						//look right
      					result_count = grid[i][j + 1] == 1 ? result_count : result_count + 1;
      				else
      					result_count++;
      				if(i - 1 >= 0 && j < grid[i - 1].size()) 		 //look up
      					result_count = grid[i - 1][j] == 1 ? result_count : result_count + 1;
      				else
      					result_count++;
      				if(i + 1 < grid.size() && j < grid[i + 1].size())//look down												//look down
      					result_count = grid[i + 1][j] == 1 ? result_count : result_count + 1;
      				else
      					result_count++;
      			}
      		}
      	}
      	return result_count;
    }
};