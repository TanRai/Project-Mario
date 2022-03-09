#include<iostream>
#include <cstdlib>
#include <string>
#include <irrKlang.h>
#pragma comment(lib,"irrKlang.lib")
using namespace std;
#include "iGraphics.h"
#include "WinUser.h"
#include "FunctionDeclarations.h"
#include "Variables.h"
#include "Input.h"
#include "Collision.h"
#include "SetFunctions.h"
#include "Fire.h"
#include "Music.h"
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
			iShowImage(levelX, levelY, 11328, 960, level2Texture);
			for (int i = 0; i < 17; i++)
			{
				if (coins[i].show == true)
				{
					iShowBMP2(coins[i].x, coins[i].y, static_coin[0], 0);
				}
			}
		}
		else if (currentLevel == 3)
		{
			iShowImage(levelX, levelY, 2240, 960, level3Texture);
		}
		else if (currentLevel == 4)
		{
			iShowImage(levelX, levelY, 10240, 960, level4Texture);
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
				if (currentLevel == 1)
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
				else if (currentLevel == 2)
				{
					if (objects[i].type == "brick")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, brickTexture2);
					}
					else if (objects[i].type == "power")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, powerTexture2);
					}
					else if (objects[i].type == "done")
					{
						iShowImage(objects[i].x, objects[i].y, 64, 64, doneTexture2);
					}
					else if (objects[i].type == "ladder")
					{
						iShowImage(objects[i].x, objects[i].y, 192, 32, ladderTexture);
					}
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
	else if (gameState == 5)
	{
		iShowBMP(0, 0, "Levels\\Game Over\\gameover.bmp");
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
						if (npc[objects[i].linkedObject].objectType == "coin")
						{
							engine->play2D("Music/smb_coin.wav");
						}
						else if (npc[objects[i].linkedObject].objectType == "mushroom")
						{
							engine->play2D("Music/smb_powerup_appears.wav");
						}
						objects[i].type = "done";
					}
				}
				else if (objects[i].type == "brick")
				{
					if (aabbCollisionMario(i, marioTrueX, marioY + y))
					{
						objects[i].show = false;
						engine->play2D("Music/smb_breakblock.wav");
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
	for (int i = 0; i < 17; i++)
	{
		coins[i].x--;
	}
}
void loadTexture()
{
	levelTexture = iLoadImage("Levels\\World 1-1\\Background.png");
	level2Texture = iLoadImage("Levels\\World 1-2\\Level 2.png");
	level3Texture = iLoadImage("Levels\\World 1-2\\Level 2_2.png");
	level4Texture = iLoadImage("Levels\\World 1-4\\Level 4.png");
	brickTexture = iLoadImage("Objects\\Brick\\brick.bmp");
	powerTexture = iLoadImage("Objects\\Brick\\power.bmp");
	doneTexture = iLoadImage("Objects\\Brick\\done.bmp");
	brickTexture2 = iLoadImage("Objects\\Brick\\brick2.bmp");
	powerTexture2 = iLoadImage("Objects\\Brick\\power2.bmp");
	doneTexture2 = iLoadImage("Objects\\Brick\\done2.bmp");
	ladderTexture = iLoadImage("Objects\\Ladder\\ladder.bmp");
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
		if (jumpDistance + 12 <= jumpLimit && jumpUp)
		{
			jumpDistance += 12;
			if (!marioCollision(0, 12))
			{
				objectCollsionCheck(12);
				jumpUp = false;
			}
		}
		else
		{
			jumpDistance = 0;
			jumpUp = false;
			marioCollision(0, -12);
			if (ground())
			{
				jump = false;
			}
		}
	}
	else
	{
		marioCollision(0, -10);
	}
	if (currentLevel == 2)
	{
		for (int i = 288; i <= 289; i++)
		{
			if (!((objects[i].levelX > marioTrueX + marioWidth) || (objects[i].levelX + objects[i].width < marioTrueX) || (objects[i].levelY > marioY + marioHeight) || (objects[i].levelY + objects[i].height < marioY - 1)))
			{
				marioY -= 4;
			}
			objects[i].y -= 4;
			objects[i].levelY -= 4;
			if (objects[i].y < -100)
			{
				objects[i].y = 1060;
				objects[i].levelY = 1060;
			}
		}
		for (int i = 290; i <= 291; i++)
		{
			objects[i].y += 4;
			objects[i].levelY += 4;
			if (!((objects[i].levelX > marioTrueX + marioWidth) || (objects[i].levelX + objects[i].width < marioTrueX) || (objects[i].levelY > marioY + marioHeight) || (objects[i].levelY + objects[i].height < marioY - 1)))
			{
				marioY += 4;
			}
			if (objects[i].y > 1060)
			{
				objects[i].y = -100;
				objects[i].levelY = -100;
			}
		}
	}
}
void loadLevel1(){
	setObjects();
	setEnemy();
	setNpc();
	if (!changeTimer)
	{
		changeTimer = iSetTimer(100, change);
	}
	else
	{
		iResumeTimer(changeTimer);
	}
	if (!fourmsTimer)
	{
		fourmsTimer = iSetTimer(4, fourms);
	}
	else
	{
		iResumeTimer(fourmsTimer);
	}
	if (!fireCheckTimer)
	{
		fireCheckTimer = iSetTimer(800, fireCheck);
	}
	else
	{
		iResumeTimer(fireCheckTimer);
	}
	if (!clockTimer)
	{
		clockTimer = iSetTimer(1000, gameClock);
	}
	else
	{
		iResumeTimer(clockTimer);
	}
	createSoundEngine();
}
void pipeDetect()
{
	if (currentLevel == 2)
	{
		if (aabbCollisionMario(138, marioTrueX, marioY - 1) && aabbCollisionMario(283, marioTrueX + 1, marioY))
		{
			cout << "KILLLLLLLLLL!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			elevateMario();
		}
	}
}
void fourms(){
	npcCollision();
	fireCollision();
	gravity();
	enemyCollision();
	coinCollision();
	pipeDetect();
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
	int i;
	for (i = 0; temp != 0; i++)
	{
		temp2 = temp % 10;
		iShowBMP2(x, y, number[temp2], 0);
		x -= 32;
		temp = temp / 10;
	}
	for (int j = 3 - i; j != 0; j--)
	{
		iShowBMP2(x, y, number[0], 0);
		x -= 32;
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
	marioHeight = 63;
	marioWidth = 48;
	marioMove = false;
	marioIndex = 0;
	levelX = 0;
	levelY = 0;
	marioTrueX = 200;
	marioX = 200;
	marioY = 128; 
	jumpDistance = 0;
	marioPowerState = 0;
	fired = false;
	fireCount = 0;
	clockTime = 150;
	if (currentLevel == 1)
	{
		objectCount = 78;
		enemyCount = 17;
		npcCount = 13;
		for (int i = 0; i < 10; i++)
		{
			encounter[i] = false;
		}
		setObjects();
		setEnemy();
		setNpc();
		engine->play2D("Music/smb_overworld.wav");
	}
	else if (currentLevel == 2)
	{
		setCoins();
		objectCount = 292;
		for (int i = 0; i < 11; i++)
		{
			encounter[i] = false;
		}
		enemyCount = 16;
		npcCount = 5;
		setEnemy2();
		setObjects2();
		setNpc2();
		engine->play2D("Music/smb_underground.wav");
	}
	else if (currentLevel == 4)
	{
		objectCount = 39;
		marioTrueX = 100;
		marioX = 100;
		marioY = 532; //default 128
		enemyCount = 0;
		npcCount = 1;
		setNpc3();
		setObjects4();
		engine->play2D("Music/smb_castle.wav");
	}
	iResumeTimer(checkInputTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
	
}

void loadLevel2()
{
	setCoins();
	setEnemy2();
	setNpc2();
	currentLevel = 2;
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	objectCount = 292;
	marioMove = false;
	levelX = 0;
	levelY = 0;
	marioTrueX = 200;
	marioX = 200;
	marioY = 880; //default 128
	jumpDistance = 0;
	enemyCount = 16;
	npcCount = 5;
	fired = false;
	fireCount = 0;
	clockTime = 150;
	setObjects2();
	for (int i = 0; i < 11; i++)
	{
		encounter[i] = false;
	}
	cout << levelX << endl;
	cout << levelY << endl;
	iResumeTimer(checkInputTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
	engine->play2D("Music/smb_underground.wav");
}
void death()
{
	marioLife -= 1;
	marioIndex = 5;
	engine->stopAllSounds();
	engine->play2D("Music/smb_mariodie.wav");
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	storedMarioY = marioY;
	if (marioLife > 0)
	{
		animationCall("death");
	}
	else
	{
		animationCall("gameover");
	}
	
}
void loadLevel4()
{
	currentLevel = 4;
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	objectCount = 39;
	marioMove = false;
	levelX = 0;
	levelY = 0;
	marioTrueX = 100;
	marioX = 100;
	marioY = 532; //default 128
	jumpDistance = 0;
	enemyCount = 0;
	npcCount = 1;
	fired = false;
	fireCount = 0;
	clockTime = 150;
	setNpc3();
	setObjects4();
	for (int i = 0; i < 11; i++)
	{
		encounter[i] = false;
	}
	iResumeTimer(checkInputTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
	engine->play2D("Music/smb_castle.wav");
}
void animationCall(string x){
	animationState = x;
	capturedTime = relativeTime;
	if (!animationTimer)
	{
		animationTimer = iSetTimer(10, animation);/////
	}
	else
	{
		iResumeTimer(animationTimer);
	}
}
void animation(){
	if (animationState == "death")
	{
		if ((!deathHeightReached) && (storedMarioY + 600 > marioY))
		{
			marioY += 10;
			if (storedMarioY + 600 <= marioY)
			{
				deathHeightReached = true;
			}
		}
		else if (marioY > -300)
		{
			marioY -= 10;
		}
		else
		{
			iPauseTimer(animationTimer);
			animationState = "";
			deathHeightReached = false;
			restart();
		}
	}
	else if (animationState == "levelEnd")
	{
		if (!levelEnd_ground){
			marioCollision(0, -5);
			cout << marioY << endl;
			if (marioY == 192)
			{
				levelEnd_ground = true;
			}
		}
		else
		{
			if (!levelboundreached)
			{
				marioCollision(5, -5);
			}
			else
			{
				if (marioX < 550)
				{
					marioX += 5;
				}
				else
				{
					marioX = 2000;
				}
			}
		}
		if (clockTime > 0)
		{
			clockTime -= 1;
			point += 50;
		}
		if (capturedTime + 7 < relativeTime)
		{
			cout << "loading level 2" << endl;
			iPauseTimer(animationTimer);
			animationState = "";
			levelEnd_ground = false;
			levelboundreached = false;
			levelEndFlag = false;
			if (currentLevel == 1)
			{
				loadLevel2();
			}
			else if (currentLevel == 3)
			{
				loadLevel4();
			}
			
		}
	}
	else if (animationState == "gameover")
	{
		if ((!deathHeightReached) && (storedMarioY + 600 > marioY))
		{
			marioY += 10;
			if (storedMarioY + 600 <= marioY)
			{
				deathHeightReached = true;
			}
		}
		else if (marioY > -300)
		{
			marioY -= 10;
		}
		else
		{
			//iPauseTimer(animationTimer);
			//animationState = "";
			deathHeightReached = false;
			gameState = 5;
			animationState = "gameover-screen";
			engine->play2D("Music/smb_gameover.wav");
			capturedTime = relativeTime;
		}
	}
	else if (animationState == "gameover-screen")
	{
		if (capturedTime + 5 < relativeTime)
		{
			iPauseTimer(animationTimer);
			animationState = "";
			gameState = 1;
			resetAll();
		}
	}
	else if (animationState == "elevate")
	{
		if (capturedTime + 3 < relativeTime)
		{
			iPauseTimer(animationTimer);
			animationState = "";
			loadLevel3();
		}
	}
}
void loadLevel3()
{
	setObjects3();
	currentLevel = 3;
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	jumpUp = false;
	jump = false;
	pos = false;
	ahead = true;
	objectCount = 11;
	marioMove = false;
	levelX = 0;
	levelY = 0;
	marioTrueX = 200;
	marioX = 200;
	marioY = 256; //default 128
	jumpDistance = 0;
	enemyCount = 0;
	npcCount = 0;
	fired = false;
	fireCount = 0;
	iResumeTimer(checkInputTimer);
	iResumeTimer(fourmsTimer);
	iResumeTimer(changeTimer);
	iResumeTimer(clockTimer);
	engine->play2D("Music/smb_overworld.wav");
}
void resetAll(){
	jumpUp = false;
	jump = false;
	jumpLimit = 300;
	pos = false;
	objectCount = 78;
	marioHeight = 63;
	marioWidth = 48;
	marioMove = false;
	marioIndex = 0;
	levelX = 0;
	levelY = 0;
	loadFlag = 1;
	marioTrueX = 200;
	marioX = 200;
	marioY = 128; 
	screenWidth = 1024;
	screenHeight = 960;
	jumpDistance = 0;
	enemyCount = 17;
	gameState = 1;
	npcCount = 13;
	marioPowerState = 0;
	fired = false;
	fireCount = 0;
	for (int i = 0; i < 10; i++)
	{
		encounter[i] = false;
	}
	point = 0;
	clockTime = 150;
	cursorX = 320;
	cursorY = 380;
	cursorPosition = 1;
	ahead = true;
	currentLevel = 1;
	deathHeightReached = false;
	animationState = "";
	levelEnd_ground = false;
	levelEndFlag = false;
	levelboundreached = false;
	relativeTime = 0;
	marioLife = 3;
	iResumeTimer(checkInputTimer);
}
void levelEnd(){
	
	if (marioPowerState == 0)
		marioIndex = 0;
	else if (marioPowerState == 1)
		marioIndex = 6;
	else if (marioPowerState == 2)
		marioIndex = 11;
	engine->stopAllSounds();
	engine->play2D("Music/smb_stage_clear.wav");
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	animationCall("levelEnd");
}
void elevateMario()
{
	engine->stopAllSounds();
	engine->play2D("Music/smb_pipe.wav");
	iPauseTimer(checkInputTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
	iPauseTimer(clockTimer);
	marioX = 1200;
	animationCall("elevate");
}
void gameTime(){
	relativeTime += 1;
}
//*******************************************************************main***********************************************************************//
int main()
{
	setInput();
	iSetTimer(1, winInput);
	checkInputTimer = iSetTimer(8, checkInput);
	iSetTimer(1000, gameTime);
	iInitialize(screenWidth, screenHeight, "Project Mario");
	loadTexture();
	iStart();
	return 0;
}
//*******************************************************************end***********************************************************************//