// started 6:00 p.m. -> 9:06 p.m. 11/13/16

// General rules for roman numerals 
//	1. Smaller number in front of a larger number means substraction, all else means addition. e.g. IV - 4, VI - 6
// Best practice rules [But isn't strictly enforeced here --> http://www.onlineconversion.com/roman_numerals_advanced.htm AND http://www.mathatube.com/glo-roman-numerals.html]
//  2. No more than one smaller number in front of a larger number to substract.
//	3. You must separate ones, tens, hundreds, and thousands as separate items. That means that 99 is XCIX (90 + 9) NOT IC (100 -1)
//																													NOT IM (1000 - 1)
//																													NOT MIM (1000 + 1000 - 1)
// Observation -> the problem assunmes that the user put in the right input. Wrong input will product unexpected results.
//			   -> the solution isn't required to handle incorrect input!! 
#include <stdio.h>
#include <stdlib.h> 
int count_char(char *s){

	int count = 0;
	while(*s != NULL){
		count++;
		s++;
	}
	return count;

}
int romanToInt(char* s) {
    
    int result = 0;

    int size = count_char(s);

    int romValArr['X'];
    memset(romValArr,0,sizeof(romValArr));
    romValArr['I'] = 1;
    romValArr['V'] = 5;
    romValArr['X'] = 10;
    romValArr['L'] = 50;
    romValArr['C'] = 100;
    romValArr['D'] = 500;
    romValArr['M'] = 1000;


    int prev = 0;
    int cur = 0;
    int i;
    for(i = size - 1; i >= 0 ; i--){
    	char c = s[i];
    	cur = romValArr[c];

    	if(prev > cur){
    		result -= cur;
    		prev = 0;
    	}
    	else{
    		result += cur;
    		prev = cur;
    	}
    }
    
    return result;
}

/*
"I"
"II"
"III"
"IV"
"V"
"VI"
"VII"
"VIII"
"IX"
"X"
"XI"
"XII"
"XIII"
"XIV"
"XV"
"XVI"
"XVII"
"XVIII"
"XIX"
"XX"
"XXI"
"XXII"
"XXIII"
"XXIV"
"XXV"
"XXVI"
"XXVII"
"XXVIII"
"XXIX"
"XXX"
"XXXI"
"XL"
"L"
"LX"
"LXX"
"LXXX"
"XC"
"C"
"CI"
"CL"
"CC"
"CCC"
"CD"
"D"
"DC"
"DCC"
"DCCC"
"CM"
"M"
"MDC"
"MDCC"
"MCM"
"MMMCMXCIX"
*/	