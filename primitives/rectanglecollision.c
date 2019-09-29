#include "rectanglecollision.h"

int rectanglecollision(struct rectangle data1, struct rectangle data2)
{
   if(((data2.x1 >= data1.x1 && data2.x1 <= (data1.x2 + data1.x1)) || ((data2.x2 + data2.x1) >= data1.x1 && (data2.x2 + data2.x1) <= (data1.x2 + data1.x1))) && ((data2.y1 >= data1.y1 && data2.y1 <= (data1.y2 + data1.y1)) || ((data2.y2 + data2.y1) >= data1.y1 && (data2.y2 + data2.y1) <= (data1.y2 + data1.y1))))
   {
      return 1;
   }

   return 0;
}

