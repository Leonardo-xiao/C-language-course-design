#include "title.h"
/******************************************************************************************
  �����б�   1.void guard(CASE human, CASE robot, int identity);             //��������
                2.void treatment(CASE *human, CASE *robot, Graph G, int n);     //ҽ���չ˹���
                3.void clean(case *robot);                                      //��ɨ��������
******************************************************************************************/
/*��������������������check����������˻���İ���ˡ��������ˣ���ǰ��ӭ�ʺ�����İ���ˣ�
                  ��׽İ����ͼ��ͨ���ֻ���֪���ˣ����Ҵ��͵��ֻ���Ļ�ϣ������˽���ʶ��
                  ������˵���������������Զ�����110�����һ����˻Ằ�������������ߡ����Ծ���������
                  �������л������ڷ��������������ߣ���������Ϊ����������ˣ����������ӭ����������˻������ߡ�
  ��ڲ������ֱ��ʾ�ˣ������ߣ��ͻ����˵Ľṹ��human��robot��
            identity��ʾ����ݣ����Ǵ����ߣ�����Ϊ������õ�paint_man������Ҫ�ò���
            *x��*y��*button�������Ҫ�Ĳ���                                                   */
void rbtguard(CASE human, CASE robot, int identity, int *x, int *y, int *button)    //identity�������������˻���İ����
{
    int judge=0, j;
    paint_man(human, identity);
    if(identity)          //������
    {
        delay0(300);    //��һ��ʱ���������ʶ��ʱ��
        saveimage_g_c(robot.xpixel-105, robot.ypixel-40);     //�ڳ����ݿռ�

		bar(robot.xpixel-105, robot.ypixel-40, robot.xpixel-15, robot.ypixel,65535);
        fdhz(robot.xpixel-105, robot.ypixel-40,1,1,"���ˣ�",0);
        fdhz(robot.xpixel-105, robot.ypixel-20,1,1,"��ӭ�ؼ�",0);
        delay0(1500);  //������ʾ����һ��ʱ��
        //void fdhz(int x,int y,int mx,int my,char *s,int color)
        putsave_g_c(robot.xpixel-105, robot.ypixel-40);    //��ԭ
    }
    else
    {
        delay0(300);    //��һ��ʱ���������ʶ��ʱ��
        FillCircle(robot.xpixel-7.5, robot.ypixel+12, 3, 63776);   //�۾�
        FillCircle(robot.xpixel+7.5, robot.ypixel+12, 3, 63776);//���û��۾�����䣬�۾����

        //�����˻�˵�����������ھ��������߷������л������ڼ��
        saveimage_g_c(robot.xpixel-105, robot.ypixel-40);     //�ڳ����ݿռ�
        bar(robot.xpixel-105, robot.ypixel-20, robot.xpixel-5, robot.ypixel,65535);
        fdhz(robot.xpixel-105, robot.ypixel-20,1,1,"����������",0);
        //���ż�put���������

        //�ֻ�����ʾ������������
        iph_frame(65534);
        fdhz(ORIGINX+28, ORIGINY+70,2,2,"����������",0);
        bar(ORIGINX+45, ORIGINY+155, FINALX-45, ORIGINY+250, 65535);         //���񱳾�

        //�ֻ��ϻ��Ŵ������
        human.xpixel = MIDDLEX;		//�ֻ��ϵ���
        human.ypixel = ORIGINY+165;
        man_forebody(human, INTRADER);

        //ѯ���Ƿ񱨾�
        bar(ORIGINX+45, ORIGINY+295, MIDDLEX-10, ORIGINY+355, 63488);   //��ɫ
        fdhz(ORIGINX+65, ORIGINY+315,1,1,"����",0);
        bar(MIDDLEX+10, ORIGINY+295, FINALX-45, ORIGINY+355, 2016);   //��ɫ
        fdhz(MIDDLEX+30, ORIGINY+315,1,1,"��ӭ",0);

        while(1)
        {
            newxy(x, y, button);

            if(ORIGINX+45<=*x && *x<=MIDDLEX-10 && ORIGINY+295<=*y && *y<=ORIGINY+355 && *button)         //��������������������
            {
                judge = 0;
                break;
            }
            else if(MIDDLEX+10<=*x && *x<=FINALX-45 && ORIGINY+295<=*y && *y<=ORIGINY+355 && *button)     //��������ԡ�
            {
                judge = 1;
                break;
            }
        }

		mousehide(*x,*y);

        if(!judge)      //����
        {
            iph_frame(65534);

            fdhz(ORIGINX+45, ORIGINY+100,2,2,"���ں���",0);
            outtextxy(ORIGINX+55, ORIGINY+140,"110",2,2,50, 0);
            delay(2000);
            human.xpixel = human.x*40;
            human.ypixel = human.y*40;      //ǰ��ı���pixelλ�ã�����x,y������û�䣬���ڱ��ȥ�����˸��ǵ�
            put_image_man(human.xpixel, human.ypixel);
            putsave_g_c(robot.xpixel-105, robot.ypixel-40);    //����
            iph_frame(65534);               //�ֻ��ָ�

        }
        else
        {
            putsave_g_c(robot.xpixel-105, robot.ypixel-40);    //����
            saveimage_g_c(robot.xpixel-105, robot.ypixel-40);     //�ڳ����ݿռ�
            bar(robot.xpixel-105, robot.ypixel-40, robot.xpixel-10, robot.ypixel,43001);    //��ɫ����
            fdhz(robot.xpixel-105, robot.ypixel-40,1,1,"��ã���",0);
            fdhz(robot.xpixel-105, robot.ypixel-20,1,1,"ӭ��ĵ���",0);

            delay(2000);
            putsave_g_c(robot.xpixel-105, robot.ypixel-40);    //����
			put_image_man(human.xpixel, human.ypixel);
			bar(3 * 40, 1 * 40, 7 * 40, 3 * 40, 65502); //��ֹ�˲���ʧ�����ſ��ǿ黭һ��

			for(j = 1; j < 4; j++)
            {
                w_right(2, j);       //ԡ��
            }

        }

        FillCircle(robot.xpixel-7.5, robot.ypixel+12, 3, 1023);   //�۾����ȥ
        FillCircle(robot.xpixel+7.5, robot.ypixel+12, 3, 1023);

    }

	mousehide(*x,*y);
	iph_page_1();

}
///����Ҫ*choice��main2����ֱ�Ӵ�&choice[4]�ͺ���
/*
��������������⵽���˷���ʱ����һ��ˮ��ѯ���Ƿ񲦴�120�������������
          �����˰�ҩ����ڴ�ͷ��������ȡ��
��ڲ������˺ͻ����˵Ľṹ��ָ�루��ΪҪ�ƶ��������꣬�ʱ��봫ָ�룩
          ͼG�Լ�ͼ��Ԫ�ظ���n������Ѱ·��*x��*y��*button������õ�
          choiceָ����main2�д����choice���飬�����޸�choice������¼�Ƿ�ȥ��ҽԺ
*********************************************/
/**void fdhz(int x,int y,int mx,int my,char *s,int color)*/
void treatment(CASE *human, CASE *robot, Graph G, int n, int *x, int *y, int *button, int *choice)
{
    int i, judge=0;
	iph_page_1();

    aimmove(robot, robot->x, robot->y, 14, 2, G, n, ROBOT);//�ƶ���ˮ����
    robot->catch_th = WITH_BOTTLE;   //��ˮ�����ı���������Ժ󣬻�ͼ����fore_hold�ȳ�ˮ���ĺ�����
	water_dispenser(15, 1);          //�ػ���ˮ����ԭ�������渲����ˮ��������ˮ���������ˣ����յ���ˮ��

    aimmove(robot, robot->x, robot->y, 2, 8, G, n, ROBOT);      //����ͷ

    water_bottle(3*40+5, 8*40);                //ˮ�����ڴ�ͷ������
    robot->catch_th = WITHOUT_THING;        //ˮ�����º󣬻ص�������״̬
    saveimage_t_c(robot->xpixel, robot->ypixel-36);    //�ڳ����ݿռ�
    bar(robot->xpixel, robot->ypixel-36, robot->xpixel+120, robot->ypixel, 43001);           //�����ݣ���ɫ
    fdhz(robot->xpixel, robot->ypixel-36,1,1,"���ˣ���",0);
    fdhz(robot->xpixel, robot->ypixel-18,1,1,"��������",0);
    delay0(500);
    bar(robot->xpixel, robot->ypixel-36, robot->xpixel+120, robot->ypixel, 43001);           //�����ݣ���ɫ
    fdhz(robot->xpixel, robot->ypixel-36,1,1,"��Ҫ����",0);
    outtextxy(robot->xpixel+90, robot->ypixel-36,"120",1,1,10,0);
    fdhz(robot->xpixel, robot->ypixel-18,1,1,"��",0);
    delay(500);
    putsave_t_c(robot->xpixel, robot->ypixel-36);    //��ԭ

    //�������ֻ��ϵĶ���
    iph_frame(65534);
    bar(ORIGINX+45, ORIGINY+155, FINALX-45, ORIGINY+205, 54938);
    bar(ORIGINX+45, ORIGINY+210, FINALX-45, ORIGINY+250, 54938);
    fdhz(ORIGINX+45, ORIGINY+155,1,1,"����",0);
    outtextxy(ORIGINX+98, ORIGINY+155,"120",1,1,10,0);
    fdhz(ORIGINX+45, ORIGINY+210,1,1,"��Ϣһ�¾ͺ�",0);

    while(1)
    {
            newxy(x, y, button);

            if(*x>=ORIGINX+45 && *x<=FINALX-45 && *y>=ORIGINY+155 && *y<=ORIGINY+205 && *button)
            //if(ORIGINX+45<=*x && *x<=FINALX-45 && ORIGINY+155<=*y && *y<=ORIGINY+205 && *button)         //���������120�����������
            {
                judge = 0;
                break;
            }
            else if(*x>=ORIGINX+45 && *x<=FINALX-45 && *y>=ORIGINY+210 && *y<=ORIGINY+250 && *button)
            //else if(ORIGINX+45<=*x && *x<=FINALX-45 && ORIGINY+210<=*y && *y<=ORIGINY+250 && *button)     //�������Ϣһ�¾ͺá�
            {
                judge = 1;
                break;
            }
    }

	mousehide(*x,*y);

    if(!judge)               //��꽻�������������120��������
    {
        iph_frame(65534);
        fdhz(ORIGINX+50, ORIGINY+215,2,2,"���ں���",0);
        outtextxy(ORIGINX+50, ORIGINY+255,"120",2,2,50, 0);
        delay0(50);
        bed(0, 7);
        choice[4] = 1;      //����120����ȥҽԺ���ڶ��첻��
    }
    else
    {
        //ҩ��ŵ���ͷ����
        medical_kit(3*40+5, 7*40);
        saveimage_t_c(robot->xpixel, robot->ypixel-36);    //�ڳ����ݿռ�
        bar(robot->xpixel, robot->ypixel-36, robot->xpixel+120, robot->ypixel, 43001);           //�����ݣ���ɫ
        fdhz(robot->xpixel, robot->ypixel-36,1,1,"���Ұ�ҽ��",0);
        fdhz(robot->xpixel, robot->ypixel-18,1,1,"��������",0);
        putsave_t_c(robot->xpixel, robot->ypixel-36);    //��ԭ
        choice[4] = 0;      //û��120���ڶ�����
    }

    aimmove(robot, robot->x, robot->y, 13, 3, G, n, ROBOT);     //�ص�ԭ����λ��
    
	iph_page_1();

}

