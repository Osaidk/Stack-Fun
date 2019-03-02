//
// Created by Osaid K on 10/4/18.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stack_ll.h>

//int argc, char *argv[]
int main () {
    int row = 0;
    int col=0;
    int entry_row=0;
    int entry_col=0;
    char old_color;
    char entry_color;
    char grid[25][25];
    char fName[80];
    Stack312 pass;
    StackEntry element;

   // strcpy( fName, argv[1]);
    FILE *fptr;
    fptr = fopen("fake_picture.txt", "r");
    char buf[BUFSIZ];

    while (fscanf(fptr, "%s", buf) != EOF) {
     strcpy(grid[row], buf);
        row++;
    }

    col = strlen(grid[0]);
    for (int k = 0; k < row; k++) {
        printf("%s", grid[k]);
        printf("\n");
    }

    while (1) {   // always run, unless termination code is pushed
        printf("\n");
        printf("enter row number :");
        scanf("%d", &element.row);
        printf("enter column number :");
        scanf("%d",&element.col);
        printf("enter color :");
        scanf("%s", &entry_color);

        entry_row = element.row;   // Checking for termination code!!
        entry_col = element.col;   // Checking for termination code!!

        if(entry_row==-1 || entry_col==-1) {
            printf("\n");
            printf("-----------------------");  // Checking for termination code!!
            return (0);
        }

        old_color = grid[element.row][element.col]; // Saving older color of a pixel for comparison
        element.color=old_color;
        push(element, &pass); // Pushing First element to stack.

        while (!isEmpty(pass) && (old_color != entry_color)) {  // if stack isn't empty, and the new color isn't the same as the old, go through!
            element = pop(&pass);
            grid[element.row][element.col] = entry_color;  // updating pixel with new color

          for (int k = -1; k < 2; k++) {      // Here, these loops make it possible to inspect the neighbors of each pixel
             for (int f = -1; f <= 1; f++) {
                 if ((element.row + k < 0) || (element.row + k > row -1) || (element.col + f < 0) ||
                       (element.col + f > col-1)){
                     continue;
                 }
                 if (grid[element.row + k][element.col + f] == old_color) { //checking any pixels that need to be pushed for updating
                     element.row = element.row + k;
                     element.col = element.col + f;
                     element.color = grid[element.row + k][element.col + f];
                     if(!isFull(pass)) {
                         push(element, &pass);
                     }
                     else { printf("Error!! Stack is Full!!");}
                  }
             }
          }

        }

        printf("\n");
        for (int k = 0; k < row; k++) {
            printf("%s", grid[k]);
            printf("\n");
        }






    }


}


