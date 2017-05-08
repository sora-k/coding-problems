// 11/29/16 (paper solution) 8:10 - 8:13PM
// 12/4/16  (coding)         6:00PM - 7:08PM

// NOTE: Redo! took too many trials

void get_numeric_arr(char *v, int *v_arr){

  int subVersion = 0;
  int index = 0;
  v_arr[index] = 0;

  while(*v != NULL){
       if(*v != '.'){
            if(*v >= '0' && *v <= '9'){
                v_arr[index] *= 10;
                v_arr[index] += *v - '0';
            }else{
                v_arr[0] = -1;
                break;
            }
       }else{
            index++;
            v_arr[index] = 0;
       }
       v++;
    }

}
int count_dot(char *version){

    int cnt = 0;
    while(*version != NULL){
        cnt = (*version == '.') ? cnt + 1 : cnt;
        version++;
    }
    return cnt;

}
int compareVersion(char* version1, char* version2) {
    
    int cnt1 = count_dot(version1) + 1;
    int cnt2 = count_dot(version2) + 1 ;
    
    int v1_arr[cnt1];
    int v2_arr[cnt2];

    get_numeric_arr(version1,v1_arr);
    get_numeric_arr(version2,v2_arr);

    if(v1_arr[0] == -1 && v2_arr[0] == -1){
        return 0;
    }

    int i,l;
    for(i = 0, l = 0; i < cnt1; i++){
        if(l < cnt2){
            if(v1_arr[i] > v2_arr[l]){
                return 1;
            }
            if(v2_arr[i] > v1_arr[l]){
                return -1;
            }
            l++;
        }else{
            if(v1_arr[i] > 0){
                return 1;
            }
        }
    }
    for(;l < cnt2; l++){
        if(v2_arr[l] > 0){
            return -1;
        }
    }
    
    return 0;
}

/*
"1"
"1.0"
"1"
"1"
".1"
".2"
"1.1"
"1.2"
"ab"
"1.1"
"1.1"
"1.10"
"1.0.1"
"1"
"1.0"
"1"
"1.0.0.0"
"1"
"1.0.0.0"
"1"
"1.0.0.0.1"
"1"
"1.0.0.0.1"
"1"
*/