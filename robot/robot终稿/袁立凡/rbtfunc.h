#ifndef rbtfunc.h
#define rbtfunc.h

#include "typstrct.h"

void rbtguard(CASE human, CASE robot, int identity, int *x, int *y, int *button);//��������

void treatment(CASE *human, CASE *robot, Graph G, int n, int *x, int *y, int *button, int *choice);//ҽ���չ˹���

void clean(CASE *robot, CASE *human, Graph G, int n);//��ɨ��������

#endif // rbtfunc

