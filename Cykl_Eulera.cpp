#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

//graf sasiad, nr krawedzi
vector<pair<int,int> > graf[1000*1000+6];
bool usu[1000*1000+6];
vector<int> odp;

//cykl
void DFSeuler(int start)
{
    int sasiad;
    for(int a=0;a<graf[start].size();a++)
    {
        int kraw=graf[start][a].second;
        if(usu[kraw])
        {
            graf[start][a]=graf[start][graf[start].size()-1];
            graf[start].pop_back();
        }
        else
        {
            sasiad=graf[start][a].first;
            graf[start][a]=graf[start][graf[start].size()-1];
            graf[start].pop_back();
            usu[kraw]=1;
            DFSeuler(sasiad);
        }
    }
    odp.push_back(start);
}
int main()
{
    int n,f,g;
    pair<int,int> a;
    scanf("%i",&n);
    for(int i=0;i < n;i++)
    {
        scanf("%i %i",&f,&a.first);
        a.second=i;
        graf[f].push_back(a);
        g=a.first;
        a.first=f;
        graf[g].push_back(a);
    }
    DFSeuler(1);
    for(int i=0;i<odp.size();i++)
    {
        printf("%i\n",odp[i]);
    }
    return 0;
}
