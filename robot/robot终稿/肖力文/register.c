#include "title.h"
//���ܣ�ע�Ṧ�����߼�����
//���룺�û���Ϣ�����ͷ�ڵ㣬ָ���˺��ַ������ַ�ָ�룬ָ�������ַ������ַ�ָ�룬�������ָ��Ͱ�����Ϣָ��
//�����int��
//		����1��ע��ɹ�
//		����5�����˷��ؼ�
int UserRegist(USERS *head,char *account,char *code,int *x,int *y,int *buttons)
{
	int judge = 0; //�ж�Ӧ�õ�����Щ�����ı���
	int flag[4] = {0};  //�ֱ�ΪΪ�û��������롢���������Ƿ���ȷ���жϱ���
	int temp;  //�������ռ��̻������ı���
	char secondcode[11];  //�ڶ����������봮
	char mail[20]={0};
	char real_veri[5]={0};
	char veri[5]={0};

	/*��Ҫ�ĳ�ʼ������*/
	secondcode[0] = '\0';
	*account = '\0';
	*code = '\0';
	mousehide(*x,*y);         //�����
    regist_page();              //��¼����
	reset_mouse(x,y);         //���������
	while (1)
	{

        newxy(x, y, buttons);//���µ�λ�û����
        //�˺�����
		judge = input_area(x,y,buttons);
		
		switch(judge)
		{

			case 0:
				break;
			//�����˺����뺯��
			case 1:
				//judge = RegisteraccountsInput(account, x, y);
				judge = inpu(account, x, y, buttons,349, 260,0);
				if (account[0]==0)
				{
					bar(695,240,750,310,50712);      //��ա�����λ�ô���ͼ��
					red_cross(700,275);
					fdhz(450,242,1,1,"�˺Ų���Ϊ��",0);
					flag[0] = 0;
				}
				else if (accounts_2_code(head, account) != NULL)
				{
					bar(695,240,750,310,50712);      //��ա�����λ�ô���ͼ��
					red_cross(700,275);
					fdhz(450,242,1,1,"���˺��ѱ�ע��",0);
					flag[0] = 0;
				}
				else
				{
					bar(695,240,750,310,50712);      //��ա�����λ�ô���ͼ��
					bar(440,241,690,259,50712);      //��ա����˺��ѱ�ע�ᡱ
					green_tick(700,275);
					flag[0] = 1;

				}
				break;
			/*case 2:�����������뺯��*/
			case 2:
				//judge = RegistercodeInput(code, x, y);
				judge = inpu(code, x, y, buttons,349, 350,1);
				if (strlen(code) < 6)
				{
					/*����ɫ�Ĳ沢��ʾ���벻��������λ&flag2=0*/
					bar(695,330,750,400,50712);      //��ա�����λ�ô���ͼ��
					bar(440,331,690,349,50712);      //��ա����벻��������λ��
					red_cross(700,365);
					fdhz(442,332,1, 1, "���벻��������λ",  0);
					flag[1] = 0;
				}
				else
				{
					/*��һ����ɫ�Ĺ�&flag2=1*/
					bar(695,330,750,400,50712);      //��ա�����λ�ô���ͼ��
					bar(440,331,690,349,50712);      //��ա����벻��������λ��
					green_tick(700,365);
					flag[1] = 1;
				}
				break;

			/*case 3:���ö����������뺯��*/
			case 3:
				//judge = RegistersecondcodeInput(secondcode, x, y);
				judge = inpu(secondcode, x, y, buttons,349, 440,1);
				if (strcmp(code, secondcode) != 0)
				{
					/*����ɫ�Ĳ沢��ʾ�����������벻ͬ&&flag3=0*/
					bar(695,420,750,490,50712);      //��ա�����λ�ô���ͼ��
					bar(400,421,690,439,50712);      //��ա�������������벻ͬ��

					red_cross(700,455);
					fdhz(442,422, 1, 1, "������������벻ͬ", 0);
					flag[2] = 0;
				}
				else
				{
					/*��һ����ɫ�Ĺ�&flag3=1*/
					bar(695,420,750,490,50712);      //��ա�����λ�ô���ͼ��
					bar(400,421,690,439,50712);      //��ա�������������벻ͬ��
					green_tick(700,455);

					flag[2] = 1;
				}
				break;

			/*case 4:��������*/
			case 4:
				//judge=mail_input(mail,x,y);
				judge = inpu(mail, x, y, buttons,349, 530,0);
				break;

			/*case 5:��ȡ��֤��*/
			case 5:
				flag[3]=get_verification(mail,real_veri,flag);
				judge=4;
				break;


			/*case 6:��֤������*/
			case 6:
				//judge=verification_input(veri, x, y);
				judge = inpu(veri, x, y, buttons,349, 620,0);
				break;

			/*case 7:���ע���*/
			case 7:
				if (regist_success(real_veri, veri) && flag[1] && flag[2] && flag[0])
				{
					add_new_user(head,account,code);   //�����ļ�
					bar(695,600,750,670,50712);      //��ա�����λ�ô���ͼ��
					bar(400,601,690,619,50712);      //��ա���֤�벻��ȷ��
					return 1;
				}
				else
				{
					bar(695,600,750,670,50712);      //��ա�����λ�ô���ͼ��
					bar(400,601,690,619,50712);      //��ա���֤�벻��ȷ��

					red_cross(700,635);
					fdhz(622,602, 1, 1, "��֤�벻��ȷ", 0);
				}
				break;
			case 8:
				return 5;
		}

	}
}


