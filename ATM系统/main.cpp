#include <graphics.h>
#include <math.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#include<stdlib.h>
#include<stdio.h>
#include <ege/sys_edit.h>
#include <time.h>
#include <pthread.h>
#define N 20

struct account
{
	int id;
	char name[20];
	char password[7];
	float balance;
	int lock; //���� ��0����δ����1�������� 
};


struct CircleButton
{
	int x, y;		/* Բ��*/
	int width;
	int height;		/* �뾶*/
	bool pressed;	/* �Ƿ���*/
};

// �жϵ�(x, y)�Ƿ��ڰ�ť��������ڲ�
bool insideButton(const CircleButton* button, int x, int y);

// �������а�ť
void drawButton(const CircleButton buttonArray[], int length);

// ���� (x, y) ���ڵİ�ť�����ذ�ťID, û�з��� -1
int searchButton(int x, int y, const CircleButton buttonArray[], int length);
void noke(int i);
// ����
void draw();
void draw5();
void draw1();
void nock(int i);
int login3();
void deposit();
void withdraw();
void music();
void draw7();
void draw8();
struct account ACC[N];//�û����� 
int count=0;//��¼�û�����
int position; //��¼�û�λ�� 
time_t tt_;
struct tm *tm_ ;
char output[20]; 
void init();
struct account convert(char *p);
int login(); 
void transfer(); 
void withdraw();
void deposit();
void change();  
void draw3();
void draw4();
int login2();
void transfer();
void change();
void draw6();
void draw7();
void noce(int i); 
int login4();
int login5();
int login6(); 
void backmode();
void draw9();
void drawButton3(const CircleButton buttonArray[], int length);

#define BUTTON_SIZE 1
#define BUTTON_SIZE3 2
#define BUTTON_ID_NONE -1
#define BUTTON_SIZE2 6

//���尴ť��ȷ������
CircleButton buttonArray[BUTTON_SIZE];
CircleButton buttonArray2[BUTTON_SIZE2];
CircleButton buttonArray3[BUTTON_SIZE3];

// ���°�ťID
int pressButtonId = BUTTON_ID_NONE;



// ����������ת��Ϊ��Ա���� 
 struct account convert(char *p)  
 {
 	struct account a;
 	char *b;
 	b=strtok(p,";");
 	sscanf(b,"%d",&a.id);
 	b=strtok(NULL,";");
 	sscanf(b,"%s",a.name);
 	b=strtok(NULL,";");
 	sscanf(b,"%s",a.password);
 	b=strtok(NULL,";");
 	sscanf(b,"%f",&a.balance);
 	b=strtok(NULL,";");
 	sscanf(b,"%d",&a.lock);
 	return a;
 }
 
 //��������ȡ��ʹ�� 
void music()
{
	mciSendString("open music\\1.mp3 alias lx1",NULL,0,NULL);
	mciSendString("open music\\2.mp3 alias lx2",NULL,0,NULL);
	mciSendString("open music\\3.mp3 alias lx3",NULL,0,NULL);
	mciSendString("open music\\4.mp3 alias lx4",NULL,0,NULL);
	mciSendString("open music\\5.mp3 alias lx5",NULL,0,NULL);
	mciSendString("open music\\6.mp3 alias lx6",NULL,0,NULL);
	mciSendString("open music\\61.mp3 alias lx61",NULL,0,NULL);
	mciSendString("open music\\7.mp3 alias lx7",NULL,0,NULL);
	mciSendString("open music\\8.mp3 alias lx8",NULL,0,NULL);
	mciSendString("open music\\9.mp3 alias lx9",NULL,0,NULL);
	mciSendString("open music\\10.mp3 alias lx10",NULL,0,NULL);
	mciSendString("open music\\11.mp3 alias lx11",NULL,0,NULL);
	mciSendString("open music\\12.mp3 alias lx12",NULL,0,NULL);
	mciSendString("open music\\13.mp3 alias lx13",NULL,0,NULL);
	mciSendString("open music\\14.mp3 alias lx14",NULL,0,NULL);
	mciSendString("open music\\15.mp3 alias lx15",NULL,0,NULL);
	mciSendString("open music\\16.mp3 alias lx16",NULL,0,NULL);
	mciSendString("open music\\17.mp3 alias lx17",NULL,0,NULL);		
}
 

 //���ļ����ļ�������ȡ������֮�� 
 
void init()
{
	FILE *fp;
	char temp[50];
	fp=fopen("account_in.txt","r");
	if(fp==NULL)
	{
		printf("ϵͳ��ʼ��ʧ�ܣ����飡");
		exit(0);
	}  
	while(fgets(temp,50,fp)) 
	{
		ACC[count]=convert(temp);
		count++;
	}
	fclose(fp);
 } 



//���ñ��� 
PIMAGE lx;
void backmode()
{
	lx=newimage();
	getimage(lx,"img\\1.jpg");  
	putimage(0,0,lx);
}

void draw2();


