#include "title.h"
/****************************************************************
�����б�   1.void paint_man(CASE case_state, int identity)           //��һ�λ��˵�ʱ����ã��ử���˵�����
              2.void man_forebody(CASE case_state, int identity)        //�˵����棬����������İ����
              3.void man_backbody(CASE case_state)                      //�˵ı���
              4.void man_rightbody(CASE case_state)                     //�˵�����
              5.void man_leftbody(CASE case_state)                      //�˵�����
              6.void man_sleep(CASE case_state)                         //˯��ʱ������
              7.void man_getup(CASE case_state)                         //��
              8.void sit_1(CASE case_state)                             //�������ˣ������ͳԷ�ʱ����
              9.void sit_2(CASE case_state)                             //�������ˣ�����ʱ����
*****************************************************************/

//�������ܣ���һ�λ���ʱ�����˵ı������棬�������˵�����
//��ڲ�������ʾ�˵Ľṹ�壬�Լ�һ������ݵ��β�identity��
//          identityΪMASTER(��1)ʱΪ���ˣ�ΪINTRADER(��0)ʱΪ������
void paint_man(CASE case_state, int identity)
{
    //��ȡ���˵Ŀռ䡣��һ�λ��˵�ʱ���ô˺�������Ҫ��Ϊ��get_image
    get_image_man(case_state.xpixel, case_state.ypixel);
    man_forebody(case_state, identity);
}

//�������ܣ������˵�����
//��ڲ���ͬ�����paint_man
void man_forebody(CASE case_state, int identity)  //x-20,x+20,y+80,y
{
    int color[2][5] = {{HAIRI, SKINI, EYESI, ARMSI, PANTSI},{HAIRM, SKINM, EYESM, ARMSM, PANTSM}};
    ///color[0]�ǻ������õ���ɫ��color[1]��İ���˵ġ�
    ///ע�⵽identity��0��1�����ÿ��Ա�ʾ����ĵ�һά�͵ڶ�ά������������Լ�ȥһ�����ظ�����

    //ͷ
    bar(case_state.xpixel-9, case_state.ypixel+1, case_state.xpixel+9, case_state.ypixel+8, color[identity][0]);    //ͷ��
    bar(case_state.xpixel-9, case_state.ypixel+9, case_state.xpixel+9, case_state.ypixel+19, color[identity][1]);    //Ƥ��
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 1, color[identity][2]);      //���ۣ�����
    FillCircle(case_state.xpixel+4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel+4, case_state.ypixel+10, 1, color[identity][2]);      //���ۣ�����
    Horizline(case_state.xpixel-3, case_state.ypixel+16, 6, 0);    //��

    //����
    bar(case_state.xpixel-4, case_state.ypixel+20, case_state.xpixel+4, case_state.ypixel+25,color[identity][1]);

    //����
    bar(case_state.xpixel-18, case_state.ypixel+25, case_state.xpixel+18, case_state.ypixel+50, color[identity][3]);     //�����ֵĲ���
    linever(case_state.xpixel-10, case_state.ypixel+35, case_state.xpixel-10, case_state.ypixel+55, 1, 0);
    linever(case_state.xpixel+10, case_state.ypixel+35, case_state.xpixel+10, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-9, case_state.ypixel+50, case_state.xpixel+9, case_state.ypixel+55, color[identity][3]);     //�·�
    bar(case_state.xpixel-18, case_state.ypixel+50, case_state.xpixel-11, case_state.ypixel+55, color[identity][1]);     //��
    bar(case_state.xpixel+11, case_state.ypixel+50, case_state.xpixel+18, case_state.ypixel+55, color[identity][1]);

    //��
    bar(case_state.xpixel-9, case_state.ypixel+55, case_state.xpixel+9, case_state.ypixel+73, color[identity][4]);       //����
    linever(case_state.xpixel, case_state.ypixel+55, case_state.xpixel, case_state.ypixel+80, 1, 0);

    //�ţ�Ь�ӣ�
    bar(case_state.xpixel-9, case_state.ypixel+74, case_state.xpixel+9, case_state.ypixel+80, 0);
}

//���˵ı��棬�����ʾ�˵Ľṹ���ṩ�������λ��
void man_backbody(CASE case_state)
{
     //ͷ
    bar(case_state.xpixel-9, case_state.ypixel+1, case_state.xpixel+9, case_state.ypixel+19, 41605);    //���ƣ�ͷ��

    //����
    bar(case_state.xpixel-4, case_state.ypixel+20, case_state.xpixel+4, case_state.ypixel+25,63222);    //�׻�ɫ����ɫ

    //����
    bar(case_state.xpixel-18, case_state.ypixel+25, case_state.xpixel+18, case_state.ypixel+50, 65504);     //�����ֵĲ���
    linever(case_state.xpixel-10, case_state.ypixel+35, case_state.xpixel-10, case_state.ypixel+55, 1, 0);
    linever(case_state.xpixel+10, case_state.ypixel+35, case_state.xpixel+10, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-9, case_state.ypixel+50, case_state.xpixel+9, case_state.ypixel+55, 65504);     //��������ɫ���·�
    bar(case_state.xpixel-18, case_state.ypixel+50, case_state.xpixel-11, case_state.ypixel+55, 63222);
    bar(case_state.xpixel+11, case_state.ypixel+50, case_state.xpixel+18, case_state.ypixel+55, 63222);

    //��
    bar(case_state.xpixel-9, case_state.ypixel+55, case_state.xpixel+9, case_state.ypixel+73, 29186);       //����īɫ�Ŀ���
    linever(case_state.xpixel, case_state.ypixel+55, case_state.xpixel, case_state.ypixel+80, 1, 0);

    //�ţ�Ь�ӣ�
    bar(case_state.xpixel-9, case_state.ypixel+74, case_state.xpixel+9, case_state.ypixel+80, 0);
}

