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
	int lock; //锁卡 ：0代表未锁，1代表已锁 
};


struct CircleButton
{
	int x, y;		/* 圆心*/
	int width;
	int height;		/* 半径*/
	bool pressed;	/* 是否按下*/
};

// 判断点(x, y)是否在按钮点击区域内部
bool insideButton(const CircleButton* button, int x, int y);

// 绘制所有按钮
void drawButton(const CircleButton buttonArray[], int length);

// 查找 (x, y) 所在的按钮，返回按钮ID, 没有返回 -1
int searchButton(int x, int y, const CircleButton buttonArray[], int length);
void noke(int i);
// 绘制
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
struct account ACC[N];//用户数组 
int count=0;//记录用户总数
int position; //登录用户位置 
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

//定义按钮，确定区域
CircleButton buttonArray[BUTTON_SIZE];
CircleButton buttonArray2[BUTTON_SIZE2];
CircleButton buttonArray3[BUTTON_SIZE3];

// 按下按钮ID
int pressButtonId = BUTTON_ID_NONE;



// 将数据类型转换为成员类型 
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
 
 //语音的提取和使用 
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
 

 //打开文件将文件内容提取到数组之中 
 
void init()
{
	FILE *fp;
	char temp[50];
	fp=fopen("account_in.txt","r");
	if(fp==NULL)
	{
		printf("系统初始化失败，请检查！");
		exit(0);
	}  
	while(fgets(temp,50,fp)) 
	{
		ACC[count]=convert(temp);
		count++;
	}
	fclose(fp);
 } 



//设置背景 
PIMAGE lx;
void backmode()
{
	lx=newimage();
	getimage(lx,"img\\1.jpg");  
	putimage(0,0,lx);
}

void draw2();


//主界面按钮的判断和按下按钮后的函数调用 
int login()
{
	initgraph(640, 480, INIT_RENDERMANUAL);
	setcaption("刘星ATM4.5版本");
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
			mouse_msg msg = getmouse();// 判断鼠标左键按下（左键按下确定位置，同时判断是否为按钮区域	// 抬起则解除按下状态
			if (msg.is_left()) {
				if (msg.is_down()) {
						// 检查是否有按钮被按下
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE);
						int i=btnId;
						noke(i);
					// 将被按下的按钮设置为按下状态
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
					//左键抬起，如果有按钮被按下，解除按下状态
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// 判断是否需要重绘，减少不必要的绘制操作
	}

	return 0;
}
char mc[100];
/*登录界面的判定*/ 
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
	editBox.setfont(25, 0, "宋体");
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
		
			//获取输入框的内容，保存到字符数组strBuffer[]中
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
					setfont(25, 0, "楷体");
					settextjustify(LEFT_TEXT, TOP_TEXT);	
					xyprintf(480, 197, "卡号正确",b);
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
							editBox1.setfont(25, 0, "宋体");
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
									{	editBox.destory();//销毁 
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
										setfont(25, 0, "楷体");
										settextjustify(LEFT_TEXT, TOP_TEXT);	
										xyprintf(185, 400, "密码错误！您还有%d次机会",b);
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
			
	//flushkey();//键盘清理
	//editBox.destory();//销毁 
	//editBox1.destory(); 

	
 //} 


//当按钮按下时更改按钮的背景颜色
//显示被按下的状态 
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
		setcolor(BLACK);//文字背景 
		setfont(20,10,"楷体");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "登录");
		Sleep(150);
	}
  }  

// 设置鼠标点击按钮的有效范围 
bool insideButton(const CircleButton* button, int x, int y)
{
	return (x >= button->x) && (y >= button->y)
		&& (x < button->x + button->width)
		&& (y < button->y + button->height);
}

//绘制按钮 
void drawButton(const CircleButton buttonArray[], int length)
{ 
	//setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	//setcolor(WHITE);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	
	//setfont(36, 0, "");
	//color_t lastFillColor = getfillcolor();
	for (int i = 0; i < length; i++) {
		//根据状态进行不同的绘制，这里按状态改变颜色
		//为了减少颜色设置操作进行的优化操作，少量绘制可有可无
		// 绘制按钮
		setfillcolor(RGB(250,200, 0));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//文字背景 
		setfont(20,10,"楷体");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "登录");
	}
}

