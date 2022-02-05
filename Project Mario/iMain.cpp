#include<iostream>
#include <cstdlib>
using namespace std;
#include "iGraphics.h"
#include "WinUser.h"
#include "FunctionDeclarations.h"
#include "Variables.h"
#include "Input.h"
#include "Collision.h"
#include "SetFunctions.h"
#include "Fire.h"
//*******************************************************************iDraw***********************************************************************//
void iDraw()
{
	iClear();
	if (gameState == 1)
	{
		iShowBMP(0, 0, "Levels\\Main Menu\\Main-menu.bmp");
		pointDraw();
		clockDraw();
		iShowBMP2(cursorX, cursorY, "Font\\UI\\cursor.bmp", 255);
	}
	else if (gameState == 2)
	{
		iShowBMP(0, 0, "Levels\\Main Menu\\help.bmp");
	}
	else if (gameState == 3)
	{
		iShowBMP(0, 0, "Levels\\Main Menu\\credits.bmp");
	}
	else if (gameState == 4)
	{
		iShowImage(levelX, levelY, 13504, 960, levelTexture);
		iShowBMP2(marioX, marioY, Mario[marioIndex], 0);
		for (int i = 0; i < enemyCount; i++)
		{
			if (enemyObjects[i].alive == true)
			{
				iShowBMP2(enemyObjects[i].x, enemyObjects[i].y, goomba[0], 255);
			}
		}
		for (int i = 0; i < npcCount; i++)
		{
			if (npc[i].show == true)
			{
				//cout <<"Showing NPC = "<< i << endl;
				if (npc[i].objectType == "mushroom")
				{
					iShowBMP2(npc[i].x, npc[i].y, mushroom[0], 0);
				}
				else if (npc[i].objectType == "coin")
				{
					iShowBMP2(npc[i].x, npc[i].y, coin[0], 0);
				}
				
			}
		}
		for (int i = 0; i < objectCount; i++)
		{
			if (objects[i].show == true)
			{
				if (objects[i].type == "brick")
				{
					iShowImage(objects[i].x, objects[i].y, 64, 64, brickTexture);
				}
				else if (objects[i].type == "power")
				{
					iShowImage(objects[i].x, objects[i].y, 64, 64, powerTexture);
				}
				else if (objects[i].type == "done")
				{
					iShowImage(objects[i].x, objects[i].y, 64, 64, doneTexture);
				}
			}
		}
		for (int i = 0; i < fireCount; i++)
		{
			//cout << "value = " << i << "        " << fireObjects[i].status << endl;
			if (fireObjects[i].status == true)
			{
				//cout << "displaying fire" << endl;
				iShowBMP2(fireObjects[i].x, fireObjects[i].y, fire[0], 0);
			}
		}
		pointDraw();
		clockDraw();
		UIDraw();
	}
}
//******************************************************************Useless **************************************************************************//
void iMouseMove(int mx, int my)
{

}
void iPassiveMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{

}
void iKeyboard(unsigned char key)
{

}
void iSpecialKeyboard(unsigned char key)
{

}

//*******************************************************************My Functions***********************************************************************//d
void objectCollsionCheck(int y)
{
	if (jumpUp == true)
	{
		for (int i = 0; i < objectCount; i++)
		{
			if (objects[i].show == true)
			{
				if (objects[i].type == "power")
				{
					if (aabbCollisionMario(i, marioTrueX, marioY + y))
					{
						//cout << "colliding with power = " << i << endl;
						npc[objects[i].linkedObject].show = true;
						objects[i].type = "done";
					}
				}
				if (objects[i].type == "brick")
				{
					if (aabbCollisionMario(i, marioTrueX, marioY + y))
					{
						objects[i].show = false;
						pointAdd(50);
					}
				}
			}
		}
	}
}
void levelScroll()
{
	for (int i = 0; i < enemyCount; i++)
	{
		enemyObjects[i].x--;
	}
	for (int i = 0; i < npcCount; i++)
	{
		npc[i].x--;
	}
	for (int i = 0; i < objectCount;i++)
	{
		objects[i].x--;
	}
	for (int i = 0; i < fireCount; i++)
	{
		fireObjects[i].x--;
	}
}
void loadLevel()
{
	if (loadFlag == 1)
	{
		levelTexture = iLoadImage("Levels\\World 1-1\\Background.png");
		loadFlag = 0;
	}
	brickTexture = iLoadImage("Objects\\Brick\\brick.bmp");
	powerTexture = iLoadImage("Objects\\Brick\\power.bmp");
	doneTexture = iLoadImage("Objects\\Brick\\done.bmp");
}