//���˵����棬�����ʾ�˵Ľṹ���ṩ�������λ��
void man_rightbody(CASE case_state)      //x-10, x+10, y+80,y
{
    //ͷ
    bar(case_state.xpixel-10, case_state.ypixel, case_state.xpixel-1, case_state.ypixel+20, 41605);
    bar(case_state.xpixel-1, case_state.ypixel, case_state.xpixel+10, case_state.ypixel+8, 41605);
    bar(case_state.xpixel-1, case_state.ypixel+9, case_state.xpixel+10, case_state.ypixel+20, 63222);
    FillCircle(case_state.xpixel+4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel+4, case_state.ypixel+10, 1, 65535);
    Horizline(case_state.xpixel+6, case_state.ypixel+18, 3, 0);

    //����
    bar(case_state.xpixel-4, case_state.ypixel+21, case_state.xpixel+4, case_state.ypixel+25, 63222);

    //����
    bar(case_state.xpixel-10, case_state.ypixel+26, case_state.xpixel+10, case_state.ypixel+55, 65504);
    linever(case_state.xpixel-5, case_state.ypixel+28, case_state.xpixel-5, case_state.ypixel+55, 1, 0);
    linever(case_state.xpixel+5, case_state.ypixel+28, case_state.xpixel+5, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-4, case_state.ypixel+50, case_state.xpixel+5, case_state.ypixel+55, 63222);   //��
    Horizline(case_state.xpixel-5, case_state.ypixel+55, 10, 0);

    //��
    bar(case_state.xpixel-8, case_state.ypixel+55, case_state.xpixel+8, case_state.ypixel+73, 29186);       //����īɫ�Ŀ���
    //�ţ�Ь�ӣ�

    bar(case_state.xpixel-8, case_state.ypixel+74, case_state.xpixel+8, case_state.ypixel+80, 0);
}

//���˵����棬�����ʾ�˵Ľṹ���ṩ�������λ��
void man_leftbody(CASE case_state)
{
    //ͷ
    bar(case_state.xpixel+1, case_state.ypixel, case_state.xpixel+10, case_state.ypixel+20, 41605);
    bar(case_state.xpixel-10, case_state.ypixel, case_state.xpixel+1, case_state.ypixel+8, 41605);
    bar(case_state.xpixel-10, case_state.ypixel+9, case_state.xpixel+1, case_state.ypixel+20, 63222);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 1, 65535);
    Horizline(case_state.xpixel-6, case_state.ypixel+18, -3, 0);

    //����
    bar(case_state.xpixel-4, case_state.ypixel+21, case_state.xpixel+4, case_state.ypixel+25, 63222);

    //����
    bar(case_state.xpixel-10, case_state.ypixel+26, case_state.xpixel+10, case_state.ypixel+55, 65504);
    linever(case_state.xpixel-5, case_state.ypixel+28, case_state.xpixel-5, case_state.y+55, 1, 0);
    linever(case_state.xpixel+5, case_state.ypixel+28, case_state.xpixel+5, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-4, case_state.ypixel+50, case_state.xpixel+5, case_state.ypixel+55, 63222);   //��
    Horizline(case_state.xpixel-5, case_state.ypixel+55, 10, 0);

    //��
    bar(case_state.xpixel-8, case_state.ypixel+55, case_state.xpixel+8, case_state.ypixel+73, 29186);       //����īɫ�Ŀ���

    //�ţ�Ь�ӣ�
    bar(case_state.xpixel-8, case_state.ypixel+74, case_state.xpixel+8, case_state.ypixel+80, 0);
}

