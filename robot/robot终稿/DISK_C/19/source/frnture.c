#include "title.h"
/*************************************************************************************
��Դ�ļ��д�����мҾߵ�Դ����
��ڲ�����1. ��Ϊ����Ҫ���ĵط������Ͻǣ����ܶຯ���ж��и��ݾ����������һ����ƫ����
           2. ΪѰ·���㣬�󲿷ּҾߵ���ڲ�����40*40�Ĵ����꣬�պ�ռ��һ��block�����
           3. �ܶຯ����� x *= 40 �� y *= 40�Ĳ������ǽ�������ת��ΪС���ꡣ��������ص�С����Ĳ��ֻ����ǿ��
�����б�     void trashbin(int x,int y)      //����Ͱ
                void bed(int x,int y)           //��
                void window_close(int x,int y)      //����
                void cupboard(int x,int y)          //�¹�
                void aircon(int x,int y,int open)   //�յ�
                void WashMach(int x,int y)          //40*40��ϴ�»�
                void bookshelf(int x,int y)         //40*80�����
                void desk(int x,int y)              //80*40��С����
                void seat(int x,int y)              //40*40��С���
                void trash1(int x,int y)            //40*40��ֽ��
                void trash2(int x,int y)            //40*40����Ҷ
                void trash3(int x,int y)            //40*40������
                void pc(int x,int y)                //����
                void TV(int x,int y)                //����
                void rect_table(int x,int y)        //���Ʒ�׿
                void sofa_main(int x, int y)        //ɳ����Ҫ����
                void sofa_up(int x, int y)          //ɳ������Ļ���������
                void sofa_down(int x, int y)        //ɳ������Ļ���������
                void toilet(int x, int y)           //40*40����Ͱ
                void water_dispenser(int x, int y)  //40*80����ˮ��
                void zaotai(int x, int y)           //��̨
                void water_bottle(int x, int y)     //ˮ������������ص�С����
                void clothes(int x, int y)          //�·���������ȥ�¹��õ�ԡ�ң�
                void plate(int x,int y)             //����
                void medical_kit(int x, int y)      //ҽ�ư�
                void TV_on(void)                    //���Ӵ�״̬
                void TV_off(void)                   //���ӹرգ�������TV�Ĳ�֮ͬ���ǣ�Ҫ������滭ȥ�ָ�����ģ����
                void music_on(int x, int y)         //����
                void music_off( int x, int y)       //ȥ������
**************************************************************************************/

void trashbin(int x,int y)      //����Ͱ����ڲ���������Ͱ�����Ͻ�
{
	x = x*40;
	y = y*40+4;
	bar(x+15,y,x+35,y+40,65187);
	ever_Fillellipse(x+23,y,x+27,y,8,65187);
	ever_Fillellipse(x+23,y,x+27,y,6,0);
	ever_Fillellipse(x+23,y,x+27,y,5,65535);
}

void bed(int x,int y)       //��
{
	x = x*40+10;            //Ϊ��ֹͼ�������Ļ�����10��ƫ����
	y = y*40+4+30;          //+30
	theta_bar(x-5,y-48,30,4,-45,62604);
	theta_bar(x+20,y-50,32,4,45,62604);
	lean_line(x,y-48,4,-45,0);
	lean_line(x+48,y-50,4,45,0);
	bar(x-5,y-48,x+55,y-32,52263);
	bar(x-5,y-32,x+55,y+42,65535);
	bar(x+4,y-35,x+46,y-15,0);
	bar(x+5,y-35,x+45,y-15,65535);
	fill_bow_right_down(x+25,y-48,20,52263);
	fill_bow_left_down(x+25,y-48,20,52263);
	fill_bow_up(x+25,y+21,43,64950);
	bar(x-3,y-7,x+53,y+10,64950);
	fill_bow_up(x+25,y+28,40,65535);
	bar(x-4,y,x+54,y+42,0);
	bar(x-3,y,x+53,y+42,65535);
	bar(x-5,y+53,x+2,y+59,52263);
	bar(x+48,y+53,x+55,y+59,52263);
	bar(x-5,y+42,x+55,y+55,44373);
	bar(x-5,y+42,x+2,y+55,57083);
	bar(x+11,y+42,x+18,y+55,57083);
	bar(x+32,y+42,x+39,y+55,57083);
	bar(x+48,y+42,x+55,y+55,57083);
	linelevel(x-3,y+42,x+53,y+42,3,42260);
	linever(x+2,y+45,x+2,y+55,1,0);
	linever(x+11,y+45,x+11,y+55,1,0);
	linever(x+18,y+45,x+18,y+55,1,0);
	linever(x+32,y+45,x+32,y+55,1,0);
	linever(x+39,y+45,x+39,y+55,1,0);
	linever(x+48,y+45,x+48,y+55,1,0);
	fill_bow_down(x-2,y+53,4,65535);
    	fill_bow_down(x+14,y+53,4,65535);
	fill_bow_down(x+36,y+53,4,65535);
	fill_bow_down(x+53,y+53,4,65535);
	linelevel(x-5,y-48,x+55,y-48,1,0);
	linever(x,y-48,x,y-32,1,0);
	linever(x+50,y-48,x+50,y-32,1,0);
}

