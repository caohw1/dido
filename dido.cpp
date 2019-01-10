
#include "dido.h"
#include <cstdio>


int
dido_test()
{

  dido<int> dd;
  
  printf("\n");
  dd.push_back(2);
  dd.push_back(1);
  dd.push_front(3);
  dd.push_front(4);
  dd.push_front(5);
  dd.push_front(6);

  while(!dd.empty()) {
    const auto d = dd.back(); dd.pop_back();
    printf("%i\n", d);
  }
  
  printf("\n");
  dd.push_back(2);
  dd.push_back(1);
  dd.push_front(3);
  dd.push_front(4);
  dd.push_front(5);
  dd.push_front(6);

  while(!dd.empty()) {
    const auto d = dd.front(); dd.pop_front();
    printf("%i\n", d);
  }
  
  return 0;
}



#ifdef _TEST
int main() {return dido_test();}
#endif

