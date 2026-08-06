#ifndef seg_t
#define seg_t
#define ll long long
#include<vector>
class SMT
{
/*    n     数据大小
 *    a[]   原始数据
 *    tr[]  线段树
 *    tag[] 懒标签
*/
public:
    SMT(ll m):n(m),a(m),tr(m<<2),tag(m<<2){}
private:
    ll n;
    std::vector<ll>a,tr,tag;
    inline ll ls(ll r)
    {
        return r<<1;
    }
    inline ll rs(ll r)
    {
        return r<<1|1;
    }
    inline void push_up(ll r)
    {
        tr[r]=tr[ls(r)]+tr[rs(r)];//操作(+,-,^,max,min等)
        return;
    }
    inline void push_down(ll r,ll lt,ll rt)
    {
        //向下传递懒标签，并更新数据
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
    inline void build(ll r,ll lt,ll rt){
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
    inline void update(ll r,ll lt,ll rt,ll qlt,ll qrt,ll v){
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
    inline ll query(ll r,ll lt,ll rt,ll qlt,ll qrt){
        if(qrt<lt||qlt>rt)return 0;//不在范围内
        if(qlt<=lt&&qrt>=rt)return tr[r];//在整个范围内
        push_down(r,lt,rt);
        ll mid=((lt+rt)>>1);
        return query(r<<1,lt,mid,qlt,qrt)/*左半部分*/+query(r<<1,mid+1,rt,qlt,qrt)/*右半部分*/;
    }
    //单点修改
    inline void point_update(ll r,ll lt,ll rt,ll qpt,ll v){
        if(lt>qpt||rt<qpt){
            //不在范围内
            return;
        }
        if(lt==rt){
            //单点
            tr[r]=tr[r]+v;//操作(+,-,^,max,min等)
            return;
        }
        ll mid=((lt+rt)>>1);
        point_update(ls(r),lt,mid,qpt,v);//左半部分
        point_update(rs(r),mid+1,rt,qpt,v);//右半部分
        push_up(r);//向上更新
        return;
    }
    //单点查询
    inline ll point_query(ll r,ll lt,ll rt,ll qpt){
        if(lt>qpt||rt<qpt){
            return 0;//不在范围内
        }
        if(lt==rt){
            return tr[r];//单点
        }
        ll mid=(lt+rt)>>1;
        return point_query(ls(r),lt,mid,qpt)/*左半部分*/+point_query(rs(r),mid+1,rt,qpt)/*右半部分*/;
    }
};
#undef ll
#endif