void window_close(int x,int y)      //���ŵĴ���
{
	x = x*40;
	y = y*40+4;
	bar(x,y+10,x+80,y+35,27469);
	bar(x+3,y+13,x+77,y+32,17430);
	bar(x+35,y+12,x+45,y+32,29714);
	linever(x+40,y+10,x+40,y+35,1,0);
}

void cupboard(int x,int y)      //�¹�
{
	x = x*40;
	y = y*40+4;
	theta_bar(x,y+5,20,10,-30,56612);
	theta_bar(x+12,y,20,10,30,56612);
	bar(x,y+5,x+40,y+40,0);
	bar(x+1,y+6,x+39,y+39,56612);
	linelevel(x,y+5,x+40,y+40,1,0);
	linever(x+20,y+5,x+20,y+40,1,0);
	circle(x+16,y+20,2,0);
	circle(x+24,y+20,2,0);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
}

void aircon(int x,int y,int open)//80*40,open==1Ϊ�������յ�
{

	int color[2] = {2016,55463};        //��һ��Ԫ�����̣��ڶ���Ԫ���Ǻ�
	x = x*40;
	y = y*40-2;
	bar(x,y+10,x+80,y+40,65535);
	linelevel(x,y+30,x+80,y+30,1,0);
	linever(x+4,y+30,x+4,y+40,1,0);
	linever(x+76,y+30,x+76,y+40,1,0);
	linelevel(x+10,y+34,x+70,y+34,1,0);
	linelevel(x+10,y+37,x+70,y+37,1,0);

	if(open)        //�յ���
	{
		FillCircle(x+5,y+15,3,color[0]);        //�̵���
	}
	else            //�յ���
	{
		FillCircle(x+5,y+15,3,color[1]);        //�����
	}

}

void WashMach(int x,int y)//40*40��ϴ�»�
{
	int color[3] = {17430/*����*/,29714/*ʯ���*/,50712/*��ɫ������������ӰЧ��*/};
	x = x*40+5;        //��8��ƫ����
	y = y*40+4;
	theta_bar(x,y+5,20,10,-30,color[2]);
	theta_bar(x+12,y,20,10,30,color[2]);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
	bar(x,y+5,x+40,y+40,0);
	bar(x+1,y+6,x+39,y+39,65535);
	linelevel(x,y+5,x+40,y+5,1,0);
	FillCircle(x+20,y+23,10,color[1]);
	FillCircle(x+20,y+23,7,color[0]);
	circle(x+20,y+23,8,0);

}

void bookshelf(int x,int y)//40*80�����
{
	int color[5] = {44373,64033,64594,34816,45312};//���ɫ���Ⱥ�ɫ�����ɫ�����ɫ���ͻ�ש
	x = x*40;
	y = y*40+4;
	bar(x,y,x+40,y+2,65535);
	bar(x,y+40,x+40,y+42,65535);
	bar(x,y+2,x+2,y+40,color[0]);
	bar(x+38,y+2,x+40,y+40,color[0]);
	bar(x,y+42,x+2,y+80,color[0]);
	bar(x+38,y+42,x+40,y+80,color[0]);

	//��
	bar(x+2,y+30,x+7,y+40,color[1]);
	bar(x+7,y+30,x+12,y+40,color[2]);
	bar(x+12,y+20,x+20,y+40,color[3]);
	bar(x+20,y+20,x+28,y+40,65535);
	bar(x+28,y+20,x+36,y+40,color[4]);
}

