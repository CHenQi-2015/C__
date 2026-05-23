#import "iostream"
#import "algorithm"
#import "map"
#import "vector"
#define int long long
const int N=3e5;
int n,k,a[N],sum;
std::map<int,int>cnt;
bool cmp(int x,int y){
    return x*cnt[x]>y*cnt[y];
}
signed main() {
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    std::cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        std::cin>>a[i];
        cnt[a[i]]++;
        sum+=a[i];
    }
    std::vector<int> lnk;
    for (const auto &p: cnt)
    {
        lnk.push_back(p.first);
    }
    std::sort(lnk.begin(),lnk.end(),cmp);
    for (int i=0;i<k&&i<lnk.size();i++)
    {
        int x=lnk[i];
        sum-=x*cnt[x];
    }
    std::cout<<sum;
    return 0;
}