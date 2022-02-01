/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
AUTHOR:B.AJAY
License:Apache 2.0
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Comments:
        This program computes PI using random numbers between 0,1
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef  long long int LARGE_NUM;                               //typedef long long int 
int main(void) {
  LARGE_NUM points=0;
  LARGE_NUM *ptr;
  ptr=&points;
  srand((unsigned long long int )ptr);                          //Seeding a random memory location seemed more fitting than seeding the current time as u_int32 
  LARGE_NUM points_in_circle=0;
  printf("Enter the number of sample points 100000<x<10000000\n");
  scanf("%Ld",&points);
  for (int i=0;i<points;i++){
    float x_coor=(((float)rand()/RAND_MAX));                    //RAND_MAX defined as macro in <stdlib.h> any random number / RAND_MAX <1
    float y_coor=(((float)rand()/RAND_MAX));                    //For y coordinate
    if(sqrt((double)pow((double)x_coor,2)+(double)pow((double)y_coor,2))<=1){points_in_circle++;}//Check if point is in unit circle
    else{continue;}
  }
  printf("Value of  π approx : %lf\n",points_in_circle*4/(double)points);
  return 0;
}