void desk(int x,int y)//80*40��С����
{
	int color[2] = {41605,65469};//������ɫ������ɫ
	x = x*40+5;
	y = y*40+4;
	bar(x,y,x+80,y+25,color[0]);
	bar(x,y+25,x+80,y+32,color[1]);
	bar(x,y+32,x+10,y+40,color[1]);
	bar(x+70,y+32,x+80,y+40,color[1]);
}

void seat(int x,int y)//40*40��С���
{
	int color = 65370;//�Ŷ���
	x = x*40;
	y = y*40+4;
	bar(x+11,y+10,x+30,y+30,0);
	bar(x+12,y+11,x+29,y+29,color);
	ever_Fillellipse(x+15,y+10,x+25,y+10,5,0);
	ever_Fillellipse(x+15,y+10,x+25,y+10,4,color);
}

void trash1(int x,int y)//40*40��ֽ��
{
	x = x*40;
	y = y*40+4;
	FillCircle(x+20,y+30,5,65535);
	triangle1(x+12,y+23,7,65535);
	triangle1(x+25,y+12,10,65535);
	lean_line(x+25,y+30,7,-45,0);
	bow(x+23,y+21,12,0);

}

void trash2(int x,int y)//40*40,��Ҷ
{
    x = x*40;
    y = y*40+4;
    linever(x+20,y+15,x+20,y+25,2,transcolor(127,255,0));
    linever(x+14,y+15,x+14,y+25,2,transcolor(127,255,0));
    linever(x+18,y+15,x+18,y+25,2,transcolor(127,255,0));
    lean_line(x+20,y+25,10,45,transcolor(127,255,0));
    lean_line(x+14,y+25,10,45,transcolor(127,255,0));
	lean_line(x+18,y+25,10,45,transcolor(127,255,0));
}

void trash3(int x,int y)//40*40,����
{
	x = x*40;
	y = y*40+4;
	bar(x+18,y+10,x+22,y+25,transcolor(255,215,0));
	ever_Fillellipse(x+12,y+10,x+28,y+10,3,63488);
	linever(x+20,y,x+20,y+10,1,0);
}

void pc(int x,int y)    //����
{
	x = x*40+5;       //���������С��������꣬��5��ƫ����
	y = y*40;
	bar(x,y,x+40,y+20,0);
	bar(x+2,y+2,x+38,y+18,65535);
	bar(x+16,y+20,x+24,y+25,0);
	bar(x+12,y+25,x+28,y+28,0);
}

void TV(int x,int y)    //15*125
{
    x = x*40;       //���������С���������
	y = y*40+4+40;
	bar(x,y,x+6,y+150,0);  //��ɫ����
}

void rect_table(int x,int y)//80*80��ľ���Ʒ���
{
	int i;
	int color[3]={63222,54705,35362};
	x = x*40+5;     //��5��ƫ����
	y = y*40+4;
	bar_round(x+40,y+35,80,70,3,1,0);
	bar_round(x+40,y+35,78,68,3,1,color[1]);
	bar(x+5,y+1,x+7,y+69,color[0]);
	bar(x+5+1*15,y+1,x+9+1*15,y+69,color[0]);
	bar(x+5+2*15,y+1,x+13+2*15,y+69,color[0]);
	bar(x+5+48,y+1,x+9+3*15,y+69,color[0]);
	bar(x+5+64,y+1,x+7+4*15,y+69,color[0]);
	theta_bar(x,y+71,50,6,45,color[2]);
	theta_bar(x+40,y+74,38,5,-45,color[2]);
	bar(x+10,y+75,x+14,y+80,color[2]);
	bar(x+68,y+75,x+74,y+80,color[2]);

}

