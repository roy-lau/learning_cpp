#include <stdio.h>

int main() {
  int i = 1;
  printf("i is %d\n", i);
  int *d;
  printf("d is %p\n", d);
  printf("d is %p\n", &d);

  int year = 2022;
  int *p_year;
  p_year = &year;
  printf("year is %d\n", year);
  printf("&year is %p\n", &year);
  printf("p_year is %p\n", p_year);
  printf("*p_year is %d\n", *p_year);
  printf("&p_year is %p\n", &p_year);

  return 0;
}