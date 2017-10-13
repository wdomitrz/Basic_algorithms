#include <cstdio>

const int base = 1048576; //1 << 20;
int drz[2 * base];
int t[1000 * 1000 + 10]; // tablica z ciagiem
int n;


void popr(int x) { // x jest na najnizszym poziomie
	x /= 2; // skok do ojca
	while(x >= 1) {
		drz[x] = drz[2 * x] + drz[2 * x + 1];
		x /= 2;
	}
}

int czytaj(int a, int b) { // miejsca w tablicy, a <= b
	// a - poczatek, b - koniec przedzialu
	a += base;
	b += base;
	int sum = 0;
	
	while(a < b) {
		if((a % 2) == 1) {
			sum += drz[a];
			a /= 2;
			a++;
		}
		else a /= 2;
		if((b % 2) == 1) b /= 2;
		else {
			sum += drz[b];
			b /= 2;
			--b;
		}
	}
	if(a == b)
		sum += drz[a];
	
	return sum;
}

int czytaj2(int x, int pocz, int kon, int a, int b) {
	// [a, b] = przedzial, [pocz, kon] = to, co widzi wierzcholek x
	if(pocz == a && kon == b)
		return drz[x];
	
	int sr = (pocz + kon) / 2;
	if(b <= sr)
		return czytaj2(2 * x, pocz, sr, a, b);
	
	if(a > sr)
		return czytaj2(2 * x + 1, sr + 1, kon, a, b);
		
	return czytaj2(2 * x, pocz, sr, a, sr) +
			czytaj2(2 * x + 1, sr + 1, kon, sr + 1, b);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
		drz[i + base] = t[i];
	}
	
	for(int i = base - 1; i > 0; --i)
		drz[i] = drz[2 * i] + drz[2 * i + 1];
	int z;
	scanf("%d", &z);
	while(z--) {
		// 0 -  zmiana i-tego elementu
		// 1 - pytanie o sume na przedziale
		int c;
		scanf("%d", &c);
		if(c == 0) {
			int i, x;
			scanf("%d%d", &i, &x);
			t[i] = x;
			drz[i + base] = x;
			popr(i + base);
		}
		else {
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n%d\n", czytaj(a, b), czytaj2(1, 0, base - 1, a, b));
		}
	}
	
	
	return 0;
}
