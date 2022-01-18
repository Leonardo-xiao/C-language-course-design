#include "title.h"
//���������ǻ����������ı����洢����
//��һ���ǵõ������ı���
//�ڶ�������������ı����������������
//���룺������Ͻ�
//�������
//�ߴ磺240*80
void saveimage_chat(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	fp=fopen("save//welcome","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<245;i++)
		for(j=0;j<85;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************��240*80�ĵ����ڵ�������ʾ*****/

void putsave_chat(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//welcome","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<245;i++)
		for(j=0;j<85;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//���������ǻ����˻�ӭ��ı����洢����
//��һ���ǵõ������ı���
//�ڶ�������������ı����������������
//���룺������Ͻ�
//�������
//�ߴ磺240*80
void saveimage_welcome(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	fp=fopen("save//chat","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<710;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************��710*40�ĵ����ڵ�������ʾ*****/

void putsave_welcome(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//chat","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<710;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}


//����������ѡ���ı����洢����
//��һ���ǵõ�ѡ���ı���
//�ڶ��������ѡ���ı�����������ѡ���
//���룺������Ͻ�
//�������
//�ߴ磺240*40
void saveimage_choose(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	fp=fopen("save//choose","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<250;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************��240*40�ĵ����ڵ�������ʾ*****/

void putsave_choose(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//choose","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<250;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}


//���������ǻ����˶���״̬��ı����洢����
//��һ���ǵõ�����״̬��ı���
//�ڶ������������״̬��ı����������Ƕ���״̬��
//���룺������Ͻ�
//�������
//�ߴ磺80*30
void saveimage_doing(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//doing","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<85;i++)
	{
		for(j=0;j<33;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	}
	fclose(fp);
}

/******************��80*30�ĵ����ڵ�������ʾ*****/

void putsave_doing(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//doing","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<85;i++)
	{
		for(j=0;j<33;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	}
	fclose(fp);
}

//����������g_c��ı����洢����
//��һ���ǵõ�g_c��ı���
//�ڶ��������g_c��ı�����������g_c��
//���룺������Ͻ�
//�������
//�ߴ磺90*40
void saveimage_g_c(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//g_c","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<105;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************��90*40�ĵ����ڵ�������ʾ*****/

void putsave_g_c(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//g_c","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<95;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//���������ǻ�����t_c��ı����洢����
//��һ���ǵõ�t_c��ı���
//�ڶ��������t_c��ı�����������t_c��
//���룺������Ͻ�
//�������
//�ߴ磺120*40
void saveimage_t_c(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//t_c","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<125;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************��120*40�ĵ����ڵ�������ʾ*****/

void putsave_t_c(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//t_c","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<125;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//���������ǻ�����box��ı����洢����
//��һ���ǵõ�box��ı���
//�ڶ��������box��ı�����������box��
//���룺������Ͻ�
//�������
//�ߴ磺200*40
void saveimage_box(int x,int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//box","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<210;i++)
		for(j=0;j<45;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

/******************��200*40�ĵ����ڵ�������ʾ*****/

void putsave_box(int x,int y)
{
	int i,j;
	unsigned int t;
	FILE *fp;
	fp=fopen("save//box","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<210;i++)
		for(j=0;j<45;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//�����������˱����洢����
//��һ���ǵõ��˵ı���
//�ڶ���������˵ı�������������
//���룺������Ͻ�
//�������
//�ߴ磺70*90

void get_image_man(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//man","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=-35;i<35;i++)
		for(j=-5;j<85;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_man(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//man","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=-35;i<35;i++)
		for(j=-5;j<85;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//���������ǻ����˵ı����洢����
//��һ���ǵõ������˵ı���
//�ڶ�������������˵ı����������ǻ�����
//���룺������Ͻ�
//�������
//�ߴ磺70*90
void get_image_robot(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//robot","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=-35;i<35;i++)
		for(j=-5;j<85;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_robot(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	//while(1);
	fp=fopen("save//robot","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=-35;i<35;i++)
		for(j=-5;j<85;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//��������������1�ı����洢����
//��һ���ǵõ�����1�ı���
//�ڶ������������1�ı���������������1
//���룺������Ͻ�
//�������
//�ߴ磺40*40
void get_image_trash1(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash1","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_trash1(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash1","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//��������������2�ı����洢����
//��һ���ǵõ�����2�ı���
//�ڶ������������2����������������2
//���룺������Ͻ�
//�������
//�ߴ磺40*40
void get_image_trash2(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash2","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_trash2(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash2","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

//��������������3�ı����洢����
//��һ���ǵõ�����3�ı���
//�ڶ������������3�ı���������������3
//���룺������Ͻ�
//�������
//�ߴ磺40*40
void get_image_trash3(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash3","w");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_trash3(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//trash3","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<43;i++)
		for(j=0;j<43;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}


//��������ϴ�豳���洢����
//��һ���ǵõ�ϴ��ı���
//�ڶ��������ϴ��ı����������ǵذ�
//���룺������Ͻ�
//�������
//�ߴ磺80*80
void get_image_bath(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//bath","w+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<83;i++)
		for(j=0;j<83;j++)
		{
			t=Getpixel64k(x+i,y+j);
			fwrite(&t,2,1,fp);
		}
	fclose(fp);
}

void put_image_bath(int x, int y)
{
	FILE *fp;
	int i,j;
	unsigned int t;
	 
	fp=fopen("save//bath","r+");
	if(fp==NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	rewind(fp);
	for(i=0;i<83;i++)
		for(j=0;j<83;j++)
		{
			fread(&t,2,1,fp);
			Putpixel64k(x+i,y+j,t);
		}
	fclose(fp);
}

