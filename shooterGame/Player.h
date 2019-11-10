/**
 * Author:  Andrew Whitney
 * Date: 6/6/2019
*/ 

class Player {
    private:
    int distanceFromCenter;
    int lives;
    int score;
    int playerNumber;
    int x;
    int y;
    int ammo;

    public:
    Player(int pNumber);
    int getX();
    int getY();
    void addScore(int scoreIncrease);
    void removeLife();
    void walkForward(int numSteps);
    void walkBackward(int numSteps);
    void shoot();
    bool shotAt(int x, int y, int distance);
    void printInfo();
    bool isDead();
    void setLocation(int distance, int x, int y);
    int getScore();
    bool checkAmmo();
    void reload();
    int getDistance();


};
