#include "title.h"
//���ܣ����˻ؼҺ���
//���룺�����˽ṹ��ָ�룬�˽ṹ��ָ�룬���ָ�룬����ѡ�������ָ�룬ͼ
//�������
void come_home(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n)
{
    paint_man(*man, MASTER);																	//���ˣ��˵Ĳ����Ѿ��������̺�����д��
	aimmove(robot,robot->x,robot->y,4,4,G,n,ROBOT);												//�û����˵�4��4ȥӭ������


	saveimage_chat(robot->x*40+40,robot->y*40);													//��������ı����Ĵ洢
	saveimage_choose(robot->x*40+40,robot->y*40+40*2);											//ѡ������ı����Ĵ洢

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  	//����׿�
	show_reply("��ӭ�ؼң�����",robot);

	delay(500);

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
	show_reply("��������Դ��˻��������أ�",robot);

	bar_round_2(robot->x*40+40,robot->y*40+2*40,robot->x*40+40+118,robot->y*40+3*40,5,1,65535);  //ѡ��׿�
	fdhz(robot->x*40+40+40,robot->y*40+2*40+12,1,1,"����",0);

	bar_round_2(robot->x*40+40+122,robot->y*40+2*40,robot->x*40+40+240,robot->y*40+3*40,5,1,65535);  //ѡ��׿�
	fdhz(robot->x*40+40+120+40,robot->y*40+2*40+12,1,1,"����",0);

	while (1)
    {
        newxy(mx,my,button);
        if (*mx>=robot->x*40+40 && *mx<=robot->x*40+40+120 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)  //ѡ�񴨲�
        {
            choice[1]=1;
            break;
        }
        if (*mx>=robot->x*40+40+120 && *mx<=robot->x*40+40+240 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)  //ѡ������
        {
            choice[1]=2;
            break;
        }
    }

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
	show_reply("�õģ��һ��ס����ѡ��",robot);

	putsave_chat(robot->x*40+40,robot->y*40);  //�ָ������ı���ı���
	putsave_choose(robot->x*40+40,robot->y*40+40*2);  //ѡ�����ʧ
	delay(300);

	entertain_and_work(robot,man,mx,my,button,choice,G, n);							//���빤�����ֺ�������ģ��
    delay0(200);
    aimmove(robot,robot->x,robot->y,10,2,G,n,ROBOT);
	saveimage_doing(robot->x*40-40,robot->y*40-35);									//����״̬�򱳺��ͼ��Ĵ洢

    bar(robot->x*40-40,robot->y*40-35,robot->x*40+40,robot->y*40-5,65535);           //����״̬�׿�
    fdhz(robot->x*40-30,robot->y*40-30,1,1,"������",0);
}