//���ܣ�decide which input function will be invoked
//���룺the pointer's information of mouse
//�����int��
//		����1�������˺����뺯��
//		����2�������������뺯��
//		����3���������ȷ���������뺯��
//		����4�������������뺯��
//		����6������������֤�뺯��
//		����7���������ɣ�����ע����֤����
//		����8�����ˡ�back"
int input_area(int *x,int *y, int *buttons)
{
		if(*x>=344 &&*x<=690&&*y>=260&&*y<=290&&*buttons)
		{
			return 1;
		}
		//����
		if(*x>=344&&*x<=690&&*y>=350&&*y<=380&&*buttons)
		{
			return 2;
		}
		//����ȷ������
		if(*x>=344&&*x<=690&&*y>=440&&*y<=470&&*buttons)
		{
			return 3;
		}
		//��������
		if(*x>=344&&*x<=584&&*y>=530&&*y<=560&&*buttons)
		{
			return 4;
		}
		//��ȡ��֤��
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			return 5;
		}
		//������֤��
		if(*x>=344&&*x<=690&&*y>=620&&*y<=650&&*buttons)
		{
			return 6;
		}
		//ע�Ტ��¼
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			return 7;
		}
        	//���ؼ�
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 8;
		}
		else 
			return 0;

}




//���ܣ�ע��ĸ���ģ�������
//���룺
//		char*inpu_c����Ҫ������ַ������׵�ַ
//		int *x, int *y, int *buttons����������Ͱ�����ָ��
//		int x_posi, int y_posi��������ʼλ�ã���һ���ַ������Ͻ����꣩
//		int a_p���ж�������Ƿ������룬���������ʾʵ��Բ�����Ǿ���ʾ���е��ַ�
//				0����������
//				1��������
//�����int��
//		����1�������˺����뺯��
//		����2�������������뺯��
//		����3���������ȷ���������뺯��
//		����4�������������뺯��
//		����6������������֤�뺯��
//		����7���������ɣ�����ע����֤����
//		����8�����ˡ�back"
int inpu(char*inpu_c, int *x, int *y, int *buttons,int x_posi, int y_posi,int a_p)  //a_p��0��ʾ������
{
	int key;     //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	char *p = inpu_c;     //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
    char temp[2]={0};//����outtextxy�����
	int judge=0;
	
	/*ʹpָ��'\0',i��ʾ��ǰ�ַ���*/
	while (*p != '\0')
	{
		i++;
		p++;
	}
	
	while (1)
	{
		newxy(x, y, buttons);//���µ�λ�û����

		judge = input_area(x,y,buttons);
		
		if (judge!=0)
			return judge;

        key=0;

		if (a_p==0)
		{
			/*���ռ��̻���������*/
			if (kbhit() != 0)
			{
				key = bioskey(0);
			}

			/*��esc���˳�*/
			if(key == 0x11b)
			{
				exit(0);
			}
			/*���˻�ɾ��*/
			if(key == 0xe08)	//����˸��ʱ�Ĳ���
			{
				if(p != inpu_c)		//����Ƿ�����λ����ַ�Ƿ���ͬ��
				{
					bar(x_posi+ i * 10+4, y_posi, x_posi+16+ i * 10+4, y_posi+30,65535);
					p--;			//ָ��		��ǰ��
					i--;			//������	��ǰ��
				}
				*p = '\0';			//	ͬ�������һλ����'\0'
			}
			//	��������Ӧ���ַ�һ��������ph_num������

			ch = searchKeyValue(key);
			temp[0] = ch;
			if (ch != '\0'&&i<20)
			{
				outtextxy(x_posi+i*10+10,y_posi+7,temp,1,1,8,0);

				//	���ַ�����������
				*p = ch;
				p++;
				*p = '\0';		// ÿ�β�����Ҫ��'\0'
				i++;

			}
		}
		
		else if(a_p==1)
		{
			/*���ռ��̻���������*/
			if (kbhit() != 0)
			{
				key = bioskey(0);
			}

			/*��esc���˳�*/
			if(key == 0x11b)
			{
				exit(0);
			}
			/*���˻�ɾ��*/
			if(key == 0xe08)	//����˸��ʱ�Ĳ���
			{
				if(p != inpu_c)		//����Ƿ�����λ����ַ�Ƿ���ͬ��
				{
					bar(x_posi + i * 15 -15, y_posi, x_posi+15 + i * 15, y_posi+30,65535);
					p--;			//ָ��		��ǰ��
					i--;			//������	��ǰ��
				}
				*p = '\0';			//	ͬ�������һλ����'\0'
			}
			//	��������Ӧ���ַ�һ��������ph_num������

			ch = searchKeyValue(key);
			temp[0] = ch;
			if (ch != '\0'&&i<20)
			{
				FillCircle(x_posi + i * 15+8, y_posi+15, 5, 0);

				//	���ַ�����������
				*p = ch;
				p++;
				*p = '\0';		// ÿ�β�����Ҫ��'\0'
				i++;

			}
		}
	}
	
}

