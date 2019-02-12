#include<stdio.h>
#include<stdlib.h>

void printImgArray(int array[10][10])
{
 // Print out the contents of the array, it can be
 // used with the original array, or with the labeled
 // output after calling cell_count().
  
 printf("------ Image Contents -------\n");
 for (int i=0; i<10; i++)
 {
   for (int j=0; j<10; j++)
     printf("%02d, ",array[i][j]);
   printf("\n");
 }
 printf("-----------------------------\n");
}


// A function to check if a given cell (row, col) can be included in DFS 
int is_safe(int image[10][10], int row, int col) { 
  // row number is in range, column number is in range
  return (row >= 0) && (row < 10) && (col >= 0) && (col < 10) && (image[row][col]==1);  
}


void DFS(int image[10][10], int row, int col, int count) { 
    // These arrays are used to get row and column numbers of 8 neighbours of a given cell 
    int row_nbr[] = {-1, -1, -1,  0, 0,  1, 1, 1}; 
    int col_nbr[] = {-1,  0,  1, -1, 1, -1, 0, 1}; 
  
    // set the label
    image[row][col] = count;
    // Recur for all connected neighbours 
    for (int k = 0; k < 8; k++) 
      if (is_safe(image, row + row_nbr[k], col + col_nbr[k])) 
        DFS(image, row + row_nbr[k], col + col_nbr[k], count);
} 


int cell_count(int image[10][10]) {
  int count = 2;
  for (int row=0; row < 10; row ++) {
    for (int col=0; col < 10; col ++) {
      if (image[row][col]==1) {
        DFS(image, row, col, count);
        count++;
      }
    }
  }
 return count - 2;
}


#ifndef __testing
int main()
{
  // DO not change anything in main(), it will confuse the
  // auto-checker.  
  int count;
  int cellImg[10][10]={{0,0,1,1,0,0,1,0,0,1},\
           {1,0,1,1,0,0,1,1,0,1},\
           {1,0,0,1,1,0,1,1,0,1},\
           {1,1,0,0,0,0,0,0,0,0},\
           {1,0,0,1,1,1,0,0,1,0},\
           {0,0,0,0,1,0,0,1,1,0},\
           {0,0,1,0,0,1,0,1,0,0},\
           {0,0,1,1,0,0,1,0,0,0},\
           {0,0,1,0,0,0,0,0,1,1},
           {0,1,1,0,0,0,1,1,1,1}};
           
  printImgArray(cellImg);
  count=cell_count(cellImg);
  printImgArray(cellImg);
  printf("Total number of cells in the image: %d\n",count);
  
  return 0;
}
#endif