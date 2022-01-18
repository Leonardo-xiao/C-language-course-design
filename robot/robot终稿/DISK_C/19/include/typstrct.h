#ifndef typstrct.h
#define typstrct.h

///�����˺��˵Ľṹ��,�������������Ϣ
typedef struct{

	char hand;                      //����ǰΪ1������Ϊ0
	char hand_left;
	char hand_right;                //�ֵ��˶�����,Ϊ��
	char catch_th;                  //�Ƿ���1�����������˵���������û������
	int x;			                 //x,y��xpixel,ypixel���ǻ�����x���ġ�y���ϵ�λ������
	int y;                          //С����16*19
	int xpixel;
	int ypixel;                     //���ص㣬1024*768
	int direction;                  //����1Ϊ�ң�2Ϊ��3Ϊ�ϣ�4Ϊ��
}CASE;

///��

typedef int QElemtype;  //�ӵ�Ԫ������

typedef struct Qnode    //QElemtype�Ƕ�����Ԫ�ص����ͣ�Qnode����������ͣ��ں�һ��Ԫ��һ��ָ����
{
    QElemtype data;
    struct Qnode *next;
}Qnode, *QueuePtr;

typedef struct          //��ָ��
{
    QueuePtr front; //��ͷָ��
    QueuePtr rear;  //��β
}LinkQueue;

///ͼ

typedef struct LinkNode //����
{
    int x;
    int y;
    char direction;  //1Ϊ�ң�2Ϊ��3Ϊ�ϣ�4Ϊ��
    struct LinkNode *next;
}LNode;

typedef struct Node     //G�����Ԫ�����ͣ��Լ�G������
{
    int x;  //x���꣨�����꣬40*40��block��
    int y;
    LNode *next;    //ָ�����
}VType, *Graph;     //Graph���Ƕ���һ��VType�͵�����

typedef struct
{
    int x;
    int y;
}Axis;              //x��y����

///Ѱ·��Ҫ����
typedef struct
{
    int former;
    int direction;
}PathType;          //����path�����ͣ���һά��ǰһ���ڵ����������һ����ʾ����

///ջ

typedef PathType SElemtype;     //ÿ��ջ�ڵ��data���������ͣ�����PathType����ΪҪ��ջ��ջ�ľ���path

typedef struct StackNode        //ջ�ڵ�
{
    SElemtype data;              //ָ��ջ�ף�����ջ����㣬��ջ����֮ǰ������֮��baseֵΪNULL
    struct StackNode  *next;     //ָ��ջ��
}SNode;

typedef struct LinkStack        //��ʽջ
{
    SNode *bottom;      //ָ��ջ��
    SNode *top;         //ָ��ջ��
}LkStack;


typedef struct ChTab
{
    int qhwh;
    char str[7];
}CH;

typedef struct EnTab
{
    int qhwh;
    char str;
}EN;

typedef struct Coordinate
{
    int x;
    int y;
} Coordinate;

typedef struct Area
{
    Coordinate lt;
    Coordinate rb;
} Area;

typedef struct USERS{
	char account[11];
	char code[11];
    struct USERS *next;
}USERS;

typedef struct tagBITMAPFILEHEADER{
	int bfType;
	long bfsize;//�ļ���С����λΪ�ֽ�
	int bfReserved1;//����������Ϊ0
	int bfReserved2;//����������Ϊ0
	long bfOffBits;
}BITMAPFILEHEADER;

/*BMP��Ϣͷ�ṹ*/
typedef struct tagBITMAPINFOHEADER{
	long biSize; /*��Ϣͷ��С*/
	long biWidth; /*ͼ����*/
	long biHeight; /*ͼ��߶�*/
	int biPlanes; /*����Ϊ1*/
	int biBitCount; /*ÿ����λ��������Ϊ1��4��8��24*/
	long	biCompression;	/*  ѹ������ */
	long	biSizeImage;	/* ʵ��ͼ���С�������� 4 �ı��� */
	long	biXPelsPerMeter;	/*  ˮƽ����ÿ�������� */
	long	biYPelsPerMeter;	/*  ��ֱ����ÿ��������*/
	long	biClrUsed;	/*  ������ɫ��*/
	long	biClrImportant;	/* ��Ҫ����ɫ�� */
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD
{
	unsigned char B;	/*��ɫ������RED��д*/
	unsigned char G;	/*��ɫ������GREEN��д*/
	unsigned char R;	/*��ɫ������BLUE��д*/
	unsigned char reserved;		/*������*/
} RGBQUAD;

typedef struct{
	int x;                          //left_up
	int y;                          //left_up
	int height;
	int wide;
	int click;
	int over;
}BUTTONS;

#endif // typstrct

