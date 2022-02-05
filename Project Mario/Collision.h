//////////////////////////////////////////////////////////////////////   Mario Collision //////////////////////////////////////////////////////////////////////////////
bool marioCollision(int x, int y)
{
	int i, k, l;
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
		if (objects[i].show == true)
		{
			if (aabbCollisionMario(i, x, y))
			{
				return true;
			}
		}
	}
	return false;
}
bool aabbCollisionMario(int a, int x, int y)
{
	if (objects[a].levelX > x + marioWidth)
		return false;
	if (objects[a].levelX + objects[a].width < x)
		return false;
	if (objects[a].levelY > y + marioHeight)
		return false;
	if (objects[a].levelY + objects[a].height < y)
		return false;
	return true;
}
void marioLevelBound(int x, int y)
{
	if (marioX + x >= 0 && marioX + x <= 328)
	{
		marioX = marioX + x;
		marioTrueX += x;
	}
	else if (marioX + x == 329)
	{
		if (13504 + levelX - screenWidth - x >= 0)
		{
			levelX = levelX - x;
			marioTrueX += x;
			levelScroll();
		}
	}
	if (marioY + y >= 0) //&& marioY + y <= 856)
	{
		marioY += y;
	}
	if (marioY <= 0)
	{
		cout << "death !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		death();
	}
	encounterCheck();
}



/////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////// NPC and enemy Collision /////////////////////////////////////
////////////////////////
void npcCollision()
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
bool aabbCollisionNpc(int i, int o, int x, int y)
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
bool aabbCollisionEnemy(int e, int o, int x, int y)
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