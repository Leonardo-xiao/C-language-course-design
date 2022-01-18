/******************�����嵥***************************
1.  void show_order(int *qhwh,int *y);
2.	void get_str(int *qhwh, char *incode);
3.	void reply_match(char * str,char *order,char *reply);
4.	void show_reply(char *incode, int * y);
5.	void show_main(int *qhwh);
*****************************************************/
#include "title.h"



/**************

	��ӡ����

**************/
void show_order(int *qhwh,int *y)
{
	int num_qhwh;	//�ַ���
	int num_line;	//���ӡ������
	int box_top;	//���������

	Area order_box;
	Coordinate order_begin;

	/***************
	����м����ֲ����Ի����
	***************/
	num_qhwh = CheckQhwhNum(qhwh);	//�õ��ַ���
	num_line = num_qhwh/10+1;		//ȷ�ϴ�ӡ����
	box_top = 345-20*num_line;		//ȷ�϶Ի�������

	if(num_qhwh<=10)
	{
		bar_round_2(ORIGINX+239-num_qhwh*16-4,ORIGINY+box_top,ORIGINX+242,ORIGINY+345,5,1,65535);   //��ӡ�Ի���
	}
	else
	{
		bar_round_2(ORIGINX+239-10*16-4,ORIGINY+box_top,ORIGINX+242,ORIGINY+345,5,1,65535);
	}

	/***************
	��ӡ���ֲ���ӡ�û�����
	***************/
	if(num_qhwh<=10)
	{
		order_box.lt.x = ORIGINX+239-num_qhwh*16-4;
		order_box.lt.y = ORIGINY+box_top;
		order_box.rb.x = ORIGINX+243;
		order_box.rb.y = ORIGINY+345;
		order_begin.x = ORIGINX+239-num_qhwh*16;
		order_begin.y = ORIGINY+box_top+2;

		ShowTxt(qhwh, order_box, &order_begin,16);
	}
	else{
		order_box.lt.x = ORIGINX+239-10*16-4;
		order_box.lt.y = ORIGINY+box_top;
		order_box.rb.x = ORIGINX+243;
		order_box.rb.y = ORIGINY+345;
		order_begin.x = ORIGINX+239-10*16;
		order_begin.y = ORIGINY+box_top+2;

		ShowTxt(qhwh, order_box, &order_begin,16);
	}

	fdhz(ORIGINX+243-16*2,ORIGINY+box_top-20,1,1,"��",65535);
	fdhz(ORIGINX+243-16*1,ORIGINY+box_top-20,1,1,"��",65535);

	/*************
	�ı�ظ������ռλ��¼ֵ
	*************/
	//*y = ORIGINY+box_top-25;
	*y = ORIGINY+50+20*num_line+25;
}

/**************

	�����õ��û�������ַ���

**************/
void get_str(int *qhwh, char *incode)
{
	char *p=incode;	//incode��λ��ָ��
	int num_qhwh = CheckQhwhNum(qhwh);
	int i;

	for(i=0;i<num_qhwh;i++)
	{
		qhwh2incode(*qhwh,p);
		p+=2;
		qhwh++;
	}
	*p = 0;
	*(p+1)=0;
}


