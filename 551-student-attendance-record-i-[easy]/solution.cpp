// 4/22/17 6:17PM - 6:40PM

class Solution {
public:
    bool checkRecord(string s) {
        
        bool condition_1 = false; //more than one 'A' (absent) 
        bool condition_2 = false; //more than two continuous 'L' (late).

        int a_count = 0;
        int l_count = 0;

        string::iterator it;
        for(it = s.begin(); it != s.end(); ++it){
        	
        	if(*it == 'A')
        		a_count++;
        	if(*it == 'L')
        		l_count++;
        	if((*it != 'L') && (l_count < 3))
        		l_count = 0;

        }
        condition_1 = a_count > 1;
        condition_2 = l_count > 2;

        return (condition_1 == false) && (condition_2 == false);

    }
};

/*
"PPALLP"
"PPALLL"
"LALL"
*/