/********************************
ϵͳ�����̣����ø��ֹ���
void mainprocess(int *x,int *y);
********************************/
#include "title.h"
void mainprocess(int *x,int *y, int *pbutton)
{
	int button=*pbutton;    //��갴��
	int click=0;            //�ֶ�ָ��ģ��ѡ���жϱ���
	int i;
	int judge=0;            //ʱ����ģ��ѡ���жϱ���
	int temp;				//���ڴ洢�������롣����esc�ĵ��

	int air_t=24;			//�յ��¶ȳ�ʼ��
	int bath_t=38;			//ϴ��ˮ�³�ʼ��

	int n;
	VType G[166];           //���ڼ��㷢�֣�ֻ�в���166�������

	int time=15*60;			//ʱ���ʼ��
	int hour;
	int minute;
	char s_hour[3];			//Сʱ���ַ�������
	char s_minute[3];		//���ӵ��ַ�������
	int times=-1;  			//�¼���ʲô
	int wht_happen=0;		//�¼��Ƿ���        *********���ã���ʱ�����ϵĺ���ִ�й�һ��֮����������ͱ��1����ѭ���оͲ������޵��øú���
	int wht_happen2=0;		//�¼��Ƿ���        *********���ã����ֶ�ָ���ϵĺ���ִ�й�һ��֮����������ͱ��1����ѭ���оͲ������޵��øú���

    int choice[5]={0};		//ѡ�����鶨�弰���ʼ��

	CASE robot,man;  		//�˺ͻ����˵ı����ĳ�ʼ��

	BUTTONS esc1;			//�˳���ť
	esc_init(&esc1);		//�˳���ť��ʼ��
	mouseInit(x, y,&button);//����ʼ��

	n = CreateGraph(G);    //��ͼ


    //��ʼ��������λ�÷�����֫״̬
	robot.x = 13;
	robot.y = 3;
	robot.direction = 4;

	robot.hand = 0;
	robot.hand_left = 0;
	robot.hand_right = 0;
	robot.xpixel=robot.x*40;
	robot.ypixel=robot.y*40;



	//��ʼ����λ�÷�����֫״̬
	man.x = 4;
	man.y = 1;
	man.direction = 4;
	man.hand = 0;
	man.hand_left = 0;
	man.hand_right = 0;
	man.xpixel=man.x*40;
	man.ypixel=man.y*40;

    //���Ƶ�ͼ���ֻ�������
	mousehide(*x,*y);
	paint_house();							//������
	iph_page_1();							//�ֻ�������
	time_page();							//ʱ�侲̬����
	hour=time/60;							//Сʱ
	minute=time%60;							//����
	itoa(hour,s_hour,10);					//Сʱ����Ϣ�����ַ�������
	itoa(minute,s_minute,10);				//���ӵ���Ϣ�����ַ�������
	minute_adjust(s_minute);				//����ȫ����Ϊ2λ��
	outtextxy(810,615,s_hour,3,3,20,0);
	outtextxy(874,607,":",3,3,0,0);
	outtextxy(920,615,s_minute,3,3,20,0);	    //ʱ�侲̬����

	paint_robot(robot);						//��������

	//�������
	reset_mouse(x,y);

	while(1)
	{

		newxy(x,y,&button);					//ˢ�����λ�ú�״̬

		//����Ƿ����˳���ť
		judge = esc_check(&esc1,x,y,&button);
		
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		/*��esc���˳�*/
		if(temp == 0x11b)
		{
			exit(0);
		}



		if (*x>=ORIGINX && *x <=FINALX&& *y>=ORIGINY+54 && *y <=ORIGINY+209&& button)    //�ֶ�ָ�ť
        {
            click=1;
			wht_happen2=0;
        }

        if (*x>=ORIGINX && *x <=FINALX&& *y>=ORIGINY+209 && *y <=ORIGINY+363&& button)   //���찴ť
        {
            click=2;
			wht_happen2=0;
        }
        if (*x>=ORIGINX && *x <=FINALX&& *y>=ORIGINY+363 && *y <=ORIGINY+515&& button)   //Ĭ�������޸İ�ť
        {
            click=3;
			wht_happen2=0;
        }
        if (*x>=0 && *x <=20&& *y>=0 && *y <=20&& button)                                //�˳���ť
        {
            click=4;
        }
        if (*x>=764 && *x <=1020&& *y>=690 && *y <=764&& button)
        {
			time_adjust_plus(&time, &times, &wht_happen);	//ʱ�����¼�����
            hour=time/60;
            minute=time%60;
            itoa(hour,s_hour,10);
            itoa(minute,s_minute,10);
			minute_adjust(s_minute);

            bar(794,597,990,665,65535);//ʱ����ʾ��
            outtextxy(810,615,s_hour,3,3,20,0);
			outtextxy(874,607,":",3,3,0,0);
			outtextxy(920,615,s_minute,3,3,20,0);
        }



        if (wht_happen==0 && times==0)
        {
            rbtguard(man, robot, INTRADER, x, y, &button); 			//��������ʵ��
            wht_happen=1;
        }
        if (wht_happen==0 && times==1)
        {
			iph_page_1();
            come_home(&robot, &man, x, y, &button, choice,G, n);	//�ؼҺ���ʵ��
            wht_happen=1;
        }
        if (wht_happen==0 && times==2)
        {
            dinner(&robot, &man, x, y, &button, choice,G, n);		//������ʵ��
            wht_happen=1;
        }
        if (wht_happen==0 && times==3)
        {
            bath(&robot, &man, x, y, &button, choice,G, n);			//ϴ�蹦��ʵ��
            wht_happen=1;
        }
        if (wht_happen==0 && times==4)
        {
            treatment(&man, &robot, G, n, x, y, &button, choice);			//������Ԯ����ʵ��
            wht_happen=1;
        }
        if (wht_happen==0 && times==5  && choice[4]==0)  			//choice[4]==0��ʾû��ȥҽԺ
        {
            breakfast(&robot, &man, G, n);			//��͹���ʵ��
			wht_happen=1;
        }
		if (times==6)
		{
			good_bye();												//��������
		}


		if (wht_happen2==0)
		{
			switch(click)
			{
				case 0:
				{
					break;
				}
				//�ֶ�ָ��
				case 1:
				{
					sdzl_main(x,y,&button,&robot,&man, G, n, times, choice[4]);  	 //�����ֶ�ָ��ܺ���
					iph_page_1();							  	 //�˳��ֶ�ָ���������
					wht_happen2=1;							  	 //�Ѿ�����һ�飬����һֱѭ��
					break;
				}
				//���칦��
				case 2:
				{
					chatmain(&robot);							//�����������
					//click=0;
					iph_page_1();								//�˳������������
					wht_happen2=1;								//�Ѿ�����һ�飬����һֱѭ��
					break;
				}
				//Ĭ�������޸�
				case 3:
				{
					set_change(&air_t, &bath_t);				//����Ĭ�������޸Ľ���
					//click=0;
					iph_page_1();								//�˳�Ĭ�������޸ĺ�������
					wht_happen2=1;								//�Ѿ�����һ�飬����һֱѭ��
					break;
				}
			}
		}
		//������˳�ϵͳ��������ѭ��
		if(judge==4)
		{
			break;
		}
    }

}

