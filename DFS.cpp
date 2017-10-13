#include<iostream>
#include<vector>
using namespace std;
bool vis[1000*1000+1];                          // tablica odwiedzonych
vector<int>G[1000*1000+1];                      // tablicz vektorów do zapisania grafu
int n,m;                                        // n => ilosc wierzcholkow, m => ilosc krawedzi
void dfs(int v)                                 // deklaracja funkcji dfs (przyjmuje ona punkt teraz odwiedzany)
{
    vis[v]=1;                                   // zapisanie, ze odwiedzilem v
    for(int i=0; i<G[v].size(); ++i)            // przegladam sasiadow
    {
        int u=G[v][i];                          // nazwanie sąsiada u (u => numer sasiada)
        if(!vis[u])                             // sprawdzanie, czy juz byl odwiedzony (jesli byl, to mamy cykl)        !!!!!!!!!!
        {
            dfs(u);                             // uruchamiamy dfs w punkcie 'u'
        }
    }
}
int main()
{
	ios_base::sync_with_stdio (0);
	int x;									    // numer wierzcholka poczatkowego
	cin >> n >> m >> x;						    // wczytanie liczby wierzcholków, liczby krawedzi i numeru wierzcholka poczatkowego
	for(int i=0;i<m;i++)					    // pocz¹tek wczytywania pocz¹tków i koñców krawêdzi
	{
		int a,b;							    // pomocnicze zmienne do wczytywania poczateku i konieca
		cin >> a >> b;					        // wczytanie poczatek i koniec krawêdzi
		G[a].push_back(b);					    // zapisanie trasy krawedzi (pocz¹tek -> koñec)
		G[b].push_back(a);
	}
	dfs(x);                                     // uruchomienie dfs (Przeszukiwanie Grafu Wglab)
	return 0;
}
