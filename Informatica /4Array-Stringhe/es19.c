/* confronta se due stringhe sono identiche */

#include "libstring.h"
#include <stdio.h>
#include <stdlib.h>

typedef char* string;



void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n'){}
}

int confrontaStringhe(string s1, string s2){
    
    if(strlen(s1) != strlen(s2)){
        return 0;
    }

    for(int i=0; s1[i] != '\0'; i++){
        if(s1[i]!=s2[i]){
            return 0;
        }
        
    }

    printf("Le stringhe sono uguali");

}