//���ܣ���ͺ���
//���룺�����˽ṹ��ָ�룬�˽ṹ��ָ�룬���ָ�룬����ѡ�������ָ�룬ͼ
//�������
void dinner(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n)
{
    int t;											//��������������ж�����������
    char *s=NULL;									//����ָ��������ַ�������ַ�ָ��
    srand((unsigned int)time(0));
    t=rand()%4;										//��t�����ֵ

    putsave_doing(robot->x*40-40,robot->y*40-35);  //ȥ���������С���״̬

	robot->catch_th = WITH_PLATE;					//�����˵�״̬��Ϊ��������
    aimmove(robot,robot->x,robot->y,11,6,G,n,ROBOT);//�������ߵ�������
	robot->catch_th = WITHOUT_THING;				//�����˽����ӷŵ�����
    plate(12*40,8*40+20);


    //***********�����ǻ�ԭ�˹�������Ϣʱ�Ҿߵ�״̬

    if(choice[0]==1) 			 //������������Ϣ
    {
        if(choice[2]==1) 		//������ѡ���˿�����
        {
            TV_off();   		//�ص����ӻ�
            delay(200);
        }
        else if(choice[2]==2)	//������ѡ����������
        {
            music_off(8,10);
            music_off(9,10);	//ȥ�����ֵ�����
            delay(200);
        }

		//**********����Ϊ�Է������ӻָ�ԭ�������ڳԷ������ӻָ�ԭ��ʹ��
        wood_ver(14, 12);
        wood_ver(14, 13);
        wood_ver(15, 12);
        wood_ver(15, 13);
		wood_ver(14, 14);
		wood_ver(15, 14);
        sofa_main(14, 11);
		man->xpixel=man->x*40;  //�˵�λ�ûָ���������֮ǰ��λ��
        man->ypixel=man->y*40;
        man_forebody(*man,1);	//���˵�����
		//***********
    }
    else if(choice[0]==2)  //������ȥ����
    {
		//*******************  �����ǹ��������ӻָ�ԭ�������ڹ��������ӻָ�ԭ��ʹ��
        green_bedroom(0, 14);
        green_bedroom(0, 15);
        green_bedroom(0, 16);
        green_bedroom(1, 14);
        green_bedroom(1, 15);
        green_bedroom(1, 16);
        rect_table(0, 13);
        desk(0, 15);
        seat(0, 16);
        pc(0, 15);
		man->xpixel=man->x*40;
        man->ypixel=man->y*40;
        man_forebody(*man,1);
		//***********************************
    }

    aimmove(man,man->x,man->y,9,10,G,n,MAN);    //�˵�������



    put_image_man(man->xpixel,man->ypixel);     //���˸�ס
    man->xpixel=500;
    man->ypixel=315;							//����������ʱ������
    sit_1(*man);								//����������ǰ

    if (choice[1]==1)							//���ѡ����Ǵ��ˣ���������һ������
    {
        if(t==0)
        {
            s="���Ŷ���";
        }
        else if (t==1)
        {
            s="������˿";
        }
        else if (t==2)
        {
            s="ð��";
        }
        else if (t==3)
        {
            s="��������";
        }
    }
    else if (choice[1]==2)						//���ѡ����Ǵ��ˣ���������һ������
    {
        if(t==0)
        {
            s="��֭����";
        }
        else if (t==1)
        {
            s="��Ƥ����";
        }
        else if (t==2)
        {
            s="�������";
        }
        else if (t==3)
        {
            s="�����h��Ϻ";
        }
    }
	saveimage_chat(robot->x*40+40,robot->y*40);  //��������ı����Ĵ洢

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
	fdhz(robot->x*40+40+10,robot->y*40+20,1,1,"������",0);
	fdhz(robot->x*40+40+10,robot->y*40+40,1,1,s,0);
	fdhz(robot->x*40+40+10,robot->y*40+60,1,1,"������",0);

	getch();									//��Ҫ��һ�¼�
    putsave_chat(robot->x*40+40,robot->y*40);	//������򱳺�ı����ų���

    //*********************
    //�����������ӣ���ʾ���ڳԷ���
    //*************
    saveimage_doing(man->x*40-40,man->y*40-35);	//����˵Ķ���״̬�����ı���

    bar(man->x*40-40,man->y*40-35,man->x*40+40,man->y*40-5,65535);           //�Է�
    fdhz(man->x*40-20,man->y*40-30,1,1,"�Է���",0);
    getch();

    putsave_doing(man->x*40-40,man->y*40-35);		//����״̬����put��

    entertain_and_work(robot,man,mx,my,button,choice,G, n);  //���빤�����ֺ�������ģ��

}

