#include "e2a.h"

void e2a(__u8 *ptr, unsigned int size)
{
 unsigned int i;
 __u8 tmp;
  for (i=0;i<size;i++)
    {
      tmp = (__u8) ptr[i];
      ptr[i] = ebcdic2ascii[tmp];
    }
}
