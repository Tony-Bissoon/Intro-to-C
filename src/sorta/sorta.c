#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {
    if (argc <= 1) {
        
        return EXIT_FAILURE; 
    }

    int swapped;
    do {
        swapped = 0;
        for (int i = 1; i < argc - 1; i++) {
            if (strcmp(argv[i], argv[i + 1]) > 0) {
                // Swap the arguments if they are out of order
                char *temp = argv[i];
                argv[i] = argv[i + 1];
                argv[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);

    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return EXIT_SUCCESS;
    
}
