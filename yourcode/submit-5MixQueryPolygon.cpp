#include "submit-5MixQueryPolygon.h"
#include "global.h"
using namespace std;

void SetEnvironmentFromMixQueryPolygon() {

}

bool Visitor_Polygon5(leaf_type leaf)
{
    if(has_deleted_sk && sk_isdeleted[leaf]) return true;
    bool odd= false;
    pointInPolygon(Singlepoint[leaf].first,Singlepoint[leaf].second,query_polygon,query_n,odd);
    if(odd) ret[visitor_counter++]=sk_id[leaf];
    return true; // keep going
}

void AddPointFromMixQueryPolygon(int id, double x, double y) {
    Singlepoint[sk]=make_pair(x,y), sk_id[sk]=id, id_sk[id]=sk;
    int bb[2]={int(x),int(y)};
    point_tree.Insert(bb,bb,sk);
    sk++;
}

vector<int> QueryPolygonFromMixQueryPolygon(int n, vector<pair<double, double> > &polygon) {
    visitor_counter=0;
    double x1,x2,y1,y2;
    x1=x2=polygon[0].first, y1=y2=polygon[0].second;
    for(int i=0;i<n;++i)
    {
        if(polygon[i].first<x1) x1=polygon[i].first;
        else if(polygon[i].first>x2) x2=polygon[i].first;
        if(polygon[i].second<y1) y1=polygon[i].second;
        else if(polygon[i].second>y2) y2=polygon[i].second;
        query_polygon[i]=polygon[i];
    }
    query_n=n;
    int min[2]={int(x1),int(y1)}, max[2]={int(x2),int(y2)};
    point_tree.Search(min,max,Visitor_Polygon5);
    vector<int> Ret(ret,ret+visitor_counter);
    return Ret;
}

void DeletePointFromMixQueryPolygon(int id) {
    has_deleted_sk=true;
    sk_isdeleted[id_sk[id]]=true;
}