#include "title.h"
/*******************************************************
�����б�   1.void paint_robot(CASE case_state)      //��һ�λ�������ʱ���ã����������˴��ı������棬����������������
              2.void forebodyhead(CASE case_state)              //����������
              3.void backbodyhead(CASE case_state)              //�����˱���
              4.void robot_left(CASE case_state)                //����������
              5.void robot_right(CASE case_state)               //����������
              6.void robot_hand_right(int x,int y,int theta)    //�����˵��֣�ָ���Ҳ࣬��װ�������������ļ��������е���
              7.void robot_hand_left(int x,int y,int theta)     //�����˵��֣�ָ����࣬��װ�������������ļ��������е���
              8.void right_hold(CASE case_state)                //�������ֳ���Ʒ������
              9.void left_hold(CASE case_state)                 //�������ֳ���Ʒ������
              10.void front_hold(CASE case_state)               //�������ֳ���Ʒ�����ߣ������棩
              11.void back_hold(CASE case_state)                //�������ֳ���Ʒ�����ߣ������棩
********************************************************/

//�������ܣ���һ�λ���ʱ���������˵ı������棬�����������˵�����
void paint_robot(CASE case_state)
{
	 //��ȡ�����˱��������ƻ�����
	get_image_robot(case_state.xpixel, case_state.ypixel);
    forebodyhead(case_state);
}

//�������˵����棬�����ʾ�����˵Ľṹ���ṩ�����������λ��
void forebodyhead(CASE case_state)//��Χ��case_state.xpixel+-30;
{
	robot_hand_right(case_state.xpixel+4,case_state.ypixel+56,45);
	robot_hand_left(case_state.xpixel-28,case_state.ypixel+65,-45);
	//ͷ
	ever_Fillellipse(case_state.xpixel-7.5, case_state.ypixel+12, case_state.xpixel+7.5, case_state.ypixel+12, 9, 0);    //�Ȼ����ٸ��ǣ��൱����������
	ever_Fillellipse(case_state.xpixel-7.5, case_state.ypixel+12, case_state.xpixel+7.5, case_state.ypixel+12, 8, 65535);

    FillCircle(case_state.xpixel-7.5, case_state.ypixel+12, 3, 1023);   //�۾�
    FillCircle(case_state.xpixel+7.5, case_state.ypixel+12, 3, 1023);
    //��Ҫ���Ҳ��
   // bow(case_state.xpixel-7.5, case_state.ypixel+12, 7.5/sin(3.14159/12), 0);
    //��
    bar(case_state.xpixel-15, case_state.ypixel+60, case_state.xpixel+15, case_state.ypixel+75, 65535);
    linever(case_state.xpixel-15, case_state.ypixel+60, case_state.xpixel-15, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+15, case_state.ypixel+60, case_state.xpixel+15, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+70, 30, 0);
    linever(case_state.xpixel, case_state.ypixel+60, case_state.xpixel, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);
    //����
	bar(case_state.xpixel-16, case_state.ypixel + 19,case_state.xpixel+16, case_state.ypixel + 61, 0);//�߿�
	bar(case_state.xpixel-15, case_state.ypixel + 20,case_state.xpixel+15, case_state.ypixel + 60, 65535);//��������ġ�����
    circle(case_state.xpixel, case_state.ypixel + 40, 10, 0);   //�����
    Horizline(case_state.xpixel-15, case_state.ypixel+60, 30, 0);
    //��ʱ������ʮ��

}

