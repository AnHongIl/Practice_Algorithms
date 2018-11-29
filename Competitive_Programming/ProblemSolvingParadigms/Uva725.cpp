/*
Cautions
1. If you don't abide by the rule of the output, Time limit exceeded can happen.
2. When the complete search solution is used, be sure to deliberate what the minimum range of the search space is
3. In order to fill zero, use stringstream.
4. stringstream clear() is to initialize a flag, not to initialize stringstream.
   - For initializing stringstream, ss.str("").
 */

#include <iostream>
#include <stdio.h>

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

bool isSatisfy(int denominator, int N){
  string no = to_string(denominator * N);
  if(no.size() > 5)
    return false;

  stringstream ss;
  ss << setw(5) << setfill('0') << denominator * N;
  no = ss.str();

  ss.str("");
  ss << setw(5) << setfill('0') << denominator;
  string de(ss.str());

  int arr[10] = {0};
  for(int i=0; i<5; i++)
    arr[no[i] - '0'] += 1;

  for(int i=0; i<5; i++)
    arr[de[i] - '0'] += 1;

  for(int i=0; i<10; i++)
    if(arr[i] != 1)
      return false;

  return true;
}

bool findAll(int N){
  bool isFind = false;

  for(int de = 1234; de<=98765; de++){
    if(isSatisfy(de, N)){
      printf("%05d / %05d = %d\n", de*N, de, N);
      isFind = true;
    }
  }

  return isFind;
}

int main(){
  int N;
  bool line=false;
  
  while(scanf("%d", &N) == 1){
    if(N == 0)
      break;
    
    if(line){
      printf("\n");
      line=false;
    }
    if(!findAll(N))
      printf("There are no solutions for %d.\n", N);
    line=true;
  }
}
