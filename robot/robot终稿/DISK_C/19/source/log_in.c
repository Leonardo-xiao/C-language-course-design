#include "title.h"
//���ܣ���¼ע�Ṧ�����߼�
//���룺��
//�����int��
//      ����1Ϊ��½�ɹ�������ѭ����������һģ��
//		����0Ϊ��½ʧ�ܣ�����ѭ��
int enter(void)
{
	USERS user;												//������ŵ�ǰ�û�����Ϣ
	USERS *head = NULL;										//�����ͷ�ڵ�
	int temp;												//���ڴ�ż�������
	//int error=0;											//
	int button,x,y;
	int judge=0;											
	user.account[0] = '\0';
	user.code[0] = '\0';

	if ((head = (USERS *)malloc(sizeof(USERS))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
	create_list(head);
	log_in_page();                                 //��ֹ��¼����
	mouseInit(&x, &y,&button);
    while(1)
	{
		//newxy(&x, &y, &button);
				    /*��ʼ�������ܻ���������*/
		if (kbhit() == 0)
		{
			newxy(&x, &y, &button);
		}
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		/*��esc���˳�*/
		if(temp == 0x11b)
		{
			exit(0);
		}

		/*��¼*/
		if(x>=650&&x<=700&&y<=495&&y>=445&&button)
		{
			judge = log_in_check(head,user.account,user.code);  //��¼�ɹ�����1
		}


		/*ע��*/
		if(x>=440&&x<=560&&y>=555&&y<=590&&button)
		{
			
			judge = UserRegist(head,user.account,user.code,&x,&y,&button);
		}

		if(x>=300&&x<=700&&y>=295&&y<=345&&button)	//ѡ��id����
		{
			judge = 2;
		}

		if(x>=300&&x<=700&&y>=445&&y<=495&&button)	//ѡ����������
		{
			judge = 3;
		}

		if(judge==2)//����id
		{
			judge = input_account(head,&user.account,&user.code,&x,&y);

		}
		if(judge==3)//����password
		{
			judge = input_code(head,&user.account,&user.code,&x,&y);
		}
		if(judge==1)
		{
			free_list(&head);
            return 1;
		}
		//���ص�¼����
		if(judge==5)
		{
			free_list(&head);
			head=NULL;
			return 0;    //ֻҪ����1�Ϳ�����
		}

	}
}


//���ܣ���¼�ľ�ֹ����
//���룺��
//�������
void log_in_page(void)
{
    CASE robot_position;
    robot_position.xpixel=500;
    robot_position.ypixel=120;
    
    linever_color(0,0,1024,768,211,211,211,128,128,128);
    bar_round(500,320,400,50,5,1,65535);//300,295,700,345
    bar_round(500,470,400,50,5,1,65535);
    fdhz(250,310,1,1,"��",0);
    fdhz(270,310,1,1,"��",0);
    fdhz(250,460,1,1,"��",0);
    fdhz(270,460,1,1,"��",0);
    FillCircle(675,470,22,65535);
    circle(675,470,22,33808);
    circle(675,470,23,33808);
    linelevel(660,470,690,470,2,33808);
    lean_line_thick(690,470,20,225,2,33808);
    lean_line_thick(690,470,20,135,2,33808);
    bar (440,555,560,590,50712);
    fdhz(484,570,1,1,"ע��",0);
	   

    logo_robot(robot_position);

}


//���ܣ��˺����뺯��
//���룺�û���Ϣ�����ͷ�ڵ㣬ָ���˺��ַ������ַ�ָ�룬ָ�������ַ������ַ�ָ�룬�������ָ��
//�����int��
//		����1����¼��ע��ɹ�
//		����3�������������뺯��
int input_account(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//���ڼ�����������ַ���Ŀ�ı���
	char *p=account;//�����ַ����м�ָ�����
	char ch;//������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons,judge;
	char temp[2] = {'\0','\0'};

	//�鿴�Ѿ������˶��ٸ��ַ�
	while(*p != '\0')
	{
		i++;
		p++;
	}
    while(1)
	{
		//newxy(x,y,&buttons);
		key=0;
		if (kbhit() == 0)
		{
			newxy(x,y,&buttons);
		}
		if (kbhit() != 0)
		{
			key = bioskey(0);    //������Ǽ�ֵ
		}


	     /*��������Ӧ���ַ�����account��*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			temp[0] = ch;
			outtextxy(300+i*18,305,temp,2,2,10,0);


		/*���ַ�����������*/
		    *p = ch;
		    p++;
		    *p = '\0';
		    i++;
	    }



        if(key ==0xe08)         //���˻�ɾ��
	    {
		    if(p != account)
		    {
			    bar(290 + i * 18, 295, 340 + i * 18, 345,65535);
			    p--;
			    i--;
		    }
			*p = '\0';
	    }
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}

		//ɾ���˷�ֹ����ڵ��Ĺ��ܣ�2020/7/26��



		//��������
		if(*x>=300&&*x<=700&&*y>=445&&*y<=495&&buttons)
		{
			return 3;
		}

		//ע���
		if(*x>=440&&*x<=560&&*y>=555&&*y<=590&&buttons)
		{
			
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}




		//��¼��
		if(*x>=650&&*x<=700&&*y<=495&&*y>=445&&buttons)
		{

			judge = log_in_check(head,account,code);
			return judge;
		}
	}
}

//���ܣ��˺����뺯��
//���룺�û���Ϣ�����ͷ�ڵ㣬ָ���˺��ַ������ַ�ָ�룬ָ�������ַ������ַ�ָ�룬�������ָ��
//�����int��
//		����1����¼��ע��ɹ�
//		����2������id���뺯��
int input_code(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//���ڼ�����������ַ���Ŀ�ı���
	char *u = code;//�����ַ����м�ָ�����
	char ch;//������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons,judge;

	while(*u != '\0')
	{
		i++;
		u++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)
	    {
		    if(u != code)
		    {
			    bar(275 + i * 25, 450, 305 + i * 25, 490,65535);
			    u--;
			    i--;
		    }
			*u = '\0';
	    }

		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}

		//��¼��
		if(*x>=650&&*x<=700&&*y<=495&&*y>=445&&buttons)
		{
            
			judge = log_in_check(head,account,code);
			return judge;
		}

		//ɾȥ��ֹ����ʱ�ڵ�����



		//�����˺�
		if(*x>=300&&*x<=700&&*y>=295&&*y<=345&&buttons)
		{

			return 2;
		}

		//ע���
		if(*x>=440&&*x<=560&&*y>=555&&*y<=590&&buttons)
		{
			
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}


	/*��������Ӧ���ַ�����code������*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {


		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(315+i*25,470,8,0);

		/*���ַ�����������*/
		    *u = ch;
		    u++;
		    *u = '\0';
		    i++;
	    }
	}
}



//���ܣ���֤�˺������Ƿ���ȷ
//���룺�û���Ϣ�����ͷ�ڵ㣬ָ�����ַ������ַ�ָ�룬ָ�������ַ������ַ�ָ��
//�����int��
//		����1����֤�ɹ�
//		����5����֤ʧ��
int log_in_check(USERS *head,char *account,char *code)
{
	char *rightcode= NULL;
	rightcode = accounts_2_code(head, account);
	if (rightcode != NULL &&strcmp(rightcode, code) == 0)
		return 1; //��¼�ɹ�
	else
	{
		fdhz(410, 500,1, 1, "�û����������������", 0);
        getch();
		return 5;
	}
}
