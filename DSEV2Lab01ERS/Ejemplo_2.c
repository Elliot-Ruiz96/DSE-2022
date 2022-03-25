#include <stdio.h>
#include <conio.h>

main(void)
{
  int x;
  int *xPtr;
  int y;
  int *yPtr;
  int z;
  
  yPtr = &y;
  xPtr = &x;

  z = x * y;
  
  printf("x = %d \n", x);
  printf("y = %d \n", y);
  printf("z = %d \n\n", z);
  
  printf("Se aplica *xPtr = 10; y *yPtr = 2;\n");
  printf("El resultado es:\n");

  *xPtr = 10;
  *yPtr = 2;
  z = x * y;

  printf("x = %d \n", x);
  printf("y = %d \n", y);
  printf("z = %d \n\n", z);
  
  while(!kbhit());
}