//判断按钮是否需要重绘 
int searchButton(int x, int y, const CircleButton buttonArray[], int length)
{
	int buttonId = BUTTON_ID_NONE;

	for (int i = 0; i < length; i++) {
		if (insideButton(&buttonArray[i], x, y)) {
			buttonId = i;
			break;   //退出，已经检测到，后面的按钮不再检测
		}
	}

	return buttonId;
}

//绘制图形界面上的文字内容 
void draw()
{
	//绘制 
	//drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(30, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(130, 200, "账号：");
	xyprintf(130, 250, "密码：");
	xyprintf(180, 100, "狗熊岭银行登录界面");
	
}
void draw2()
{
	//绘制 
	cleardevice();
	//drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(24, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	backmode();
	xyprintf(120, 200, "该卡号已被锁！！！请联系银行工作人员·····");
	music();
	mciSendString("play lx15",NULL,1,NULL);
	Sleep(2000);
	
}
void draw3()
{
	//绘制 
	drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(40, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(150, 100, "欢迎进入狗熊岭银行！！！");
	
}


void draw4()
{
	//绘制 
	//drawButton(buttonArray, BUTTON_SIZE);
	backmode();
	setcolor(BLACK);
	setfont(25, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);	
	xyprintf(185, 400, "密码错误！");
	music();
	mciSendString("play lx14",NULL,1,NULL);
	Sleep(2000);
}
void draw5()
{
	//绘制 
	cleardevice();
	//drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(24, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	backmode();
	xyprintf(0, 0, "登录成功！！！");
	xyprintf(0,30,"尊敬的%s先生，您好！",ACC[position].name);
	xyprintf(0,60,"您的余额为：%.2f",ACC[position].balance);
	Sleep(1000);
}


void draw6()
{
	//绘制 
	cleardevice();
	//drawButton(buttonArray, BUTTON_SIZE);
	setcolor(BLACK);
	setfont(40, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	setcolor(BLACK);
	backmode();
	xyprintf(225,100, "密码修改");
	setfont(24, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(115,200, "旧密码:");
	xyprintf(115, 240, "新密码:");
	xyprintf(20, 280, "再次输入新密码:");
	music();
	mciSendString("play lx9",NULL,1,NULL);
	
}


void draw7()
{
	//绘制 
	cleardevice();
	backmode();
	setcolor(BLACK);
	setfont(40, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	backmode();
	xyprintf(185, 200, "转账账号不能为自己！");
/*	music();
	mciSendString("play lx14",NULL,1,NULL);*/
	Sleep(2000);
}


void draw8()
{
	//绘制 
	cleardevice();
	backmode();
	setcolor(BLACK);
	setfont(40, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	backmode();
	xyprintf(185, 200, "账号错误！！");
/*	music();
	mciSendString("play lx14",NULL,1,NULL);*/
	Sleep(2000);
}

//功能界面的选择是否需要继续 
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
			mouse_msg msg = getmouse();// 判断鼠标左键按下（左键按下确定位置，同时判断是否为按钮区域	// 抬起则解除按下状态
			if (msg.is_left() && msg.is_down()) {
				if (msg.is_down()) {
						// 检查是否有按钮被按下
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE3);
						int i=btnId;
						noce(i);
					// 将被按下的按钮设置为按下状态
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
					//左键抬起，如果有按钮被按下，解除按下状态
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// 判断是否需要重绘，减少不必要的绘制操作
		if (redraw) {
			cleardevice();
			draw9();
			redraw = false;
		}
	}

	return 0;
}


//功能界面的鼠标选择 
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
			mouse_msg msg = getmouse();// 判断鼠标左键按下（左键按下确定位置，同时判断是否为按钮区域	// 抬起则解除按下状态
			if (msg.is_left() && msg.is_down()) {
				if (msg.is_down()) {
						// 检查是否有按钮被按下
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE3);
						int i=btnId;
						noce(i);
					// 将被按下的按钮设置为按下状态
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
					//左键抬起，如果有按钮被按下，解除按下状态
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// 判断是否需要重绘，减少不必要的绘制操作
		if (redraw) {
			cleardevice();
			draw9();
			redraw = false;
		}
	}

	return 0;
}


//功能界面的鼠标选择 
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
			mouse_msg msg = getmouse();// 判断鼠标左键按下（左键按下确定位置，同时判断是否为按钮区域	// 抬起则解除按下状态
			if (msg.is_left() && msg.is_down()) {
				if (msg.is_down()) {
						// 检查是否有按钮被按下
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE3);
						int i=btnId;
						noce(i);
					// 将被按下的按钮设置为按下状态
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
					//左键抬起，如果有按钮被按下，解除按下状态
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// 判断是否需要重绘，减少不必要的绘制操作
		if (redraw) {
			cleardevice();
			draw9();
			redraw = false;
		}
	}

	return 0;
}

//更改按钮的颜色，显示出按钮被按下的状态 
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
		setcolor(BLACK);//文字背景 
		setfont(20,10,"楷体");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "是");
		if(i==1)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "否");
		Sleep(150);
	}
  }  



