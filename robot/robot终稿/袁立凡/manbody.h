#ifndef manbody.h
#define manbody.h

#include "typstrct.h"

extern void paint_man(CASE case_state, int identity);   //��һ�λ��˵�ʱ����ã��ử���˵�����

void man_forebody(CASE case_state, int identity);   //�˵����棬����������İ����

void man_backbody(CASE case_state);                 //�˵ı���

void man_leftbody(CASE case_state);                 //�˵�����

void man_rightbody(CASE case_state);                //�˵�����

void man_sleep(CASE case_state);                    //˯��ʱ������

void man_getup(CASE case_state);                    //��

void sit_1(CASE case_state);                        //�������ˣ������ͳԷ�ʱ����

void sit_2(CASE case_state);                        //�������ˣ�����ʱ����

#endif