void reply_match(char * str,char *reply, CASE* robot)
{
	int k;
	char *t_str=str;
	srand((unsigned int)time(0));
	while (*t_str!=0)                                           
	{
		if (!strncmp(t_str,"��",2))
		{
			k=rand()%4;
			if (k==0)
				reply="�����ô��";
			else if (k==1)
				reply="�Ҿ��û���ţ����ó�";
			else if (k==2)
				reply="�����Ƽ��߲�ɳ��";
			else if (k==3)
				reply="�㶼��ô���˻����";
		}
		else if (!strncmp(t_str,"��",2))
		{
			k=rand()%4;
			if (k==0)
				reply="�������ģ��ʺ�����";
			else if (k==1)
				reply="��������С�꣬������Ŵ�ɡ";
			else if (k==2)
				reply="���꣬���ǿ�����";
			else if (k==3)
				reply="���죬��ˬ���ʣ��Ǹ������˶��ĺ�����";
		}
		else if (!strncmp(t_str,"��",2))
		{
			k=rand()%3;
			if (k==0)
				reply="���ǿ��׵����ܻ����ˣ�������Э���������Ǹ����ǵ�ѡ��";
			else if (k==1)
				reply="�������ܻ����ˣ�����ĵؽ�����������";
			else if (k==2)
				reply="����һ�������Ļ����ˣ����Һ�����";
		}
		else if (!strncmp(t_str,"��",2))
		{
			k=rand()%3;
			if (k==0)
				reply="�Ҳ�������Ϸ���ܣ�ȥ������Ϸƽ̨��";
			else if (k==1)
				reply="������Ϸ���̫���������컹��ЪЪ��";
			else if (k==2)
				reply="��˵������Ƕ�����Լ��أ���Ҫȥ������";
		}
		else if (!strncmp(t_str,"��",2))
		{
			k=rand()%1;
			if (k==0)
				reply="��������ֻ��ʶФ���ĺ�Ԭ��������������������˧��";
		}
		else
			reply=NULL;
		t_str+=2;
		if (reply!=NULL)
		{
			saveimage_chat(robot->x*40+40,robot->y*40);
			show_reply(reply,robot);	//��ʼ��ʾ�ظ���Ϣ
			getch();
			putsave_chat(robot->x*40+40,robot->y*40);
		}
		reply=NULL;
	}
	if (no_keyword(str))
	{
		reply="����";
        saveimage_chat(robot->x*40+40,robot->y*40);
        show_reply(reply,robot);	//��ʼ��ʾ�ظ���Ϣ
        getch();
        putsave_chat(robot->x*40+40,robot->y*40);
	}
}


void show_reply(char *incode,CASE* robot)
{
	int x=robot->x*40+40+10,y;	//��ӡ�ظ����ֵ�λ��
	int box_top;	//�Ի���׶�����������
	int i;			//temp
	int num_word=0;	//��Ҫ�ظ�������
	int num_line;	//�ظ�����
	char *p_incode=incode;	//incode��λ��ָ��

	//����м�����
	while(*p_incode!=NULL)
	{
		p_incode+=2;
		num_word++;
	}


	//���Ի����
	
	bar_round_2(robot->x*40+40,robot->y*40,robot->x*40+240,robot->y*40+80,5,2,65535);

	//��ӡ�ظ��ĺ���
	
	i = 0;	//���������
	y = robot->y*40+5;
	while(*incode!=NULL)
	{
		while( (i<10)&&(*incode!=NULL) )
		{
			dishz(x,y,1,1,incode,0);
			i++;
			x+=16*1;
			incode+=2;
		}
		i=0;
		x=robot->x*40+40+10;
		y+=20*1;
	}


}




void show_main(int *qhwh, CASE* robot)
{
	int num_qhwh;	//ͳ��������ַ�����
	int begin_y;	//���ÿ�ζԻ������ʱ�Ķ���y������ȷ��putimage�ķ�Χ
	char *reply =NULL;	//֮���ǵ��ļ��еĴ�䲿��
	char incode[30] ={0};

	//��ʾ�û����벿��
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1,ORIGINY+345+1);
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,54938);	//���Ҫ��ʾ�û�������Ϣ������
	show_order(qhwh,&begin_y);	//��ʼ��ʾ�û�������Ϣ
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);

	delay(500);	//�ȴ������˻ظ�

	//��ʾ�����˻ظ�����
	//Ѱ��ƥ���
	get_str( qhwh, incode);
	reply_match( incode, reply,robot);
}

int no_keyword(char *str)
{
	int p=1;
	char *t_str=str;
	while (*t_str!=0)
	{
		if (!strncmp(t_str,"��",2)  ||  !strncmp(t_str,"��",2)  ||  !strncmp(t_str,"��",2)  ||  !strncmp(t_str,"��",2)  ||  !strncmp(t_str,"��",2)  )
			p=0;
		t_str+=2;
	}
	return  p;
}

