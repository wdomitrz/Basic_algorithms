#include<iostream>
#include<vector>
#include<set>
using namespace std;						// "n"-zawsze liczba wierzcho³ków						!!!!!!!!!!!!!!!!
int n,m;									// "m"-zawsze liczba krawêdzi							!!!!!!!!!!!!!!!!
int odl[100001];							// odleg³osæ od pocz¹tku	100000 to maksymalne "n"
vector <int> G[100001];						// krawedzie				100000 to maksymalne "n"
vector <int> war[100001];					// d³ugosci krawedzi		100000 to maksymalne "n"
int nies = 1000000000;
struct porset								// struktura poruwnuj¹ca seta
{
	bool operator()(int a, int b)			// funkcja poruwnuj¹ca
	{
		if(odl[a]==odl[b])
		{
			return a<b;
		}
		return odl[a]<odl[b];
	}										// koniec funkcji poruwnuj¹cej
};
set<int,porset>s;							// deklaracja seta
void dijkstra(int x)						// deklaracja funkcji (Jas idzie do Ma³gosi)
{
	for(int i=1;i<=n;i++)					// wype³nianie tablicy nieskoñczonosciami
	{
		odl[i]=nies;
	}										// kniec wype³niania taklicy nieskoñczonosciami
	odl[x]=0;								// ustawiamy pocz¹tek(Jasia) na 0
	s.insert(x);							// wrzucamy pocz¹tek(Jasia) na set
	while(!s.empty())						// dopuki wuerzcho³ki siê nie skoñcz¹ (nie przerobimy wszysstkich) (Jas chodzi po grafie)
	{
		x=*s.begin();						// szukam wierzcho³ka o najmniejszej odleg³osci od pocz¹tku z nieprzerobionych wierzcho³ków (miejsca startu Jasia)
		s.erase(x);							// usuwamy wiercho³ek jako przerobiany (odwiedzony przez Jasia)
		for(int i=0;i<G[x].size();i++)		// patrze na s¹siednie wierzcho³ki
		{
			int a=G[x][i];					// nazywamy s¹siedni wierzcho³ek "a" (dla wygody i skrócenia kodu)
			if(odl[x]+war[x][i]<odl[a])		// czy a treba poprawiaæ (czy trzeba zmieniaæ na mniejsz¹[czy istnieje minejsza])
			{
				if(odl[a]<nies)				// czy a jest w secie
					s.erase(a);				// jesli jest to usuñ
				odl[a]=odl[x]+war[x][i];	// popraw (zmieñ na mniejsz¹) odleg³osæ
				s.insert(a);				// dodaj a do przerobienia (do seta)
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio (0);
	int x;									// numer wierzcho³ka pocz¹tkowego (startu Jasia)
	cin >> n >> m >> x;						// wczytanie liczby wierzcho³ków, liczby krawêdzi i numeru wierzcho³ka pocz¹tkowego (startu Jasia)
	for(int i=0;i<m;i++)					// pocz¹tek wczytywania wartosci, pocz¹tków i koñców krawêdzi
	{
		int a,b,c;							// pomocnicz zmienne do wczytywania pocz¹tek, koniec i wartosæ krawêdzi
		cin >> a >> b >> c;					// wczytujemy pocz¹tek, koniec i wartosæ krawêdzi
		G[a].push_back(b);					// zapisanie trasy krawêdzi (pocz¹tek -> koñec)
		G[b].push_back(a);
		war[a].push_back(c);
		war[b].push_back(c);				// zapisanie wartosci krawêdzi
	}
	dijkstra(x);    						// uruchamiam algorytm Edsgara Dijkstry dla pocz¹tku "x" (miejsce startu Jasia)
	cout << odl[n] << '\n';					// wypisuje minimaln¹ odleg³osæ pocz¹tku do koñca (Jasia od Ma³gosi)
	return 0;
}