//�����水ť���жϺͰ��°�ť��ĺ������� 
int login()
{
	initgraph(640, 480, INIT_RENDERMANUAL);
	setcaption("����ATM4.5�汾");
	backmode();
	//setbkcolor(RGB(255, 255, 0));
	setbkmode(TRANSPARENT);
	
	ege_enable_aa(true);

	for (int i = 0; i < BUTTON_SIZE; i++) {
		buttonArray[i].x = (i % 2 * 2 + 1) * 1050 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 300;
		buttonArray[i].width = 100;
		buttonArray[i].height = 50;
		buttonArray[i].pressed = false;
	}

	pressButtonId = BUTTON_ID_NONE;
	bool redraw = true;

	for (; is_run(); delay_fps(60)) {
			draw3();
		while (mousemsg()) {
			mouse_msg msg = getmouse();// �ж����������£��������ȷ��λ�ã�ͬʱ�ж��Ƿ�Ϊ��ť����	// ̧����������״̬
			if (msg.is_left()) {
				if (msg.is_down()) {
						// ����Ƿ��а�ť������
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE);
						int i=btnId;
						noke(i);
					// �������µİ�ť����Ϊ����״̬
					if (btnId != BUTTON_ID_NONE) {
						
						pressButtonId = btnId;
						buttonArray[pressButtonId].pressed = true;
						redraw = true;
						music();
						mciSendString("play lx1",NULL,1,NULL);
						while(1)
						{
							
							int j=login2();
							switch(j){
								case 0:login();break; 
								case 1:login3();break;
								case 2:draw2();login();break;	
							}
						
						}	
					}
					
				}
				else {
					//���̧������а�ť�����£��������״̬
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// �ж��Ƿ���Ҫ�ػ棬���ٲ���Ҫ�Ļ��Ʋ���
	}

	return 0;
}
char mc[100];
/*��¼������ж�*/ 
int login2()
{
	init(); 
	cleardevice();
	backmode();

	draw();
	sys_edit editBox;
	editBox.create(false);					
	editBox.move(205, 197);				
	editBox.size(240, 35);				
	editBox.setbgcolor(WHITE);
	editBox.setcolor(BLACK);
	editBox.setfont(25, 0, "����");
	editBox.setmaxlen(100);			
	editBox.visable(true);				
	editBox.setfocus();	
	for(int z=0;z<6;z++)
	{
		char x=getch();	
	}
						
	flushkey();	
	
	char strBuffer[100];
	
	for (;is_run(); delay_fps(60)) 
	{
			
		bool exit = false;
		
			//��ȡ���������ݣ����浽�ַ�����strBuffer[]��
			editBox.gettext(100,  strBuffer);
			int a,b=2;
			sscanf(strBuffer, "%d", &a);
			int i,h=1; 
			for(i=0;i<count;i++)
			{
				if(ACC[i].id==a)
				{
					position=i;
					setcolor(RED);
					setfont(25, 0, "����");
					settextjustify(LEFT_TEXT, TOP_TEXT);	
					xyprintf(480, 197, "������ȷ",b);
					if(ACC[i].lock==1)
					{
						return 2;
					}
					else
					{
						for(int r=0;r<3;r++)
						{
							flushkey();
							sys_edit editBox1;
							editBox1.create(true);						
							editBox1.move(205, 245);		
							editBox1.size(240, 35);		
							editBox1.setbgcolor(WHITE);
							editBox1.setcolor(BLACK);
							editBox1.setfont(25, 0, "����");
							editBox1.setmaxlen(100);		
							editBox1.visable(true);
							editBox.setreadonly(true);
							editBox1.settext("");
							int t=1;
							for(int c=0;c<100;)
							{
								char ch=getch();
								if(ch==13)
								{
									break;
								}
								if(ch==8)
								{
									if(c!=0)
									{
										c--;
										t=t-2;
									}	
									if(t<=0)
									{
										editBox1.settext("");
										t=0;
									}
										
								}
								else
								{
									mc[c]=ch;
									c++;
									flushkey();
								}	
								if(t==1)
									editBox1.settext("*");
								else
									if(t==2)
										editBox1.settext("**");
									else
										if(t==3)
											editBox1.settext("***");
										else
											if(t==4)
												editBox1.settext("****");
											else
												if(t==5)
													editBox1.settext("*****");
												else
													if(t==6)
														editBox1.settext("******");
								t++;
							}
							flushkey();
							for (;is_run(); delay_fps(60))
							{
								bool exit = false;
								if(strcmp(mc,ACC[i].password)==0)
								{
									
									music();
									mciSendString("play lx2",NULL,1,NULL);
									return 1;
								}
								else
								{
									if(b<=0)
									{	editBox.destory();//���� 
										//editBox1.destory(); 
										ACC[position].lock=1;
										FILE *p;
										int i;
										p=fopen("account_in.txt","r+");
										for(i=0;i<count;i++)
											fprintf(p,"%d;%s;%s;%.2f;%d\n",ACC[i].id,ACC[i].name,ACC[i].password,ACC[i].balance,ACC[i].lock);
										fclose(p);
								   		return 2;
									}
									else
									{
										cleardevice();
										backmode();
										setcolor(BLACK);
										draw();
										setfont(25, 0, "����");
										settextjustify(LEFT_TEXT, TOP_TEXT);	
										xyprintf(185, 400, "�������������%d�λ���",b);
										music();
										mciSendString("play lx14",NULL,1,NULL);
										b--;
										flushkey();
										break;	
									}
									
								}
							}
							
						}	
					}
					
				}
				
			}
			if(i>=count)
			{
				editBox.destory();
				draw8();
				return 0;
			}			
			break;
		}	
		 
			
	}
			
	//flushkey();//��������
	//editBox.destory();//���� 
	//editBox1.destory(); 

	
 //} 


//����ť����ʱ���İ�ť�ı�����ɫ
//��ʾ�����µ�״̬ 
void noke(int i)
{
	if(i<6)
	{
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		printf("%d",i); 
		buttonArray[i].x = (i% 2 * 2 + 1) * 1050 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 300;
		buttonArray[i].width = 100;
		buttonArray[i].height = 50;
		setfillcolor(RGB(213,247, 245));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//���ֱ��� 
		setfont(20,10,"����");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "��¼");
		Sleep(150);
	}
  }  

// �����������ť����Ч��Χ 
bool insideButton(const CircleButton* button, int x, int y)
{
	return (x >= button->x) && (y >= button->y)
		&& (x < button->x + button->width)
		&& (y < button->y + button->height);
}

//���ư�ť 
void drawButton(const CircleButton buttonArray[], int length)
{ 
	//setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	//setcolor(WHITE);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	
	//setfont(36, 0, "");
	//color_t lastFillColor = getfillcolor();
	for (int i = 0; i < length; i++) {
		//����״̬���в�ͬ�Ļ��ƣ����ﰴ״̬�ı���ɫ
		//Ϊ�˼�����ɫ���ò������е��Ż��������������ƿ��п���
		// ���ư�ť
		setfillcolor(RGB(250,200, 0));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//���ֱ��� 
		setfont(20,10,"����");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "��¼");
	}
}

