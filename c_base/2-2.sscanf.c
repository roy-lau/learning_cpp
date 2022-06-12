#include <stdio.h>

int main() {
  char str[] = "hello word I\'m RoyLau";
  char temp[4][100] = { 0 }; // 二维数组

  sscanf(str, "%s %s %s %s", temp[0], temp[1], temp[2], temp[3]);
  for (int i = 0;i < 4;i++) {
    printf("temp[%d] = %s\n", i, temp[i]);
  }
  
  return 0;
}