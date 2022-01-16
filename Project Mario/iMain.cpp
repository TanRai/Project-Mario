#include<iostream>
using namespace std;
#include "iGraphics.h"
#include "WinUser.h"
#include "InputVariables.h"
//*******************************************************************Variables*********************************************************************//
void loadLevel();
void change();
void winInput();
void marioLevelBound(int x, int y);
void levelScroll(int x);
int levelX = 0;
int levelY = 0;
int loadFlag = 1;
int marioX = 200;
int marioY = 128;
unsigned int  levelTexture;
char Mario[1][25] = { "Characters\\Mario\\1m.bmp" };
//*******************************************************************iDraw***********************************************************************//
void iDraw()
{
	iClear();
	loadLevel();
	iShowImage(levelX, levelY, 13504, 960, levelTexture);
	iShowBMP2(marioX, marioY, Mario[0], 0);
}
//*******************************************************************iMouseMove***********************************************************************//
void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}
//*******************************************************************iMouse***********************************************************************//
void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}
//*******************************************************************iKeyboard***********************************************************************//
void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		
	}
	
	
}
//*******************************************************************iSpecialKeyboard***********************************************************************//
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}
//*******************************************************************My Functions***********************************************************************//
void marioLevelBound(int x, int y)
{
	if (marioX + x >= 0 && marioX + x < 312)
	{	
		marioX = marioX + x;
	}
	else if (marioX + x >= 312)
	{
		marioX = 312;
		if (13504 + levelX - 1280 - x >=0)
		{	
			levelX = levelX - x;
		}
		cout << levelX << endl;
	}
}
void winInput()
{
	d = GetAsyncKeyState(0x44);
	a = GetAsyncKeyState(0x41);
	w = GetAsyncKeyState(0x57);
	if (d)
	{
		marioLevelBound(10,0);
	}
	if (a)
	{
		marioLevelBound(-10, 0);
	}
	if (w)
	{
		marioY = marioY ++;
	}
}
void loadLevel()
{
	if (loadFlag == 1)
	{
		levelTexture = iLoadImage("Levels\\World 1-1\\Background.png");
		loadFlag = 0;
	}
}
void change(){
	
}
//*******************************************************************main***********************************************************************//
int main()
{
	iSetTimer(1, change);
	iSetTimer(1, winInput);
	iInitialize(1280, 960, "Project Mario");
	///updated see the documentations
	iStart();
	return 0;
}
//*******************************************************************end***********************************************************************//