//�жϰ�ť�Ƿ���Ҫ�ػ� 
int searchButton(int x, int y, const CircleButton buttonArray[], int length)
{
	int buttonId = BUTTON_ID_NONE;

	for (int i = 0; i < length; i++) {
		if (insideButton(&buttonArray[i], x, y)) {
			buttonId = i;
			break;   //�˳����Ѿ���⵽������İ�ť���ټ��
		}
	}

	return buttonId;
}

//����ͼ�ν����ϵ��������� 
void draw()
{
	//���� 
	//drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(30, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(130, 200, "�˺ţ�");
	xyprintf(130, 250, "���룺");
	xyprintf(180, 100, "���������е�¼����");
	
}
void draw2()
{
	//���� 
	cleardevice();
	//drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(24, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	backmode();
	xyprintf(120, 200, "�ÿ����ѱ�������������ϵ���й�����Ա����������");
	music();
	mciSendString("play lx15",NULL,1,NULL);
	Sleep(2000);
	
}
void draw3()
{
	//���� 
	drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(40, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(150, 100, "��ӭ���빷�������У�����");
	
}


void draw4()
{
	//���� 
	//drawButton(buttonArray, BUTTON_SIZE);
	backmode();
	setcolor(BLACK);
	setfont(25, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);	
	xyprintf(185, 400, "�������");
	music();
	mciSendString("play lx14",NULL,1,NULL);
	Sleep(2000);
}
void draw5()
{
	//���� 
	cleardevice();
	//drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(24, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	backmode();
	xyprintf(0, 0, "��¼�ɹ�������");
	xyprintf(0,30,"�𾴵�%s���������ã�",ACC[position].name);
	xyprintf(0,60,"�������Ϊ��%.2f",ACC[position].balance);
	Sleep(1000);
}


void draw6()
{
	//���� 
	cleardevice();
	//drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(40, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	setcolor(BLACK);
	backmode();
	xyprintf(225,100, "�����޸�");
	setfont(24, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(115,200, "������:");
	xyprintf(115, 240, "������:");
	xyprintf(20, 280, "�ٴ�����������:");
	music();
	mciSendString("play lx9",NULL,1,NULL);
	
}


void draw7()
{
	//���� 
	cleardevice();
	backmode();
	setcolor(BLACK);
	setfont(40, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	backmode();
	xyprintf(185, 200, "ת���˺Ų���Ϊ�Լ���");
/*	music();
	mciSendString("play lx14",NULL,1,NULL);*/
	Sleep(2000);
}


void draw8()
{
	//���� 
	cleardevice();
	backmode();
	setcolor(BLACK);
	setfont(40, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	backmode();
	xyprintf(185, 200, "�˺Ŵ��󣡣�");
/*	music();
	mciSendString("play lx14",NULL,1,NULL);*/
	Sleep(2000);
}

//���ܽ����ѡ���Ƿ���Ҫ���� 
int login4()
{
	initgraph(640, 480, INIT_RENDERMANUAL);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	ege_enable_aa(true);

	for (int i = 0; i < BUTTON_SIZE3; i++) {
		buttonArray[i].x = (i % 2 * 2 + 1) * 500 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 300;
		buttonArray[i].width = 100;
		buttonArray[i].height = 50;
		//buttonArray[i].radius = 50;
		buttonArray[i].pressed = false;
	}

	pressButtonId = BUTTON_ID_NONE;

	bool redraw = true;

	for (; is_run(); delay_fps(60)) {

		while (mousemsg()) {
			mouse_msg msg = getmouse();// �ж����������£��������ȷ��λ�ã�ͬʱ�ж��Ƿ�Ϊ��ť����	// ̧����������״̬
			if (msg.is_left() && msg.is_down()) {
				if (msg.is_down()) {
						// ����Ƿ��а�ť������
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE3);
						int i=btnId;
						noce(i);
					// �������µİ�ť����Ϊ����״̬
					if (btnId != BUTTON_ID_NONE) {
						pressButtonId = btnId;
						buttonArray[pressButtonId].pressed = true;
						redraw = true;
						switch(btnId)
						{
							case 0:transfer();break;
							case 1:login3();break;
						}
					}
				}
				else {
					//���̧������а�ť�����£��������״̬
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// �ж��Ƿ���Ҫ�ػ棬���ٲ���Ҫ�Ļ��Ʋ���
		if (redraw) {
			cleardevice();
			draw9();
			redraw = false;
		}
	}

	return 0;
}


//���ܽ�������ѡ�� 
int login5()
{
	initgraph(640, 480, INIT_RENDERMANUAL);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	ege_enable_aa(true);

	for (int i = 0; i < BUTTON_SIZE3; i++) {
		buttonArray[i].x = (i % 2 * 2 + 1) * 500 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 300;
		buttonArray[i].width = 100;
		buttonArray[i].height = 50;
		//buttonArray[i].radius = 50;
		buttonArray[i].pressed = false;
	}

	pressButtonId = BUTTON_ID_NONE;

	bool redraw = true;

	for (; is_run(); delay_fps(60)) {

		while (mousemsg()) {
			mouse_msg msg = getmouse();// �ж����������£��������ȷ��λ�ã�ͬʱ�ж��Ƿ�Ϊ��ť����	// ̧����������״̬
			if (msg.is_left() && msg.is_down()) {
				if (msg.is_down()) {
						// ����Ƿ��а�ť������
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE3);
						int i=btnId;
						noce(i);
					// �������µİ�ť����Ϊ����״̬
					if (btnId != BUTTON_ID_NONE) {
						pressButtonId = btnId;
						buttonArray[pressButtonId].pressed = true;
						redraw = true;
						switch(btnId)
						{
							case 0:deposit();break;
							case 1:login3();break;
						}
					}
				}
				else {
					//���̧������а�ť�����£��������״̬
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// �ж��Ƿ���Ҫ�ػ棬���ٲ���Ҫ�Ļ��Ʋ���
		if (redraw) {
			cleardevice();
			draw9();
			redraw = false;
		}
	}

	return 0;
}


//���ܽ�������ѡ�� 
int login6()
{
	initgraph(640, 480, INIT_RENDERMANUAL);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	ege_enable_aa(true);

	for (int i = 0; i < BUTTON_SIZE3; i++) {
		buttonArray[i].x = (i % 2 * 2 + 1) * 500 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 300;
		buttonArray[i].width = 100;
		buttonArray[i].height = 50;
		//buttonArray[i].radius = 50;
		buttonArray[i].pressed = false;
	}

	pressButtonId = BUTTON_ID_NONE;

	bool redraw = true;

	for (; is_run(); delay_fps(60)) {

		while (mousemsg()) {
			mouse_msg msg = getmouse();// �ж����������£��������ȷ��λ�ã�ͬʱ�ж��Ƿ�Ϊ��ť����	// ̧����������״̬
			if (msg.is_left() && msg.is_down()) {
				if (msg.is_down()) {
						// ����Ƿ��а�ť������
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE3);
						int i=btnId;
						noce(i);
					// �������µİ�ť����Ϊ����״̬
					if (btnId != BUTTON_ID_NONE) {
						pressButtonId = btnId;
						buttonArray[pressButtonId].pressed = true;
						redraw = true;
						switch(btnId)
						{
							case 0:withdraw();break;
							case 1:login3();break;
						}
					}
				}
				else {
					//���̧������а�ť�����£��������״̬
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// �ж��Ƿ���Ҫ�ػ棬���ٲ���Ҫ�Ļ��Ʋ���
		if (redraw) {
			cleardevice();
			draw9();
			redraw = false;
		}
	}

	return 0;
}

//���İ�ť����ɫ����ʾ����ť�����µ�״̬ 
void noce(int i)
{
	if(i<6)
	{
		settextjustify(CENTER_TEXT, CENTER_TEXT); 
		buttonArray[i].x = (i% 2 * 2 + 1) * 500 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 300;
		buttonArray[i].width = 100;
		buttonArray[i].height = 50;
		setfillcolor(RGB(213,247, 245));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//���ֱ��� 
		setfont(20,10,"����");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "��");
		if(i==1)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "��");
		Sleep(150);
	}
  }  



void draw9()
{
	//���� 
	backmode();
	drawButton3(buttonArray, BUTTON_SIZE3);
	setcolor(BLACK);
	setfont(24, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(195, 200, "�Ƿ�Ҫ�����˲�����");
	
}

//���ܽ��棬���ѡ��
//����ܲ�ִ�� 

int login3()
{
	initgraph(640, 480, INIT_RENDERMANUAL);
	backmode();
	setbkcolor(RGB(255, 255, 0));
	setbkmode(TRANSPARENT);draw1();
	ege_enable_aa(true);

	for (int i = 0; i < BUTTON_SIZE2; i++) {
		buttonArray[i].x = (i % 2 * 2 + 1) * 500 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 120;
		buttonArray[i].width = 100;
		buttonArray[i].height = 50;
		//buttonArray[i].radius = 50;
		buttonArray[i].pressed = false;
		
	}
	pressButtonId = BUTTON_ID_NONE;

	bool redraw = true;
	for (; is_run(); delay_fps(60)) {
		
		while (mousemsg()) {
			mouse_msg msg = getmouse();// �ж����������£��������ȷ��λ�ã�ͬʱ�ж��Ƿ�Ϊ��ť����	// ̧����������״̬
			if (msg.is_left() && msg.is_down()) {
				if (msg.is_down()) {
						// ����Ƿ��а�ť������
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE2);
						int i=btnId;
						nock(i);
					// �������µİ�ť����Ϊ����״̬
					if (btnId != BUTTON_ID_NONE) {
						pressButtonId = btnId;
						buttonArray[pressButtonId].pressed = true;
						redraw = true;
						switch(pressButtonId)
						{
							case 0:break;
							case 1:transfer();break;
							case 2:deposit();break;
							case 3:withdraw();break;
							case 4:change();break;
							case 5:login();break;
						}
					}
					
				}
				else {
					//���̧������а�ť�����£��������״̬
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// �ж��Ƿ���Ҫ�ػ棬���ٲ���Ҫ�Ļ��Ʋ���
		if (redraw) {
			cleardevice();
			draw1();
			redraw = false;
		}
	}

	return 0;
}




//���ܽ��水ť������ʱ������ɫ 
void nock(int i)
{
	if(i<6)
	{
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		printf("%d",i); 
		buttonArray[i].x = (i% 2 * 2 + 1) * 500 / 4;
		buttonArray[i].y = (i / 2) * 320 / 3 + 120;
		buttonArray[i].width = 100;
		buttonArray[i].height = 50;
		setfillcolor(RGB(213,247, 245));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//���ֱ��� 
		setfont(20,10,"����");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "����");
		if(i==1)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "ת��");
		if(i==2)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "��Ǯ");
		if(i==3)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "ȡǮ");
		if(i==4)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "����");
		if(i==5)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "�˳�");	
		Sleep(150);
	}
  }  

//���ƹ��ܽ��水ť 
void drawButton1(const CircleButton buttonArray[], int length)
{ 
	//setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	//setcolor(WHITE);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	//setfont(36, 0, "");
	//color_t lastFillColor = getfillcolor();
	for (int i = 0; i < length; i++) {
		//����״̬���в�ͬ�Ļ��ƣ����ﰴ״̬�ı���ɫ
		//Ϊ�˼�����ɫ���ò������е��Ż��������������ƿ��п���
		// ���ư�ť
		setfillcolor(RGB(250,200, 0));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//���ֱ��� 
		setfont(20,10,"����");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "����");
		if(i==1)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "ת��");
		if(i==2)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "��Ǯ");
		if(i==3)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "ȡǮ");
		if(i==4)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "����");
		if(i==5)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "�˳�");	
	}
}