//���ܣ���һλ���ֵķ�����������2λ����
void minute_adjust(char *s_minute)
{
	if(strcmp(s_minute,"0")==0)
		strcpy(s_minute,"00");
	if(strcmp(s_minute,"1")==0)
		strcpy(s_minute,"01");
	if(strcmp(s_minute,"2")==0)
		strcpy(s_minute,"02");
	if(strcmp(s_minute,"3")==0)
		strcpy(s_minute,"03");
	if(strcmp(s_minute,"4")==0)
		strcpy(s_minute,"04");
	if(strcmp(s_minute,"5")==0)
		strcpy(s_minute,"05");
	if(strcmp(s_minute,"6")==0)
		strcpy(s_minute,"06");
	if(strcmp(s_minute,"7")==0)
		strcpy(s_minute,"07");
	if(strcmp(s_minute,"8")==0)
		strcpy(s_minute,"08");
	if(strcmp(s_minute,"9")==0)
		strcpy(s_minute,"09");
}

//���ܣ������¼�������ʱ��
void time_adjust_plus(int *time, int *times, int *wht_happen)
{
	(*times)++;
	*wht_happen=0;
	if (*times==0)				//���¼�Ϊ0����˵����16�㣬������Ӧʱ��
	{
		*time=60*16;
	}
	if (*times==1)				//���¼�Ϊ1����˵����18�㣬������Ӧʱ��
	{
		*time=60*18;
	}
	if (*times==2)				//���¼�Ϊ2����˵����18��룬������Ӧʱ��
	{
		*time=60*18+30;
	}
	if (*times==3)				//���¼�Ϊ3����˵����21�㣬������Ӧʱ��
	{
		*time=60*21;
	}
	if (*times==4)				//���¼�Ϊ4����˵����1�㣬������Ӧʱ��
	{
		*time=1*60;
	}
	if (*times==5)				//���¼�Ϊ5����˵����6�㣬������Ӧʱ��
	{
		*time=6*60;
	}
}
