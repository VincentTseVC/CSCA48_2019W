#include<stdio.h>
#define MAX_STR_LEN 2048

void stringLength(char *str, int *len) {

  int i;
  for (i = 0; i < MAX_STR_LEN; i++) {
    // if (str[i] == '\0') 
    if (*(str + i) == '\0') 
      break;
  }

  *len = i;        
}

void stringCopy(char *destStr, char *srcStr) {

  int srcLen = 0;
  stringLength(srcStr, &srcLen);
  // for (int i = 0; i < MAX_STR_LEN; i++) 
  for (int i = 0; i < srcLen + 1; i++)
    // *(destStr + i) = *(srcStr + i);
    destStr[i] = srcStr[i];
}

int main() {
  char string1[MAX_STR_LEN]="To see a world in a grain of sand,";
  char string2[MAX_STR_LEN]="And a heaven in a wild flower.";
  int len1,len2;

  len1=0;
  len2=0;
  printf("%s\n",string1);
  printf("%s\n",string2);

  stringLength(string1, &len1);
  stringLength(string2, &len2);

  printf("String 1 is %d characters long\n",len1);
  printf("String 2 is %d characters long\n",len2);

  stringCopy(string2, string1);

  printf("%s\n",string1);
  printf("%s\n",string2);

  return 0;

}