//�������ܣ�time_line�У���ȥ˯��ʱ����վ�ŵ�����������put_image�ķ�ʽ�Ƴ����ָ����������ڴ��ϻ�����˯����ͼ��
//��ڲ�������ʾ�˵Ľṹ�壬�ṩ�������λ��
void man_sleep(CASE case_state) //�ϴ�˯��
{
    //ֱ�Ӵ��ϻ��˵�ͷ���ɣ�����get��put������Ҫ���Ȱ�վ�ŵ��˵�ͼ�����أ�Ҳ����put
    put_image_man(case_state.xpixel, case_state.ypixel);
	case_state.xpixel = 0.75*40+5;		//ͷ��λ�ã���ʱ�ı䣬+5����Ϊ���������5��ƫ����
	case_state.ypixel = 6.8*40;

    //ͷ
    bar(case_state.xpixel-9, case_state.ypixel+1, case_state.xpixel+9, case_state.ypixel+8, HAIRM);    //ͷ��
    bar(case_state.xpixel-9, case_state.ypixel+9, case_state.xpixel+9, case_state.ypixel+19, SKINM);    //Ƥ��

    Horizline(case_state.xpixel-6, case_state.ypixel+10, 4, 0);     //���ۣ����ۣ�
    Horizline(case_state.xpixel+2, case_state.ypixel+10, 4, 0);     //���ۣ����ۣ�
    Horizline(case_state.xpixel-3, case_state.ypixel+16, 6, 0);    //��

    //����
    bar(case_state.xpixel-4, case_state.ypixel+20, case_state.xpixel+4, case_state.ypixel+21,SKINM);
}

//�������ܣ��Ѵ���˯������ȥ����������Ӧλ�û���վ������
//��ڲ�������ʾ�˵Ľṹ�壬�ṩ�������λ��
void man_getup(CASE case_state) //��
{
    //�ػ�һ�Ŵ����Ϳ��԰�ͷ�����ˡ��ٰ��˻�������
    bed(0, 7);
    paint_man(case_state, MASTER);
}

//�˹���ʱ�ͳԷ�ʱ�ı������ˣ������ʾ�˵Ľṹ���ṩ�������λ��
void sit_1(CASE case_state)  //��������
{
    //ͷ��ʵ����ֻ��Ҫ��ͷ��
    bar(case_state.xpixel-9, case_state.ypixel+1, case_state.xpixel+9, case_state.ypixel+19, 41605);    //���ƣ�ͷ��

    //����
    bar(case_state.xpixel-4, case_state.ypixel+20, case_state.xpixel+4, case_state.ypixel+25,63222);    //�׻�ɫ����ɫ

    //����
    bar(case_state.xpixel-18, case_state.ypixel+25, case_state.xpixel+18, case_state.ypixel+40, 65504);     //�����ֵĲ���
    bar(case_state.xpixel-9, case_state.ypixel+40, case_state.xpixel+9, case_state.ypixel+50, 65504);
    bar(case_state.xpixel-9, case_state.ypixel+50, case_state.xpixel+9, case_state.ypixel+55, 65504);     //��������ɫ���·�
    linever(case_state.xpixel-10, case_state.ypixel+35, case_state.xpixel-10, case_state.ypixel+55, 1, 0);
    linever(case_state.xpixel+10, case_state.ypixel+35, case_state.xpixel+10, case_state.ypixel+55, 1, 0);

    //ƨ��
    bar(case_state.xpixel-9, case_state.ypixel+55, case_state.xpixel+9, case_state.ypixel+63, 29186);       //����īɫ�Ŀ���
}

//������ʱ�Ĳ������ˣ������ʾ�˵Ľṹ���ṩ�������λ��
void sit_2(CASE case_state)  //��������
{
     //ͷ
    bar(case_state.xpixel+1, case_state.ypixel, case_state.xpixel+10, case_state.ypixel+20, 41605);
    bar(case_state.xpixel-10, case_state.ypixel, case_state.xpixel+1, case_state.ypixel+8, 41605);
    bar(case_state.xpixel-10, case_state.ypixel+9, case_state.xpixel+1, case_state.ypixel+20, 63222);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 2, 0);
    FillCircle(case_state.xpixel-4, case_state.ypixel+10, 1, 65535);
    Horizline(case_state.xpixel-6, case_state.ypixel+18, -3, 0);

    //����
    bar(case_state.xpixel-4, case_state.ypixel+21, case_state.xpixel+4, case_state.ypixel+25, 63222);

    //����
    bar(case_state.xpixel-10, case_state.ypixel+26, case_state.xpixel+10, case_state.ypixel+55, 65504);
    linever(case_state.xpixel-5, case_state.ypixel+28, case_state.xpixel-5, case_state.y+55, 1, 0);
    linever(case_state.xpixel+5, case_state.ypixel+28, case_state.xpixel+5, case_state.ypixel+55, 1, 0);
    bar(case_state.xpixel-4, case_state.ypixel+50, case_state.xpixel+5, case_state.ypixel+55, 63222);   //��
    Horizline(case_state.xpixel-5, case_state.ypixel+55, 10, 0);

    //��
    bar(case_state.xpixel-18, case_state.ypixel+55, case_state.xpixel+8, case_state.ypixel+62, 29186);       //����īɫ�Ŀ���
    bar(case_state.xpixel-18, case_state.ypixel+62, case_state.xpixel-6, case_state.ypixel+70, 29186);
    bar(case_state.xpixel-18, case_state.ypixel+70, case_state.xpixel-6, case_state.ypixel+76, 0);
}

