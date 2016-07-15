/* CS261- Assignment 1 - Q.5*/
/* Name: Sky Wilson
 * Date: 03/31/2015
 * Solution description: This program has 3 user defined functions. toUpperCase() returns a char, converted from a lowercase char (parameter) to an uppercase char. toLowerCase() returns a char, converted from an uppercase char to a lowercase char. sticky() is the 3rd function, it returns void, and loops through the chars of the char array, it use if loops to determine if the char element of the array is lower or uppercase and thus, calls the appropriate toUpperCase()/toLowerCase(). sticky() loops until the char element of the array is equivalent to a null ('\0') value, a marker of the end of a char array. In the main function, scanf() is employed to read in a char (40chars) from the user. 40 chars are statically allocated memory via malloc(). sticky() is then called with the argument being the user's read in string of chars held in a char array. Finally, printf() is used to print the user's char array post-sticky() manipulations. 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
	return toupper(ch);
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
	return tolower(ch);
}

void sticky(char* word){
     /*Convert to sticky caps*/
	int i = 0;
	while(word[i] != '\0'){
		if(word[i] >= 'A' && word[i] <= 'Z'){
			/* ith char is uppercase */
			word[i] = toLowerCase(word[i]);
		}	
		else if(word[i] >= 'a' && word[i] <= 'z'){
			/* ith char is LOWERCASE */
			word[i] = toUpperCase(word[i]);
		}
		i++;
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	printf("ENTER A WORD(no more than 40 characters): ");
	char *userChar = malloc(40 * sizeof(char));;
	scanf("%s", &(*userChar));
    /*Call sticky*/
	sticky(userChar);    
    /*Print the new word*/
	printf("%s\n\n", userChar); 
	
	return 0;
}

