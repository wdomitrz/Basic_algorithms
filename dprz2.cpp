#include <cstdio>

const int base = 1048576; //1 << 20;
int drz[2 * base];
int t[1000 * 1000 + 10]; // tablica z ciagiem
int n;


int czytaj(int x) { // x jest na najnizszym poziomie
	int sum = 0;
	while(x >= 1) {
		sum += drz[x];
		x /= 2;
	}
	return sum;
}

void popr(int a, int b, int x) { // miejsca w tablicy, a <= b
	// a - poczatek, b - koniec przedzialu
	a += base;
	b += base;
	
	while(a < b) {
		if((a % 2) == 1) {
			drz[a] += x;
			a /= 2;
			a++;
		}
		else a /= 2;
		if((b % 2) == 1) b /= 2;
		else {
			drz[b] += x;
			b /= 2;
			--b;
		}
	}
	if(a == b)
		drz[a] += x;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
	}
	
	int z;
	scanf("%d", &z);
	while(z--) {
		// 0 - pytanie o wartosc i-tego elementu 
		// 1 - dodajemy x na przedziale [a,b]
		int c;
		scanf("%d", &c);
		if(c == 0) {
			int i;
			scanf("%d", &i);
			printf("%d\n", t[i] + czytaj(i + base));
		}
		else {
			int a, b, x;
			scanf("%d%d%d", &a, &b, &x);
			popr(a, b, x);
		}
	}
	
	
	return 0;
}