//�������˵ı��棬�����ʾ�����˵Ľṹ���ṩ�����������λ��
void backbodyhead(CASE case_state)//��Χ��x+30,-30,y-80~y;
{
	robot_hand_right(case_state.xpixel+4,case_state.ypixel+56,45);
	robot_hand_left(case_state.xpixel-28,case_state.ypixel+65,-45);
	ever_Fillellipse(case_state.xpixel-7.5, case_state.ypixel+12, case_state.xpixel+7.5, case_state.ypixel+12, 9, 0);    //�Ȼ����ٸ��ǣ��൱����������
	ever_Fillellipse(case_state.xpixel-7.5, case_state.ypixel+12, case_state.xpixel+7.5, case_state.ypixel+12, 8, 65535);
    putpixel(case_state.xpixel-7.5, case_state.ypixel+12, 0);   //�۾�
    putpixel(case_state.xpixel+7.5, case_state.ypixel+12, 0);

    //��
    bar(case_state.xpixel-15, case_state.ypixel+60, case_state.xpixel+15, case_state.ypixel+75, 65535);
    linever(case_state.xpixel-15, case_state.ypixel+60, case_state.xpixel-15, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+15, case_state.ypixel+60, case_state.xpixel+15, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+70, 30, 0);
    linever(case_state.xpixel, case_state.ypixel+60, case_state.xpixel, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

     //����
	bar(case_state.xpixel-16, case_state.ypixel + 19,case_state.xpixel+16, case_state.ypixel + 61, 0);//�߿�
	bar(case_state.xpixel-15, case_state.ypixel + 20,case_state.xpixel+15, case_state.ypixel + 60, 65535);//��������ġ�����
    Horizline(case_state.xpixel-15, case_state.ypixel+60, 30, 0);
}

//�������˵����棬�����ʾ�����˵Ľṹ���ṩ�����������λ��
void robot_left(CASE case_state)//x-10~x+10,y-80~y
{
    //ͷ
    FillCircle(case_state.xpixel, case_state.ypixel+15,12, 65535);
    FillCircle(case_state.xpixel-4, case_state.ypixel+15, 3, 1023); //�۾�

    ///������ͷҲ���󣬹ʲ������ֻ������֣����õĶ���robot_hand_left����
    //����
    robot_hand_left(case_state.xpixel-20,case_state.ypixel+67,-45+case_state.hand_right);

    //����
    bar(case_state.xpixel-12, case_state.ypixel+20, case_state.xpixel+12, case_state.ypixel+60, 0);
    bar(case_state.xpixel-11, case_state.ypixel+21, case_state.xpixel+11, case_state.ypixel+59, 65535);
    Horizline(case_state.xpixel-5, case_state.ypixel+30, 10, 0);

    //��
    bar(case_state.xpixel-11, case_state.ypixel+59, case_state.xpixel+11, case_state.ypixel+74, 65535);
    linever(case_state.xpixel-12, case_state.ypixel+60, case_state.xpixel-12, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+12, case_state.ypixel+60, case_state.xpixel+12, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+60, 24, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+70, 24, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

    //����
    robot_hand_left(case_state.xpixel-20,case_state.ypixel+71,-45-case_state.hand_right);

}

//�������˵����棬�����ʾ�����˵Ľṹ���ṩ�����������λ��
void robot_right(CASE case_state)//x-10~x+10,y-80~y���ֺ�ͷ������
{
    //ͷ
    FillCircle(case_state.xpixel, case_state.ypixel+15,12, 65535);
    FillCircle(case_state.xpixel+4, case_state.ypixel+15, 3, 1023); //�۾�

    ///�����ң�ͷҲ���ң��ʲ������ֻ������֣����õĶ���robot_hand_right����
    //����
    robot_hand_right(case_state.xpixel-4,case_state.ypixel+58,45-case_state.hand_left);

    //����
    bar(case_state.xpixel-12, case_state.ypixel+20, case_state.xpixel+12, case_state.ypixel+60, 0);
    bar(case_state.xpixel-11, case_state.ypixel+21, case_state.xpixel+11, case_state.ypixel+59, 65535);
    Horizline(case_state.xpixel-5, case_state.ypixel+30, 10, 0);

    //��
    bar(case_state.xpixel-11, case_state.ypixel+59, case_state.xpixel+11, case_state.ypixel+74, 65535);
    linever(case_state.xpixel-12, case_state.ypixel+60, case_state.xpixel-12, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+12, case_state.ypixel+60, case_state.xpixel+12, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+60, 24, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+70, 24, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

    //����
    robot_hand_right(case_state.xpixel-4,case_state.ypixel+62,45+case_state.hand_left);

}

//�������ܣ����������˵��֣�ָ���Ҳ࣬��װ�������������ļ��������е���
//��ڲ�����С���ص㣬��ʾ����ֻ�ֵ�λ�ã�theta�ǿ����ְڶ��ĽǶȣ������Ժ��theta_bar��������
void robot_hand_right(int x,int y,int theta)
{
    ///��Ļ�Ͽ�����ֻ���ڴ���ұߣ�ʵ�����Ǵ�׵�����
    ///�����Ҫ��(0,0)Ū����ֻ�ֵĶ��㣬�õ���(xpixel+10, ypixel+40)
    //colorΪ0����΢��һ�����ص��theta_bar��������һ�����أ��Ȼ���һ�㣬֮�󱻸��ǣ���colorΪ65535���Ǵ�׵���ɫ
    theta_bar(x-1,y-29,(int)(12/sin((double)(theta)/180*PI)),(int)(12/sin((double)(theta)/180*PI)),theta,0);
	theta_bar(x,y-30,(int)(10/sin((double)(theta)/180*PI)),(int)(10/sin((double)(theta)/180*PI)),theta,65535);
	FillCircle(x+(int)(16/tan((double)(theta)/180*PI))+5,y-(int)(24*sin((double)(theta)/180*PI))-2,7,0);
    FillCircle(x+(int)(16/tan((double)(theta)/180*PI))+5,y-(int)(24*sin((double)(theta)/180*PI))-2,6,65535);
}

//�������ܣ����������˵��֣�ָ����࣬��װ�������������ļ��������е���
//��ڲ���ͬrobot_hand_right
void robot_hand_left(int x,int y,int theta)
{
    ///ע������Ҳͬ�����robot_hand_right
    ///��(xpixel,ypixel)=(40,40)����ֻ�֣���Լ��(xpixel-20, ypixel+50),��(20,90)
    theta_bar(x-1,y-29,(int)(12/sin((double)(-1*theta)/180*PI)),(int)(12/sin((double)(-1*theta)/180*PI)),theta,0);
	theta_bar(x,y-30,(int)(10/sin((double)(-1*theta)/180*PI)),(int)(10/sin((double)(-1*theta)/180*PI)),theta,65535);
	FillCircle(x+(int)(16/tan((double)(-1*theta)/180*PI))-13,y-(int)(24*sin((double)(-1*theta)/180*PI))-10,7,0);
    FillCircle(x+(int)(16/tan((double)(-1*theta)/180*PI))-13,y-(int)(24*sin((double)(-1*theta)/180*PI))-10,6,65535);
}

///����ÿ������Ѱ�ߵĺ����У�����Ʒ��λ�ö�����Ҫ����΢���ģ������޷���һ��ͳһ�Ļ���Ʒ�ĺ���ȥ��װ
//�����������ֳ���Ʒ�����ߵ�ͼ�񣬴����ʾ�����˵Ľṹ���ṩ�����������λ��
void right_hold(CASE case_state)    //����ת���������ֲ�������
{
	///����ÿ�������Ĵ����robot_right��ȫһ�£�����Ϊ�˵õ���->��Ʒ->����Ĳ�θУ�
	///�ڻ�����ǰ��������Ʒ����˲���ֱ�ӵ��ú����������ֻ�ܳ����ظ��������

	//ͷ
    FillCircle(case_state.xpixel, case_state.ypixel+15,12, 65535);
    FillCircle(case_state.xpixel+4, case_state.ypixel+15, 3, 1023); //�۾�

    //����
    robot_hand_right(case_state.xpixel-4,case_state.ypixel+58,45+case_state.hand_left);

    //����
    bar(case_state.xpixel-12, case_state.ypixel+20, case_state.xpixel+12, case_state.ypixel+60, 0);
    bar(case_state.xpixel-11, case_state.ypixel+21, case_state.xpixel+11, case_state.ypixel+59, 65535);
    Horizline(case_state.xpixel-5, case_state.ypixel+30, 10, 0);

    //��
    bar(case_state.xpixel-11, case_state.ypixel+59, case_state.xpixel+11, case_state.ypixel+74, 65535);
    linever(case_state.xpixel-12, case_state.ypixel+60, case_state.xpixel-12, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+12, case_state.ypixel+60, case_state.xpixel+12, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+60, 24, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+70, 24, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

    if(case_state.catch_th == WITH_BOTTLE)          //��ˮ��
    {
        water_bottle(case_state.xpixel+16, case_state.ypixel+31);
    }
    else if(case_state.catch_th == WITH_CLOTHES)    //���·�
    {
        clothes(case_state.xpixel+5, case_state.ypixel+31);
    }
    else if(case_state.catch_th == WITH_PLATE)      //�˵���
    {
        plate(case_state.xpixel-10, case_state.ypixel+31);
    }

    //����
    robot_hand_right(case_state.xpixel-4,case_state.ypixel+62,45+case_state.hand_left);

}

//�����������ֳ���Ʒ�����ߵ�ͼ�񣬴����ʾ�����˵Ľṹ���ṩ�����������λ��
void left_hold(CASE case_state)//�����ö�����ͼ��
{
    //����
    robot_hand_left(case_state.xpixel-20,case_state.ypixel+67,-45-case_state.hand_right);

    if(case_state.catch_th == WITH_BOTTLE)              //��ˮ��
    {
        water_bottle(case_state.xpixel-25, case_state.ypixel+28);
    }
    else if(case_state.catch_th == WITH_CLOTHES)        //���·�
    {
        clothes(case_state.xpixel-20, case_state.ypixel+28);
    }
    else if(case_state.catch_th == WITH_PLATE)          //�˵���
    {
        plate(case_state.xpixel-20, case_state.ypixel+32);
    }

    //ͷ
    FillCircle(case_state.xpixel, case_state.ypixel+15,12, 65535);
    FillCircle(case_state.xpixel-4, case_state.ypixel+15, 3, 1023); //�۾�

    //����
    bar(case_state.xpixel-12, case_state.ypixel+20, case_state.xpixel+12, case_state.ypixel+60, 0);
    bar(case_state.xpixel-11, case_state.ypixel+21, case_state.xpixel+11, case_state.ypixel+59, 65535);
    Horizline(case_state.xpixel-5, case_state.ypixel+30, 10, 0);

    //��
    bar(case_state.xpixel-11, case_state.ypixel+59, case_state.xpixel+11, case_state.ypixel+74, 65535);
    linever(case_state.xpixel-12, case_state.ypixel+60, case_state.xpixel-12, case_state.ypixel+75, 1, 0);
    linever(case_state.xpixel+12, case_state.ypixel+60, case_state.xpixel+12, case_state.ypixel+75, 1, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+60, 24, 0);
    Horizline(case_state.xpixel-12, case_state.ypixel+70, 24, 0);
    Horizline(case_state.xpixel-15, case_state.ypixel+75, 30, 0);

    //����
    robot_hand_left(case_state.xpixel-20,case_state.ypixel+71,-45-case_state.hand_right);

}

//�����������ֳ���Ʒ�����ߵ�ͼ�����棩�������ʾ�����˵Ľṹ���ṩ�����������λ��
void front_hold(CASE case_state)
{
    //ˮ��ֱ������ȥ�������ڻ����˵�����ͺ��ˡ�ע�����Ȼ������ˣ��ٻ���Ʒ��ע���θС�
    forebodyhead(case_state);
    if(case_state.catch_th == WITH_BOTTLE)
    {
        water_bottle(case_state.xpixel-30, case_state.ypixel+23);
    }
    else if(case_state.catch_th == WITH_CLOTHES)
    {
        clothes(case_state.xpixel-20, case_state.ypixel+27);
    }
    else if(case_state.catch_th == WITH_PLATE)
    {
        plate(case_state.xpixel-20, case_state.ypixel+29);
    }
}

//�����������ֳ���Ʒ�����ߵ�ͼ�񣨱��棩�������ʾ�����˵Ľṹ���ṩ�����������λ��
void back_hold(CASE case_state)
{
    //ע�����Ȼ���Ʒ���ٻ������ˣ�ע���θС�
    if(case_state.catch_th == WITH_BOTTLE)
    {
        water_bottle(case_state.xpixel+20, case_state.ypixel+23);
    }
    else if(case_state.catch_th == WITH_CLOTHES)
    {
        clothes(case_state.xpixel+10, case_state.ypixel+27);
    }
    else if(case_state.catch_th == WITH_PLATE)
    {
        plate(case_state.xpixel+10, case_state.ypixel+27);
    }
    backbodyhead(case_state);
}

