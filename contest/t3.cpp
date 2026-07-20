#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> X(m+1);
    vector<long long> cnt(n+2, 0);
    for(int i=1;i<=m;i++){
        scanf("%d", &X[i]);
        cnt[X[i]]++;
    }

    vector<long long> PA(n+2,0), PB(n+2,0), PC(n+2,0), PD(n+2,0);
    vector<long long> SufCD(n+2,0), PrefAB(n+2,0);

    for(int p=2; p<=n-1; p+=2){
        int k = p/2;

        SufCD[n] = 0;
        for(int x=n-1; x>=0; x--){
            long long term = 0;
            int v = x+1;
            if(v <= n-k) term = cnt[v]*cnt[v+k];
            SufCD[x] = SufCD[x+1] + term;
        }

        PrefAB[0] = 0;
        for(int x=1; x<=n; x++){
            long long term = 0;
            if(x > p) term = cnt[x-p]*cnt[x];
            PrefAB[x] = PrefAB[x-1] + term;
        }

        for(int vb=p+1; vb<=n; vb++){
            if(cnt[vb]==0) continue;
            long long x = vb + 3LL*p;
            int xi = (x>n) ? n : (int)x;
            PB[vb] += cnt[vb-p]*SufCD[xi];
        }

        for(int va=1; va<=n-p; va++){
            if(cnt[va]==0) continue;
            long long x = va + 4LL*p;
            int xi = (x>n) ? n : (int)x;
            PA[va] += cnt[va+p]*SufCD[xi];
        }

        for(int vc=1; vc<=n-k; vc++){
            if(cnt[vc]==0) continue;
            long long x = (long long)vc - 3LL*p - 1;
            int xi = (x<0) ? 0 : ((x>n) ? n : (int)x);
            PC[vc] += cnt[vc+k]*PrefAB[xi];
        }

        for(int vd=k+1; vd<=n; vd++){
            if(cnt[vd]==0) continue;
            long long x = (long long)vd - k - 3LL*p - 1;
            int xi = (x<0) ? 0 : ((x>n) ? n : (int)x);
            PD[vd] += cnt[vd-k]*PrefAB[xi];
        }
    }

    string out;
    out.reserve((size_t)m*24);
    char buf[64];
    for(int i=1;i<=m;i++){
        int v = X[i];
        int len = sprintf(buf, "%lld %lld %lld %lld\n", PA[v], PB[v], PC[v], PD[v]);
        out.append(buf, len);
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}