//���ܣ����ֹ�������
//���룺�����˽ṹ��ָ�룬�˽ṹ��ָ�룬���ָ�룬����ѡ�������ָ�룬ͼ
//�������
void entertain_and_work(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n)
{

	saveimage_chat(robot->x*40+40,robot->y*40);  //��������ı����Ĵ洢
	saveimage_choose(robot->x*40+40,robot->y*40+40*2);  //ѡ������ı����Ĵ洢

	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  	//����׿�
    show_reply("��������ѡ�����ֻ��ǹ����أ�",robot);
	bar_round_2(robot->x*40+40,robot->y*40+2*40,robot->x*40+40+118,robot->y*40+3*40,5,1,65535);  //ѡ��
	fdhz(robot->x*40+40+40,robot->y*40+2*40+12,1,1,"����",0);

	bar_round_2(robot->x*40+40+122,robot->y*40+2*40,robot->x*40+40+240,robot->y*40+3*40,5,1,65535);  //ѡ��
	fdhz(robot->x*40+40+120+40,robot->y*40+2*40+12,1,1,"����",0);

    while (1)
    {
        newxy(mx,my,button);
        if (*mx>=robot->x*40+40 && *mx<=robot->x*40+40+120 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)   		//ѡ������
        {
            choice[0]=1;
            break;
        }
        if (*mx>=robot->x*40+40+120 && *mx<=robot->x*40+40+240 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)    //ѡ����
        {
            choice[0]=2;
            break;
        }
    }

    putsave_choose(robot->x*40+40,robot->y*40+40*2);  //ѡ�����ʧ
	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
	fdhz(robot->x*40+40+20,robot->y*40+20,1,1,"�õ�",0);

	delay(200);


	if(choice[0]==1)  //����
    {
        bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
        show_reply("��Ҫ����������",robot);

        bar_round_2(robot->x*40+40,robot->y*40+2*40,robot->x*40+40+118,robot->y*40+3*40,5,1,65535);  //ѡ��
        fdhz(robot->x*40+40+40,robot->y*40+2*40+12,1,1,"������",0);

        bar_round_2(robot->x*40+40+122,robot->y*40+2*40,robot->x*40+40+240,robot->y*40+3*40,5,1,65535);  //ѡ��
        fdhz(robot->x*40+40+120+40,robot->y*40+2*40+12,1,1,"������",0);

        while (1)
        {
            newxy(mx,my,button);
            if (*mx>=robot->x*40+40 && *mx<=robot->x*40+40+120 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)  	//ѡ�񿴵���
            {
                choice[2]=1;
                break;
            }
            if (*mx>=robot->x*40+40+120 && *mx<=robot->x*40+40+240 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)	//ѡ��������
            {
                choice[2]=2;
                break;
            }
        }

        putsave_choose(robot->x*40+40,robot->y*40+40*2);  //ѡ�����ʧ
        bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
        fdhz(robot->x*40+40+20,robot->y*40+20,1,1,"�õ�",0);

        delay(200);

        putsave_chat(robot->x*40+40,robot->y*40);  //�ָ������ı���ı���

		//*********����Ϊ�������Է������ӻָ�ԭ״

        wood_ver(12, 7);
        wood_ver(12, 8);
        wood_ver(12, 9);
        desk(12, 8);
        seat(12, 9);
		seat(12, 7);
		man->xpixel=man->x*40;
        man->ypixel=man->y*40;
        man_forebody(*man,1);         //�Է������ӻָ�ԭ״

        //****************
        aimmove(man,man->x,man->y,14,15,G,n,MAN);
        //*************��һ����������ɳ���ϵ�ͼ��

        put_image_man(man->x*40,man->y*40);
        man->xpixel=580;
        man->ypixel=500;
        sit_2(*man);
		//*********************

        if(choice[2]==1)    //����ѡ���˿�����
        {
            TV_on();		//�򿪵��ӻ�

        }
        else if (choice[2]==2) //������ѡ����������
        {

            music_on(8,10);
            music_on(9,10);  		//������������
        }
    }
    else if (choice[0]==2)			//������ȥ����
    {
		delay(200);

        putsave_chat(robot->x*40+40,robot->y*40);  //�ָ������ı���ı���

		//************����Ϊ�������Է������ӻָ�ԭ״
		wood_ver(12, 7);
        wood_ver(12, 8);
        wood_ver(12, 9);
        desk(12, 8);
        seat(12, 9);
		seat(12, 7);
		man->xpixel=man->x*40;
        man->ypixel=man->y*40;
        man_forebody(*man,1);         //�Է������ӻָ�ԭ״
		//***********************
		aimmove(man,man->x,man->y,2,15,G,n,MAN);	//��ǰ��������ǰ
        //**************��������������ǰ������ͼ��

        put_image_man(man->x*40,man->y*40);
        man->xpixel=20;
        man->ypixel=600;
        sit_1(*man);
		//**********************

        aimmove(robot,robot->x,robot->y,14,2,G,n,ROBOT);//������ȥ��ˮ

        saveimage_doing(robot->x*40-40,robot->y*40-35); //�����˶���״̬�򱳾��洢

        bar(robot->x*40-40,robot->y*40-35,robot->x*40+40,robot->y*40-5,65535);           //��ˮ
        fdhz(robot->x*40-30,robot->y*40-30,1,1,"��ˮ��",0);
        delay(500);

        putsave_doing(robot->x*40-40,robot->y*40-35); 	//����״̬��ָ�
		robot->catch_th = WITH_BOTTLE;          //  ��������˵�������ˮ��

        aimmove(robot,robot->x,robot->y,3,14,G,n,ROBOT);  //���е�Ŀ�����ͱ�ˮ��ȥ
		robot->catch_th = WITHOUT_THING;

        water_bottle(50,605);//��ˮ����������
        aimmove(robot,robot->x,robot->y,13,2,G,n,ROBOT);  //�ص�Ĭ��λ�ô�
        delay0(50);
    }
}

