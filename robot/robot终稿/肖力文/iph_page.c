#include "title.h"



//���ܣ��ֻ����ȹ̶�Ԫ�أ��κν��涼��Ҫ��ʾ
void iph_frame()
{
	bar_round_2(ORIGINX,ORIGINY,FINALX,FINALY,30,1,65534);
	linelevel(ORIGINX+30,2,FINALX-30,2,2,0);
	linelevel(ORIGINX+30,FINALY,FINALX-30,547,2,0);
	linever(ORIGINX,ORIGINY+30,ORIGINX,FINALY-30,2,0);
	linever(FINALX,ORIGINY+30,FINALX,FINALY-30,2,0);
	bow_left_down(ORIGINX+30,FINALY-30,31,0);
	bow_left_down(ORIGINX+30,FINALY-30,32,0);
	bow_left_up(ORIGINX+30,ORIGINY+30,31,0);
	bow_left_up(ORIGINX+30,ORIGINY+30,32,0);
	bow_right_down(FINALX-30,FINALY-30,31,0);
	bow_right_down(FINALX-30,FINALY-30,32,0);
	bow_right_up(FINALX-30,ORIGINY+30,31,0);
	bow_right_up(FINALX-30,ORIGINY+30,32,0);
	bar (MIDDLEX-6,4,MIDDLEX+6,9,0);
	FillCircle(MIDDLEX,9,6,0);
	FillCircle(MIDDLEX,9,2,4523);												//	RGB��0 52 91
	//	�ź�&��Դ
	bar(FINALX-52,24,FINALX-49,32,0);
	bar(FINALX-48,21,FINALX-45,32,0);
	bar(FINALX-44,18,FINALX-41,32,0);
	bar(FINALX-40,15,FINALX-37,32,0);																//	RGB: 10 10 10
	bar_round(FINALX-20,21,20,12,2,1,0);

}

//���ܣ��ֻ����渽��Ԫ��
void iph_frame_plus()
{
    linelevel(ORIGINX,ORIGINY+56,FINALX,ORIGINY+56,1,0);                                   //ҳ������
    bar_round_2(ORIGINX,ORIGINY,FINALX,ORIGINY+56,30,1,54938);
    bar(ORIGINX,ORIGINY+26,FINALX,ORIGINY+56,54938);
    bar (MIDDLEX-6,ORIGINY,MIDDLEX+6,ORIGINY+5,0);
	FillCircle(MIDDLEX,ORIGINY+5,6,0);
	FillCircle(MIDDLEX,ORIGINY+5,2,4523);
	bar(FINALX-52,24,FINALX-49,32,0);
	bar(FINALX-48,21,FINALX-45,32,0);
	bar(FINALX-44,18,FINALX-41,32,0);
	bar(FINALX-40,15,FINALX-37,32,0);																//	RGB: 10 10 10
	bar_round(FINALX-20,21,20,12,2,1,0);
}

//���ܣ��ֻ�������
void iph_page_1()
{
    iph_frame();

    iph_frame_plus();
	fdhz(MIDDLEX-30,ORIGINY+18,1,1,"������",0);

	linelevel(ORIGINX,ORIGINY+209,FINALX,ORIGINY+209,1,0);                           //�ֶ�ָ�ť
	fdhz(MIDDLEX-80,ORIGINY+116,2,2,"�ֶ�ָ��",0);

	linelevel(ORIGINX,ORIGINY+363,FINALX,ORIGINY+363,1,0);
	fdhz(MIDDLEX-40,ORIGINY+269,2,2,"����",0);                               //���찴ť

	linelevel(ORIGINX,ORIGINY+515,FINALX,ORIGINY+515,1,0);                          //Ĭ�������޸İ�ť
	fdhz(MIDDLEX-120,ORIGINY+422,2,2,"Ĭ�������޸�",0);
}

