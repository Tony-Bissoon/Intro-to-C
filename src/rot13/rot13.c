#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv){
    
    if (argc != 2) {
        
        return EXIT_FAILURE; 
    }

    char *input = argv[1];

    
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        
        if (isalpha(c)) {
            
            char al = (islower(c)) ? 'a' : 'A';

            
            putchar((((c - al) + 13) % 26) + al);
        } else {
            
            putchar(c);
        }
    }

    putchar('\n'); 
    return EXIT_SUCCESS; 
}



    
    
     