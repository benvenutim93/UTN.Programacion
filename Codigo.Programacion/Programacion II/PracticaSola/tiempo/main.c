#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
   time_t sisTime;
   struct tm * tiempo;
   int mes;

   time(&sisTime);
   tiempo=localtime(&sisTime);
   mes=tiempo->tm_mon;
   printf ("MES %d \n",mes+1);
    return 0;
}
