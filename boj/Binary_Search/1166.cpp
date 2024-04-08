#include <cstdio>
typedef long long ll;
typedef long double ld;
int main(){
	ll n, l, w, h;
	scanf("%lld %lld %lld %lld",&n, &l, &w, &h);
	ld s = 0;
	ld e = 1000000000;
	ld mid, num;
	while (e-s>1e-10){
		mid = (s + e) / 2;
		num = (ll)(l / mid)*(ll)(w / mid)*(ll)(h / mid);
		if (n > num)
			e = mid;
		else
			s = mid;
	}
	printf("%.10Lf", mid);
    return 0;
}