//���ܣ�ϴ�躯��
//���룺�����˽ṹ��ָ�룬�˽ṹ��ָ�룬���ָ�룬����ѡ�������ָ�룬ͼ
//�������
void bath(CASE *robot, CASE *man, int *mx, int *my, int *button, int choice[],VType G[], int n)
{
	if (choice[0]==1)	//����ѡ����ԡ
	{
		aimmove(robot,robot->x,robot->y,13,16,G,n,ROBOT);    //�����˻ص�Ĭ��λ��
	}
	if (choice[0]==2)	//����ѡ������
	{
		aimmove(robot,robot->x,robot->y,3,15,G,n,ROBOT);    //������ǰ��������ˮ
	}

	saveimage_chat(robot->x*40+40,robot->y*40);  //��������ı����Ĵ洢
	saveimage_choose(robot->x*40+40,robot->y*40+40*2);  //ѡ������ı����Ĵ洢


	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
    show_reply("��������ѡ����ԡ�������裿",robot);


	bar_round_2(robot->x*40+40,robot->y*40+2*40,robot->x*40+40+118,robot->y*40+3*40,5,1,65535);  //ѡ��
	fdhz(robot->x*40+40+40,robot->y*40+2*40+12,1,1,"��ԡ",0);

	bar_round_2(robot->x*40+40+122,robot->y*40+2*40,robot->x*40+40+240,robot->y*40+3*40,5,1,65535);  //ѡ��
	fdhz(robot->x*40+40+120+40,robot->y*40+2*40+12,1,1,"����",0);

    while (1)
    {
        newxy(mx,my,button);
        if (*mx>=robot->x*40+40 && *mx<=robot->x*40+40+120 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button) 	//ѡ����ԡ
        {
            choice[3]=1;
            break;
        }
        if (*mx>=robot->x*40+40+120 && *mx<=robot->x*40+40+240 && *my>=robot->y*40+2*40 && *my<=robot->y*40+3*40 && *button)	//ѡ������
        {
            choice[3]=2;
            break;
        }
    }

    putsave_choose(robot->x*40+40,robot->y*40+40*2);  //ѡ�����ʧ
	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
	fdhz(robot->x*40+40+20,robot->y*40+20,1,1,"�õ�",0);

	delay(200);

	if(choice[3]==2)
    {
        bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+40+40*6,robot->y*40+2*40, 7,2,65535);  //����׿�
        show_reply("����Ϊ��׼����ˮ",robot);

        delay(1000);
        putsave_chat(robot->x*40+40,robot->y*40);  //�ָ������ı���ı���

        aimmove(robot,robot->x,robot->y,2,3,G,n,ROBOT);//�����˵�ԡ���Ա�

        saveimage_doing(robot->x*40-40,robot->y*40+82);
        bar(robot->x*40-40,robot->y*40+82,robot->x*40+40,robot->y*40+112,65535);           //׼����ˮ
        fdhz(robot->x*40-30,robot->y*40+85,1,1,"��ˮ��",0);
        delay(1000);
        putsave_doing(robot->x*40-40,robot->y*40+82);
    }
	else
    {
        putsave_chat(robot->x*40+40,robot->y*40);  //�ָ������ı���ı���
    }
        aimmove(robot,robot->x,robot->y,13,3,G,n,ROBOT);  //�ص�Ĭ��λ�ô�

    //*********����Ϊ�������Է������ӻָ�ԭ״ �� ����Ϊ���������������ӻָ�ԭ״
	if(choice[0]==2)   //������ѡ���˹���
	{
		green_bedroom(0, 14);
		green_bedroom(0, 15);
		green_bedroom(0, 16);
		green_bedroom(1, 14);
		green_bedroom(1, 15);
		green_bedroom(1, 16);
		rect_table(0, 13);
		desk(0, 15);
		seat(0, 16);
		pc(0, 15);
		man->x=2;
		man->y=15;
		man->xpixel=2*40;
		man->ypixel=15*40;
		man_forebody(*man,1);
	}
	else if(choice[0]==1) //������ѡ��������
	{
		if(choice[2]==1)  //������ѡ���˿�����
        {
            TV_off();
            delay(200);
        }
        else if(choice[2]==2)//������ѡ����������
        {
            music_off(8,10);
            music_off(9,10);
            delay(200);
        }
        wood_ver(14, 12);
        wood_ver(14, 13);
        wood_ver(15, 12);
        wood_ver(15, 13);
		wood_ver(14, 14);
		wood_ver(15, 14);
        sofa_main(14, 11);
		man->x=14;
		man->y=15;
		man->xpixel=14*40;
		man->ypixel=15*40;
		man_forebody(*man,1);
	}
	//*******************
    aimmove(man,man->x,man->y,1,3,G,n,MAN);  //��ȥϴ��

    put_image_man(man->x*40,man->y*40);
	get_image_bath(40, 40);    				//ϴ��ĵذ�ı����洢
    bar(40,40,120,120,65535);
    fdhz(45,45,1,1,"ϴ����",0);				//���˸�ס

    aimmove(robot,robot->x,robot->y,5,11,G,n,ROBOT);	//������ȥ���·�
    delay(500);
    delay(500);
	robot->catch_th = WITH_CLOTHES;						//��ʱ�������˵�״̬����Ϊ�����·�
    aimmove(robot,robot->x,robot->y,3,4,G,n,ROBOT);     //������ǰ���������·�
	robot->catch_th = WITHOUT_THING;					//��ʱ�������˵�״̬����Ϊû���·�


    //***********
    //���·��������������

	clothes(1*40,4*40);

    aimmove(robot,robot->x,robot->y,3,11,G,n,ROBOT);  //ȥ���յ�
    delay(500);
    //    �յ���Ʊ��̵�
    aircon(3, 6, 1);
    delay(500);
    aimmove(robot,robot->x,robot->y,13,3,G,n,ROBOT);  //�ص�Ĭ��λ�ô�

    //*****���»���ԡ�׺͵ذ����
    put_image_bath(40,40);
    glass(1, 4);
    man_forebody(*man,1);
	
	//******************************
    delay(500);
    aimmove(man,man->x,man->y,3,10,G,n,MAN);  		//���ߵ����Ա�

	man_sleep(*man);								//����˯����ͼ
}