void draw1()
{
	backmode();
	drawButton1(buttonArray, BUTTON_SIZE2);
	setcolor(BLACK);
	setfont(24, 0, "����");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(350, 0, "��¼�ɹ�������");
	xyprintf(350,30,"�𾴵�%s���������ã�",ACC[position].name);
	xyprintf(350,60,"�������Ϊ��%.2f",ACC[position].balance);
	
}



//�����Ƿ�����ù��ܵİ�ť 
void drawButton3(const CircleButton buttonArray[], int length)
{ 
	//setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	//setcolor(WHITE);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	//setfont(36, 0, "");
	//color_t lastFillColor = getfillcolor();
	for (int i = 0; i < length; i++) {
		//����״̬���в�ͬ�Ļ��ƣ����ﰴ״̬�ı���ɫ
		//Ϊ�˼�����ɫ���ò������е��Ż��������������ƿ��п���
		// ���ư�ť
		setfillcolor(RGB(250,200, 0));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//���ֱ��� 
		setfont(20,10,"����");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "��");
		if(i==1)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "��");
	}
}


//ת�˹��� 
void transfer()
{
	
	cleardevice();
	flushkey();  
	backmode();
	
	sys_edit editBox;
	editBox.create(false);	//false���У�true����				
	editBox.move(200, 225);				
	editBox.size(240, 35);				
	editBox.setbgcolor(WHITE);
	editBox.setcolor(BLACK);
	editBox.setfont(25, 0, "����");
	editBox.setmaxlen(100);			
	editBox.visable(true);				
	editBox.setfocus();
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	music();
	mciSendString("play lx3",NULL,1,NULL);
	setfont(35,0,"����");
	xyprintf(320 ,200,"������ת���˺ţ�");
	 	
	for (;is_run(); delay_fps(60))
	{
		bool exit = false;
		while (kbmsg()) 
		{
			key_msg msg = getkey();

			if ((msg.key == key_enter) && (msg.msg == key_msg_up))
			{
				exit = true;
				break;
			}			
		}
		
		char strBuffer[100];//�˺� 

		
		if(exit)
		{
			editBox.gettext(100,strBuffer);
			int a;
			sscanf(strBuffer, "%d", &a);
			
			editBox.destory();
			
			int i;
			if(a==ACC[position].id)
			{
				draw7();
				break;
			}
			else
				for(i=0;i<count;i++)
				{
					if(a==ACC[i].id)
					{
					
						cleardevice();  
						backmode();
					
						sys_edit editBox;
						editBox.create(false);	//false���У�true����				
						editBox.move(200, 225);				
						editBox.size(240, 35);				
						editBox.setbgcolor(WHITE);
						editBox.setcolor(BLACK);
						editBox.setfont(25, 0, "����");
						editBox.setmaxlen(100);			
						editBox.visable(true);				
						editBox.setfocus();
						setbkmode(TRANSPARENT);
						setcolor(BLACK);
						music();
						mciSendString("play lx5",NULL,1,NULL);
						setfont(35,0,"����");
						xyprintf(320 ,200,"������ת�˽�");
					
					
						for (;is_run(); delay_fps(60))
						{
							bool exit1 = false;
							while (kbmsg()) 
							{
								key_msg msg = getkey();
					
								if ((msg.key == key_enter) && (msg.msg == key_msg_up))
								{
									exit1 = true;
									break;
								}			
							}
						
							char strBuffer1[100];//��� 		
										
							if(exit1)
							{
								editBox.gettext(100,strBuffer1);
								int b;
								sscanf(strBuffer1, "%d", &b);
								
								editBox.destory();
							
								if(b<=ACC[position].balance)
								{
								
									ACC[i].balance+=b;
									ACC[position].balance-=b;
																
									FILE *p;
									int i;
									p=fopen("account_in.txt","r+");
									for(i=0;i<count;i++)
										fprintf(p,"%d;%s;%s;%.2f;%d\n",ACC[i].id,ACC[i].name,ACC[i].password,ACC[i].balance,ACC[i].lock);
									fclose(p);
								
									for(i=2;i>=1;i--)
									{
										cleardevice();
										backmode();
										
										setbkmode(TRANSPARENT);
										setcolor(BLACK);
										setfont(40,0,"����");
										xyprintf(320 ,200,"ת�˳ɹ���");
										setfont(30,0,"����");
										setcolor(BLACK);
										music();
										mciSendString("play lx19",NULL,1,NULL);
										setfont(25,0,"����");
										xyprintf(305 ,235,"(ϵͳ%d����˳�����)",i);
										flushkey();
										Sleep(1000);		
									}
									login4(); 
									break;						
								}
								else
								{
									editBox.destory();
									cleardevice();
									backmode();
									setbkmode(TRANSPARENT);
									setcolor(RED);
									setfont(40,0,"����");
									xyprintf(320 ,200,"���㣡");
									music();
									mciSendString("play lx16",NULL,1,NULL);
									flushkey();
									Sleep(1000);
									break;
								}							
							}				
						}
						break;
	
					}
				}
			
			if(i==count)
			{	
				editBox.destory();
				for(i=5;i>=1;i--)
				{
					cleardevice();
					backmode();
					
					setbkmode(TRANSPARENT);
					setcolor(RED);
					setfont(40,0,"����");
					xyprintf(320 ,200,"���޴˺ţ�");
					setfont(30,0,"����");
					setcolor(BLACK);
					music();
					mciSendString("play lx4",NULL,1,NULL);
					setfont(25,0,"����");
					xyprintf(305 ,235,"(ϵͳ%d����˳�����)",i);
					Sleep(1000);
				}
				//lushkey();
				break;
				
			}
			break;	
		} 
	}
	
	
} 


