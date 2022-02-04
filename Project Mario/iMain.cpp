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
				cout <<"Showing NPC = "<< i << endl;
				iShowBMP2(npc[i].x, npc[i].y, mushroom[0], 0);
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
	enemyObjects[0] = { 1332, 385, 1332, 385, 63, 63, 2, true };
	enemyObjects[1] = { 1422, 385, 1422, 385, 63, 63, 2, true };
}
void setNpc()
{
	npc[0] = { 1024, 321, 1024, 321, 61, 61,0, 3, false };
	npc[1] = { 1344, 321, 1344, 321, 61, 61, 0, 3, false };
	npc[2] = { 1472, 321, 1472, 321, 61, 61, 0, 3, false };
	npc[3] = { 1408, 577, 1408, 577, 61, 61, 0, 3, false };
	npc[4] = { 4992, 321, 4992, 321, 61, 61, 0, 3, false };
	npc[5] = { 6016, 577, 6016, 577, 61, 61, 0, 3, false };
	npc[6] = { 6784, 321, 6784, 321, 61, 61, 0, 3, false };
	npc[7] = { 6976, 321, 6976, 321, 61, 61, 0, 3, false };
	npc[8] = { 7168, 321, 7168, 321, 61, 61, 0, 3, false };
	npc[9] = { 6976, 577, 6976, 577, 61, 61, 0, 3, false };
	npc[10] = { 8256, 577, 8256, 577, 61, 61, 0, 3, false };
	npc[11] = { 8320, 577, 8320, 577, 61, 61, 0, 3, false };
	npc[12] = { 10880, 320, 10880, 320, 61, 61, 0, 3, false };
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
			if (npc[i].maxHeight < 64)
			{
				npc[i].y += 8;
				npc[i].levelY += 8;
				npc[i].maxHeight += 8;
				cout << npc[i].maxHeight << endl;
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
			if (!((npc[i].levelX > marioTrueX + marioWidth) || (npc[i].levelX + npc[i].width < marioTrueX) || (npc[i].levelY > marioY + marioHeight) || (npc[i].levelY + npc[i].height < marioY)))////////////////////here////////////////////////////////////
			{
				marioPowerState = 1;
				cout << "Power!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				npc[i].show = false;
			}
		}

	}
}
/*void npcCollision(int x, int y)         ///version 2
{
	int j, k, l;
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
	for (int i = 0; i < npcCount; i++)
	{
		if (npc[i].show == true)
		{
			if (npc[i].maxHeight < 64)
			{
				npc[i].y += 8;
				npc[i].levelY += 8;
				npc[i].maxHeight += 8;
				cout << npc[i].maxHeight << endl;
			}
			else
			{
				for (j = 1; j <= abs(x); j++)
				{
					int flag = 0;
					for (int o = 0; o < objectCount; o++)
					{

						if (aabbCollisionNpc(i, o, k, 0))
						{
							flag = 1;
						}
					}
					if (flag == 0)
					{
						npc[i].x += k;
						npc[i].levelX += k;
					}
				}
				for (j = 1; j <= abs(y); j++)
				{
					int flag = 0;
					for (int o = 0; o < objectCount; o++)
					{

						if (aabbCollisionNpc(i, o, 0, l))
						{
							flag = 1;
						}
					}
					if (flag == 0)
					{
						npc[i].y += l;
						npc[i].levelY += l;
					}

				}
			}
		}
	}
}*/
/*void npcCollision(int x,int y) /////version 1
{
	for (int i = 0; i < npcCount; i++)
	{
		if (npc[i].show == true)
		{
			if (npc[i].maxHeight < 72)
			{
				npc[i].y += 8;
				npc[i].levelY += 8;
				npc[i].maxHeight += 8;
				cout << npc[i].maxHeight << endl;
			}
			else
			{
				int flag = 0;
				for (int o = 0; o < objectCount; o++)
				{
					
					if (aabbCollisionNpc(i,o,x,y))
					{
						flag = 1;
					}
				}
				if (flag == 0)
				{
					if (x)
					{
						npc[i].x += x;
						npc[i].levelX += x;
					}
					if (y)
					{
						npc[i].y += y;
						npc[i].levelY += y;
					}
				}

			}
		}
	}
}*/
bool aabbCollisionNpc(int i,int o,int x,int y)
{
	//cout << o << endl;
	if (objects[o].levelX > (npc[i].levelX + npc[i].width + x))//enemyObjects[o].x + enemyObjects[o].width
	{
		return false;
	}
	if ((objects[o].levelX + objects[o].width) < (npc[i].levelX + x))//enemyObjects[o].x
	{
		return false;
	}
	if (objects[o].levelY > (npc[i].levelY + npc[i].height + y))//enemyObjects[o].y + enemyObjects[o].height
	{
		return false;
	}
	if ((objects[o].levelY + objects[o].height) < (npc[i].levelY + y))//enemyObjects[o].y
	{
		return false;
	}
	//cout << "culprit" << endl;
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
			cout << "DEATH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
	}
}
bool aabbCollisionEnemy(int e,int o,int x,int y)
{

	//cout << "e = " << e << " i = " << i << endl;
	if (objects[o].levelX > (enemyObjects[e].levelX + enemyObjects[e].width + x))//enemyObjects[o].x + enemyObjects[o].width
	{
		//cout << "error 1" << endl;
		return false;
	}
	//cout << "Failed first check" << endl;
	if ((objects[o].levelX + objects[o].width) < (enemyObjects[e].levelX + x))//enemyObjects[o].x
	{
		//cout << "error 2" << endl;
		return false;
	}
	//cout << "Failed second check" << endl;
	if (objects[o].levelY > (enemyObjects[e].levelY + enemyObjects[e].height + y))//enemyObjects[o].y + enemyObjects[o].height
	{
		//cout << "error 3" << endl;
		return false;
	}
	//cout << "Failed third check" << endl;
	if ((objects[o].levelY + objects[o].height) < (enemyObjects[e].levelY + y))//enemyObjects[o].y
	{
		return false;
		//cout << "i = " << i << " objects[i].y = " << objects[i].y << " objects[i].height = " << objects[i].height << " e = " << e << " enemyobjects[i].y = " << enemyObjects[e].y << " enemyobjects[i].height = " << enemyObjects[e].height << " y = " << y << endl;
	}
	//cout << "Failed fourth check" << endl;
	//cout << "i = " << i << " objects[i].y = " << objects[i].y << " objects[i].height = " << objects[i].height << " enemyobjects[e].levelY = " << enemyObjects[e].levelY <<" y = " << y << endl;
	//cout << "colliding" << endl;
	return true;
}
/*void enemyCollision()
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
		if (!((enemyObjects[e].levelX > marioTrueX + marioWidth) || (enemyObjects[e].levelX + enemyObjects[e].width < marioTrueX) || (enemyObjects[e].levelY > marioY + marioHeight) || (enemyObjects[e].levelY + enemyObjects[e].height < marioY)))////////////////////here////////////////////////////////////
		{
			cout << "DEATH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

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
}*/
void objectCollsionCheck(int y)
{
	if (jumpUp == true)
	{
		for (int i = 0; i < objectCount; i++)
		{
			if (objects[i].type == "power")
			{
				if (aabbCollisionMario(i, marioTrueX, marioY + y))
				{
					cout << "colliding with power = " << i << endl;
					npc[objects[i].linkedObject].show = true;
					objects[i].type = "done";
				}
			}
			if (objects[i].type == "brick")
			{
				if (aabbCollisionMario(i, marioTrueX, marioY + y))
				{
					objects[i].show = false;
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
				marioIndex = 0;
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
	iSetTimer(100, change);
	iSetTimer(16, gravity);
	iSetTimer(100, enemyCollision);
	iSetTimer(4, fourms);
}
void fourms(){
	npcCollision();

}
//*******************************************************************main***********************************************************************//
int main()
{
	setInput();
	iSetTimer(1, winInput);
	iSetTimer(8, checkInput);
	iInitialize(screenWidth, screenHeight, "Project Mario");
	loadLevel();
	iStart();
	return 0;
}
//*******************************************************************end***********************************************************************//