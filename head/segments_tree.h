#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H
#include<vector>
class SMT
{
/*    n     数据大小
 *    a[]   原始数据
 *    tr[]  线段树
 *    tag[] 懒标签
*/
//#define ll long long
//typedef long long ll;
using ll=long long;//=#define ll long long 或 typedef long long ll;
public:
    SMT(ll m,const std::vector<ll>&arr):n(m),a(m+5),tr((m<<2)+5),tag((m<<2)+5)
    {
        for (ll i=1;i<=m;i++)
        {
            a[i]=arr[i];//1-index编码
        }
        return;
    }
    void build(){build(1,1,n);}
    void update(ll qlt,ll qrt,ll v){update(1,1,n,qlt,qrt,v);}
    ll query(ll qlt,ll qrt){return query(1,1,n,qlt,qrt);}
    void point_update(ll qpt,ll v){update(1,1,n,qpt,qpt,v);}
    ll point_query(ll qpt){return query(1,1,n,qpt,qpt);}
private:
    ll n;
    std::vector<ll>a,tr,tag;
    static constexpr ll ls(ll r)
    {
        return r<<1;
    }
    static constexpr ll rs(ll r)
    {
        return r<<1|1;
    }
    void push_up(ll r)
    {
        tr[r]=tr[ls(r)]+tr[rs(r)];//操作(+,-,^,max,min等)
        return;
    }
    void push_down(ll r,ll lt,ll rt)
    {
        //向下传递懒标签，并更新数据
        if (!tag[r])return;
        ll mid=(lt+rt)>>1;
        tr[ls(r)]=tr[ls(r)]+(mid-lt+1)*tag[r];//操作(+,-,^,max,min等)
        tag[ls(r)]=tag[ls(r)]+tag[r];//操作(+,-,^,max,min等)
        tr[rs(r)]=tr[rs(r)]+(rt-mid)*tag[r];//操作(+,-,^,max,min等)
        tag[rs(r)]=tag[rs(r)]+tag[r];//操作(+,-,^,max,min等)
        //归零:
        tag[r]=0;
        return;
    }
    //构建线段树
    void build(ll r,ll lt,ll rt){
        //对 [lt,rt] 区间构建线段树,当前根的编号为 r
        if(lt==rt){
            tr[r]=a[lt];
            return;
        }
        ll mid=(lt+rt)>>1;
        build(ls(r),lt,mid);
        build(rs(r),mid+1,rt);
        push_up(r);//向上更新
        return;
    }
    //区间修改
    void update(ll r,ll lt,ll rt,ll qlt,ll qrt,ll v){
        if(qlt<=lt&&qrt>=rt){
            //在整个范围内
            tr[r]=tr[r]+(rt-lt+1)*v;//操作(+,-,^,max,min等)
            tag[r]=tag[r]+v;//操作(+,-,^,max,min等)
            return;
        }
        push_down(r,lt,rt);
        ll mid=(lt+rt)>>1;
        if(qlt<=mid)update(ls(r),lt,mid,qlt,qrt,v);//在左半部分
        if(qrt>mid)update(rs(r),mid+1,rt,qlt,qrt,v);//在右半部分
        push_up(r);//向上更新
        return;
    }
    //区间查询
    ll query(ll r,ll lt,ll rt,ll qlt,ll qrt){
        if(qrt<lt||qlt>rt)return 0;//不在范围内
        if(qlt<=lt&&qrt>=rt)return tr[r];//在整个范围内
        push_down(r,lt,rt);
        ll mid=((lt+rt)>>1);
        return query(ls(r),lt,mid,qlt,qrt)/*左半部分*/+query(rs(r),mid+1,rt,qlt,qrt)/*右半部分*/;
    }
//#undef ll
};
#endif