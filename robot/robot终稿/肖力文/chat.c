#include "title.h"


//	�����ܮ�
void chat_interface()
{
	/***************
	�����
	**************/
	bar_round_2(ORIGINX+13,ORIGINY+50,ORIGINX+243,ORIGINY+413,5,1,54938);
	bar_round_2(ORIGINX+13,ORIGINY+403,ORIGINX+243,ORIGINY+508,5,1,65535);
}


void chatmain(CASE *robot)
 {
	Area box_area = { {ORIGINX+15+2,ORIGINY+420} , {ORIGINX+240,ORIGINY+465} };		//��������Ͻ�����
	Coordinate current_show_position = {ORIGINX+17,ORIGINY+415};		//������������ֵ����Ͻ�����

	int i;
	int flag;
	int *qhwh=(int *)malloc(sizeof(int)*MAXTXT);		//����λ��


	if(qhwh==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	//����
	iph_frame(28153);
	chat_interface();

	while(1)
	{
		//��ʼ����λ��
		QhwhToZero(qhwh);
		//��ʼ���뷨
		flag = ShowChTab(box_area,current_show_position/*������������ֵ����Ͻ�����*/, 16,qhwh) ;
		//�س���֮��ˢ�����촰��
		bar(ORIGINX+15, ORIGINY+405, ORIGINX+240, ORIGINY+460,65535);
		if(flag == 3)
		{
			show_main(qhwh,robot);
		}
		else
		{
			break;
		}
		getch();
	}
	free(qhwh);
	qhwh = NULL;
 }
