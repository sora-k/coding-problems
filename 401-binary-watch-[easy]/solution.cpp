//started 4/24/17 2:43PM - 3:04PM (stuck)
//TODO: keep your mind open!!
//      solution was extreamely straight forward (go through all the possible time) haha!!
//NOTE: if stuck for a long time, just look up the solution!!
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
       
        vector<string> result;
        char buffer[50];
        int  len,one_cnt;
 
        for(int hour = 0; hour <= 11; ++hour){
           for(int minute = 0; minute <= 59; ++minute){
               one_cnt = one_bit_cnt(hour) + one_bit_cnt(minute);
               if(one_cnt == num){
                  len = sprintf (buffer, "%d:%02d", hour, minute);
                  string tmp(buffer, len);
                  result.push_back(tmp);
               }
           }
        }
        return result;
    }
private:
    int one_bit_cnt(int n){
    int count = 0;
    while(n > 0){
        n = n & (n - 1);
        ++count;
    }
    return count;
    }
};