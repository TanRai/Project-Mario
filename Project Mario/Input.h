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
			if (cursorPosition == 1)
			{
				cout << "Entering" << endl;
				gameState = 4;
				loadLevel1();
			}
			else if (cursorPosition == 2)
			{
				cout << "Help" << endl;
				gameState = 2;
			}
			else if (cursorPosition == 3)
			{
				cout << "Credits" << endl;
				gameState = 3;
			}
		}
		if (m_keys[0x28].bPressed == true)
		{
			if (cursorPosition < 3)
			{
				cursorPosition += 1;
				cursorY -= 68;
			}
		}
		if (m_keys[0x26].bPressed == true)
		{
			if (cursorPosition > 1)
			{
				cursorPosition -= 1;
				cursorY += 68;
			}
		}
	}
	if (gameState == 2)
	{
		if (m_keys[0x1B].bPressed == true)
		{
			gameState = 1;
		}
	}
	if (gameState == 3)
	{
		if (m_keys[0x1B].bPressed == true)
		{
			gameState = 1;
		}
	}
	if (gameState == 4)
	{
		if (m_keys[0x44].bHeld == true)
		{
			marioCollision(9, 0);
			marioMove = true;
			ahead = true;
		}
		if (m_keys[0x44].bReleased == true)
		{
			marioMove = false;
		}
		if (m_keys[0x41].bHeld == true)
		{
			marioCollision(-9, 0);
			marioMove = true;
			ahead = false;
		}
		if (m_keys[0x41].bReleased == true)
		{
			marioMove = false;
		}
		if (m_keys[0x4A].bHeld == true)
		{
			marioCollision(-1, 0);
		}
		if (m_keys[0x57].bHeld == true)
		{
			marioCollision(0, 30);
		}
		if (m_keys[0x53].bHeld == true)
		{
			marioCollision(0, -10);
		}
		if (m_keys[0x4C].bHeld == true)
		{
			marioCollision(50,0);
		}

		if (m_keys[0x20].bPressed == true)
		{
			if (!jump)
			{
				if (ground())
				{
					jump = true;
					jumpUp = true;
					engine->play2D("Music/smb_jump-super.wav");
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
					fired = true;
					cout << "firing" << endl;
					fireStart(marioX + 64, marioY+64, marioTrueX + 64, marioY+64);
				}
			}
		}
	}
}