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