void sofa_main(int x, int y)    //ɳ����Ҫ����
{
    x = x * 40;
    y = y * 40 +4;
    bar(x+20, y, x + 80, y + 160, 56784);    //Ӳľɫ
    bar(x+20, y+40, x + 50, y + 120, 65370);     //�Ŷ���
}

void sofa_up(int x, int y)      //ɳ������Ļ���������
{
    x = x * 40;
    y = y * 40 +8;
    bar(x, y, x + 80, y + 60, 56784);    //Ӳľɫ
    bar(x + 20, y + 20, x + 60, y + 60, 65370);     //�Ŷ���
}

void sofa_down(int x, int y)    //ɳ������Ļ���������
{
    x = x * 40;
    y = y * 40 +12;
    bar(x, y, x + 80, y + 60, 56784);    //Ӳľɫ
    bar(x + 20, y, x + 60, y + 40, 65370);     //�Ŷ���
}

void toilet(int x, int y)       //��Ͱ
{
    int i;
    x = x * 40 + 5;     //5��ƫ����
    y = y * 40;
    linelevel(x, y + 10, x + 10, y + 10, 1, 0);

    bar(x, y + 10, x + 10, y + 40, 65535);  //ˮ��
    Horizline(x, y + 10, 10, 0);
    Horizline(x, y + 20, 10, 0);        //ˮ���ϵķָ���

    bar(x + 10, y + 30, x + 20, y + 40, 65535); //����
    eqver_tri(x + 20, y + 30, 10, 65535);
    lean_line(x + 20, y + 40, 10 * sqrt(2), -45, 0);     //�����κ��ⲿ�ķֽ���
    Horizline(x, y + 40, 20, 0);

    FillCircle(x + 15, y + 10, 5, 65535);          //��Ͱ��
    bow_left_up(x + 15, y + 10, 5, 0);               //��Ͱ�Ǳ߿�
    bow_right_up(x + 15, y + 10, 5, 0);
    bar(x + 10, y + 10, x +20, y + 20, 65535);
    linever(x + 20, y + 10, x + 20, y + 20, 1, 0);      //Ҳ����Ͱ�������ı߽�

    bar(x + 10, y + 20, x + 25, y + 30, 65535);     //��Ͱ...
    lean_line(x + 10, y + 30, 10 * sqrt(2), -45, 0); //��������֮���б��
    Horizline(x + 20, y + 20, 8, 0);            //��������
    linelevel(x + 17.5, y + 22.5, x + 28, y + 22.5, 1, 0);
    linelevel(x + 12.5, y + 27.5, x + 28, y + 27.5, 1, 0);
    Horizline(x + 10, y + 30, 15, 0);
    FillCircle(x + 25, y + 25, 5, 65535);
    bow_right_up(x + 25, y + 25, 2.5, 0);
    bow_right_down(x + 25, y + 25, 2.5, 0);
    bow_right_up(x + 25, y + 25, 5, 0);
    bow_right_down(x + 25, y + 25, 5, 0);

    linever(x + 10, y + 10, x + 10, y + 40, 1, 0);  //ˮ������Ͱ�ǵķֽ��ߣ������ǰ�滭�ᱻ����
}

void water_dispenser(int x, int y)  //��ˮ��
{
    x = x * 40;
    y = y * 40;

    //����
    y = y + 40; //�ڶ�������
    theta_bar(x,y+5,20,10,-30,29714);   //ʯ���
	theta_bar(x+12,y,20,10,30,29714);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
	bar(x,y+5,x+40,y+40,0);
	bar(x+1,y+6,x+39,y+39,65535);
	linelevel(x,y+5,x+40,y+5,1,0);

	//��ˮ��
	bar(x + 10, y + 10, x + 30, y + 30, 34431); //������
	bar(x + 17.5, y + 10, x + 22.5, y + 15, 7327);      //tap��������

    //ˮͰ
    y = y -40;  //��һ�����񣬱����
    ever_Fillellipse(x + 15, y + 10, x + 25, y + 10, 5, 26620); //ˮ��
    ever_Fillellipse(x + 15, y + 33, x + 25, y + 33, 5, 26620); //ˮ��
    bar(x + 12, y + 10, x + 28, y + 33, 26620);     //ˮ��
    bar(x + 18.5, y + 30, x + 21.5, y + 40, 26620);

}

