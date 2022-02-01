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
bool marioCollision(int x,int y);
bool detectCollision(int x,int y);
void setObjects();
bool ground();
bool aabbCollisionMario(int a, int x,int y);
void levelScroll();
bool detectCollisionObjects(int x, int y, int e);
bool aabbCollisionObjects(int x, int y, int e, int i);
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
}objects[80];
struct enemy
{
	int x;
	int y;
	int levelX;
	int levelY;
	int width;
	int height;
	int velocity;
	bool alive;
}enemyObjects[10];
bool jumpUp = false;
bool jump = false;
int jumpLimit = 300;
bool pos = false;
int objectCount = 78;
int marioHeight = 64;
int marioWidth = 48;
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
int screenWidth = 1024;// default 1024
int screenHeight = 960;
int jumpDistance = 0;
int enemyCount = 2;
int gameState = 1;

unsigned int  levelTexture;
char Mario[7][25] = { "Characters\\Mario\\A1.bmp", "Characters\\Mario\\A2.bmp", "Characters\\Mario\\A3.bmp", "Characters\\Mario\\A4.bmp", "Characters\\Mario\\A5.bmp", "Characters\\Mario\\A6.bmp", "Characters\\Mario\\A7.bmp" };
char goomba[3][35] = { "Characters\\Goomba\\g1.bmp", "Characters\\Goomba\\g2.bmp", "Characters\\Goomba\\g3.bmp" };
//*******************************************************************iDraw***********************************************************************//
void iDraw()
{
	iClear();

	iShowImage(levelX, levelY, 13504, 960, levelTexture);
	iShowBMP2(marioX, marioY, Mario[marioIndex], 0);
	for (int i = 0; i < enemyCount; i++)
	{
		if (enemyObjects[i].alive == true)
		{
			iShowBMP2(enemyObjects[i].x, enemyObjects[i].y, goomba[0], 255);
		}
	}
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
	objects[0] = { 0, 0, 4415, 127 };
	objects[1] = { 1792, 128, 128, 128};
	objects[2] = { 2432, 128, 128, 192};
	objects[3] = { 1024, 321, 63, 63 };
	objects[4] = { 1280, 321, 63, 63 };
	objects[5] = { 1344, 321, 63, 63 };
	objects[6] = { 1408, 321, 63, 63 };
	objects[7] = { 1472, 321, 63, 63 };
	objects[8] = { 1536, 321, 63, 63 };
	objects[9] = { 1408, 577, 63, 63 };
	objects[10] = { 2944, 129, 127, 255 };
	objects[11] = { 3648, 129, 127, 255 };
	objects[12] = { 5696, 0, 4095, 127 };
	objects[13] = { 4544, 0, 959, 127 };
	objects[14] = { 4928, 321, 63, 63 };
	objects[15] = { 4992, 321, 63, 63 };
	objects[16] = { 5056, 321, 63, 63 };
	objects[17] = { 5120, 577, 63, 63 };
	objects[18] = { 5184, 577, 63, 63 };
	objects[19] = { 5248, 577, 63, 63 };
	objects[20] = { 5312, 577, 63, 63 };
	objects[21] = { 5376, 577, 63, 63 };
	objects[22] = { 5440, 577, 63, 63 };
	objects[23] = { 5504, 577, 63, 63 };
	objects[24] = { 5568, 577, 63, 63 };
	objects[25] = { 5824, 577, 63, 63 };
	objects[26] = { 5888, 577, 63, 63 };
	objects[27] = { 5952, 577, 63, 63 };
	objects[28] = { 6016, 577, 63, 63 };
	objects[29] = { 6016, 321, 63, 63 };
	objects[30] = { 6400, 321, 63, 63 };
	objects[31] = { 6464, 321, 63, 63 };
	objects[32] = { 6784, 321, 63, 63 };
	objects[33] = { 6976, 321, 63, 63 };
	objects[34] = { 7168, 321, 63, 63 };
	objects[35] = { 7552, 321, 63, 63 };
	objects[36] = { 6976, 577, 63, 63 };
	objects[37] = { 7744, 577, 63, 63 };
	objects[38] = { 7808, 577, 63, 63 };
	objects[39] = { 7872, 577, 63, 63 };
	objects[40] = { 8256, 321, 63, 63 };
	objects[41] = { 8320, 321, 63, 63 };
	objects[42] = { 8192, 577, 63, 63 };
	objects[43] = { 8256, 577, 63, 63 };
	objects[44] = { 8320, 577, 63, 63 };
	objects[45] = { 8384, 577, 63, 63 };
	objects[46] = { 9920, 0, 3583, 127 };
	objects[47] = { 8576, 128, 63, 63 };
	objects[48] = { 8640, 128, 191, 127 };
	objects[49] = { 8704, 256, 127, 63 };
	objects[50] = { 8768, 320, 63, 63 };
	objects[51] = { 8960, 320, 63, 63 };
	objects[52] = { 8960, 256, 127, 63 };
	objects[53] = { 8960, 128, 191, 127 };
	objects[54] = { 9152, 128, 63, 63 };
	objects[55] = { 9472, 128, 63, 63 };
	objects[56] = { 9536, 128, 63, 127 };
	objects[57] = { 9600, 128, 191, 191 };
	objects[58] = { 9664, 320, 127, 63 };
	objects[59] = { 9920, 128, 191, 127 };
	objects[60] = { 9920, 256, 127, 63 };
	objects[61] = { 9920, 320, 63, 63 };
	objects[62] = { 10112, 128, 63, 63 };
	objects[63] = { 10432, 128, 127, 127 };
	objects[64] = { 11456, 128, 127, 127 };
	objects[65] = { 11584, 128, 63, 63 };
	objects[66] = { 11648, 128, 191, 127 };
	objects[67] = { 11712, 256, 127, 63 };
	objects[68] = { 11776, 320, 63, 63 };
	objects[69] = { 11840, 128, 319, 319 };
	objects[70] = { 12032, 448, 127, 191 };
	objects[71] = { 11968, 512, 63, 63 };
	objects[72] = { 11904, 448, 127, 63 };
	objects[73] = { 10752, 320, 63, 63 };
	objects[74] = { 10816, 320, 63, 63 };
	objects[75] = { 10880, 320, 63, 63 };
	objects[76] = { 10944, 320, 63, 63 };
	objects[77] = { 12672, 128, 63, 63 };

}
void setEnemy()
{
	enemyObjects[0] = { 1332, 385, 1332, 385, 63, 63, 1, true };
	enemyObjects[1] = { 1422, 385, 1422, 385, 63, 63, 1, true };
}
void enemyCollision()
{
	for (int e = 0; e < enemyCount; e++)
	{
		//cout << "hello" << endl;
		if (!detectCollisionObjects(-1, 0, e))
	{
		enemyObjects[e].x = enemyObjects[e].x - 1;
		enemyObjects[e].levelX = enemyObjects[e].levelX - 1;
	}
	if (!detectCollisionObjects(0, -1, e))
	{
		enemyObjects[e].y = enemyObjects[e].y - 1;
		enemyObjects[e].levelY = enemyObjects[e].levelY - 1;
	}
	}
}
bool detectCollisionObjects(int x, int y,int e)
{
	for (int i = 0; i < objectCount; i++)
	{
		if (aabbCollisionObjects(x, y, e, i))
		{
			return true;
		}
	}
	return false;
}
bool aabbCollisionObjects(int x, int y, int e,int i)
{

	//cout << "e = " << e << " i = " << i << endl;
	if (objects[i].x > (enemyObjects[e].levelX + enemyObjects[e].width + x))//enemyObjects[o].x + enemyObjects[o].width
	{
		//cout << "error 1" << endl;
		return false;
	}
	//cout << "Failed first check" << endl;
	if ((objects[i].x + objects[i].width) < (enemyObjects[e].levelX + x))//enemyObjects[o].x
	{
		//cout << "error 2" << endl;
		return false;
	}
	//cout << "Failed second check" << endl;
	if (objects[i].y > (enemyObjects[e].levelY + enemyObjects[e].height + y))//enemyObjects[o].y + enemyObjects[o].height
	{
		//cout << "error 3" << endl;
		return false;
	}
	//cout << "Failed third check" << endl;
	if ((objects[i].y + objects[i].height) < (enemyObjects[e].levelY + y))//enemyObjects[o].y
	{
		return false;
		//cout << "i = " << i << " objects[i].y = " << objects[i].y << " objects[i].height = " << objects[i].height << " e = " << e << " enemyobjects[i].y = " << enemyObjects[e].y << " enemyobjects[i].height = " << enemyObjects[e].height << " y = " << y << endl;
	}
	//cout << "Failed fourth check" << endl;
	//cout << "i = " << i << " objects[i].y = " << objects[i].y << " objects[i].height = " << objects[i].height << " enemyobjects[e].levelY = " << enemyObjects[e].levelY <<" y = " << y << endl;
	//cout << "colliding" << endl;
	return true;

}
bool aabbCollisionMario(int a,int x,int y)
{
	if (objects[a].x > x + marioWidth)
		return false;
	if (objects[a].x + objects[a].width < x)
		return false;
	if (objects[a].y > y + marioHeight)
		return false;
	if (objects[a].y + objects[a].height < y)
		return false;
	return true;
}
void marioLevelBound(int x, int y)
{
	if (marioX + x >= 0 && marioX + x <=312)
	{
		marioX = marioX + x;
		marioTrueX += x;
	}
	else if (marioX + x == 313)
	{
		if (13504 + levelX - screenWidth - x >= 0)
		{
			levelX = levelX - x;
			marioTrueX += x;
			levelScroll();
		}
	}
	if (marioY + y >= 0 && marioY + y <= 856)
	{
		marioY += y;
	}
}
void levelScroll()
{
	for (int i = 0; i < enemyCount; i++)
	{
		enemyObjects[i].x--;
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
	if (m_keys[0x4C].bHeld == true)
	{
		enemyObjects[0].alive = false;
	}
	if (m_keys[0x4A].bHeld == true)
	{
		marioCollision(-1, 0);
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
bool marioCollision(int x,int y)                                        // Requested position of Mario first comes here. It is generally called wtih either x or y but not both. It exectues the first for loop if the movement is in x direction and the second if it is in y direction.It calls another function to check for collision. The purpose of this function is to check collision by moving 1 unit at a time.
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
		if (!detectCollision(marioTrueX + k, marioY))
		{
			marioLevelBound(k, 0);
		}
		else
		{
			return false;
		}
	}
	for (i = 1; i <= abs(y); i++)
	{
		if (!detectCollision(marioTrueX, marioY + l))
		{
			marioLevelBound(0, l);
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool detectCollision(int x, int y)
{
	int i;
	for (i = 0; i < objectCount; i++)
	{
		if (aabbCollisionMario(i,x,y))                                  
		{
			cout << "mario colliding" << endl;
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
		if (aabbCollisionMario(i, marioTrueX, marioY-1))
		{
			return true;
		}
	}
	return false;
	
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
		else if (marioIndex == 2 && pos == true)
		{
			marioIndex++;
		}
		else if (marioIndex == 2 && pos == false)
		{
			marioIndex--;
		}
		else if (marioIndex == 3)
		{
			pos = false;
			marioIndex--;
		}
		else if (marioIndex == 1)
		{
			pos = true;
			marioIndex++;
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
			if (!marioCollision(0, 10))
			{
				jumpUp = false;
			}
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
	setEnemy();
	iSetTimer(100, change);
	iSetTimer(1, winInput);
	iSetTimer(8, checkInput);
	iSetTimer(16, gravity);
	iSetTimer(10, enemyCollision);
	iInitialize(screenWidth, screenHeight, "Project Mario");
	loadLevel();
	iStart();
	return 0;
}
//*******************************************************************end***********************************************************************//