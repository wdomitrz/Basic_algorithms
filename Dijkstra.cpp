#include<iostream>
#include<vector>
#include<set>
using namespace std;						// "n"-zawsze liczba wierzcho�k�w						!!!!!!!!!!!!!!!!
int n,m;									// "m"-zawsze liczba kraw�dzi							!!!!!!!!!!!!!!!!
int odl[100001];							// odleg�os� od pocz�tku	100000 to maksymalne "n"
vector <int> G[100001];						// krawedzie				100000 to maksymalne "n"
vector <int> war[100001];					// d�ugosci krawedzi		100000 to maksymalne "n"
int nies = 1000000000;
struct porset								// struktura poruwnuj�ca seta
{
	bool operator()(int a, int b)			// funkcja poruwnuj�ca
	{
		if(odl[a]==odl[b])
		{
			return a<b;
		}
		return odl[a]<odl[b];
	}										// koniec funkcji poruwnuj�cej
};
set<int,porset>s;							// deklaracja seta
void dijkstra(int x)						// deklaracja funkcji (Jas idzie do Ma�gosi)
{
	for(int i=1;i<=n;i++)					// wype�nianie tablicy niesko�czonosciami
	{
		odl[i]=nies;
	}										// kniec wype�niania taklicy niesko�czonosciami
	odl[x]=0;								// ustawiamy pocz�tek(Jasia) na 0
	s.insert(x);							// wrzucamy pocz�tek(Jasia) na set
	while(!s.empty())						// dopuki wuerzcho�ki si� nie sko�cz� (nie przerobimy wszysstkich) (Jas chodzi po grafie)
	{
		x=*s.begin();						// szukam wierzcho�ka o najmniejszej odleg�osci od pocz�tku z nieprzerobionych wierzcho�k�w (miejsca startu Jasia)
		s.erase(x);							// usuwamy wiercho�ek jako przerobiany (odwiedzony przez Jasia)
		for(int i=0;i<G[x].size();i++)		// patrze na s�siednie wierzcho�ki
		{
			int a=G[x][i];					// nazywamy s�siedni wierzcho�ek "a" (dla wygody i skr�cenia kodu)
			if(odl[x]+war[x][i]<odl[a])		// czy a treba poprawia� (czy trzeba zmienia� na mniejsz�[czy istnieje minejsza])
			{
				if(odl[a]<nies)				// czy a jest w secie
					s.erase(a);				// jesli jest to usu�
				odl[a]=odl[x]+war[x][i];	// popraw (zmie� na mniejsz�) odleg�os�
				s.insert(a);				// dodaj a do przerobienia (do seta)
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio (0);
	int x;									// numer wierzcho�ka pocz�tkowego (startu Jasia)
	cin >> n >> m >> x;						// wczytanie liczby wierzcho�k�w, liczby kraw�dzi i numeru wierzcho�ka pocz�tkowego (startu Jasia)
	for(int i=0;i<m;i++)					// pocz�tek wczytywania wartosci, pocz�tk�w i ko�c�w kraw�dzi
	{
		int a,b,c;							// pomocnicz zmienne do wczytywania pocz�tek, koniec i wartos� kraw�dzi
		cin >> a >> b >> c;					// wczytujemy pocz�tek, koniec i wartos� kraw�dzi
		G[a].push_back(b);					// zapisanie trasy kraw�dzi (pocz�tek -> ko�ec)
		G[b].push_back(a);
		war[a].push_back(c);
		war[b].push_back(c);				// zapisanie wartosci kraw�dzi
	}
	dijkstra(x);    						// uruchamiam algorytm Edsgara Dijkstry dla pocz�tku "x" (miejsce startu Jasia)
	cout << odl[n] << '\n';					// wypisuje minimaln� odleg�os� pocz�tku do ko�ca (Jasia od Ma�gosi)
	return 0;
}