void draw9()
{
	//绘制 
	backmode();
	drawButton3(buttonArray, BUTTON_SIZE3);
	setcolor(BLACK);
	setfont(24, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(195, 200, "是否要继续此操作！");
	
}

//功能界面，鼠标选择
//各项功能并执行 

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
			mouse_msg msg = getmouse();// 判断鼠标左键按下（左键按下确定位置，同时判断是否为按钮区域	// 抬起则解除按下状态
			if (msg.is_left() && msg.is_down()) {
				if (msg.is_down()) {
						// 检查是否有按钮被按下
						int  btnId= searchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE2);
						int i=btnId;
						nock(i);
					// 将被按下的按钮设置为按下状态
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
					//左键抬起，如果有按钮被按下，解除按下状态
					if (pressButtonId != BUTTON_ID_NONE) {
						buttonArray[pressButtonId].pressed = false;
						pressButtonId = BUTTON_ID_NONE;
						redraw = true;
					}
				}
			}
		}

		// 判断是否需要重绘，减少不必要的绘制操作
		if (redraw) {
			cleardevice();
			draw1();
			redraw = false;
		}
	}

	return 0;
}




//功能界面按钮被按下时更改颜色 
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
		setcolor(BLACK);//文字背景 
		setfont(20,10,"楷体");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "刘星");
		if(i==1)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "转账");
		if(i==2)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "存钱");
		if(i==3)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "取钱");
		if(i==4)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "改密");
		if(i==5)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "退出");	
		Sleep(150);
	}
  }  

//绘制功能界面按钮 
void drawButton1(const CircleButton buttonArray[], int length)
{ 
	//setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	//setcolor(WHITE);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	//setfont(36, 0, "");
	//color_t lastFillColor = getfillcolor();
	for (int i = 0; i < length; i++) {
		//根据状态进行不同的绘制，这里按状态改变颜色
		//为了减少颜色设置操作进行的优化操作，少量绘制可有可无
		// 绘制按钮
		setfillcolor(RGB(250,200, 0));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//文字背景 
		setfont(20,10,"楷体");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "作者");
		if(i==1)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "转账");
		if(i==2)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "存钱");
		if(i==3)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "取钱");
		if(i==4)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "改密");
		if(i==5)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "退出");	
	}
}


void draw1()
{
	backmode();
	drawButton1(buttonArray, BUTTON_SIZE2);
	setcolor(BLACK);
	setfont(24, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(350, 0, "登录成功！！！");
	xyprintf(350,30,"尊敬的%s先生，您好！",ACC[position].name);
	xyprintf(350,60,"您的余额为：%.2f",ACC[position].balance);
	
}



//绘制是否继续该功能的按钮 
void drawButton3(const CircleButton buttonArray[], int length)
{ 
	//setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	//setcolor(WHITE);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	//setfont(36, 0, "");
	//color_t lastFillColor = getfillcolor();
	for (int i = 0; i < length; i++) {
		//根据状态进行不同的绘制，这里按状态改变颜色
		//为了减少颜色设置操作进行的优化操作，少量绘制可有可无
		// 绘制按钮
		setfillcolor(RGB(250,200, 0));
		bar(buttonArray[i].x, buttonArray[i].y, buttonArray[i].x + buttonArray[i].width, buttonArray[i].y + buttonArray[i].height);
		setcolor(BLACK);//文字背景 
		setfont(20,10,"楷体");
		if(i==0)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "是");
		if(i==1)
			xyprintf(buttonArray[i].x+50, buttonArray[i].y+25, "否");
	}
}


