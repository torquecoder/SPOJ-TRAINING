# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
//# include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace __gnu_pbds;
//namespace vl = boost::multiprecision;

// Did you miss me ?

# define gc          getchar
# define LL          long long
# define VLL         vl::cpp_int
# define pb          push_back
# define mp          make_pair
# define vi          vector<int>
# define vll         vector<LL>
# define pii         pair<int,int>
# define all(v)      v.begin(),v.end()

const int MOD = 1000000007;
const int MAXN = 1e6 + 5;
const int INF = 1e9;
const double PI = 3.14159265359;

template<class T> void in(T &x) { register T c=gc();x=0;T neg=0;for(;((c<48||c>57)&&c!='-');c=gc());if(c=='-'){neg=1;c=gc();}for(;c>47&&c<58;c=gc()){x=(x<<1)+(x<<3)+c-48;}if(neg)x=-x;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
LL power(LL a,LL b,LL m){ if(b==0) return 1; if(b==1) return a%m; LL t=power(a,b/2,m); t=(t*t)%m; if(b&1)t=(t*a)%m; return t;}
LL lcm(LL a, LL b) { LL ret = a*b; ret /= __gcd(a,b); return ret;}
LL nC2(LL n) {LL ret = n*(n-1)/2; return ret;}

/*vector<int> primes;
void sieve(int n) {
	bool isPrime[n + 1];
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i * i <= n; i++)
		if (isPrime[i])
			for (int j = 2 * i; j <= n; j += i)
			 	isPrime[j] = false;
	for (int i = 2; i <= n; i++)
		if (isPrime[i])
			primes.push_back(i);
}*/

string s[1001];
LL n, m, sz;
int vis[1001][1001], cap[1001][1001];

bool valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && s[x][y] == '#')
        return true;
    return false;
}

void dfs(int x, int y)
{
    sz++;
    vis[x][y] = 1;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx != 0 && dy != 0)
                continue;
            if (valid(x + dx, y + dy))
                dfs(x + dx, y + dy);
        }
    }
}

int main()
{
	int t;
	in(t);
	//t = 1;
	while (t--) {
        memset(vis, 0, sizeof(vis));
        memset(cap, 0, sizeof(cap));
        in(n), in(m);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        LL num = 0, denom;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sz = 0;
                if (!vis[i][j] && s[i][j] == '#')
                {
                    dfs(i, j);
                    num += sz * sz;
                }

            }
        }
        denom = n * m;
        LL g = __gcd(num, denom);
        num /= g;
        denom /= g;
        if (denom == 1)
            cout << num << "\n";
        else
            cout << num << " / " << denom << "\n";

	}
    return 0;
}
