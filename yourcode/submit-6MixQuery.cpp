#include "submit-6MixQuery.h"
#include "global.h"
using namespace std;

void SetEnvironmentFromMixQuery() {

}

bool Visitor_Point6(leaf_type leaf)
{
    if(has_deleted_vk && vk_isdeleted[leaf]) return true;
    bool odd= false;
    pointInPolygon(query_point_x,query_point_y,&Vertex[leaf][0],vk_n[leaf],odd);
    if(odd) ret[visitor_counter++]=vk_id[leaf];
    return true; // keep going
}

bool Visitor_Polygon6(leaf_type leaf)
{
    if(has_deleted_sk && sk_isdeleted[leaf]) return true;
    bool odd= false;
    pointInPolygon(Singlepoint[leaf].first,Singlepoint[leaf].second,query_polygon,query_n,odd);
    if(odd) ret[visitor_counter++]=sk_id[leaf];
    return true; // keep going
}

void AddPointFromMixQuery(int id, double x, double y) {
    Singlepoint[sk]=make_pair(x,y), sk_id[sk]=id, id_sk[id]=sk;
    int bb[2]={int(x),int(y)};
    point_tree.Insert(bb,bb,sk);
    sk++;
}

void AddPolygonFromMixQuery(int id, int n, vector<pair<double, double>> &polygon) {
    double x1,x2,y1,y2;
    x1=x2=polygon[0].first, y1=y2=polygon[0].second;
    for(int i=0;i<n;++i)
    {
        if(polygon[i].first<x1) x1=polygon[i].first;
        else if(polygon[i].first>x2) x2=polygon[i].first;
        if(polygon[i].second<y1) y1=polygon[i].second;
        else if(polygon[i].second>y2) y2=polygon[i].second;
        Vertex[vk][i]=polygon[i];
    }
    vk_n[vk]=n, vk_id[vk]=id, id_vk[id]=vk;
    int min[2]={int(x1),int(y1)},max[2]={int(x2),int(y2)};
    polygon_tree.Insert(min,max,vk); //加入新多边形
    vk++;
}

vector<int> QueryPointFromMixQuery(double x, double y) {
    visitor_counter=0;
    query_point_x=x,query_point_y=y;
    int bb[2]={int(x),int(y)};
    polygon_tree.Search(bb, bb, Visitor_Point6);
    vector<int> Ret(ret,ret+visitor_counter);
    return Ret;
}

vector<int> QueryPolygonFromMixQuery(int n, vector<pair<double, double>> &polygon) {
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
    point_tree.Search(min,max,Visitor_Polygon6);
    vector<int> Ret(ret,ret+visitor_counter);
    return Ret;
}

void DeletePolygonFromMixQuery(int id) {
    has_deleted_vk=true;
    vk_isdeleted[id_vk[id]]=true;
}

void DeletePointFromMixQuery(int id) {
    has_deleted_sk=true;
    sk_isdeleted[id_sk[id]]=true;
}