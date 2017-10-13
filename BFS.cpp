#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool vis[1000*1000+1];                          // tablica odwiedzonych
int odl[1000*1000+1];
vector<int>G[1000*1000+1];                      // tablicz vektorów do zapisania grafu
queue<int>q;                                    // deklaracja kolejki do pomocy w bfs (trzymania wierzcholkow do odwiedzenia)
int n,m;                                        // n => ilosc wierzcholkow, m => ilosc krawedzi
void bfs(int v)                                 // deklaracja funkcji bfs (przyjmuje ona punkt startowy)
{
    vis[v]=1;                                   // zapisanie, ze wrzucono v do kolejki
    q.push(v);                                  // dodajemy v do kolejki do odwiedzin
    while(!q.empty())
    {
        int spra=q.front();                     // biore wierzcholek do przeglodania
        q.pop();//                                // usuwamy wlasnie przegladany wierzcholek z kolejki
        for(int i=0; i<G[spra].size(); ++i)     // przegladam sasiadow
        {
            int u=G[spra][i];                   // nazwanie sąsiada 'u' (u => numer sasiada)
            if(!vis[u])                         // sprawdzanie, czy juz byl wrzucony do kolejki (jesli byl, to mamy cykl)        !!!!!!!!!!
            {
                q.push(u);                     	// wrzucamy u do kolejki
                vis[u]=1;
                odl[u]=odl[spra]+1;		// zapisujemy, ze wrzucilismy u do kolejki
            }
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
	bfs(x);                                     // uruchomienie bfs (Przeszukiwanie Grafu Wszeż)
	return 0;
}