//���ܣ��ֶ�ָ�����
void iph_page_2()                                                                   //�ֶ�ָ�����
{
    iph_frame();

    iph_frame_plus();
	fdhz(MIDDLEX-40,ORIGINY+18,1,1,"�ֶ�ָ��",0);

	linelevel(ORIGINX,ORIGINY+171,FINALX,ORIGINY+171,1,0);                         //��ɨ������ť
	fdhz(MIDDLEX-80,ORIGINY+116,2,2,"��ɨ����",0);

	linelevel(ORIGINX,ORIGINY+286,FINALX,ORIGINY+286,1,0);
	fdhz(MIDDLEX-60,ORIGINY+231,2,2,"��ˮ",0);

}

//���ܣ��������
void iph_page_3()                                                    //�������
{
    iph_frame();

    iph_frame_plus();
	fdhz(MIDDLEX-20,22,1,1,"����",0);

	/***************
	�����
	**************/
	bar_round_2(ORIGINX+13,ORIGINY+50,ORIGINX+243,ORIGINY+468,5,1,54938);
	bar_round_2(ORIGINX+13,ORIGINY+363,ORIGINX+243,ORIGINY+468,5,1,65535);
	bar(ORIGINX+13,ORIGINY+384,ORIGINX+243,ORIGINY+403,48631);		//191 191 191

	saveimage_box(ORIGINX+25, ORIGINY+365);

	/********
	���汳��
	********/
	FillCircle(ORIGINX+200,ORIGINY+157,40,54938);	//138 198 210
	fill_bow_right_up(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204
	fill_bow_right_down(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204


}

//���ܣ�Ĭ�������޸Ľ���
void iph_page_4(char *at,char *bt)                                             //Ĭ�������޸Ľ���
{
    iph_frame();

    iph_frame_plus();
	fdhz(MIDDLEX-60,ORIGINY+18,1,1,"Ĭ�������޸�",0);

    fdhz(MIDDLEX-100,ORIGINY+138,1,1,"�յ��¶�",0);
    bar(FINALX-120,ORIGINY+136,FINALX-95,ORIGINY+161,33808);//900��140��925��165   ����
    bar(FINALX-117,ORIGINY+146,FINALX-98,ORIGINY+151,65535);

    bar(FINALX-85,ORIGINY+128,FINALX-45,ORIGINY+168,65535);  //�¶���ʾ����
    outtextxy(FINALX-75,ORIGINY+138,at,1,1,10,0);

    bar(FINALX-35,ORIGINY+136,FINALX-10,ORIGINY+161,33808); //�Ӻ�
    bar(FINALX-32,ORIGINY+146,FINALX-13,ORIGINY+151,65535);
    bar(FINALX-25,ORIGINY+139,FINALX-20,ORIGINY+158,65535);

    fdhz(MIDDLEX-100,ORIGINY+253,1,1,"ϴ��ˮ��",0);
    bar(FINALX-120,ORIGINY+251,FINALX-95,ORIGINY+276,33808);//900��140��925��165   ����
    bar(FINALX-117,ORIGINY+261,FINALX-98,ORIGINY+266,65535);

    bar(FINALX-85,ORIGINY+243,FINALX-45,ORIGINY+283,65535);  //�¶���ʾ����
    outtextxy(FINALX-75,ORIGINY+253,bt,1,1,10,0);

    bar(FINALX-35,ORIGINY+251,FINALX-10,ORIGINY+276,33808); //�Ӻ�
    bar(FINALX-32,ORIGINY+261,FINALX-13,ORIGINY+266,65535);
    bar(FINALX-25,ORIGINY+254,FINALX-20,ORIGINY+273,65535);
}

//���ܣ�ʱ�����
void time_page()
{
    bar(764,572,1020,764,50712);//��ɫ���
    linelevel(764,690,1020,690,3,0);
    bar(794,597,990,665,65535);//ʱ����ʾ��
    fdhz(894-40,727-8,1,1,"��һ�¼�",0);
}