//转账功能 
void transfer()
{
	
	cleardevice();
	flushkey();  
	backmode();
	
	sys_edit editBox;
	editBox.create(false);	//false单行，true多行				
	editBox.move(200, 225);				
	editBox.size(240, 35);				
	editBox.setbgcolor(WHITE);
	editBox.setcolor(BLACK);
	editBox.setfont(25, 0, "宋体");
	editBox.setmaxlen(100);			
	editBox.visable(true);				
	editBox.setfocus();
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	music();
	mciSendString("play lx3",NULL,1,NULL);
	setfont(35,0,"黑体");
	xyprintf(320 ,200,"请输入转账账号：");
	 	
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
		
		char strBuffer[100];//账号 

		
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
						editBox.create(false);	//false单行，true多行				
						editBox.move(200, 225);				
						editBox.size(240, 35);				
						editBox.setbgcolor(WHITE);
						editBox.setcolor(BLACK);
						editBox.setfont(25, 0, "宋体");
						editBox.setmaxlen(100);			
						editBox.visable(true);				
						editBox.setfocus();
						setbkmode(TRANSPARENT);
						setcolor(BLACK);
						music();
						mciSendString("play lx5",NULL,1,NULL);
						setfont(35,0,"黑体");
						xyprintf(320 ,200,"请输入转账金额：");
					
					
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
						
							char strBuffer1[100];//金额 		
										
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
										setfont(40,0,"黑体");
										xyprintf(320 ,200,"转账成功！");
										setfont(30,0,"黑体");
										setcolor(BLACK);
										music();
										mciSendString("play lx19",NULL,1,NULL);
										setfont(25,0,"仿宋");
										xyprintf(305 ,235,"(系统%d秒后退出……)",i);
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
									setfont(40,0,"黑体");
									xyprintf(320 ,200,"余额不足！");
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
					setfont(40,0,"黑体");
					xyprintf(320 ,200,"查无此号！");
					setfont(30,0,"黑体");
					setcolor(BLACK);
					music();
					mciSendString("play lx4",NULL,1,NULL);
					setfont(25,0,"仿宋");
					xyprintf(305 ,235,"(系统%d秒后退出……)",i);
					Sleep(1000);
				}
				//lushkey();
				break;
				
			}
			break;	
		} 
	}
	
	
} 


//存款功能 
void deposit()
{
	cleardevice();
	flushkey();  
	backmode();
	
	sys_edit editBox;
	editBox.create(false);	//false单行，true多行				
	editBox.move(200,225);				
	editBox.size(240, 35);				
	editBox.setbgcolor(WHITE);
	editBox.setcolor(BLACK);
	editBox.setfont(25, 0, "宋体");
	editBox.setmaxlen(100);			
	editBox.visable(true);				
	editBox.setfocus();
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	music();
	mciSendString("play lx6",NULL,1,NULL);
	setfont(35,0,"黑体");
	xyprintf(320,170,"请输入存款金额：");
	xyprintf(320,200,"(每日限存30000RMB且必须全为100RMB)"); 	
	
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
						setfont(40,0,"黑体");
						xyprintf(320,200,"存款成功！");
						setfont(30,0,"黑体");
						setcolor(BLACK);
						music();
						mciSendString("play lx7",NULL,1,NULL);
						setfont(25,0,"仿宋");
						xyprintf(305,235,"(系统%d秒后退出……)",i);
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
					setfont(40,0,"黑体");
					xyprintf(320,200,"不为整百数，请确认后再输入！");
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
				setfont(40,0,"黑体");
				xyprintf(320,200,"超过每日限存金额！");
				Sleep(2000);
				break; 
			}
			
							
		}
		
	}
	 
	
}  