bool ground()
{
	int i;
	for(i=0;i<objectCount;i++)
	{
		if (objects[i].show == true)
		{
			if (aabbCollisionMario(i, marioTrueX, marioY - 1))
			{
				return true;
			}
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
	if (marioPowerState == 0)
	{
		if (marioMove == true && jump == false)
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
		else if (jump == true)
		{
			marioIndex = 4;
		}
	}
	else if (marioPowerState == 1)
	{
		if (marioMove == true && jump == false)
		{
			if (marioIndex == 6)
			{
				marioIndex = 9;
			}
			else if (marioIndex == 8 && pos == true)
			{
				marioIndex++;
			}
			else if (marioIndex == 8 && pos == false)
			{
				marioIndex--;
			}
			else if (marioIndex == 9)
			{
				pos = false;
				marioIndex--;
			}
			else if (marioIndex == 7)
			{
				pos = true;
				marioIndex++;
			}
		}
		else if (jump == false)
		{
			marioIndex = 6;
		}
		else if (jump == true)
		{
			marioIndex = 10;
		}
	}
	else if (marioPowerState == 2)
	{
		if (marioMove == true && jump == false)
		{
			if (marioIndex == 11)
			{
				marioIndex = 14;
			}
			else if (marioIndex == 13 && pos == true)
			{
				marioIndex++;
			}
			else if (marioIndex == 13 && pos == false)
			{
				marioIndex--;
			}
			else if (marioIndex == 14)
			{
				pos = false;
				marioIndex--;
			}
			else if (marioIndex == 12)
			{
				pos = true;
				marioIndex++;
			}
		}
		else if (jump == false)
		{
			marioIndex = 11;
		}
		else if (jump == true)
		{
			marioIndex = 15;
		}
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
				objectCollsionCheck(10);
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
				//marioIndex = 0;
			}
		}
	}
	else
	{
		marioCollision(0, -10);
	}
}
void loadLevel1(){
	setObjects();
	setEnemy();
	setNpc();
	changeTimer = iSetTimer(100, change);
	gravityTimer = iSetTimer(16, gravity);
	fourmsTimer = iSetTimer(4, fourms);
	iSetTimer(800, fireCheck);
	clockTimer = iSetTimer(1000, gameClock);
}
void fourms(){
	npcCollision();
	fireCollision();
	enemyCollision();
}
void death()
{
	marioIndex = 5;
	iPauseTimer(checkInputTimer);
	iPauseTimer(gravityTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
}
void pointAdd(int x)
{
	point += x;
	cout << "point = " << point << endl;
}
void pointDraw()
{
	int temp = point;
	int temp2;
	int x = 256;
	int y = 832;
	int i;
	for (i = 0; temp != 0; i++)
	{
		temp2 = temp % 10;
		iShowBMP2(x, y, number[temp2], 0);
		x -= 32;
		temp = temp / 10;
	}
	for (int j = 6 - i; j != 0; j--)
	{
		iShowBMP2(x, y, number[0], 0);
		x -= 32;
	}
}
void clockDraw()
{
	int temp = clockTime;
	int temp2;
	int x = 892;
	int y = 832;
	for (int i = 0; temp != 0; i++)
	{
		temp2 = temp % 10;
		iShowBMP2(x, y, number[temp2], 0);
		x -= 32;
		temp = temp / 10;
	}
}
void UIDraw()
{
	iShowBMP2(93, 868, "Font\\UI\\mario.bmp", 0);
	iShowBMP2(801, 868, "Font\\UI\\time.bmp", 0);
}
void gameClock()
{
	clockTime -= 1;
	if (clockTime == 0)
	{
		death();
	}
}
//*******************************************************************main***********************************************************************//
int main()
{
	setInput();
	iSetTimer(1, winInput);
	checkInputTimer = iSetTimer(8, checkInput);
	iInitialize(screenWidth, screenHeight, "Project Mario");
	loadLevel();
	iStart();
	return 0;
}
//*******************************************************************end***********************************************************************//