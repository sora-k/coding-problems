//started 4/2/17 7:00AM - 8:00AM
// 				 5:00PM - 7:00PM

// TODO: took too many trials!!!
//		 READ THE PROBLEM CAREFULLY!!
//		 redo the problem, don't look at the solution!
//		 study other solutions!!!!

#include <math.h>

//brute force
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        
        int result = 0;
        
        double distance;
        int new_boom_cnt, old_boom_cnt;
        
        unordered_map<double, int> map_distances;
        vector<pair<int, int>>::iterator it_i;
        vector<pair<int, int>>::iterator it_x;
       	double x1, x2, y1, y2;

        for(it_i = points.begin(); it_i != points.end(); ++it_i){
        	map_distances.clear();
            
            //cout<<"================="<<endl;
            it_x = (points.begin() == it_i) ? points.begin() + 1 : points.begin();
        	for(; it_x != points.end();  it_x = (it_x + 1) == it_i ? it_x + 2 : it_x + 1){
       			x1 = std::get<0>(*it_i); 	y1 = std::get<1>(*it_i);
       			x2 = std::get<0>(*it_x); 	y2 = std::get<1>(*it_x);
       			
       			distance = (double)sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
                
                //  cout<<"x1:"<<x1<<" y1:"<<y1<<" x2:"<<x2<<" y2:"<<y2<<endl;
                //  cout<<"distance:"<<distance<<endl;
                
       			if(map_distances.find(distance) != map_distances.end()){
       			    old_boom_cnt = map_distances[distance] * (map_distances[distance] - 1);
       			    map_distances[distance]++;
       			    new_boom_cnt = map_distances[distance] * (map_distances[distance] - 1);
       			    
       			    result = (map_distances[distance] == 1) ? result : result - old_boom_cnt; //sub old boom cnt if not 1 so that we can update with an updated cnt
       			    result += new_boom_cnt;
       			}
       			else
       				map_distances.insert({distance, 1});
       		}
  	  	}
  	  	return result;
    }
        	
};
/*
[[1,0],[1,2],[2,4]]
[[0,0],[1,0],[2,0]]
[[0,0],[1,0],[-1,0],[0,1],[0,-1]]
[[1,1],[2,2],[3,3],[4,4],[5,5],[6,6],[7,7],[8,8]]
*/