//���ܣ���̬ע�����
//���룺��
//�������
void regist_page(void)
{
    CASE robot_position;
    robot_position.xpixel=517;
    robot_position.ypixel=90;
	bar(0,0,1024,768,54938);
	bar(80,70,944,695,50712);
	fdhz(296,11,3,3,"��",0);
	fdhz(392,11,3,3,"ӭ",0);
	fdhz(488,11,3,3,"��",0);
	fdhz(584,11,3,3,"��",0);
	fdhz(690,11,3,3,"��",0);
	//bar_round(100,100,50,50,3,1,255);
	bar_round(517,275,346,30,5,1,65535);//�û���     344,260   690,290
    bar_round(517,365,346,30,5,1,65535);//����       344,350   690,380
    bar_round(517,455,346,30,5,1,65535);//�ٴ���������  344,440   690,470
    bar_round(517,545,346,30,5,1,65535);//��������  344,530   690,560
    bar_round(517,635,346,30,5,1,65535);//������֤��  344,620   690,650
    bar(584,533,690,557,54938);         //��ȡ��֤��    584��533   690��557
	//bar_round(517,540,234,50,5,1,33808);
	logo_robot(robot_position);
	fdhz(280,267,1,1,"��",0);
	fdhz(300,267,1,1,"��",0);
	fdhz(280,357,1,1,"��",0);
	fdhz(300,357,1,1,"��",0);
	fdhz(240,447,1,1,"ȷ",0);
	fdhz(260,447,1,1,"��",0);
	fdhz(280,447,1,1,"��",0);
	fdhz(300,447,1,1,"��",0);
	fdhz(280,537,1,1,"��",0);
	fdhz(300,537,1,1,"��",0);
	fdhz(590,537,1,1,"��ȡ��֤��",27469);
	fdhz(260,647,1,1,"��",0);
	fdhz(280,647,1,1,"֤",0);
	fdhz(300,647,1,1,"��",0);
	fdhz(468,715,2,2,"��",0);
	fdhz(532,715,2,2,"��",0);
	outtextxy(83,95,"back",1,1,10,65535);
}

