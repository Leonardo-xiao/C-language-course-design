#include "title.h"
#define YG 40
#define M 4
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define UP_DOWN 5
#define LEFT_RIGHT 6
/*****************************************************
�ذ��ש��ǽ��
��ڲ�����Ϊ���Ͻ����꣨40*40�Ĵ����꣩
******************************************************/

//����
void wood_ver(int x, int y)     //����һ��40*40�Ŀ�
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,64908);		//	�۳�ɫ����
	linever(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,1,31331);	//	��������
	linever(x*YG+10,y*YG+M,(x+1)*YG+10,(y+1)*YG+M,1,31331); //��ʮ�����ص㻭һ��
	linever(x*YG+20,y*YG+M,(x+1)*YG+20,(y+1)*YG+M,1,31331); //��40*40��λ����ϸ��
	linever(x*YG+30,y*YG+M,(x+1)*YG+30,(y+1)*YG+M,1,31331);
	linever(x*YG+40,y*YG+M,(x+1)*YG+40,(y+1)*YG+M,1,31331);
}

//ԡ��
void glass(int x, int y)
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,48797);		//	��ɫ����
	bar(x*YG,y*YG+M,(x+1)*YG,y*YG+M+2,55070);	//	ǳɫ�߿�
	bar(x*YG,y*YG+M,x*YG+2,(y+1)*YG+M,55070);
	bar(x*YG,(y+1)*YG+M-2,(x+1)*YG,(y+1)*YG+M,46651);			//	��ɫ�߿�
	bar((x+1)*YG-2,y*YG+M,(x+1)*YG,(y+1)*YG+M,46651);

	bar(x*YG+2,y*YG+M+18,(x+1)*YG-2,y*YG+M+20,46651);			//�м�ʮ��
	bar(x*YG+2,y*YG+M+20,(x+1)*YG-2,y*YG+M+22,55070);
	bar(x*YG+18,y*YG+M+2,x*YG+20,(y+1)*YG+M-2,46651);
	bar(x*YG+20,y*YG+M+2,x*YG+22,(y+1)*YG+M-2,55070);
}

//	����
void green_kitchen(int x, int y)
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,42552);		//	��ɫ����

	bar(x*YG,y*YG+M,(x+1)*YG,y*YG+M+1,31922);	//	��ɫ�߿�
	bar(x*YG,y*YG+M,x*YG+1,(y+1)*YG+M,31922);
	bar(x*YG,(y+1)*YG+M-1,(x+1)*YG,(y+1)*YG+M,31922);
	bar((x+1)*YG-1,y*YG+M,(x+1)*YG,(y+1)*YG+M,31922);

	bar(x*YG+1,y*YG+M+19,(x+1)*YG-1,y*YG+M+20,31922);			//�м�ʮ��
	bar(x*YG+1,y*YG+M+20,(x+1)*YG-1,y*YG+M+21,31922);
	bar(x*YG+19,y*YG+M+1,x*YG+20,(y+1)*YG+M-1,31922);
	bar(x*YG+20,y*YG+M+1,x*YG+21,(y+1)*YG+M-1,31922);
}

//  ����
void green_bedroom(int x, int y)
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,65502);		//	��ɫ����
	bar(x*YG,y*YG+M,(x+1)*YG,y*YG+M+2,52720);	//	��ɫ�߿�
	bar(x*YG,y*YG+M,x*YG+2,(y+1)*YG+M,52720);
	bar(x*YG,(y+1)*YG+M-2,(x+1)*YG,(y+1)*YG+M,57010);			//	ǳɫ�߿�
	bar((x+1)*YG-2,y*YG+M,(x+1)*YG,(y+1)*YG+M,57010);
}

//walls
//���濴��ȥ�����Ƕ´�ǽ
void w_blue(int x, int y)
{
	bar(x*YG,y*YG+M,(x+1)*YG,(y+1)*YG+M,42260);
	bar(x*YG,y*YG+M,(x+1)*YG,y*YG+M+5,31625);
}

//��ָ��x��y����ĸ��ӵ��Ҳ໭ǽ��
void w_right(int x,int y)           //w_��ͷ�ľ���ϸϸ�ı߿�
{                                   //right����ָ�����ӵ��ұ߻�
	bar((x+1)*YG,y*YG+M,(x+1)*YG+4,(y+1)*YG+M,31625);
}

//��ָ��x��y����ĸ��ӵ���໭ǽ��
void w_left(int x, int y)           //left��ָ�����ӵ����
{
	bar(x*YG,y*YG+M,x*YG+5,(y+1)*YG+M,31625);
}

void w_down(int x, int y)
{
	bar(x*YG,(y+1)*YG+M-2,(x+1)*YG,(y+1)*YG+M,31625);
}
