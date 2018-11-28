/*
Cautions
1. Variable type
  - If int is used, then segmentation fault 11 will happen

2. n's range & buffer size
  - In the middle of changing n, n can exceed buffer size

3. scanf in while loop
  - I follow UVA's example
 */

#include <iostream>
#include <algorithm>

#define SIZE 1000000

using namespace std;

unsigned int buffer[SIZE] = {0};

unsigned int getLen(unsigned int n){
  if(n < SIZE && buffer[n] > 0)
    return buffer[n];
  
  if(n == 1)
    return 1;

  if(n & 1)
    if(n >= SIZE)
      return getLen(3*n+1) + 1;
    else
      return buffer[n] = getLen(3*n+1) + 1;
  else
    if(n >= SIZE)
      return getLen(n/2) + 1;
    else
      return buffer[n] = getLen(n/2) + 1;
}

int main(){
  int i, j;

  while(scanf("%d %d", &i, &j) == 2){
    unsigned int len=0;
        
    for(unsigned int x=min(i,j); x<=max(i,j); x++)
      len = max(len, getLen(x));

    printf("%d %d %u\n", i, j, len);
  }
}