//���ܣ���ȡ��֤�뺯��
//���룺ָ�������ַ������ַ�ָ�룬ָ����֤���ַ������ַ�ָ�룬ָ��flag
//�����int��
//		����1���˺�������Ϣ������������ȷ��������֤��
//		����0����֤�����ɴ���
int get_verification(char *mail,char *real_veri, int flag[])
{
    char real_mail[17] = "123456aqq.com";
    int a,i;
    char b[5];
    int flag0=0;
    srand((unsigned)time(0));
    
	if (flag[0]==1 && flag[1]==1  &&  flag[2]==1)
	{
			if (whether_mail(mail)==0)
		{
			bar(390,505,690,530,50712);
			fdhz(454,510,1,1,"�����ʽ����ȷ",65535);
			bar(695,530,750,580,50712);      //��ա�����λ�ô���ͼ��
			red_cross(700,545);
		}
		if (whether_mail(mail)==1)
		{
			if (strcmp(mail,real_mail)==0)
			{
				bar(390,505,690,530,50712);
				bar(695,530,750,580,50712);      //��ա�����λ�ô���ͼ��
				green_tick(700,545);
				//get_image(290,0,740,96,image_save);
				bar (290,0,740,50,65535);
				bar_round_2(290,30,740,96,10,1,65535);
				fdhz(300,5,1,1,"�𾴵��û������ã�",0);
				fdhz(332,25,1,1,"��ӭʹ�ñ����ܼҾӻ�����ϵͳ��������",0);
				fdhz(332,45,1,1,"ע�����֤��Ϊ��",0);
				linelevel(380,90,620,90,3,0);
				a=rand()%10000;
				itoa(a,b,5);

				b[4]='\0';

				for(i=0;i<5;i++)
				{
					real_veri[i] = b[i];
				}


				outtextxy(450,50,b,2,2,15,0);

				fdhz(300,75,1,1,"ף��ʹ�����",0);
				delay(1500);
				//put_image(290,0,740,96,image_save);
				flag0=1;
			}
		}
	}
	
	else 
	{
		bar(390,505,690,530,50712);
		fdhz(454,510,1,1,"�˺�������Ϣ������",65535);
		bar(695,530,750,580,50712);      //��ա�����λ�ô���ͼ��
		red_cross(700,545);
	}
    return flag0;
}

//���ܣ��ж�ע���Ƿ�ɹ�
//���룺�����֤����ַ�ָ����Լ�д�����֤����ַ�ָ��
//�����int��
//		����0����֤�벻��ȷ��ʧ��
//		����1����֤����ȷ���ɹ�
int regist_success(char *real_veri, char *veri)
{
    int p=0;
    if (strcmp(real_veri,veri)==0)
    {
        p=1;
    }
    return p;
}

//���ܣ��ж������Ƿ�ΪĬ�������ʽ
//���룺ָ�������ַ������ַ�ָ��
//�����int��
//		����1����ʽ��ȷ
//		����0����ʽ����
int whether_mail(char *str)
{
    int p=0;
    if (strstr(str,"aqq.com"))
    {
        p=1;
    }
    return p;
}

