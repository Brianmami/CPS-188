#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRANDSIZE 100


void clean (char before[], char after[]){

   int n = 0;

   for (int i = 0; i < strlen(before); i++){

        if (isalnum(before[i])){
            after[n] = tolower(before[i]);
            n++;
        }
   }

   after[n] = '\0';
}

void reverse (char before[], char after[], int c, int j){ //the clean string | array size of clean string 

    if (c == 0){
        after[j] = '\0';
        return;
    }
    after[j] = before [c-1]; 
    reverse(before, after, c-1, j+1);
    }

    

int main(){

    char test[100];
    char reversestring[100]; // setting variables

    printf ("what is the string you're checking: ");
    scanf ("%[^\n]", test); // gathering string 

    char temp[strlen(test)]; //setting the length of the string for use in the clean function

    printf("%s\n", test);

    clean(test, temp);

    printf("%s\n", temp);

    reverse (temp, reversestring, strlen(temp), 0); //calling reverse with the clean string, an empty string, the size of the string and zero for the recursive function

    printf("the reverse string is: %s\n", reversestring);

    if (strcmp(reversestring, temp) == 0){ //if the two strings are the same (are true)
    printf ("you found a palindrome in the sentence -> %s\n", test);
    } else {
        printf("you did not find a palindrome in in the sentence -> %s\n", test);
    }
    return (0);
}