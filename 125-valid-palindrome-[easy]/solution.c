// started 11/28/16 (paper solution) 10:43 - 10:50pm
// started 12/1/16	(coding) 7:50AM - 8:21AM, (another solution) 8:21AM - 8:49AM
#include <ctype.h>

bool isPalindrome(char* s) {
	bool result = true;
	char *t = s;
	int size = 0;
	
	while(*t != NULL){
		size++;
		t++;
	}
	if(size == 0){
		return result;
	}
	int i =0; int l = size - 1;
	while(i <= l){
		char f = s[i];
		char b = s[l];
		int isF = isalnum(f);
		int isB = isalnum(b);

		if(isF  &&  isB){
			if(tolower(f) != tolower(b)){
				result = false;
				break;
			}
			i++; l--;
		}else{
			i = (isF == 0) ? i + 1 : i;
			l = (isB == 0) ? l - 1 : l;
		}
	}
	return result;
}
/*v1 */
/*
bool isPalindrome(char* s) {
	bool result = true;
	char *t = s;
	char *reversedStr;
	char *str;
	int size = 0;
	
	while(*t != NULL){
		if(isalnum(*t) != 0){
			size++;
		}
		t++;
	}
	if(size == 0){
		return result;
	}
	
	reversedStr = (char *)malloc(sizeof(char) * (size + 1));
	str = (char *)malloc(sizeof(char) * (size + 1));
	t = s;
	int i = 0; int l = size - 1;
	while(*t != NULL){
		if(isalnum(*t) != 0){
			reversedStr[l] = tolower(*t);
			str[i] = tolower(*t);
			i++; l--;
		}
		t++;
	}
	reversedStr[size] = '\0'; str[size] = '\0';

	for(i = 0; i < size; i++){
		if(reversedStr[i] != str[i]){
			result = false;
			break;
		}
	}
	free(reversedStr);
	free(str);

	return result;
}
*/