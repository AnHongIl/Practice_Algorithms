#include <iostream>
#include <cmath>

void get(int n, int& i, int& v, int& x, int& l, int& c){
  if(n == 100)
    c++;
  else if(40 <= n && n < 50){
    x++;
    l++;
    if(1 <= (n % 10) && (n % 10) < 4)
      for(int j=0; j< n % 10; j++)
	i++;
    else if(n % 10 == 4){
      i++;
      v++;
    }else if(5 <= n % 10 && n % 10 < 9){
      v++;
      for(int j=5; j< n % 10; j++)
	i++;
    }else if(n % 10 == 9){
      i++;
      x++;
    }
  }else if(90 <= n && n < 100){
    x++;
    c++;
    if(1 <= (n % 10) && (n % 10) < 4)
      for(int j=0; j< n % 10; j++)
	i++;
    else if(n % 10 == 4){
      i++;
      v++;
    }else if(5 <= n % 10 && n % 10 < 9){
      v++;
      for(int j=5; j< n % 10; j++)
	i++;
    }else if(n % 10 == 9){
      i++;
      x++;
    }
  }else if(n < 10){
    if(1 <= n  && n  < 4)
      for(int j=0; j<n; j++)
	i++;
    else if(n == 4){
      i++;
      v++;
    }else if(5 <= n && n < 9){
      v++;
      for(int j=5; j< n; j++)
	i++;
    }else if(n == 9){
      i++;
      x++;
    }
  }else{
    int t = n;
    if(n >= 50){
      l++;
      t -= 50;
    }

    t /= 10;

    for(int j=0; j<t; j++)
      x++;
      
    if(1 <= (n % 10) && (n % 10) < 4)
      for(int j=0; j< n % 10; j++)
	i++;
    else if(n % 10 == 4){
      i++;
      v++;
    }else if(5 <= n % 10 && n % 10 < 9){
      v++;
      for(int j=5; j< n % 10; j++)
	i++;
    }else if(n % 10 == 9){
      i++;
      x++;
    }
  }
}

int main(){
  int n;
  while(scanf("%d", &n) == 1){
    if(n == 0)
      break;

    int i=0, v=0, x=0, l=0, c=0;
    for(int j=1; j<=n; j++)
      get(j, i, v, x, l, c);
    printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i, v, x, l, c);
  }
}
