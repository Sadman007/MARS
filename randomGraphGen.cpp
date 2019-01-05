#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MOD 1000000007
#define MAX 200005
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

void dataGraphGenerator()
{
    //freopen("in.txt","r",stdin);
    freopen("data/dGraph(test).txt","w",stdout);

    int n,m;
    n = 10000;
    m = 30000;
    cout << n << " " << m << "\n";

    for(int i=0; i<n; i++)
    {
        printf("%d ",(rand()%3)+1);
    }
    puts("");

    for(int i=1; i<=m; i++)
    {
        int u = (rand()%n)+1;
        int v = (rand()%n)+1;
        while(u==v) v = (rand()%n)+1;
        printf("%d %d\n",u,v);
    }
}

void queryGraphGenerator()
{
    //freopen("in.txt","r",stdin);
    freopen("queries/multiple_queries_2.txt","w",stdout);
    int t = 500;
    printf("%d\n",t);
    map< pair<int,int> , int > vp;
    vector< pair<int,int> > ans;

    while(t--)
    {
        vp.clear();
        ans.clear();
        int n,m,nM = 0;
        puts("");
        n = rand()%7;
        while(n<2) n = rand()%7;
        m = rand()%(n*(n-1)/2) + n;

        for(int i=1; i<=m; i++)
        {
            int u = (rand()%n)+1;
            int v = (rand()%n)+1;
            while(u==v) v = (rand()%n)+1;
            if(u>v) swap(u,v);
            if(vp.find({u,v})!=vp.end()) {continue;}
            else
            {
                nM++;
                ans.pb({u,v});
                vp[{u,v}] = 1;
            }
            //printf("%d %d\n",u,v);
        }
        sort(all(ans));
        m = nM;
        printf("%d %d\n",n,m);
        for(int i=1; i<=n; i++)
        {
            printf("%d ",rand()%3 + 1);
        }
        puts("");
        for(auto it : ans)
        {
            cout << it.first << " " << it.second << "\n";
        }
    }
}

struct query
{
    int n,m;
    vector<int>tag;
    vector<pii>edges;
    query(){}
};

void similarGraphGenerator()
{
    freopen("queries/multiple_queries_2.txt","w",stdout);
    vector<query>vq;

    int t = 3;
    int n0 = 5;
    printf("%d\n",t);

    while(t--)
    {
        query tmp;
        int n,m;
        n = rand()%5 + 1;
        m = n+2;
        tmp.n = n;
        tmp.m = m;

        //printf("%d %d\n",n,m);
        for(int i=1; i<=n; i++)
        {
            tmp.tag.pb(rand()%3 + 1);
            //printf("%d ",rand()%5 + 1);
        }
//        puts("");
        for(int i=1; i<=m; i++)
        {
            int u = (rand()%n)+1;
            int v = (rand()%n)+1;
            while(u==v) v = (rand()%n)+1;
            tmp.edges.pb({u,v});
            //printf("%d %d\n",u,v);
        }
        int cnt = 10;
        while(cnt--) vq.pb(tmp);
    }
    random_shuffle(all(vq));
    printf("%d\n",vq.size());
    for(int i=1;i<=vq.size();i++)
    {
        cout << vq[i].n << " " << vq[i].m << "\n";
        for(auto v : vq[i].tag)
        {
            printf("%d ",v);
        }
        puts("");
        for(auto ed : vq[i].edges)
        {
            cout << ed.first << " " << ed.second << "\n";
        }
    }
}

void mitosisOfQueries()
{
    freopen("queries/multiple_queries_2.txt","r",stdin);
    freopen("queries/multiple_queries.txt","w",stdout);

    int t = 6;
    int n,m,lala;
    vector<query>vq;
    while(t--)
    {
        query tmp;
        scanf("%d %d",&tmp.n,&tmp.m);
        for(int i=1;i<=tmp.n;i++)
        {
            scanf("%d",&lala);
            tmp.tag.pb(lala);
        }
        for(int i=1;i<=tmp.m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            tmp.edges.pb({u,v});
        }
        int cnt = 20;
        while(cnt--)
        vq.pb(tmp);
    }
    random_shuffle(all(vq));
    printf("%d\n",vq.size());
    for(int i=0;i<vq.size();i++)
    {
        query tmp = vq[i];
        printf("%d %d\n",tmp.n,tmp.m);
        for(auto v : tmp.tag) cout << v << " ";
        puts("");
        for(auto v : tmp.edges)
        {
            cout << v.first << " " << v.second << "\n";
        }
    }

}

int main()
{
    srand(time(0));
    //dataGraphGenerator();
    queryGraphGenerator();
    //similarGraphGenerator();
    //mitosisOfQueries();
    return 0;
}
