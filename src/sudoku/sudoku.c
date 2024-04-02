#include <stdio.h>
#include <stdlib.h>


int sukodu(int grid[9][9]){
    // Can not be in the same col or row
    int numExists = 1;
    for(int row=0 ; row < 9 && numExists ==1; row++){
        for(int col =0; col < 8 && numExists ==1; col++){

            for(int newC = col+1; newC < 9; newC++){
                if(grid[row][col]== grid[row][newC]){
                    numExists =0; 
                    return 0; 
                    break;
                }
            }

            for(int newR = row+1; newR < 9; newR++){
               if(grid[row][col]== grid[newR][col]){
                    numExists =0; 
                    return 0; 
                    break;
                }
            }
            
        }
    }

    if(numExists ==1){
        for(int row = 0; row < 9; row +=3){
            for(int col = 0; col < 9; col +=3){
                int oldVals[10]= {0};
                
                for(int i = row; i< row+3; i++){
                    for(int j = col; j < col+3; j++){
                        int value= grid[i][j];

                        if(oldVals[value] == 10){
                            numExists = 0;
                            return 0; 
                            break;
                        }
                        else{
                            oldVals[value] = 10;
                        }
                    }
                    if(numExists==0){
                        break;
                    }
                }
                
            }
            if(numExists ==0){
                break;
            }
        }
    }
    return 1;
}


int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1], "r");

    if(input == NULL){
        printf("ERROR \n");
        return EXIT_FAILURE;

    }

    int grid[9][9];
    int solveable = 0;
    int Erow, Ecol = 0;
    for(int row =0; row < 9; row++){
        for(int col =0; col < 9; col++){
            char c; 
            while(fscanf(input, " %c", &c)==1 && (c == '\n' || c == '\r')){}

            

                if(c == '_'){
                    grid[row][col]= '0';
                    solveable =1; 
                    Erow = row;
                    Ecol = col;

                }
                else{
                    grid[row][col] = c - '0';
                }
            
        }
    }
    fclose(input);

    int valid_solution = 1; 
    

    if(solveable == 0){
        valid_solution = sukodu(grid);
        if(valid_solution == 1){
            printf("correct\n");
        }
        else{
            printf("incorrect\n");
        }
    }
    else{
        int fill = 1; 
        while(fill <= 9){
            grid[Erow][Ecol] = fill;
            valid_solution = sukodu(grid);
            if(valid_solution == 1){
                printf("solvable\n");
               
                return EXIT_SUCCESS;
                break; 
            }
            fill++;




        }
        
       printf("unsolvable\n");
        
    }
    return EXIT_SUCCESS;


}
