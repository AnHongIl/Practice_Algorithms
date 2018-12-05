#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int a, b, rows[9], lineCounter;

bool place(int queen, int row){
  for(int prev=1; prev<queen; prev++)
    if(rows[prev] == row || (abs(rows[prev] - row) == abs(prev - queen)))
      return false;
  return true;
}

void NQueens(int queen){
  for(int row = 1; row<=8; row++){
    if(place(queen, row)){
      rows[queen] = row;
      if(queen == 8 && rows[b] == a){
	printf("%2d      %d", ++lineCounter, rows[1]);
	for(int j=2; j<=8; j++) printf(" %d", rows[j]);
	printf("\n");
      }else
	NQueens(queen + 1);
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &a, &b);
    lineCounter = 0;
    memset(rows, 0, sizeof(int)*9);
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    NQueens(1);
    if(n) printf("\n");
  }
}
