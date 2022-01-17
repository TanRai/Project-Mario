#include<iostream>
using namespace std;
#include "iGraphics.h"
#include "WinUser.h"
#include "InputVariables.h"
//*******************************************************************Function Definitions*********************************************************************//
void loadLevel();
void setInput();
void change();
void winInput();
void checkInput();
void marioLevelBound(int x, int y);
void levelScroll(int x);
//*******************************************************************Variables*********************************************************************//
struct keyState
{
	bool bPressed;
	bool bReleased;
	bool bHeld;
} m_keys[256];
short m_keyOldState[256] = { 0 };
short m_keyNewState[256] = { 0 };
int levelX = 0;
int levelY = 0;
int loadFlag = 1;
int marioX = 200;
int marioY = 128;
int screenWidth = 1024;
int screenHeight = 960;
unsigned int  levelTexture;
char Mario[1][24] = { "Characters\\Mario\\1m.bmp" };
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
		if (13504 + levelX - screenWidth - x >=0)
		{	
			levelX = levelX - x;
		}
		//cout << levelX << endl;
	}
}
/*void winInput()
{
	d = GetAsyncKeyState(0x44);
	a = GetAsyncKeyState(0x41);
	w = GetAsyncKeyState(0x57);
	if (d)
	{
		marioLevelBound(50,0);
		cout << marioX << endl;
	}
	if (a)
	{
		marioLevelBound(-10, 0);
	}
	if (w)
	{
		marioY = marioY ++;
	}
}*/
void winInput()
{
	for (int i = 0; i < 256; i++)
	{
		m_keyNewState[i] = GetAsyncKeyState(i);

		m_keys[i].bPressed = false;
		m_keys[i].bReleased = false;

		if (m_keyNewState[i] != m_keyOldState[i])
		{
			if (m_keyNewState[i] & 0x8000)
			{
				m_keys[i].bPressed = !m_keys[i].bHeld;
				m_keys[i].bHeld = true;
			}
			else
			{
				m_keys[i].bReleased = true;
				m_keys[i].bHeld = false;
			}
		}

		m_keyOldState[i] = m_keyNewState[i];
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
void checkInput()
{
	if (m_keys[0x44].bHeld == true)
	{
		marioLevelBound(10, 0);
	}
}
void setInput()
{
	short *m_keyNewState = new short[256];
	short *m_keyOldState = new short[256];
	keyState *m_keys = new keyState[256];
}
void change(){
	
}
//*******************************************************************main***********************************************************************//
int main()
{
	setInput();
	iSetTimer(1, change);
	iSetTimer(1, winInput);
	iSetTimer(8, checkInput);
	iInitialize(screenWidth, screenHeight, "Project Mario");
	///updated see the documentations
	iStart();
	return 0;
}
//*******************************************************************end***********************************************************************//