/********����������������Զ�Ѱ·ʰȡ******/
void clean(CASE *robot, CASE *human, Graph G, int n)     //һ��������û���
{
    Axis V1 = {12, 13}, V2 = {12, 13}, V3 = {12, 13}, Vtemp, Vex[3];
    int i, j, a, b, c;  //a��b��c���������������ѡ��������ʽ��

    //���������ĺ������꣨�����꣩��������ʼ����Ŀ���ǣ�ȷ�����鲻Խ�磬�ֱ�֤�����while
    //V1��V2,V3����Ҫ���������ĵ㣬Vex���ݸ���������˵�λ�ý�������
    //��������ͼר�Ÿ�trash�ã��ͻ�����Ѱ·û��ϵ
     const static int unaccessible[16][19]={
                                //[4][14],[5][4],[9][9]
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //��һ��
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
                                {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //��16��
                            };

    //���ͼ��findway������һ��������ΪҪ���������trash��߼�������
    //�������ڰ���������У�������0����һ�У�Ҳ������ߣ�Ϊ0�Ķ���Ϊ1�����ɴ�
    get_image_man(human->xpixel, human->ypixel);
    srand(time(NULL));       //���������

    while(unaccessible[V1.x-1][V1.y] && unaccessible[V1.x][V1.y-1])   //ǰһ��������֤�������ܵ���������ߣ���һ��������֤�������ֵĵط�û�б�Ķ���
    {
        V1.x = rand()%15+1;
        V1.y = rand()%18+1;
    }

    while(unaccessible[V2.x-1][V2.y] && unaccessible[V2.x][V2.y-1])
    {
        V2.x = rand()%15+1;
        V2.y = rand()%18+1;
    }

    while(unaccessible[V3.x-1][V3.y] && unaccessible[V3.x][V3.y-1])
    {
        V3.x = rand()%15+1;
        V3.y = rand()%18+1;
    }

    //����������������ѡ�����򷨣�
    Vex[0] = V1;
    Vex[1] = V2;
    Vex[2] = V3;

    for(i = 0; i < 2; i++)
    {
        for(j = i + 1; j < 3; j++)
        {   //����׼����1�������룬����ŷʽ����
            if(abs(Vex[i].x - robot->x) + abs(Vex[i].y - robot->y) > abs(Vex[j].x - robot->x) + abs(Vex[j].y - robot->y)) //1�������룬����ŷʽ����
            {
                Vtemp = Vex[i];
                Vex[i] = Vex[j];
                Vex[j] = Vtemp;
            }
        }
    }

    //�����������ı���������
    get_image_trash1(Vex[0].x*40, Vex[0].y*40);
    get_image_trash2(Vex[1].x*40, Vex[1].y*40);
    get_image_trash3(Vex[2].x*40, Vex[2].y*40);

    //��������������������������������������㣬���Բ���������������
    a = rand()%3+1;

    do{
        b = rand()%3+1;
    }while(b == a);     //ȷ��a��b�����

    do{
        c = rand()%3+1;
    }while(c == a || c == b);   //ȷ��c����a��b���

    //��������������ֵ��ȷ����λ����������ʽ
    switch(a)
    {
        case 1:     //��aΪ1��Vex[0]������һ����������ֽ��
            trash1(Vex[0].x, Vex[0].y);
            break;
        case 2:     //��aΪ2��Vex[0]�����ڶ�������
            trash2(Vex[0].x, Vex[0].y);
            break;
        case 3:     //��aΪ3��Vex[0]������������������ֽ��
            trash3(Vex[0].x, Vex[0].y);
            break;
    }

    switch(b)
    {
        case 1:     //��bΪ1��Vex[1]������һ����������ֽ��
            trash1(Vex[1].x, Vex[1].y);
            break;
        case 2:     //��bΪ2��Vex[1]�����ڶ�������
            trash2(Vex[1].x, Vex[1].y);
            break;
        case 3:     //��bΪ3��Vex[1]��������������
            trash3(Vex[1].x, Vex[1].y);
            break;
    }

    switch(c)
    {
        case 1:     //��cΪ1��Vex[2]������һ����������ֽ��
            trash1(Vex[2].x, Vex[2].y);
            break;
        case 2:     //��cΪ2��Vex[2]�����ڶ�������
            trash2(Vex[2].x, Vex[2].y);
            break;
        case 3:     //��cΪ3��Vex[2]��������������
            trash3(Vex[2].x, Vex[2].y);
            break;
    }

    //�ܵ�trash���һ�񣬰�trash�������ͷ�
    aimmove(robot, robot->x, robot->y, Vex[0].x-1, Vex[0].y, G, n, ROBOT);      //������a����Vex[0]
    put_image_trash1(Vex[0].x*40, Vex[0].y*40);                                 //�ͷű���

	aimmove(robot, robot->x, robot->y, Vex[1].x-1, Vex[1].y, G, n, ROBOT);      //������b����Vex[1]
    put_image_trash2(Vex[1].x*40, Vex[1].y*40);                                 //�ͷű���

	aimmove(robot, robot->x, robot->y, Vex[2].x-1, Vex[2].y, G, n, ROBOT);      //������c����Vex[2]
    put_image_trash3(Vex[2].x*40, Vex[2].y*40);                                 //�ͷű���

	aimmove(robot, robot->x, robot->y, 8, 2, G, n, ROBOT);    //�ӵ�������

    aimmove(robot, robot->x, robot->y, 13, 4, G, n, ROBOT);    //�ص�ԭλ
}


