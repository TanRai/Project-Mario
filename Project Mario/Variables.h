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
	int width;
	int height;
	string type;
	bool show;
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
}npc[10];
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
int npcCount = 1;
int marioPowerState = 0;

unsigned int  levelTexture;
char Mario[7][25] = { "Characters\\Mario\\A1.bmp", "Characters\\Mario\\A2.bmp", "Characters\\Mario\\A3.bmp", "Characters\\Mario\\A4.bmp", "Characters\\Mario\\A5.bmp", "Characters\\Mario\\A6.bmp", "Characters\\Mario\\A7.bmp" };
char goomba[3][35] = { "Characters\\Goomba\\g1.bmp", "Characters\\Goomba\\g2.bmp", "Characters\\Goomba\\g3.bmp" };
char mainMenu[1][40] = { " " };
char mushroom[1][40] = { "Objects\\Mushroom\\mushroom.bmp" };