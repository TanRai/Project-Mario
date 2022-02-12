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
		if (currentLevel == 1)
		{
			iShowImage(levelX, levelY, 13504, 960, levelTexture);
		}
		else if (currentLevel == 2)
		{
			iShowImage(levelX, levelY, 12228, 960, level2Texture);
		}
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
	levelTexture = iLoadImage("Levels\\World 1-1\\Background.png");
	level2Texture = iLoadImage("Levels\\World 1-2\\Level 2.png");
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
	if (ahead == true)
	{
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
				else if (jump == false)
				{
					marioIndex = 0;
				}
			}
			else if (jump == true)
			{
				marioIndex = 4;
			}
			else
			{
				marioIndex = 0;
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
				else if (jump == false)
				{
					marioIndex = 6;
				}
			}
			else if (jump == true)
			{
				marioIndex = 10;
			}
			else
			{
				marioIndex = 6;
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
				else if (jump == false)
				{
					marioIndex = 11;
				}
			}
			else if (jump == true)
			{
				marioIndex = 15;
			}
			else
			{
				marioIndex = 11;
			}
		}
	}
	else
	{
		if (marioPowerState == 0)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 16)
				{
					marioIndex = 19;
				}
				else if (marioIndex == 18 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 18 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 19)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 17)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 16;
				}
			}
			else if (jump == true)
			{
				marioIndex = 20;
			}
			else
			{
				marioIndex = 16;
			}
		}
		else if (marioPowerState == 1)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 21)
				{
					marioIndex = 24;
				}
				else if (marioIndex == 23 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 23 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 24)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 22)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 21;
				}
			}
			else if (jump == true)
			{
				marioIndex = 25;
			}
			else
			{
				marioIndex = 21;
			}
		}
		else if (marioPowerState == 2)
		{
			if (marioMove == true && jump == false)
			{
				if (marioIndex == 26)
				{
					marioIndex = 29;
				}
				else if (marioIndex == 28 && pos == true)
				{
					marioIndex++;
				}
				else if (marioIndex == 28 && pos == false)
				{
					marioIndex--;
				}
				else if (marioIndex == 29)
				{
					pos = false;
					marioIndex--;
				}
				else if (marioIndex == 27)
				{
					pos = true;
					marioIndex++;
				}
				else if (jump == false)
				{
					marioIndex = 26;
				}
			}
			else if (jump == true)
			{
				marioIndex = 30;
			}
			else
			{
				marioIndex = 26;
			}
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
	restart();
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
void restart()
{
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	objectCount = 78;
	marioHeight = 64;
	marioWidth = 48;
	marioMove = false;
	marioIndex = 0;
	levelX = 0;
	levelY = 0;
	marioTrueX = 200;
	marioX = 200;
	marioY = 128; //default 128
	jumpDistance = 0;
	enemyCount = 17;
	npcCount = 13;
	marioPowerState = 0;
	fired = false;
	fireCount = 0;
	for (int i = 0; i < 10; i++)
	{
		encounter[i] = false;
	}
	setObjects();
	setEnemy();
	setNpc();
	clockTime = 150;
	iResumeTimer(checkInputTimer);
	iResumeTimer(gravityTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
}
void loadLevel2()
{
	iPauseTimer(checkInputTimer);
	iPauseTimer(gravityTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	objectCount = 1;
	marioMove = false;
	levelX = 0;
	levelY = 0;
	marioTrueX = 200;
	marioX = 200;
	marioY = 128; //default 128
	jumpDistance = 0;
	enemyCount = 0;
	npcCount = 0;
	fired = false;
	fireCount = 0;
	clockTime = 150;
	setObjects2();
	cout << levelX << endl;
	cout << levelY << endl;
	iResumeTimer(checkInputTimer);
	iResumeTimer(gravityTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
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