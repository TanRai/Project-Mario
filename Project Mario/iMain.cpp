#include<iostream>
#include <cstdlib>
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
void gravity();
void marioLevelBound(int x, int y);
void marioCollision(int x,int y);
bool detectCollision(int x,int y);
void setObjects();
bool collisionStructure(int i, int x, int y);
bool ground();
//*******************************************************************Variables*********************************************************************//
struct keyState
{
	bool bPressed;
	bool bReleased;
	bool bHeld;
} m_keys[256];
struct levelObjects
{
	int x;
	int y;
	int width;
	int height;
}objects[4];
bool jumpUp = false;
bool jump = false;
int jumpLimit = 300;
int objectCount = 3;
int marioHeight = 64;
int marioWidth = 64;
bool marioMove = false;
int marioIndex = 0;
short m_keyOldState[256] = { 0 };
short m_keyNewState[256] = { 0 };
int levelX = 0;
int levelY = 0;
int loadFlag = 1;
int marioTrueX = 200;
int marioX = 200;
int marioY = 128; //default 128
int screenWidth = 1024;
int screenHeight = 960;
int jumpDistance = 0;

unsigned int  levelTexture;
char Mario[7][25] = { "Characters\\Mario\\A1.bmp", "Characters\\Mario\\A2.bmp", "Characters\\Mario\\A3.bmp", "Characters\\Mario\\A4.bmp", "Characters\\Mario\\A5.bmp", "Characters\\Mario\\A6.bmp", "Characters\\Mario\\A7.bmp" };
//*******************************************************************iDraw***********************************************************************//
void iDraw()
{
	iClear();
	loadLevel();
	iShowImage(levelX, levelY, 13504, 960, levelTexture);
	iShowBMP2(marioX, marioY, Mario[marioIndex], 0);
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
void setObjects()
{
	objects[0] = { 0, 0, 4415, 128 };
	objects[1] = { 1792, 128, 128, 128};
	objects[2] = { 2432, 128, 128, 192};
}
void marioLevelBound(int x, int y)
{
	if (marioX + x >= 0 && marioX + x < 312)
	{	
		marioX = marioX + x;
		marioTrueX += x;
	}
	else if (marioX + x >= 312)
	{
		marioX = 312;
		if (13504 + levelX - screenWidth - x >=0)
		{	
			levelX = levelX - x;
			marioTrueX += x;
		}
		//cout << levelX << endl;
	}
	if (marioY + y >= 0 && marioY + y <= 856)
	{
		marioY += y;
	}
}
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
		marioCollision(7, 0);
		marioMove = true;
	}
	if (m_keys[0x44].bReleased == true)
	{
		marioMove = false;
	}
	if (m_keys[0x41].bHeld == true)
	{
		marioCollision(-7, 0);
	}
	if (m_keys[0x57].bHeld == true)
	{
		marioCollision(0, 10);
	}
	if (m_keys[0x53].bHeld == true)
	{
		marioCollision(0, -10);
	}
	
	if (m_keys[0x20].bPressed == true)
	{
		if (!jump)
		{
			if (ground())
			{
				jump = true;
				jumpUp = true;
				marioIndex = 5;
			}
		}
	}
	
}
void marioCollision(int x,int y)                                        // Requested position of Mario first comes here. It is generally called wtih either x or y but not both. It exectues the first for loop if the movement is in x direction and the second if it is in y direction.It calls another function to check for collision. The purpose of this function is to check collision by moving 1 unit at a time.
{
	int i,k,l;
	if (x > 0)
	{
		k = 1;
	}
	else if (x < 0)
	{
		k = -1;
	}
	if (y > 0)
	{
		l = 1;
	}
	else if (y<0)
	{
		l = -1;
	}
	for (i = 1; i <= abs(x); i++)
	{
		if (!detectCollision(marioTrueX + 1 * k, marioY))
		{
			marioLevelBound(k, 0);
		}
	}
	for (i = 1; i <= abs(y); i++)
	{
		if (!detectCollision(marioTrueX, marioY + 1 * l))
		{
			marioLevelBound(0, l);
		}
	}
}
bool detectCollision(int x, int y)                 //This function sends four corners of mario to check if it is in collision with any objects. If Mario is in collision with any objects it returns true,otherwise false. 
{
	int i;
	for (i = 0; i < objectCount; i++)
	{
		if (collisionStructure(i, x, y + 64))                                   //top left of mario
		{
			cout << "err1" << endl;
			return true;
		}
		if (collisionStructure(i, x + 64, y + 64))                              //top right of mario
		{
			cout << "err2" << endl;
			return true;
		}
		if (collisionStructure(i, x, y))                                       //bottom left of mario
		{
			cout << "err3" << endl;
			return true;
		}
		if (collisionStructure(i, x + 64, y))                                  //bottom right of mario
		{
			cout << "err4" << endl;
			return true;
		}
	}
	return false;
}
bool ground()
{
	int i;
	for(i=0;i<objectCount;i++)
	{
		if (collisionStructure(i, marioTrueX, marioY-1))
		{
			cout << "left ground" << endl;
			return true;
		}
		if (collisionStructure(i, marioTrueX + 64, marioY - 1))
		{
			cout << "right ground" << endl;
			return true;
		}
	}
	return false;
	
}
bool collisionStructure(int i, int x, int y)                                                        //checks if the requested coordinate/position of mario puts him in collision with any objects. If it does collide with any object it returns true, otherwise false
{
	bool flag1 = 0;
	bool flag2 = 0;
	bool flag3 = 0;
	bool flag4 = 0;
	if (x > objects[i].x && y > objects[i].y)														//bottom left of object
	{
		flag1 = 1;
	}
	if (x > objects[i].x && y < objects[i].y + objects[i].height)									//top left of object 
	{
		flag2 = 1;
	}
	if (x < objects[i].x + objects[i].width && y < objects[i].y + objects[i].height)                 //top right of object
	{
		flag3 = 1;
	}
	if (x < objects[i].x + objects[i].width && y > objects[i].y)                                     //bottom right of object
	{
		flag4 = 1;
	}
	if (flag1 && flag2 && flag3 && flag4)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void setInput()
{
	short *m_keyNewState = new short[256];
	short *m_keyOldState = new short[256];
	keyState *m_keys = new keyState[256];
}
void change(){
	if (marioMove == true  && jump == false)
	{
		if (marioIndex == 0)
		{
			marioIndex = 3;
		}
		else if (marioIndex < 3)
		{
			marioIndex++;
		}
		else
		{
			marioIndex = 1;
		}
	}
	else if (jump == false)
	{
		marioIndex = 0;
	}
}
void gravity()
{
	if (jump)
	{
		if (jumpDistance + 10 <= jumpLimit && jumpUp)
		{
			jumpDistance += 10;
			cout << "gg" << endl;
			marioCollision(0, 10);
		}
		else
		{
			jumpDistance = 0;
			jumpUp = false;
			marioCollision(0, -10);
			if (ground())
			{
				jump = false;
				marioIndex = 0;
			}
		}
	}
	else
	{
		marioCollision(0, -10);
	}
}
//*******************************************************************main***********************************************************************//
int main()
{
	setObjects();
	setInput();
	iSetTimer(70, change);
	iSetTimer(1, winInput);
	iSetTimer(8, checkInput);
	iSetTimer(16, gravity);
	iInitialize(screenWidth, screenHeight, "Project Mario");
	iStart();
	return 0;
}
//*******************************************************************end***********************************************************************//