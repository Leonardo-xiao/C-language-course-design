#include "title.h"
/*****************************************************************
�����б� 1.void dmove(CASE *case_state, int casetype)      //�ı������
            2.void move0(CASE *case_state, int casetype)      //����ĸı��붯������
            3.int aimmove(CASE *case_state,int x0,int y0,int xt,int yt,const Graph G, const int n, int casetype)    //�û������ƶ�ʱ��Ҫֱ�ӵ��õĺ���
*****************************************************************/
/*����������dmove��ÿһ���ƶ�����С��λ������ֻ�ı����꣬Ȼ��ֱ�ӻ������ʱ��Ļ����˻����˵�ͼ�񣬲����漰���ֵİڶ���
  ��ڲ�������ʾ�����˻��˵�״̬�Ľṹָ��case_state����Ϊ�ı�������Ҫַ����
            casetype���ڱ�ʾ���˻��ǻ����ˣ�MAN����1�����ˣ�ROBOT����0���ǻ�����
*/
void dmove(CASE *case_state, int casetype)    //Ҫ�ı�״̬������Ӧ�ô�ָ�룬casetypeΪ0�ǻ����ˣ�1����
{
	int x0 = case_state->xpixel, y0 = case_state->ypixel;

	//�жϷ����ƶ���Ӧ���루�����ص�ƣ�
	if(!casetype)   //�ǻ�����
	{
	    switch(case_state->direction)
        {
            case 1:         //������
            {
                if(case_state->catch_th == WITHOUT_THING)   //����û�ö���
                {
                    robot_right(*case_state);       //���������ߵ�ͼ��
                }
                else    //������ˮ�����·�������
                {
                    right_hold(*case_state);
                }
                x0 = x0 + 10;
                break;
            }
            case 2:         //����
            {
                if(case_state->catch_th == WITHOUT_THING)   //����û�ö���
                {
                    robot_left(*case_state);       //���������ߵ�ͼ��
                }
                else    //������ˮ�����·�������
                {
                    left_hold(*case_state);
                }
                x0 = x0 - 10;
                break;
            }
            case 3:         //����
            {
                if(case_state->catch_th == WITHOUT_THING)   //����û�ö���
                {
                    backbodyhead(*case_state);
                }
                else    //������ˮ�����·�������
                {
                    back_hold(*case_state);
                }
                y0 = y0 - 10;
                break;
            }
            case 4:         //����
            {
                if(case_state->catch_th == WITHOUT_THING)
                {
                    forebodyhead(*case_state);
                }
                else    //������ˮ�����·�������
                {
                    front_hold(*case_state);
                }
                y0 = y0 + 10;
                break;
            }
        }

        delay(80); //����ͼ��
        put_image_robot(case_state->xpixel, case_state->ypixel);

	}
    else        //����
    {
        switch(case_state->direction)
        {
            case 1:         //������
            {
                man_rightbody(*case_state);
                x0 = x0 + 10;
                break;
            }
            case 2:         //����
            {
                man_leftbody(*case_state);
                x0 = x0 - 10;
                break;
            }
            case 3:         //����
            {
                man_backbody(*case_state);
                y0 = y0 - 10;
                break;
            }
            case 4:         //����
            {
                man_forebody(*case_state, 1);   //һ���������ƶ���İ����ֻ�ǳ��ֲ�check������Ҫ���ƶ�
                y0 = y0 + 10;
                break;
            }
        }

        delay(80); //����ͼ��
        put_image_man(case_state->xpixel, case_state->ypixel);

	}

	case_state->xpixel = x0;  //�ı�λ��
	case_state->ypixel = y0;
	case_state->x = (case_state->xpixel + 2)/40;        //��������С������������������
	case_state->y = (case_state->ypixel + 2)/40;        //������ƫ��������Ϊ2�����ص㱾���޴󰭣�Ϊ�˷�ֹ�߽紦����Ǳ�ڵĹ���

	if(!casetype)       //������
    {
        get_image_robot(case_state->xpixel, case_state->ypixel);
    }
    else                //��
    {
        get_image_man(case_state->xpixel, case_state->ypixel);
    }

}

/*������������dmove������ĸı䣨��λ�õ��ƶ����붯���ĸı��ںϣ��൱���˶��ĵ���
  ��ڲ�����ͬdmove*/