//取款功能 
void withdraw()
{
	cleardevice();
	flushkey();
	backmode();
	sys_edit editBox;
	editBox.create(false);	//false单行，true多行				
	editBox.move(200,225);				
	editBox.size(240, 35);				
	editBox.setbgcolor(WHITE);
	editBox.setcolor(BLACK);
	editBox.setfont(25, 0, "宋体");
	editBox.setmaxlen(100);			
	editBox.visable(true);				
	editBox.setfocus();
	setbkmode(TRANSPARENT);
	
	setcolor(BLACK);
	music();
	mciSendString("play lx8",NULL,1,NULL);
	setfont(35,0,"黑体");
	xyprintf(320 ,170,"请输入取款金额：");
	xyprintf(320 ,200,"(取款金额在2000以内且为整百数）"); 
	
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
							setfont(40,0,"黑体");
							xyprintf(320 ,200,"取款成功！");
							setfont(30,0,"黑体");
							setcolor(BLACK);
							music();
							mciSendString("play lx61",NULL,1,NULL);
							setfont(25,0,"仿宋");
							xyprintf(305,235,"(系统%d秒后退出……)",i);
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
						setfont(40,0,"黑体");
						xyprintf(320 ,200,"抱歉,余额不足！");
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
				setfont(40,0,"黑体");
				music();
				mciSendString("play lx17",NULL,1,NULL);
				xyprintf(285 ,200,"抱歉！取款金额超过每笔限额"); 
				Sleep(1000);
				//getch();
				flushkey();
				withdraw(); 
							
			}	
		}		
	}
	flushkey();
}

//改密功能 
void change()
{
	
	cleardevice();  
	flushkey();
	draw6();
	char mc1[20],mc2[20];
	sys_edit editBox1,editBox2,editBox3;
	editBox1.create(false);	//false单行，true多行				
	editBox1.move(200, 200);				
	editBox1.size(240, 35);				
	editBox1.setbgcolor(WHITE);
	editBox1.setcolor(BLACK);
	editBox1.setfont(25, 0, "宋体");
	editBox1.setmaxlen(100);			
	editBox1.visable(true);				
	editBox1.setfocus();
	
	
	for(int z=0;z<6;z++)
	{
		char x=getch();	
	}
		
	editBox2.create(false);	//false单行，true多行				
	editBox2.move(200,240);				
	editBox2.size(240, 35);				
	editBox2.setbgcolor(WHITE);
	editBox2.setcolor(BLACK);
	editBox2.setfont(25, 0, "宋体");
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

	editBox3.create(false);	//false单行，true多行				
	editBox3.move(200, 280);				
	editBox3.size(240, 35);				
	editBox3.setbgcolor(WHITE);
	editBox3.setcolor(BLACK);
	editBox3.setfont(25, 0, "宋体");
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
						setfont(40,0,"黑体");
						xyprintf(200,200,"修改成功！");
						setfont(30,0,"黑体");
						setcolor(BLACK);
						music();
						mciSendString("play lx12",NULL,1,NULL);
						setfont(25,0,"仿宋");
						xyprintf(185,255,"(系统%d秒后退出……)",i);
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
						setfont(40,0,"黑体");
						xyprintf(60,200,"两次密码不一致，请确认后输入！");
						setfont(30,0,"黑体");
						setcolor(BLACK);
						music();
						mciSendString("play lx11",NULL,1,NULL);
						setfont(25,0,"仿宋");
						xyprintf(185,255,"(系统%d秒后重新输入……)",i);
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
					setfont(40,0,"黑体");
					xyprintf(200,200,"原密码错误！");
					setfont(30,0,"黑体");
					setcolor(BLACK);
					music();
					mciSendString("play lx10",NULL,1,NULL);
					setfont(25,0,"仿宋");
					xyprintf(185,255,"(系统%d秒后退出……)",i);
					Sleep(1000);
				}
				flushkey();				
				break;	
			}
			
			
		//}
	}
} 



//主函数执行主界面功能 
int main()
{
	login();
}

