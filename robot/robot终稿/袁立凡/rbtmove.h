#ifndef rbtmove.h
#define rbtmove.h

#include "typstrct.h"

void dmove(CASE *case_state, int casetype);//�ı������

void move0(CASE *case_state,int casetype);//����ĸı��붯������

int aimmove(CASE *case_state,int x0,int y0,int xt,int yt, const Graph G, const int n, int casetype); //�û������ƶ�ʱ��Ҫֱ�ӵ��õĺ���

#endif
