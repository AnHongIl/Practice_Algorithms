/*
Cautions
1. Make the code as abstract as possible
  - Array is not needed to solve the problem.
2. Escape from a naive solution.
  - I don't need to follow one-by-one!
  - Remove the loop as much as possible.
3. Carefully see a state.
 */

#include <iostream>
#include <cmath>

int getPosition(int d, int balls){
  int v = 1;
  
  for(int i=1; i<d; i++){
    if(balls & 1){
      v *= 2;
      balls = balls / 2 + 1;
    }else{
      v = 2*v + 1;
      balls = balls / 2;
    }
  }

  return v;
}

int main(){
  int test_cases;
  scanf("%d", &test_cases);
  for(int t=0; t<test_cases; t++){
    int d, i;
    scanf("%d %d", &d, &i);

    printf("%d\n", getPosition(d, i));
  }
  scanf("%d", &test_cases);
}