void move0(CASE *case_state, int casetype)
{
	int i;
	if(!casetype)       //������
    {
        put_image_robot(case_state->xpixel, case_state->ypixel);
    }
    else
    {
        put_image_man(case_state->xpixel, case_state->ypixel);
    }

	//��һ���ļ���ı�����˵�λ��
	for(i=0;i<4;i++)
	{
		//�ı��ֵĽǶ�
		if(case_state->hand)
		{
			case_state->hand_left++;
			case_state->hand_right--;
		}
		else//��ʼ��ʱΪ0����������
		{
			case_state->hand_right++;
			case_state->hand_left--;
		}
		if((case_state->hand_right>=10)||(case_state->hand_left>=10)||(case_state->hand_right<=-10)||(case_state->hand_left<=-10))
		{
			case_state->hand=!case_state->hand;
		}
		//ǰ����Щ�������ڸı䶯�����൱����һ����·��ͼ��
		//�������dmove����������ƶ���
///����������⣬��·�Ķ����ǣ�����ԭ�ظı䶯���������ע������Ĳ��֣�+�����⶯������λ��ƽ��2�����ص㡱�ĵ���
		//������С�ƶ���Ԫ
		dmove(case_state,casetype);
	}
	//����λ��
	case_state->x = case_state->xpixel/40;
	case_state->y = case_state->ypixel/40;

	if(!casetype)
    {
        forebodyhead(*case_state);
    }
    else
    {
        man_forebody(*case_state, 1);
    }

}

/*
���������� case_state��x��y����ᵽmove0��Ȼ���ٽ���demove0��Ȼ��ű��ı�
            demove0�У����ݷ����ƶ��������ص㣬�ı�case_state
�������ܣ� ��������ʼ�㵽��ֹ������·�����˺ͻ����˹��ô˺���
��ڲ����� ��ʾ�����˻��˵�״̬�Ľṹָ��case_state����ʼ�㡢��ֹ���x��y���꣨�����꣩
            ͼG�Լ�G��Ԫ�ظ���n��casetype���ڱ�ʾ���˻��ǻ�����
*/
int aimmove(CASE *case_state,int x0,int y0,int xt,int yt,const Graph G, const int n, int casetype)//��(0,0)Ϊ��ʼ�������ص�
{
	Axis V0, Vt;        //����findway

	///path����findway��Ȼ������ջS���ٰ�S�����Ż�path
	PathType *path = NULL, *t = NULL;      //t����ջ��ջʱ�õ��ݴ����
	LkStack S;
	int i;

	V0.x = x0, V0.y = y0;           //��V0��Vt��ʼ������Ϊfindway��Ҫ����Axis�͵ĵ�
	Vt.x = xt, Vt.y = yt;

	InitStack(&S);                  //��ʼ��ջ

    path = (PathType *)malloc(n*sizeof(PathType));      //Ϊpath����ռ䣬path����Ԫ����Ŀ���ֻ��G�ĸ�����

	if(!path)                       //����ʧ��
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}

	t = (PathType *)malloc(sizeof(PathType));   //Ϊ�ݴ�ڵ����ռ�

	if(!t)                          //����ʧ��
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}

	//����������յ�
	if(x0==xt && y0==yt)
	{
		return 0;       //���ش�����Ϣ
	}

	if(!FindWay(G, path, n, V0, Vt))//����FindWay����������ҵ�·������õ���������·��path������õ�������Ϣ����ʾѰ·����
	{
		//Ѱ·����
		FindWay_error(500,500);
		getch();
		exit(1);
	}
	else
	{
		//��path�е�Ԫ�ص�����ѹ��S
		for(i = LocateVex(G, n, Vt); i != -1; i = path[i].former)     //���յ㿪ʼ��ǰ���ݣ�i!=-1˵��������ʼ���Ҫ����ʼ����ջ
		{
		    Push(&S, path[i]);
		}

		//����S��Ԫ�أ��������ƶ�
		while(S.top != S.bottom)    //ջ�ǿ�
		{
            Pop(&S, t);             //��ջһ���㣬���õ����ڸ��������һ����
            case_state->direction = t->direction;     //�Ƿ���֪����һ��������һ������ʲô�����߶�������¸�move0��ʱ���֪�����򣬿������������������겻��Ҫ
            move0(case_state, casetype);              //ÿһ�����ƶ�ͨ��move0ʵ��
		}
	}

	//�ͷŶ�
	free(t);
    free(path);
    DestroyStack(&S);   //����ջ

	//��ָ����Ϊ��
	path = NULL;
	t = NULL;
}