//���� 
void deposit()
{
	cleardevice();
	flushkey();  
	backmode();
	
	sys_edit editBox;
	editBox.create(false);	//false���У�true����				
	editBox.move(200,225);				
	editBox.size(240, 35);				
	editBox.setbgcolor(WHITE);
	editBox.setcolor(BLACK);
	editBox.setfont(25, 0, "����");
	editBox.setmaxlen(100);			
	editBox.visable(true);				
	editBox.setfocus();
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	music();
	mciSendString("play lx6",NULL,1,NULL);
	setfont(35,0,"����");
	xyprintf(320,170,"���������");
	xyprintf(320,200,"(ÿ���޴�30000RMB�ұ���ȫΪ100RMB)"); 	
	
	char strBuffer[100];
	for (;is_run(); delay_fps(60))
	{
		bool exit = false;
		while (kbmsg()) 
		{
			key_msg msg = getkey();

			if ((msg.key == key_enter) && (msg.msg == key_msg_up))
			{
				exit = true;
				break;
			}			
		}
		if(exit)
		{
			editBox.gettext(100,strBuffer);
			int a;
			sscanf(strBuffer, "%d", &a);
			if(a<=30000)
			{
				if(a%100==0)
				{
					ACC[position].balance+=a;
			
					FILE *p;
					int i;
					p=fopen("account_in.txt","r+");
					for(i=0;i<count;i++)
						fprintf(p,"%d;%s;%s;%.2f;%d\n",ACC[i].id,ACC[i].name,ACC[i].password,ACC[i].balance,ACC[i].lock);
					fclose(p);
					
					editBox.destory();
					
					for(i=2;i>=1;i--)
					{
						cleardevice();
						backmode();
						
						setbkmode(TRANSPARENT);
						setcolor(BLACK);
						setfont(40,0,"����");
						xyprintf(320,200,"���ɹ���");
						setfont(30,0,"����");
						setcolor(BLACK);
						music();
						mciSendString("play lx7",NULL,1,NULL);
						setfont(25,0,"����");
						xyprintf(305,235,"(ϵͳ%d����˳�����)",i);
						Sleep(1000);
						//login4();
					}
					login5();
					//flushkey();
					break;
				 } 
				 else
				 {
				 	cleardevice();
					backmode();
						
					setbkmode(TRANSPARENT);
					setcolor(BLACK);
					setfont(40,0,"����");
					xyprintf(320,200,"��Ϊ����������ȷ�Ϻ������룡");
					Sleep(2000);
					break; 
				 }
				
			 } 
			 else
			{
				cleardevice();
				backmode();
					
				setbkmode(TRANSPARENT);
				setcolor(BLACK);
				setfont(40,0,"����");
				xyprintf(320,200,"����ÿ���޴��");
				Sleep(2000);
				break; 
			}
			
							
		}
		
	}
	 
	
}  


