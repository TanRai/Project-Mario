//*******************************************************************Function Declarations*********************************************************************//
void loadLevel();
void setInput();
void change();
void winInput();
void checkInput();
void gravity();
void marioLevelBound(int x, int y);
bool marioCollision(int x, int y);
bool detectCollision(int x, int y);
void setObjects();
bool ground();
bool aabbCollisionMario(int a, int x, int y);
void levelScroll();
bool detectCollisionObjects(int x, int y, int e);
void enemyCollision();
bool aabbCollisionEnemy(int e, int o, int x, int y);
void loadLevel1();
void objectCollsionCheck(int y);
bool aabbCollisionNpc(int i, int o, int x, int y);
void npcCollision();
void fourms();
void death();
void fireCheck();
void fireStart(int x, int y, int levelX, int levelY);
void fireCollision();
bool aabbCollisionFireObjects(int f, int o, int x, int y);
bool aabbCollisionFireEnemy(int f, int e);
void encounterCheck();
void pointAdd(int x);
void pointDraw();
void gameClock();
void clockDraw();
void UIDraw();
void restart();
void setObjects2();
void loadLevel2();