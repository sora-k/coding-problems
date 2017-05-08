//12/6/16 (paper solution) 8:55PM - 9:40PM (NOT DONE!)
//12/7/16       "          10:48PM - 11:31PM

int power(int num, int power){

    int result = 1;
    
    if(power == 0){
        return result;
    }
    result = num;
    while(power > 1){
        result *= num;
        power--;
    }

    return result;
}
int count_char(char *s){

    int count = 0;
    while(*s != NULL){
        count++;
        s++;
    }

    return count;
}
char to_lower_case(char s){

    char result = s;

    if( s >= 'A' && s <= 'Z'){
        char offset = s - 'A';
        result = 'a' + offset;
    }
    return result;

}
int titleToNumber(char* s) {
    
    int result = 0;
    int size = count_char(s);
    int pwr = size - 1;
    int i;
    for(i = 0; i < size; i++){
        int multiplier = (to_lower_case(s[i]) - 'a') + 1;
        result += multiplier * power(26,pwr);
        pwr--;
    }
    
    return result;
}
/*
"A"
"AA"
"AB"
"AAA"
"AAAA"
"ZZZ"
*/return result;
}