#include "title.h"
/****************************************************************************
�����б�   1.paint_floor();      //���ذ�
              2.paint_wall();       //��ǽ��
              3.paint_furniture();  //���Ҿ�
���ܣ�     ���÷�װ��bricks.c��wall.c��frnture.c�еĺ�������������������
****************************************************************************/

void paint_house()
{
    paint_floor();      //���ذ�
    paint_wall();       //��ǽ��
    paint_furniture();  //���Ҿ�
}

void paint_floor()      //�ذ�
{
    int i, j;

    bar(3*40, 1*40, 7*40, 3*40, 65502);         //���屳�����ɰ�ɫ��������������������Ǻڵ�

    for(i = 3; i < 7; i++)      //���Ŵ�
    {
        for(j = 3; j < 6; j++)
        {
            wood_ver(i, j);
        }
    }

    for(i = 7; i < 16; i++)      //��������
    {
        for(j = 3; j < 19; j++)
        {
            wood_ver(i, j);
        }
    }

    ///���ϰѿ������ֻ����ˣ������Ǹ���С����

    for(i = 0; i < 3; i++)    //bathroom
    {
        for(j = 1; j < 6; j++)
        {
            glass(i, j);
        }
    }

    for(j = 1; j < 3; j++)    //kitchen
    {
        for(i = 7; i < 16; i++) //i��ѭ�����������������Ч��
        {
            green_kitchen(i, j);
        }
    }

    for(i = 0; i < 7; i++)    //bedroom
    {
        for(j = 7; j < 19; j++)
        {
            green_bedroom(i, j);
        }
    }

}

void paint_wall()       //ǽ��
{
    int i, j;

    for(i = 0; i < 7; i++)      //���ϵĺ����ҵ�
    {
        w_blue(i, 0);
        w_blue(i, 6);
    }

    for(i = 7; i < 16; i++)     //���ϵģ���Ϊ����ֻ���� i = 6Ϊֹ�����ϵ�ʣ�ಿ�ֵ���������
    {
        w_blue(i, 0);
    }

    for(j = 11; j < 19; j++)     //�������������
    {
        w_right(6, j);
    }

    for(j = 0; j < 19; j++)     //��������
    {
        w_right(15, j);
    }

    for(j = 1; j < 3; j++)  //������
    {
        w_left(7, j);
    }

    for(j = 1; j < 4; j++)
    {
        w_right(2, j);       //ԡ��
    }

}

void paint_furniture()  //�Ҿ�
{
    //bedroom
    bed(0, 7);
    rect_table(3, 7);
    aircon(3, 6, 0);
    bookshelf(6, 11);
    bookshelf(6, 12);
    bookshelf(6, 13);
    bookshelf(6, 14);
    cupboard(6, 11);
    rect_table(0, 13);
    desk(0, 15);
    seat(0, 12);
    seat(2, 14);
    seat(0, 16);
    pc(0, 15);

    //reception room
    rect_table(11, 12);
    desk(12, 8);
    seat(12, 7);    //�����Աߵ�С���
    seat(13, 7);
    seat(11, 8);
    seat(14, 8);
    seat(12, 9);
    seat(13, 9);
    TV(7, 10.5);
    sofa_main(14, 11);
    sofa_up(11, 10);
    sofa_down(11, 14.5);

    //bathroom
    window_close(1, 0);
    WashMach(0, 1);
    toilet(0, 3);

    //kitchen
    trashbin(7, 2);
    water_dispenser(15, 1);
    zaotai(9, 1);
    desk(12, 1);    //��ˮ��������
    water_bottle(15.5*40, 2.4*40);
}