void zaotai(int x, int y)       //��̨
{
    x = x * 40;
    y = y * 40;
    theta_bar(x, y + 10, 60, 10, -45, 46651);   //��������̨��
    theta_bar(x + 10, y+2, 60, 10, 45, 46651);
    bar(x, y + 10, x + 80, y + 40, 46651);
    Horizline(x, y + 10, 80, 0);
    Horizline(x, y + 40, 80, 0);
    Horizline(x + 10, y, 60, 0);
    lean_line(x, y + 10, 10 * sqrt(2), -45, 0);
    lean_line(x + 70, y, 10 * sqrt(2), 45, 0);
    linever(x, y +10, x, y + 40, 1, 0);
    linever(x + 80, y + 10, x + 80, y + 40, 1, 0);

    //��̨�ļ���Ȧ
    FillCircle(x + 30, y + 6, 2.5, 29779);    //���һ�
    FillCircle(x + 50, y + 6, 2.5, 29779);

    //������
    bow_left_up(x + 30, y + 6, 3.5, 0);
    bow_left_down(x + 30, y + 6, 3.5, 0);
    bow_right_up(x + 30, y + 6, 3.5, 0);
    bow_right_down(x + 30, y + 6, 3.5, 0);

    bow_left_up(x + 50, y + 6, 3.5, 0);
    bow_left_down(x + 50, y + 6, 3.5, 0);
    bow_right_up(x + 50, y + 6, 3.5, 0);
    bow_right_down(x + 50, y + 6, 3.5, 0);
}

///���Ͻǣ���һ��ˮ����ռ1/16��������ڸ�Ϊ���ص㣬���Ǵ����꣬��Ϊ�����˳����ͼ��Ҫ��
void water_bottle(int x, int y)
{
    bar(x+1, y, x+9, y+13, 0);
    bar(x+2, y+1, x+8, y+12, 59391);
}

void clothes(int x, int y)  //�·�
{
    bar(x+5, y, x+25, y+3, ARMSM);
    bar(x+5, y+4, x+25, y+6, PANTSM);
}

void plate(int x,int y)     //����
{
	theta_bar(x,y+5,20,10,-30,65535);
	theta_bar(x+12,y,20,10,30,65535);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
    linelevel(x,y+5,x+30,y+5,1,0);
}

void medical_kit(int x, int y)  //ҽ�ư�
{
	bar(x+10, y+15, x+30, y+35, 65535);
	FillCircle(x+20, y+25, 7, 63488);
	bar(x+18, y+20, x+22, y+30, 65535);     //ʮ�ֵĺ�
	bar(x+15, y+23, x+25, y+27, 65535);     //ʮ�ֵ���
}

void TV_on(void)            //���Ӵ�״̬
{
    int i,j;

    for (i=0;i<34;i++)
    {
        for (j=0;j<150+2*i;j++)
        {
            Putpixel64k(287+i,445-i+j,57083);
        }
    }

}

void TV_off(void)           //���ӹرգ�������TV�Ĳ�֮ͬ���ǣ�Ҫ������滭ȥ�ָ�����ģ����
{
    int j;

    for(j = 10; j < 16; j++)      //�ոձ�����ͶӰ��ɫ���ǲ��ֵĵذ�ָ�
    {
        wood_ver(7, j);
    }

    for(j = 11; j < 17; j++)     //��������������ǽ�ڻָ�
    {
        w_right(6, j);
    }

    TV(7, 10.5);
}

void music_on(int x, int y) //����
{
    bar(x*40+15,y*40,x*40+20,y*40+32,0);
    FillCircle(x*40+9,y*40+32,8,0);
    bow_right_up(x*40+20,y*40+15,15,0);
    bow_right_up(x*40+20,y*40+14,14,0);
    bow_right_up(x*40+20,y*40+13,13,0);
    bow_right_up(x*40+20,y*40+12,12,0);
    bow_right_up(x*40+20,y*40+11,11,0);
}

void music_off( int x, int y)   //ȥ������
{
    wood_ver(x, y);
	wood_ver(x, y-1);
}








