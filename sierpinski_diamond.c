#include <stdio.h>
#include <math.h>
#include<stdlib.h>

void print_row(int row, int height, int level){
    //if you are at the base level simply print the stars and spaces of that row
    if(level == 1){
        int space, stars;
        for(space=(height-row); space>=1; space--){
            printf(" ");
        }
        for(stars=1; stars<= ((2*row)-1); stars++){
             printf("*");
        }
        for(space=(height-row); space>=1; space--){
            printf(" ");
        }
        return;
    }  
    //if you are in the top half
    if(row<=(height/2)){
        //print enough spaces so recursive triangle will shift to the correct place 
        int i; 
        int width = ((2*height)-1);
        for(i=0; i<=(width/4); i++){
            printf(" ");
        }
        //call on print row with a decreased level 
        print_row(row, (height/2), (level-1));
        for(i=0; i<=(width/4); i++){
            printf(" ");
        }
    }
    else{
        //if you are in the bottom row, need to print 2 recursive triangles separated by a space 
        print_row((row-(height/2)), (height/2), (level-1));
        printf(" ");
        print_row((row-(height/2)), (height/2), (level-1));
    }
    return; 
}

//same thing as print_row but reversed. 
void print_reverse_row(int row, int height, int level){
    if(level == 1){
        int space, stars;
        for(space=1; space<=(height-row); space++){
            printf(" ");
        }
        for(stars=((2*row)-1); stars>= 1; stars--){
             printf("*");
        }
        for(space=0; space<=(height-row); space++){
            printf(" ");
        }
        return;
    }
    //if you are in the top half need to print two recursive triangles (dont have to add a space since accounted for it in print_row)
    if(row>(height/2)){
        print_reverse_row((row-(height/2)), (height/2), (level-1));
        print_reverse_row((row-(height/2)), (height/2), (level-1));
    }
    //if you are in the bottom half print appropriate spaces to shift recursive triangle to correct position then print recursive triangle
    else{
        int i; 
        int width = ((2*height)-1);
        for(i=0; i<=(width/4); i++){
            printf(" ");
        }
        print_reverse_row(row, (height/2), (level-1));
        for(i=0; i<=(width/4); i++){
            printf(" ");
        }
    }
    return;   
}
    
int main(int argc, char *argv[]){ 

    if(argc != 3){
        printf("ERROR: Wrong number of arguments. Two required");
        return 0;
    }

    int height= atoi(argv[1]); 
    int row; 
    int level= atoi(argv[2]);
    int triangleheight= (height/2)+1; 
    //if the input matches the required formats, loop through half the height and call on print_row, then loop through the other half of the height-1 and call on print_reverse_row
    if(ceil(log(triangleheight)/log(2)) == floor(log(triangleheight)/log(2))  && (triangleheight >= pow(2, (level-1)))){
        for(row=1; row<= triangleheight; row++){
        print_row(row, triangleheight, level);
        printf("\n");
        }

        for(row=triangleheight-1; row>=1; row--){
        print_reverse_row(row, triangleheight, level);
        printf("\n");
        }
        return 0; 
    }
    //if the input coniditions are not met print an error to the screen to avoid segfaults 
    else{
        printf("ERROR: Height does not allow evenly dividing requested number of levels.");
        return 0; 
    }
}


