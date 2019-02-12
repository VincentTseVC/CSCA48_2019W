#include<stdio.h>
#include<stdlib.h>





void solveMagicSquare(int square[6][6]) {
  int sum = 111; //6*(6*6 + 1) / 2

  int row_unknown[6] = {0, 0, 0, 0, 0, 0}; // {0, 2, 0, 1, 1, 1}
  int col_unknown[6] = {0, 0, 0, 0, 0, 0}; // {0, 2, 0, 1, 1, 1}

  int row, col, r, c;
  int didRow = 0;

  for (row = 0; row < 6; row++) {
    for (col = 0; col < 6; col++) {
      if (square[row][col] == -1) {
        row_unknown[row]++;
        col_unknown[col]++;
      }
    }
  }

  for (row = 0; row < 6; row++) {
    if (row_unknown[row] == 1) {
      didRow = 1;
      for (col = 0; col < 6; col++) {
        if (square[row][col] == -1)
          c = col;
      }

      square[row][c] = sum - (square[row][0] + square[row][1] + square[row][2] + square[row][3] + square[row][4] + square[row][5] + 1);
      col_unknown[c]--;
    }
  }

  for (col = 0; col < 6; col++) {
    if (col_unknown[col] == 1) {
      for (row = 0; row < 6; row++) {
        if (square[row][col] == -1)
          r = row;
      }

      square[r][col] = sum - (square[0][col] + square[1][col] + square[2][col] + square[3][col] + square[4][col] + square[5][col] + 1);
      row_unknown[r]--;
    }
  }


  if (didRow == 0) {
    for (row = 0; row < 6; row++) {
      if (row_unknown[row] == 1) {
        for (col = 0; col < 6; col++) {
          if (square[row][col] == -1)
            c = col;
        }
        square[row][c] = sum - (square[row][0] + square[row][1] + square[row][2] + square[row][3] + square[row][4] + square[row][5] + 1);
      }
    }
  }


}




// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;


   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};
    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