//ȡ��� 
void withdraw()
{
	cleardevice();
	flushkey();
	backmode();
	sys_edit editBox;
	editBox.create(false);	//false���У�true����				
	editBox.move(200,225);				
	editBox.size(240, 35);				
	editBox.setbgcolor(WHITE);
	editBox.setcolor(BLACK);
	editBox.setfont(25, 0, "����");
	editBox.setmaxlen(100);			
	editBox.visable(true);				
	editBox.setfocus();
	setbkmode(TRANSPARENT);
	
	setcolor(BLACK);
	music();
	mciSendString("play lx8",NULL,1,NULL);
	setfont(35,0,"����");
	xyprintf(320 ,170,"������ȡ���");
	xyprintf(320 ,200,"(ȡ������2000������Ϊ��������"); 
	
	char strBuffer[100];
	for (;is_run(); delay_fps(60)) 
	{
		
		bool exit = false;
		while (kbmsg()) 
		{
			key_msg msg = getkey();

			if ((msg.key == key_enter) && (msg.msg == key_msg_up))
			{
				exit = true;
				break;
			}
					
		}
		if(exit)
		{ 
			editBox.gettext(100,  strBuffer);
			int a;
			int i; 
			char ch;
			sscanf(strBuffer, "%d", &a);
			editBox.destory();
			cleardevice();
			if(a<=2000)
			{
				if(a%100==0)
				{
					if(a<=ACC[position].balance)
					{
						ACC[position].balance-=a; 
						editBox.destory();
						cleardevice();										
						for(i=2;i>=1;i--)
						{
							cleardevice();			
							setbkmode(TRANSPARENT);
							backmode();
							setcolor(BLACK);
							setfont(40,0,"����");
							xyprintf(320 ,200,"ȡ��ɹ���");
							setfont(30,0,"����");
							setcolor(BLACK);
							music();
							mciSendString("play lx61",NULL,1,NULL);
							setfont(25,0,"����");
							xyprintf(305,235,"(ϵͳ%d����˳�����)",i);
							Sleep(1000);
						}										
						FILE *p;
						int i;
						p=fopen("account_in.txt","r+");
						for(i=0;i<count;i++)
							fprintf(p,"%d;%s;%s;%.2f;%d\n",ACC[i].id,ACC[i].name,ACC[i].password,ACC[i].balance,ACC[i].lock);
						fclose(p);
						flushkey();
						login6();//withdraw();	
						break;		
					
					 } 
					else
					{
						editBox.destory();
						cleardevice();
						backmode();
						setbkmode(TRANSPARENT);
						setcolor(RED);
						setfont(40,0,"����");
						xyprintf(320 ,200,"��Ǹ,���㣡");
						music();
						mciSendString("play lx16",NULL,1,NULL);
						Sleep(1000);
						getch();
						flushkey();
						withdraw();
					}
				}
				
			}
			else
			{
				editBox.destory();
				cleardevice();
				backmode();
				setbkmode(TRANSPARENT);
				setcolor(RED);
				setfont(40,0,"����");
				music();
				mciSendString("play lx17",NULL,1,NULL);
				xyprintf(285 ,200,"��Ǹ��ȡ�����ÿ���޶�"); 
				Sleep(1000);
				//getch();
				flushkey();
				withdraw(); 
							
			}	
		}		
	}
	flushkey();
}

