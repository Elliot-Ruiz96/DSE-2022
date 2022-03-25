#include <stdio.h>
#include <conio.h>

main(void)
{
  int y;
  int *yPtr;
  
  y = 10;
  yPtr = &y;
  
  printf("The address of y is %p \n", &y);
  printf("The value of y is %d \n\n", y);
  
  printf("The address of yPtr is %p \n", &yPtr);
  printf("The value of yPtr is %p \n", yPtr);
  printf("The value of *yPtr is %d \n", *yPtr);
  
  while(!kbhit());
}
