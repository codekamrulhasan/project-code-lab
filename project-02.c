 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MA 1000000000000000000 // 1e18
#define M  1000000007
#define MM 1000050
#define K  1000005
typedef long long ll;

ll m,n;

ll x[K];
ll h[K];
ll s[K];

int main() {
  int t;
  ll i,j,k,l,r,jl, jr, dh, dx, high, low;

  t=1;

  while(t--) {
    scanf("%lld", &n);

    for(i=0;i<n;i++) {
      scanf("%lld", x+i);
      scanf("%lld", h+i);
    }


    for(i=0;i<n-1;i++) {
      for(j=i+1;j<n;j++) {
        dh = h[j]-h[i];
        dx = x[j]-x[i];
        if (dh<dx) {
          if (i==0)
            s[j]=dh*dh + dx*dx;
          else
            s[j]=MIN(s[j], MAX(s[i], dh*dh + dx*dx));
        } else if (i==0)
          s[j]=MA;

      }

    }

    if (s[n-1]>=MA) {
      puts("-1");
    } else
      printf("%lld\n", s[n-1]);
  }
}