//���ܹ��� 
void change()
{
	
	cleardevice();  
	flushkey();
	draw6();
	char mc1[20],mc2[20];
	sys_edit editBox1,editBox2,editBox3;
	editBox1.create(false);	//false���У�true����				
	editBox1.move(200, 200);				
	editBox1.size(240, 35);				
	editBox1.setbgcolor(WHITE);
	editBox1.setcolor(BLACK);
	editBox1.setfont(25, 0, "����");
	editBox1.setmaxlen(100);			
	editBox1.visable(true);				
	editBox1.setfocus();
	
	
	for(int z=0;z<6;z++)
	{
		char x=getch();	
	}
		
	editBox2.create(false);	//false���У�true����				
	editBox2.move(200,240);				
	editBox2.size(240, 35);				
	editBox2.setbgcolor(WHITE);
	editBox2.setcolor(BLACK);
	editBox2.setfont(25, 0, "����");
	editBox2.setmaxlen(100);			
	editBox2.visable(true);	
	int t=1;
	for(int c=0;c<100;)
	{
		char ch=getch();
		if(ch==13)
		{
			break;
		}
		if(ch==8)
		{
			if(c!=0)
			{
				c--;
				t=t-2;
			}	
			if(t<=0)
			{
				editBox1.settext("");
				t=0;
			}
				
		}
		else
		{
			mc1[c]=ch;
			c++;
		}	
		if(t==1)
			editBox2.settext("*");
		else
			if(t==2)
				editBox2.settext("**");
			else
				if(t==3)
					editBox2.settext("***");
				else
					if(t==4)
						editBox2.settext("****");
					else
						if(t==5)
							editBox2.settext("*****");
						else
							if(t==6)
								editBox2.settext("******");
		t++;
	}			

	editBox3.create(false);	//false���У�true����				
	editBox3.move(200, 280);				
	editBox3.size(240, 35);				
	editBox3.setbgcolor(WHITE);
	editBox3.setcolor(BLACK);
	editBox3.setfont(25, 0, "����");
	editBox3.setmaxlen(100);			
	editBox3.visable(true);	
	int r=1;
	for(int c=0;c<100;)
	{
		char ch=getch();
		if(ch==13)
		{
			break;
		}
		if(ch==8)
		{
			if(c!=0)
			{
				c--;
				r=r-2;
			}	
			if(r<=0)
			{
				editBox1.settext("");
				r=0;
			}
				
		}
		else
		{
			mc2[c]=ch;
			c++;
		}	
		if(r==1)
			editBox3.settext("*");
		else
			if(r==2)
				editBox3.settext("**");
			else
				if(r==3)
					editBox3.settext("***");
				else
					if(r==4)
						editBox3.settext("****");
					else
						if(r==5)
							editBox3.settext("*****");
						else
							if(r==6)
								editBox3.settext("******");
		r++;
	}			

	for (;is_run(); delay_fps(60))
	{
		bool exit = false;
	/*	while (kbmsg()) 
		{
			key_msg msg = getkey();

			if ((msg.key == key_enter) && (msg.msg == key_msg_up))
			{
				exit = true;
				break;
			}			
		}*/
		
		char strBuffer1[100];
		char strBuffer2[100];
		char strBuffer3[100];	
		int i;
		
		//if(exit)
	//	{
			editBox1.gettext(100,strBuffer1);
		//	editBox2.gettext(100,strBuffer2);
			//editBox3.gettext(100,strBuffer3);
			if(strcmp(strBuffer1,ACC[position].password)==0)
			{
				if(strcmp(mc1,mc2)==0)
				{
					strcpy(ACC[position].password,mc2);
					FILE *p;
					p=fopen("account_in.txt","w+");
					for(i=0;i<count;i++)
						fprintf(p,"%d;%s;%s;%.2f;%d\n",ACC[i].id,ACC[i].name,ACC[i].password,ACC[i].balance,ACC[i].lock);
					fclose(p);	
					editBox1.destory(); editBox2.destory(); editBox3.destory();	
					for(i=3;i>=1;i--)
					{

						cleardevice();

						flushkey();		
						setbkmode(TRANSPARENT);
						setcolor(BLACK);
						backmode();
						setfont(40,0,"����");
						xyprintf(200,200,"�޸ĳɹ���");
						setfont(30,0,"����");
						setcolor(BLACK);
						music();
						mciSendString("play lx12",NULL,1,NULL);
						setfont(25,0,"����");
						xyprintf(185,255,"(ϵͳ%d����˳�����)",i);
						flushkey();
						Sleep(1000);
					}
					flushkey();				
					break;									
				}
				else
				{
					for(i=3;i>=1;i--)
					{
						flushkey();
						cleardevice();
						editBox1.destory(); editBox2.destory(); editBox3.destory();
						setbkmode(TRANSPARENT);
						backmode();
						setcolor(BLACK);
						setfont(40,0,"����");
						xyprintf(60,200,"�������벻һ�£���ȷ�Ϻ����룡");
						setfont(30,0,"����");
						setcolor(BLACK);
						music();
						mciSendString("play lx11",NULL,1,NULL);
						setfont(25,0,"����");
						xyprintf(185,255,"(ϵͳ%d����������롭��)",i);
						Sleep(1000);
					}
					//change();
					flushkey();
					break;
				}
			}	
					
			else
			{
				for(i=3;i>=1;i--)
				{
					editBox1.destory(); editBox2.destory(); editBox3.destory();
					cleardevice();
					backmode();				
					setbkmode(TRANSPARENT);
					setcolor(RED);
					setfont(40,0,"����");
					xyprintf(200,200,"ԭ�������");
					setfont(30,0,"����");
					setcolor(BLACK);
					music();
					mciSendString("play lx10",NULL,1,NULL);
					setfont(25,0,"����");
					xyprintf(185,255,"(ϵͳ%d����˳�����)",i);
					Sleep(1000);
				}
				flushkey();				
				break;	
			}
			
			
		//}
	}
} 



//������ִ�������湦�� 
int main()
{
	login();
}

