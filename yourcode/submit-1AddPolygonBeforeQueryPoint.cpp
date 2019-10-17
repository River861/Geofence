#include "submit-1AddPolygonBeforeQueryPoint.h"
#include "global.h"
using namespace std;

void SetEnvironmentFromAddPolygonBeforeQueryPoint() {                          //初始化写这里

}

bool Visitor_Point1(leaf_type leaf)
{
    bool odd= false;
    pointInPolygon(query_point_x,query_point_y,&Vertex[leaf][0],vk_n[leaf],odd);
    if(odd) ret[visitor_counter++]=vk_id[leaf];
    return true; // keep going
}

vector<int> QueryPointFromAddPolygonBeforeQueryPoint(double x, double y) {
    visitor_counter=0;
    query_point_x=x,query_point_y=y;
    int bb[2]={int(x),int(y)};
    polygon_tree.Search(bb, bb, Visitor_Point1);
    vector<int> Ret(ret,ret+visitor_counter);
    return Ret;
}

void AddPolygonFromAddPolygonBeforeQueryPoint(int id, int n, vector<pair<double, double> > &polygon) {
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
    vk_n[vk]=n,vk_id[vk]=id;
    int min[2]={int(x1),int(y1)},max[2]={int(x2),int(y2)};
    polygon_tree.Insert(min,max,vk); //加入新多边形
    vk++;
}
