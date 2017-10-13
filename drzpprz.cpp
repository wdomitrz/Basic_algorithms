#include<cstdio>
#include<algorithm>
using namespace std;

const int base = 1 << 20;
int drz[2 * base];
bool gwiazdki[2 * base];

void spusc(int x) {
	gwiazdki[x] = false;
	drz[x * 2] = drz[x];
	gwiazdki[x * 2] = true;
	drz[x * 2 + 1] = drz[x];
	gwiazdki[x * 2 + 1] = true;
}

void aktualizuj(int x) {
	drz[x] = max(drz[2 * x], drz[2 * x + 1]);
}

void zmien(int x, int pocz, int kon, int a, int b, int naco) {
	// [a, b] = przedzial, [pocz, kon] = to, co widzi wierzcholek x
	if(a == pocz && b == kon) {
		drz[x] = naco;
		gwiazdki[x] = true;
		return;
	}
	
	if(gwiazdki[x])
		spusc(x);
	int sr = (a + b) / 2;
	
	if(b <= sr) {
		zmien(x * 2, pocz, sr, a, b, naco);
		aktualizuj(x);
		return;
	}
	
	if(a > sr) {
		zmien(x * 2 + 1, sr + 1, kon, a, b, naco);
		aktualizuj(x);
		return;
	}
	
	zmien(x * 2, pocz, sr, a, sr, naco);
	zmien(x * 2 + 1, sr + 1, kon, sr + 1, b, naco);
	aktualizuj(x);
}

int czytaj(int x, int pocz, int kon, int a, int b) {
	if(a == pocz && b == kon) {
		return drz[x];
	}
	
	if(gwiazdki[x])
		spusc(x);
	int sr = (a + b) / 2;
	
	if(b <= sr) {
		return czytaj(x * 2, pocz, sr, a, b);
	}
	
	if(a > sr) {
		return czytaj(x * 2 + 1, sr + 1, kon, a, b);
	}
	
	return max(czytaj(x * 2, pocz, sr, a, sr),
				czytaj(x * 2 + 1, sr + 1, kon, sr + 1, b));
}
