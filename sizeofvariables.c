#include<stdio.h>

int main()
{
  int a = 545;
  float b = 2.1;
  char c = 'z';
  double d = 62019023.8023948203;

  unsigned int j = 21;
  signed int k = -10;


  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("float b value: %f and size: %lu bytes\n", b, sizeof(b));
  printf("char c value: %c and size: %lu bytes\n", c, sizeof(c));
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));
  printf("unsigned int j value: %d and size: %lu bytes\n", j, sizeof(j));
  printf("signed int k value: %d and size: %lu bytes\n", k, sizeof(k));

}

