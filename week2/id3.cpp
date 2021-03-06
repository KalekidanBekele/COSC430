#include <cstdio>
#include <iostream>
using namespace std;

struct intdouble {
  int i;
  double d;
};

int main()
{
  intdouble id1, id2;

  id1.i = 5;          /* Set id1 to 5 and 3.14 as before. */
  id1.d = 3.14;

  id2 = id1;          /* This makes a copy of id and then adds 5 to each field. */
  id2.i += 5;
  id2.d += 5;

  printf("1: %d %.2lf\n", id1.i, id1.d);   /* Print them out. */
  printf("2: %d %.2lf\n", id2.i, id2.d);

  return 0;
}

