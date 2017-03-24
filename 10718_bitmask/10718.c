#include <math.h>
#include <stdio.h>

typedef long long ll;

ll answer(ll x, ll l, ll u){
	ll mask = 1LL << 32;
	ll m = 0;
	while(mask){
		ll temp = m ^ mask;
		if((!(x & mask) && temp <= u) || (x & mask && temp <= l))
			m = temp;
		mask >>= 1;
	}
	return m;
}

int main(){
	ll n,l,u;
	while(scanf("%lld%lld%lld", &n, &l, &u) != EOF){
		printf("%lld\n", answer(n,l,u));
	}
	return 0;
}
