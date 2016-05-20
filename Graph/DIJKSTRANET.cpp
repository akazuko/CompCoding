#include <bits/stdc++.h>

typedef long long ll;

#define MOD       1000000007
#define scll(t)      scanf("%lld",&t)
#define sc(t)       scanf("%d",&t)
#define max(a,b)      (a>=b?a:b)
#define min(a,b)      (a<b?a:b)
#define gc           getchar_unlocked
#define mp           make_pair
#define pb           push_back
#define freinp       freopen("in.txt","r",stdin)
#define freout       freopen("out.txt","w",stdout)

using namespace std;


vector<int >incoming[109];
int vis[109],truth[109],outgoing[109],claim[109],flag=0;
stack<int> st;

void dfs()
{
    int tval,next_node;
    while(!st.empty())
    {
        int cur_node = st.top();
        st.pop();
        if(vis[cur_node])
            continue;

        vis[cur_node] = 1;

        if(truth[cur_node] == 1)
            tval = claim[cur_node];
        else tval = not(claim[cur_node]);

        next_node = outgoing[cur_node];

        if(!vis[next_node])
        {
            truth[next_node] = tval;
            st.push(next_node);
        }
        else if(truth[next_node] != tval)
        {
            flag = 0;
            return;
        }

        //for incoming edges

        for(int i=0;i<incoming[cur_node].size();i++)
        {
            int inc_node = incoming[cur_node][i];
            if(truth[cur_node] == 1)
                tval = claim[inc_node];
            else tval = not(claim[inc_node]);

            if(!vis[inc_node])
            {
                st.push(inc_node);
                truth[inc_node] = tval;
            }
            else if(truth[inc_node] != tval)
            {
                flag = 0;
                return;
            }
        }

    }
}

int main()
{

  int t,n,i,x;
 string s;
 sc(n);
 while(n!=0)
 {
        while(!st.empty())
            st.pop();

        flag = 1;

   for(i=0;i<=n;i++)
  {
            incoming[i].clear();
            vis[i] = 0;
            truth[i] = 0;
            claim[i] = 0;
  }
  for(i=1;i<=n;i++)
  {
            sc(x);
            cin>>s;
            if(s=="true")
                claim[i] = 1;
            outgoing[i] = x;
            incoming[x].pb(i);
            st.push(i);
  }
        dfs();

       if(flag)
            printf("NOT PARADOX\n");
        else printf("PARADOX\n");

        sc(n);
 }
}