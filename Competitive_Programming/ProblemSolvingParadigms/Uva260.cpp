#include <iostream>
#include <vector>

using namespace std;

int N;
char board[200][200];
int neighbors[6][2] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};

bool isBlackWin(int row, int col){
  if(row < 0 || col < 0 || row >= N || col >= N)
    return false;

  if(board[row][col] == 0 || board[row][col] == 'w')
    return false;

  if(row == N-1)
    return true;
  
  board[row][col] = 0;

  for(int i=0; i<6; i++)
    if(isBlackWin(row + neighbors[i][0], col + neighbors[i][1]))
      return true;

  return false;
}

bool getWinner(){
  for(int col=0; col<N; col++)
    if(isBlackWin(0, col))
      return true;

  return false;
}

int main(){
  for(int test_case=1; ; test_case++){
    scanf("%d", &N);

    if(N == 0)
      break;

    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
	scanf(" %c", &board[i][j]);

    if(getWinner())
      printf("%d B\n", test_case);
    else
      printf("%d W\n", test_case);
  }
}
