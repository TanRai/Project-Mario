#include<iostream>
#include <cstdlib>
using namespace std;
#include "iGraphics.h"
#include "WinUser.h"
#include "FunctionDeclarations.h"
#include "Variables.h"
#include "Input.h"
#include "Collision.h"
//*******************************************************************iDraw***********************************************************************//
void iDraw()
{
	iClear();
	if (gameState == 1)
	{
		iShowBMP(0, 0, "Levels\\Main Menu\\Main-menu.bmp");
	}
	else if (gameState == 2)
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

//*******************************************************************My Functions***********************************************************************//
void setObjects()
{
	objects[0] = { 0, 0, 0, 0, 4415, 127, "floor", true ,-1};
	objects[1] = { 1792, 128, 1792, 128, 128, 128, "pipe", true, -1 };
	objects[2] = { 2432, 128, 2432, 128, 128, 192, "pipe", true, -1 };
	objects[3] = { 1024, 321, 1024, 321, 63, 63, "power", true, 0 };
	objects[4] = { 1280, 321, 1280, 321, 63, 63, "brick", true, -1 };
	objects[5] = { 1344, 321, 1344, 321, 63, 63, "power", true, 1 };
	objects[6] = { 1408, 321, 1408, 321, 63, 63, "brick", true, -1 };
	objects[7] = { 1472, 321, 1472, 321, 63, 63, "power", true, 2 };
	objects[8] = { 1536, 321, 1536, 321, 63, 63, "brick", true, -1 };
	objects[9] = { 1408, 577, 1408, 577, 63, 63, "power", true, 3 };
	objects[10] = { 2944, 129, 2944, 129, 127, 255, "pipe", true, -1 };
	objects[11] = { 3648, 129, 3648, 129, 127, 255, "pipe", true, -1 };
	objects[12] = { 5696, 0, 5696, 0, 4095, 127, "floor", true, -1 };
	objects[13] = { 4544, 0, 4544, 0, 959, 127, "floor", true, -1 };
	objects[14] = { 4928, 321, 4928, 321, 63, 63, "brick", true, -1 };
	objects[15] = { 4992, 321, 4992, 321, 63, 63, "power", true, 4 };
	objects[16] = { 5056, 321, 5056, 321, 63, 63, "brick", true, -1 };
	objects[17] = { 5120, 577, 5120, 577, 63, 63, "brick", true, -1 };
	objects[18] = { 5184, 577, 5184, 577, 63, 63, "brick", true, -1 };
	objects[19] = { 5248, 577, 5248, 577, 63, 63, "brick", true, -1 };
	objects[20] = { 5312, 577, 5312, 577, 63, 63, "brick", true, -1 };
	objects[21] = { 5376, 577, 5376, 577, 63, 63, "brick", true, -1 };
	objects[22] = { 5440, 577, 5440, 577, 63, 63, "brick", true, -1 };
	objects[23] = { 5504, 577, 5504, 577, 63, 63, "brick", true, -1 };
	objects[24] = { 5568, 577, 5568, 577, 63, 63, "brick", true, -1 };
	objects[25] = { 5824, 577, 5824, 577, 63, 63, "brick", true, -1 };
	objects[26] = { 5888, 577, 5888, 577, 63, 63, "brick", true, -1 };
	objects[27] = { 5952, 577, 5952, 577, 63, 63, "brick", true, -1 };
	objects[28] = { 6016, 577, 6016, 577, 63, 63, "power", true, 5 };
	objects[29] = { 6016, 321, 6016, 321, 63, 63, "brick", true, -1 };
	objects[30] = { 6400, 321, 6400, 321, 63, 63, "brick", true, -1 };
	objects[31] = { 6464, 321, 6464, 321, 63, 63, "brick", true, -1 };
	objects[32] = { 6784, 321, 6784, 321, 63, 63, "power", true, 6 };
	objects[33] = { 6976, 321, 6976, 321, 63, 63, "power", true, 7 };
	objects[34] = { 7168, 321, 7168, 321, 63, 63, "power", true, 8 };
	objects[35] = { 7552, 321, 7552, 321, 63, 63, "brick", true, -1 };
	objects[36] = { 6976, 577, 6976, 577, 63, 63, "power", true, 9 };
	objects[37] = { 7744, 577, 7744, 577, 63, 63, "brick", true, -1 };
	objects[38] = { 7808, 577, 7808, 577, 63, 63, "brick", true, -1 };
	objects[39] = { 7872, 577, 7872, 577, 63, 63, "brick", true, -1 };
	objects[40] = { 8256, 321, 8256, 321, 63, 63, "brick", true, -1 };
	objects[41] = { 8320, 321, 8320, 321, 63, 63, "brick", true, -1 };
	objects[42] = { 8192, 577, 8192, 577, 63, 63, "brick", true, -1 };
	objects[43] = { 8256, 577, 8256, 577, 63, 63, "power", true, 10 };
	objects[44] = { 8320, 577, 8320, 577, 63, 63, "power", true, 11 };
	objects[45] = { 8384, 577, 8384, 577, 63, 63, "brick", true, -1 };
	objects[46] = { 9920, 0, 9920, 0, 3583, 127, "floor", true, -1 };
	objects[47] = { 8576, 128, 8576, 128, 63, 63, "rock", true, -1 };
	objects[48] = { 8640, 128, 8640, 128, 191, 127, "rock", true, -1 };
	objects[49] = { 8704, 256, 8704, 256, 127, 63, "rock", true, -1 };
	objects[50] = { 8768, 320, 8768, 320, 63, 63, "rock", true, -1 };
	objects[51] = { 8960, 320, 8960, 320, 63, 63, "rock", true, -1 };
	objects[52] = { 8960, 256, 8960, 256, 127, 63, "rock", true, -1 };
	objects[53] = { 8960, 128, 8960, 128, 191, 127, "rock", true, -1 };
	objects[54] = { 9152, 128, 9152, 128, 63, 63, "rock", true, -1 };
	objects[55] = { 9472, 128, 9472, 128, 63, 63, "rock", true, -1 };
	objects[56] = { 9536, 128, 9536, 128, 63, 127, "rock", true, -1 };
	objects[57] = { 9600, 128, 9600, 128, 191, 191, "rock", true, -1 };
	objects[58] = { 9664, 320, 9664, 320, 127, 63, "rock", true, -1 };
	objects[59] = { 9920, 128, 9920, 128, 191, 127, "rock", true, -1 };
	objects[60] = { 9920, 256, 9920, 256, 127, 63, "rock", true, -1 };
	objects[61] = { 9920, 320, 9920, 320, 63, 63, "rock", true, -1 };
	objects[62] = { 10112, 128, 10112, 128, 63, 63, "rock", true, -1 };
	objects[63] = { 10432, 128, 10432, 128, 127, 127, "pipe", true, -1 };
	objects[64] = { 11456, 128, 11456, 128, 127, 127, "pipe", true, -1 };
	objects[65] = { 11584, 128, 11584, 128, 63, 63, "rock", true, -1 };
	objects[66] = { 11648, 128, 11648, 128, 191, 127, "rock", true, -1 };
	objects[67] = { 11712, 256, 11712, 256, 127, 63, "rock", true, -1 };
	objects[68] = { 11776, 320, 11776, 320, 63, 63, "rock", true, -1 };
	objects[69] = { 11840, 128, 11840, 128, 319, 319, "rock", true, -1 };
	objects[70] = { 12032, 448, 12032, 448, 127, 191, "rock", true, -1 };
	objects[71] = { 11968, 512, 11968, 512, 63, 63, "rock", true, -1 };
	objects[72] = { 11904, 448, 11904, 448, 127, 63, "rock", true, -1 };
	objects[73] = { 10752, 320, 10752, 320, 63, 63, "brick", true, -1 };
	objects[74] = { 10816, 320, 10816, 320, 63, 63, "brick", true, -1 };
	objects[75] = { 10880, 320, 10880, 320, 63, 63, "power", true, 12 };
	objects[76] = { 10944, 320, 10944, 320, 63, 63, "brick", true, -1 };
	objects[77] = { 12672, 128, 12672, 128, 63, 63, "rock", true, -1 };
}
void setEnemy()
{
	enemyObjects[0] = { 1298, 128, 1298, 128, 63, 63, -2, false };
	enemyObjects[1] = { 2587, 128, 2587, 128, 63, 63, -2, false };
	enemyObjects[2] = { 3096, 128, 3096, 128, 63, 63, -2, false };
	enemyObjects[3] = { 3224, 128, 3224, 128, 63, 63, -2, false };
	enemyObjects[4] = { 5128, 641, 5128, 641, 63, 63, -2, false };
	enemyObjects[5] = { 5256, 641, 5256, 641, 63, 63, -2, false };
	enemyObjects[6] = { 6449, 128, 6449, 128, 63, 63, -2, false };
	enemyObjects[7] = { 6577, 128, 6577, 128, 63, 63, -2, false };
	enemyObjects[8] = { 6864, 128, 6864, 128, 63, 63, -2, false };
	enemyObjects[9] = { 7466, 128, 7466, 128, 63, 63, -2, false };
	enemyObjects[10] = { 7594, 128, 7594, 128, 63, 63, -2, false };
	enemyObjects[11] = { 8110, 128, 8110, 128, 63, 63, -2, false };
	enemyObjects[12] = { 8238, 128, 8238, 128, 63, 63, -2, false };
	enemyObjects[13] = { 8310, 128, 8310, 128, 63, 63, -2, false };
	enemyObjects[14] = { 8510, 128, 8510, 128, 63, 63, -2, false };
	enemyObjects[15] = { 11254, 128, 11254, 128, 63, 63, -2, false };
	enemyObjects[16] = { 11370, 128, 11370, 128, 63, 63, -2, false };
}
void encounterCheck()
{
	if (marioTrueX > 548 && !encounter[0])
	{
		encounter[0] = true;
		enemyObjects[0].alive = true;
	}
	if (marioTrueX > 548 && !encounter[1])
	{
		encounter[1] = true;
		enemyObjects[1].alive = true;
	}
	if (marioTrueX > 548 && !encounter[2])
	{
		encounter[2] = true;
		enemyObjects[2].alive = true;
		enemyObjects[3].alive = true;
	}
	if (marioTrueX > 4363 && !encounter[3])
	{
		cout << "encouter 3" << endl;
		encounter[3] = true;
		enemyObjects[4].alive = true;
		enemyObjects[5].alive = true;
	}
	if (marioTrueX > 5699 && !encounter[4])
	{
		encounter[4] = true;
		enemyObjects[6].alive = true;
		enemyObjects[7].alive = true;
	}
	if (marioTrueX > 6114 && !encounter[5])
	{
		encounter[5] = true;
		enemyObjects[8].alive = true;
	}
	if (marioTrueX > 6716 && !encounter[6])
	{
		encounter[6] = true;
		enemyObjects[9].alive = true;
		enemyObjects[10].alive = true;
	}
	if (marioTrueX > 7360 && !encounter[7])
	{
		encounter[7] = true;
		enemyObjects[11].alive = true;
		enemyObjects[12].alive = true;
	}
	if (marioTrueX > 7572 && !encounter[8])
	{
		encounter[8] = true;
		enemyObjects[13].alive = true;
		enemyObjects[14].alive = true;
	}
	if (marioTrueX > 10604 && !encounter[9])
	{
		encounter[9] = true;
		enemyObjects[15].alive = true;
		enemyObjects[16].alive = true;
	}
}
void setNpc()
{
	npc[0] = { 1024, 321, 1024, 321, 61, 61, 0, 3, false, "coin" };
	npc[1] = { 1344, 321, 1344, 321, 61, 61, 0, 3, false, "mushroom" };
	npc[2] = { 1472, 321, 1472, 321, 61, 61, 0, 3, false, "coin" };
	npc[3] = { 1408, 577, 1408, 577, 61, 61, 0, 3, false, "coin" };
	npc[4] = { 4992, 321, 4992, 321, 61, 61, 0, 3, false, "mushroom" };
	npc[5] = { 6016, 577, 6016, 577, 61, 61, 0, 3, false, "coin" };
	npc[6] = { 6784, 321, 6784, 321, 61, 61, 0, 3, false, "coin" };
	npc[7] = { 6976, 321, 6976, 321, 61, 61, 0, 3, false, "coin" };
	npc[8] = { 7168, 321, 7168, 321, 61, 61, 0, 3, false, "coin" };
	npc[9] = { 6976, 577, 6976, 577, 61, 61, 0, 3, false, "mushroom" };
	npc[10] = { 8256, 577, 8256, 577, 61, 61, 0, 3, false, "coin" };
	npc[11] = { 8320, 577, 8320, 577, 61, 61, 0, 3, false, "coin" };
	npc[12] = { 10880, 320, 10880, 320, 61, 61, 0, 3, false, "coin" };
}
void npcCollision()         ///version 3
{
	int flag2;
	for (int i = 0; i < npcCount; i++)
	{
		int j, k, l;
		if (npc[i].velocityX > 0)
		{
			k = 1;
		}
		else if (npc[i].velocityX < 0)
		{
			k = -1;
		}
		l = -1;
		if (npc[i].show == true)
		{
			if (npc[i].objectType == "mushroom")
			{
				if (npc[i].maxHeight < 64)
				{
					npc[i].y += 8;
					npc[i].levelY += 8;
					npc[i].maxHeight += 8;
					//cout << npc[i].maxHeight << endl;
				}
				else
				{
					flag2 = 0;
					for (j = 1; j <= abs(npc[i].velocityX); j++)
					{
						int flag = 0;
						for (int o = 0; o < objectCount; o++)
						{
							if (objects[o].show == true)
							{
								if (aabbCollisionNpc(i, o, k, 0))
								{
									flag = 1;
								}
							}
						}
						if (flag == 0)
						{
							npc[i].x += k;
							npc[i].levelX += k;
						}
						else
						{
							flag2 = 1;
						}
					}
					if (flag2 == 1)
					{
						npc[i].velocityX *= -1;
					}
					for (j = 1; j <= 10; j++)
					{
						int flag = 0;
						for (int o = 0; o < objectCount; o++)
						{
							if (objects[o].show == true)
							{
								if (aabbCollisionNpc(i, o, 0, l))
								{
									flag = 1;
								}
							}
						}
						if (flag == 0)
						{
							npc[i].y += l;
							npc[i].levelY += l;
						}

					}
				}
				if (!((npc[i].levelX > marioTrueX + marioWidth) || (npc[i].levelX + npc[i].width < marioTrueX) || (npc[i].levelY > marioY + marioHeight) || (npc[i].levelY + npc[i].height < marioY)))
				{
					if (marioPowerState < 2)
					{
						if (marioPowerState == 0)
						{
							marioHeight += 64;
						}
						marioPowerState += 1;
					}
					cout << "Power!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					npc[i].show = false;
					pointAdd(1000);
				}
			}
			else if (npc[i].objectType == "coin")
			{
				if (npc[i].maxHeight < 128)
				{
					npc[i].y += 8;
					npc[i].levelY += 8;
					npc[i].maxHeight += 8;
					//cout << npc[i].maxHeight << endl;
				}
				else
				{
					npc[i].show = false;
					pointAdd(200);
				}
			}
		}

	}
}
bool aabbCollisionNpc(int i,int o,int x,int y)
{
	if (objects[o].levelX > (npc[i].levelX + npc[i].width + x))
	{
		return false;
	}
	if ((objects[o].levelX + objects[o].width) < (npc[i].levelX + x))
	{
		return false;
	}
	if (objects[o].levelY > (npc[i].levelY + npc[i].height + y))
	{
		return false;
	}
	if ((objects[o].levelY + objects[o].height) < (npc[i].levelY + y))
	{
		return false;
	}
	return true;
}
void enemyCollision()
{
	int flag2;
	for (int i = 0; i < enemyCount; i++)
	{
		int j, k, l;
		if (enemyObjects[i].velocityX > 0)
		{
			k = 1;
		}
		else if (enemyObjects[i].velocityX < 0)
		{
			k = -1;
		}
		l = -1;
		if (enemyObjects[i].alive == true)
		{
			flag2 = 0;
			for (j = 1; j <= abs(enemyObjects[i].velocityX); j++)
			{
				int flag = 0;
				for (int o = 0; o < objectCount; o++)
				{
					if (objects[o].show == true)
					{
						if (aabbCollisionEnemy(i, o, k, 0))
						{
							flag = 1;
						}
					}
				}
				if (flag == 0)
				{
					enemyObjects[i].x += k;
					enemyObjects[i].levelX += k;
				}
				else
				{
					flag2 = 1;
				}
			}
			if (flag2 == 1)
			{
				enemyObjects[i].velocityX *= -1;
			}
			for (j = 1; j <= 10; j++)
			{
				int flag = 0;
				for (int o = 0; o < objectCount; o++)
				{
					if (objects[o].show == true)
					{
						if (aabbCollisionEnemy(i, o, 0, l))
						{
							flag = 1;
						}
					}
				}
				if (flag == 0)
				{
					enemyObjects[i].y += l;
					enemyObjects[i].levelY += l;
				}
			}
		}
		if (!((enemyObjects[i].levelX > marioTrueX + marioWidth) || (enemyObjects[i].levelX + enemyObjects[i].width < marioTrueX) || (enemyObjects[i].levelY > marioY + marioHeight) || (enemyObjects[i].levelY + enemyObjects[i].height < marioY)))////////////////////here////////////////////////////////////
		{
			if (enemyObjects[i].alive == true)
			{
				if (enemyObjects[i].levelY + 40 < marioY)
				{
					enemyObjects[i].alive = false;
					pointAdd(100);
				}
				else
				{
					cout << "Death !!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					death();
				}
			}
		}
	}
}
bool aabbCollisionEnemy(int e,int o,int x,int y)
{
	if (objects[o].levelX > (enemyObjects[e].levelX + enemyObjects[e].width + x))//enemyObjects[o].x + enemyObjects[o].width
	{
		return false;
	}
	if ((objects[o].levelX + objects[o].width) < (enemyObjects[e].levelX + x))//enemyObjects[o].x
	{
		return false;
	}
	if (objects[o].levelY > (enemyObjects[e].levelY + enemyObjects[e].height + y))//enemyObjects[o].y + enemyObjects[o].height
	{
		return false;
	}
	if ((objects[o].levelY + objects[o].height) < (enemyObjects[e].levelY + y))//enemyObjects[o].y
	{
		return false;
	}
	return true;
}
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
}
void fourms(){
	npcCollision();
	fireCollision();
	enemyCollision();
}
void fireCollision()
{
	int flag2;
	for (int i = 0; i < fireCount; i++)
	{
		int j, k, l;
		if (fireObjects[i].velocityX > 0)
		{
			k = 1;
		}
		else if (fireObjects[i].velocityX < 0)
		{
			k = -1;
		}
		if (fireObjects[i].velocityY > 0)
		{
			l = 1;
		}
		else if (fireObjects[i].velocityY < 0)
		{
			l = -1;
		}
		if (fireObjects[i].status == true)
		{
			flag2 = 0;
			for (j = 1; j <= abs(fireObjects[i].velocityX); j++)
			{
				int flag = 0;
				for (int o = 0; o < objectCount; o++)
				{
					if (objects[o].show == true)
					{
						if (aabbCollisionFireObjects(i, o, k, 0))
						{
							flag = 1;
						}
					}
				}
				if (flag == 0)
				{
					fireObjects[i].x += k;
					fireObjects[i].levelX += k;
				}
				else
				{
					flag2 = 1;
				}
			}
			if (flag2 == 1)
			{
				fireObjects[i].status = false;
			}
			for (j = 1; j <= abs(fireObjects[i].velocityY); j++)
			{
				int flag = 0;
				for (int o = 0; o < objectCount; o++)
				{
					if (objects[o].show == true)
					{
						if (aabbCollisionFireObjects(i, o, 0, l))
						{
							flag = 1;
						}
					}
				}
				if (flag == 0)
				{
					fireObjects[i].y += l;
					fireObjects[i].levelY += l;
					fireObjects[i].maxHeight += l;
				}
				else
				{
					flag2 = 1;
				}
			}
			if (flag2 == 1)
			{
				fireObjects[i].velocityY *= -1;
			}
			else if (fireObjects[i].maxHeight > 48)
			{
				fireObjects[i].velocityY *= -1;
			}
		}
		for (int e = 0; e < enemyCount; e++)
		{
			if (fireObjects[i].status == true)
			{
				if (enemyObjects[e].alive == true)
				{
					if (aabbCollisionFireEnemy(i, e))
					{
						fireObjects[i].status = false;
						enemyObjects[e].alive = false;
						pointAdd(100);
					}
				}
			}
		}
	}
}
bool aabbCollisionFireObjects(int f, int o, int x, int y)
{
	if (objects[o].levelX > (fireObjects[f].levelX + 32 + x))
	{
		return false;
	}
	if ((objects[o].levelX + objects[o].width) < (fireObjects[f].levelX + x))
	{
		return false;
	}
	if (objects[o].levelY > (fireObjects[f].levelY + 32 + y))
	{
		return false;
	}
	if ((objects[o].levelY + objects[o].height) < (fireObjects[f].levelY + y))
	{
		return false;
	}
	return true;
}
bool aabbCollisionFireEnemy(int f, int e)
{
	if (enemyObjects[e].levelX > (fireObjects[f].levelX + 32))
	{
		return false;
	}
	if ((enemyObjects[e].levelX + enemyObjects[e].width) < (fireObjects[f].levelX))
	{
		return false;
	}
	if (enemyObjects[e].levelY > (fireObjects[f].levelY + 32))
	{
		return false;
	}
	if ((enemyObjects[e].levelY + enemyObjects[e].height) < (fireObjects[f].levelY))
	{
		return false;
	}
	return true;
}
void fireStart(int x,int y,int levelX,int levelY)
{
	//cout << "in FireStart" << endl;
	fireObjects[fireCount].x = x;
	fireObjects[fireCount].y = y;
	fireObjects[fireCount].levelX = levelX;
	fireObjects[fireCount].levelY = levelY;
	//cout << fireObjects[fireCount].x << "                  " << fireObjects[fireCount].y << endl;
	fireCount++;
}
void fireCheck()
{
	fired = false;
}
void death()
{
	marioIndex = 5;
	iPauseTimer(checkInputTimer);
	iPauseTimer(gravityTimer);
	iPauseTimer(fourmsTimer);
	iPauseTimer(changeTimer);
}
void pointAdd(int x)
{
	point += x;
	cout << "point = " << point << endl;
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