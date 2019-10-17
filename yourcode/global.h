#ifndef GEO_R_GLOBAL_H
#define GEO_R_GLOBAL_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include "RTree.h"
using namespace std;
//--------------------------------------global function/factor
extern int ret[160000];                         //专门用于返回答案数组

extern int visitor_counter;                     //专门由于记录ret中答案的个数

void pointInPolygon(double x,double y,pair<double, double>* polygon,int n,bool& odd);  //射线法

//--------------------------------------for polygon_tree
typedef int leaf_type;

typedef RTree<leaf_type, int, 2, float> Polygon_Tree;

extern Polygon_Tree polygon_tree;                //专门放多边形的树

extern pair<double,double> Vertex[160000][200];  //多边形顶点集，用于储存所添加的所有多边形的点

extern int query_point_x,query_point_y;          //储存所询问的点

extern int vk;                                   //vk代表所添加的polygon的cnt

extern int vk_id[160000],vk_n[160000];           //用cnt查id、n

//--------------------------------------for point_tree
typedef RTree<leaf_type, int, 2, float> Point_Tree;

extern Point_Tree point_tree;                     //专门放点的树

extern pair<double,double> Singlepoint[160000];   //点集，用于储存所添加的所有点

extern pair<double,double> query_polygon[200];    //储存所询问的多边形

extern int query_n;                               //所询问的多边形的边数

extern int sk;                                    //sk代表所添加的point的cnt

extern int sk_id[160000];                         //用cnt查id

//---------------------------------------for "delete" case
extern unordered_map<int,int> id_vk;              //用id查cnt，尽量少用         \
                                                  //                           |
extern bool vk_isdeleted[160000];                 //用cnt查多边形是否被删除       |-->  for deleted polygon
                                                  //                           |
extern bool has_deleted_vk;                       //是否有删除的多边形           /

extern unordered_map<int,int> id_sk;              //用id查cnt，尽量少用         \
                                                  //                           |
extern bool sk_isdeleted[160000];                 //用cnt查点是否被删除          |-->   for deleted point
                                                  //                           |
extern bool has_deleted_sk;                       //是否有删除的点              /

#endif //GEO_R_GLOBAL_H
