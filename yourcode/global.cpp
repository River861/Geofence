#include <iostream>
#include "global.h"
using namespace std;
//--------------------------------------global function/factor
int ret[160000];

int visitor_counter;

void pointInPolygon(double x,double y,pair<double, double>* polygon,int n,bool& odd)  //射线法
{
    for(int i=0,j=n-1;i<n;j=i,i++)
    {
        if((polygon[i].second<y&&polygon[j].second>=y || polygon[j].second<y && polygon[i].second>=y)
           && (polygon[i].first>=x || polygon[j].first>=x))
            if(polygon[i].first+(y-polygon[i].second)/(polygon[j].second-polygon[i].second)*(polygon[j].first-polygon[i].first)>x)
                odd=!odd;
    }
    return;
}

//--------------------------------------for polygon_tree
Polygon_Tree polygon_tree;

pair<double,double> Vertex[160000][200];

int query_point_x,query_point_y;

int vk=0;

int vk_id[160000],vk_n[160000];

//--------------------------------------for point_tree
Point_Tree point_tree;

pair<double,double> Singlepoint[160000];

pair<double,double> query_polygon[200];

int query_n;

int sk=0;

int sk_id[160000];

//---------------------------------------for "delete" case
unordered_map<int,int> id_vk;

bool vk_isdeleted[160000];

bool has_deleted_vk= false;

unordered_map<int,int> id_sk;

bool sk_isdeleted[160000];

bool has_deleted_sk= false;