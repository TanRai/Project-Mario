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
	int levelX;
	int levelY;
	int width;
	int height;
	string type;
	bool show;
	int linkedObject;
}objects[80];
struct powerObjects{
	int x;
	int y;
	int levelX;
	int levelY;
	int width;
	int height;
	int maxHeight;
	int velocityX;
	bool show;
	string objectType;
}npc[13];
struct fire
{
	int x;
	int y;
	int levelX;
	int levelY;
	int maxHeight = 0;
	int velocityX = 15;
	int velocityY = -15;
	bool status = true;
	fire()
	{

	}
	fire(int _x,int _y,int _levelX,int _levelY)
	{
		x = _x;
		y = _y;
		levelX = _levelX;
		levelY = _levelY;
	}
}fireObjects[1000];
struct enemy
{
	int x;
	int y;
	int levelX;
	int levelY;
	int width;
	int height;
	int velocityX;
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
int npcCount = 13;
int marioPowerState = 0;
int checkInputTimer;
int changeTimer;
int gravityTimer;
int enemyCollisionTimer;
int fourmsTimer;
bool fired = false;
int fireCount = 0;






unsigned int  levelTexture;
unsigned int  brickTexture;
unsigned int  powerTexture;
unsigned int  doneTexture;




char Mario[16][40] = { "Characters\\Mario\\A1.bmp", "Characters\\Mario\\A2.bmp", "Characters\\Mario\\A3.bmp", "Characters\\Mario\\A4.bmp", "Characters\\Mario\\A5.bmp", "Characters\\Mario\\A6.bmp", "Characters\\Big Mario\\A15.bmp", "Characters\\Big Mario\\A16.bmp", "Characters\\Big Mario\\A17.bmp", "Characters\\Big Mario\\A18.bmp", "Characters\\Big Mario\\A19.bmp","Characters\\Fire Mario\\1.bmp","Characters\\Fire Mario\\2.bmp","Characters\\Fire Mario\\3.bmp","Characters\\Fire Mario\\4.bmp","Characters\\Fire Mario\\5.bmp" };
char goomba[3][35] = { "Characters\\Goomba\\g1.bmp", "Characters\\Goomba\\g2.bmp", "Characters\\Goomba\\g3.bmp" };
char mainMenu[1][40] = { " " };
char mushroom[1][40] = { "Objects\\Mushroom\\mushroom.bmp" };
char coin[1][40] = { "Objects\\Coin\\coin.bmp" };
char fire[1][40] = { "Objects\\Fire\\fire.bmp" };