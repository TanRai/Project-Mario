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
void checkInput()
{
	if (gameState == 1)
	{
		if (m_keys[0x0D].bPressed == true)
		{
			cout << "Entering" << endl;
			gameState = 2;
			loadLevel1();
		}
	}
	if (gameState == 2)
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
					//marioIndex = 4;
				}
			}
		}
		if (m_keys[0x4D].bPressed == true)
		{
			if (marioPowerState == 2)
			{
				if (fired == false)
				{
					cout << "firing" << endl;
					fireStart(marioX + 64, marioY+64, marioTrueX + 64, marioY+64);
					fired = true;
				}
			}
		}
	}
}