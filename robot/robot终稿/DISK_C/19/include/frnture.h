#include "typstrct.h"
#ifndef furniture.h
#define furniture.h

extern void trashbin(int x,int y);      //����Ͱ����ڲ���������Ͱ�����Ͻ�

extern void bed(int x,int y);       //��

extern void window_close(int x,int y);      //���ŵĴ���

extern void cupboard(int x,int y);      //�¹�

void aircon(int x,int y,int open);	//80*40,open==1Ϊ�������յ�

void WashMach(int x,int y);	//40*40��ϴ�»�

void bookshelf(int x,int y);	//40*80�����

void desk(int x,int y);	//80*40��С����

void seat(int x,int y);	//40*40,������12��28֮�䣬С���

void trash1(int x,int y);	//40*40��ֽ��

void trash2(int x,int y);	//40*40,��Ҷ

void trash3(int x,int y);	//40*40,����

void pc(int x,int y);		//���ԣ�Ҫ�������Ǹ����������

void TV(int x,int y);		//15*125

//ľ���Ʒ���
void rect_table(int x,int y);	//80*80

extern void sofa_main(int x, int y);        //����ɳ��

extern void sofa_up(int x, int y);          //ɳ�����̣�����ģ�

extern void sofa_down(int x, int y);         //ɳ�����̣�����ģ�

void toilet(int x, int y);			//��Ͱ

extern void water_dispenser(int x, int y);	//��ˮ����40*80

extern void zaotai(int x, int y);		//��̨

extern void water_bottle(int x, int y);		//ˮ��

extern void clothes(int x, int y);  //�·�

extern void plate(int x,int y);  //����

void medical_kit(int x, int y);	//ҽ�ư�

extern void TV_on(void);        //���Ӵ�

extern void TV_off(void);       //���ӹر�

extern void music_on(int x, int y);     //����

extern void music_off( int x, int y);   //ȥ������
#endif
