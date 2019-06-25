#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int a = x;
  int b = 1;
  int i;
  for(i = 0; i < n; i++){
    if(x < A[i]){
      b = n + 1;
      break;
    }
    else if(a >= A[i]) a -= A[i];
    else{
      a = x - A[i];
      b++;
    }
  }
  return b <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 100000;
  while(ub - lb > 1){
    int m = (lb + ub) / 2;
    if(p(m)) ub = m;
    else lb = m;
  }

  printf("%d\n",ub);

  return 0;
}