//���ܣ���ͺ���
//���룺�����˽ṹ��ָ�룬�˽ṹ��ָ�룬���ָ�룬����ѡ�������ָ�룬ͼ
//�������
void breakfast(CASE *robot, CASE *man, VType G[], int n)
{
    aimmove(robot,robot->x,robot->y,10,2,G,n,ROBOT);	//�����˵���̨�Ա�
    saveimage_doing(robot->x*40-40,robot->y*40+82);
    bar(robot->x*40-40,robot->y*40+82,robot->x*40+40,robot->y*40+112,65535);           //׼�����
    fdhz(robot->x*40-30,robot->y*40+85,1,1,"������",0);
	getch();
    putsave_doing(robot->x*40-40,robot->y*40+82);

	robot->catch_th = WITH_PLATE;
    aimmove(robot,robot->x,robot->y,11,6,G,n,ROBOT);    // ��ʱ������������
	robot->catch_th = WITHOUT_THING;
    aimmove(robot,robot->x,robot->y,13,3,G,n,ROBOT);     //��ʱ����û������

    //�����ӷ�������
	plate(12*40,8*40+20);

    //���»�һ�鴲�������ˣ����������Ա߰��˻���
	man_getup(*man);

    //ȥϴ��
     aimmove(man,man->x,man->y,1,4,G,n,MAN);  //�˵�����
	put_image_man(man->x*40,man->y*40);      //���˻�û
	man_leftbody(*man);						//�˲���վ
	saveimage_doing(man->x*40+40,man->y*40+82);
	bar(man->x*40+40,man->y*40+82,man->x*40+120,man->y*40+112,65535);           //xi shu
    fdhz(man->x*40+50,man->y*40+85,1,1,"ϴ����",0);
	getch();
	putsave_doing(man->x*40+40,man->y*40+82);

    aimmove(man,man->x,man->y,10,8,G,n,MAN);  		//�˵�������

    //��һ�εذ壬���˻�û���ٻ�һ�����˳Է�������
    put_image_man(man->x*40,man->y*40);
    man->xpixel=500;
    man->ypixel=370-60;
    sit_1(*man);
	saveimage_doing(man->xpixel-40,man->ypixel+82);
    bar(man->xpixel-40,man->ypixel+82,man->xpixel+40,man->ypixel+112,65535);           //�Է�
    fdhz(man->xpixel-30,man->ypixel+85,1,1,"�Է���",0);
    getch();
	putsave_doing(man->xpixel-40,man->ypixel+82);

    //���˻��������ٻ�һ���յ�����
    	wood_ver(12, 7);
        wood_ver(12, 8);
        wood_ver(12, 9);
        desk(12, 8);
        seat(12, 9);
	seat(12, 7);
	man->xpixel=man->x*40;
	man->ypixel=man->y*40;
    man_forebody(*man,1);         //�Է������ӻָ�ԭ״

    aimmove(robot,robot->x,robot->y,10,2,G,n,ROBOT);
    saveimage_doing(robot->x*40-40,robot->y*40+82);
	bar(robot->x*40-40,robot->y*40+82,robot->x*40+40,robot->y*40+112,65535);           //ϴ��
    fdhz(robot->x*40-30,robot->y*40+85,1,1,"ϴ����",0);
	getch();
	putsave_doing(robot->x*40-40,robot->y*40+82);

	man_forebody(*man,1);
	aimmove(man,man->x,man->y,4,1,G,n,MAN);
	put_image_man(man->x*40,man->y*40);			//���˻�û���������

	aimmove(robot,robot->x,robot->y,13,3,G,n,ROBOT);  //�ص�Ĭ��λ�ô�
}
