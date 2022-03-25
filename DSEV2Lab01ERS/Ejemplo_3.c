#include <stdio.h>
#include <conio.h>

int FN_Cube(int lx);
void SR_Cube(int *lx);

main(void)
{
  int x;
  int y;
  
  x = 2;
  y = 3;
  
  printf("x = %d \n", x);
  printf("y = %d \n", y);
  
  x = FN_Cube(x);
  SR_Cube(&y);
  
  printf("El resultado de x = FN_Cube(x) es: x = %d \n", x);
  printf("El resultado de SR_Cube(&y) es: y = %d \n", y);

  while(!kbhit());
}

int FN_Cube(int lx)
{
  int result;
  
  result = lx * lx * lx;
  
  return result;
}

void SR_Cube(int *lx)
{
  int result;
  
  result = (*lx) * (*lx) * (*lx);
  
  *lx = result;
}
