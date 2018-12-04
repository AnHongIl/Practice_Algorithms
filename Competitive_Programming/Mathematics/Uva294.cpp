#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

bitset<100010> bs;
vector<int> primes;

void sieve(int upperbound){
  bs.reset();
  bs.flip();

  bs.set(0, false);
  bs.set(1, false);

  for(long long i=2; i<=upperbound+1; i++){
    if(bs.test((int)i)){
      for(long long j=i*i; j<=upperbound+1; j += i)
	bs.set((int)j, false);
      primes.push_back((int)i);
    }
  }
}

vector<int> primeFactors(int n){
  vector<int> factors;
  int idx=0;
  int PF = primes[idx];

  while(n != 1 && (PF <= n)){
    int cnt=0;
    while(n % PF == 0){
      n /= PF;
      cnt++;
    }
    factors.push_back(cnt);
    if(idx+1 == primes.size())
      break;
    PF = primes[++idx];
  }
  
  return factors;
}

int getDivisors(int n){
  vector<int> factors = primeFactors(n);
  int l=1;
  for(int i=0; i<factors.size(); i++)
    l *= (factors[i] + 1);

  return l;
}

int main(){
  sieve(100000);
  int N;
  scanf("%d", &N);

  for(int t=0; t<N; t++){
    int L, U;
    scanf("%d %d", &L, &U);
    int P=L;
    int D=0;
    for(int i=L; i<=U; i++){
      int d = getDivisors(i);
      if(d > D){
	D = d;
	P = i;
      }
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, P, D);
  }
}
