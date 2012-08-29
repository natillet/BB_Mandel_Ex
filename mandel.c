#include "stdio.h"

#define MaxIters 200
#define SIZE     1000
#define BLACK    -1
#define LEFT     -2.0
#define RIGHT    1.0
#define TOP      1.0
#define BOTTOM   -1.0
#define CVT_SIZE 7

int main(int argc, char *argv[])
{
  short   x, y, count;
  float zr, zi, cr, ci;
  float rsquared, isquared;
  unsigned image[SIZE][SIZE];
  char cvt[CVT_SIZE+1] = "* .-+#@";

  for (y = 0; y < SIZE; y++)
    {
      for (x = 0; x < SIZE; x++)
        {
	  zr = 0.0;
	  zi = 0.0;
	  cr = LEFT + x * (RIGHT - LEFT) / SIZE;

	  ci = TOP + y * (BOTTOM - TOP) / SIZE;
	  rsquared = zr * zr;
	  isquared = zi * zi;

	  for (count = 0; rsquared + isquared <= 4.0
		 && count < MaxIters; count++)
            {
	      zi = zr * zi * 2;
	      zi += ci;

	      zr = rsquared - isquared;
	      zr += cr;

	      rsquared = zr * zr;
	      isquared = zi * zi;
            }

	  if (rsquared + isquared <= 4.0)
	    image[x][y] = 0;
	  else
	    image[x][y] = count;

        }
    }

  if (argc > 1) {
    for (y = 0; y < SIZE; y++)
      {
	for (x = 0; x < SIZE; x++)
	  {
	    printf("%c", cvt[(image[x][y])/CVT_SIZE]);
	  }
	printf("\n");
      }
  }
  return 0;
}
