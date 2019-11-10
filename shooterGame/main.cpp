/**
 * Author:  Andrew Whitney
 * Date: 6/6/2019
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Player.h"
#include <stdbool.h>
using std::cin;
using std::cout;
using std::endl;

int rounds = 1;

Player playerOne = Player(1);
Player playerTwo = Player(2);

void pause() {
    system("PAUSE");
}

void clearScreen() {
    system("CLS");
}

bool isEvenNumber(int num)
{
    int a = num % 2;
    if (a != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void topScreen()
{
    cout << "Round:         " << rounds << endl;
    cout << "Score" << endl;
    cout << "Player One:    " << playerOne.getScore() << endl;
    cout << "Player Two:    " << playerTwo.getScore() << endl;
}

void welcome()
{
    cout << "Welcome to Shooter, a game where two snipers only have one bullet left, they must hunt each other down to escape without death..." << endl;
    system("PAUSE");
}

//implement AI
void howManyPlayers()
{
}

void playerStartUp(int pNumber)
{
    if (pNumber == 1)
    {
        int playerOneStart;
        int playerOneX;
        int playerOneY;
        cout << "Player One, pick your starting distance from the center(between 0 and 20): ";
        cin >> playerOneStart;
        cout << endl;
        cout << "Player One, pick your starting x coordinate(between 0 and 10): ";
        cin >> playerOneX;
        cout << endl;
        cout << "Player One, pick your starting y coordinate(between 0 and 10): ";
        cin >> playerOneY;
        playerOne.setLocation(playerOneStart, playerOneX, playerOneY);
    }
    if (pNumber == 2)
    {
        int playerTwoStart;
        int playerTwoX;
        int playerTwoY;
        cout << "Player Two, pick your starting distance from the center(between 0 and 20): ";
        cin >> playerTwoStart;
        cout << endl;
        cout << "Player Two, pick your starting x coordinate(between 0 and 10): ";
        cin >> playerTwoX;
        cout << endl;
        cout << "Player Two, pick your starting y coordinate(between 0 and 10): ";
        cin >> playerTwoY;
        playerTwo.setLocation(playerTwoStart, playerTwoX, playerTwoY);
    }
}

void playerOneTurn()
{
    char p1turn;
    cout << "Player One it is your turn" << endl;
    cout << endl;
    cout << "Stats for Player One: " << endl;
    playerOne.printInfo();
    cout << endl;
    cout << "Would you like to shoot, reload, or search for the other sniper?" << endl;
    cout << "To shoot:                      's'" << endl;
    cout << "To reload:                     'r'" << endl;
    cout << "To search for the other sniper:'o'" << endl;
    //hide?
    cin >> p1turn;
    system("CLS");
    topScreen();
    switch (p1turn)
    {
    case 's':
        if (playerOne.checkAmmo())
        {
            int x;
            int y;
            int dis;
            cout << "Where would you like to shoot? " << endl;
            cout << "Pick the x axis, y axis, then distance: ";
            cin >> x >> y >> dis;
            playerOne.shoot();
            if (playerTwo.shotAt(x, y, dis) == false)
            {
                playerOne.removeLife();
            }
        }
        else
        {
            cout << "Click... you did not have any ammo loaded..." << endl;
            system("PAUSE");
        }
        break;
    case 'r':
        playerOne.reload();
        break;
    case 'o':
        int x;
        int y;
        int dis;
        cout << "Where would you like to search?" << endl;
        cout << "search by entering x, then y, then the distance from the center" << endl;
        cin >> x >> y >> dis;
        if (x == playerTwo.getX())
        {
            cout << "the X location is correct!" << endl;
            system("PAUSE");
        }
        else
        {
            cout << "the X location is incorrect..." << endl;
        }
        if (y == playerTwo.getY())
        {
            cout << "the Y location is correct!" << endl;
            system("PAUSE");
        }
        else
        {
            cout << "the Y location is incorrect..." << endl;
        }
        if (dis == playerTwo.getDistance())
        {
            cout << "the distance is correct!" << endl;
            system("PAUSE");
        }
        else
        {
            cout << "the distance in incorrect..." << endl;
        }
        break;
    default:
        cout << "Error, you lost a turn" << endl;
        break;
    }
}

void playerTwoTurn()
{
    char p2turn;
    cout << "Player Two it is your turn" << endl;
    cout << endl;
    cout << "Stats for Player Two: " << endl;
    playerTwo.printInfo();
    cout << endl;
    cout << "Would you like to shoot, reload, or search for the other sniper?" << endl;
    cout << "To shoot:                      's'" << endl;
    cout << "To reload:                     'r'" << endl;
    cout << "To search for the other sniper: 'o'" << endl;
    //hide?
    cin >> p2turn;

    system("CLS");
    topScreen();

    switch (p2turn)
    {
    case 's':
        if (playerTwo.checkAmmo())
        {
            int x;
            int y;
            int dis;
            cout << "Where would you like to shoot? " << endl;
            cout << "Pick the x axis, y axis, then distance: ";
            cin >> x >> y >> dis;
            playerTwo.shoot();
            if (playerOne.shotAt(x, y, dis) == false)
            {
                playerTwo.removeLife();
            }
        }
        else
        {
            cout << "Click... you did not have any ammo loaded..." << endl;
        }
        break;
    case 'r':
        playerTwo.reload();
        break;
    case 'o':
        //search function
        int x;
        int y;
        int dis;
        cout << "Where would you like to search?" << endl;
        cout << "search by entering x, then y, then the distance from the center" << endl;
        cin >> x >> y >> dis;
        if (x == playerOne.getX())
        {
            cout << "the X location is correct!" << endl;
            system("PAUSE");
        }
        if (y == playerOne.getY())
        {
            cout << "the Y location is correct!" << endl;
            system("PAUSE");
        }
        if (dis == playerOne.getDistance())
        {
            cout << "the distance is correct!" << endl;
            system("PAUSE");
        }
        break;
    default:
        cout << "Error, you lost a turn" << endl;
        break;
    }
}


void playerTurn(int playerNumber) {
    switch(playerNumber){
        case '1':
        playerOneTurn();
        break;
        case '2':
        playerTwoTurn();
        break;
        default:
        cout << "Input Error" << endl;
        exit(1);
        break;
    }
}


void playOneRound(int r)
{
    if (isEvenNumber(r) == true)
    {
        cout << "Player One goes first!" << endl;
        system("PAUSE");
        system("CLS");
        playerTurn(1);
        system("PAUSE");
        system("CLS");
        playerTurn(2);
        system("PAUSE");
        system("CLS");
    }
    if (isEvenNumber(r) == false)
    {
        cout << "Player Two goes first!" << endl;
        system("PAUSE");
        system("CLS");
        playerTurn(2);
        system("PAUSE");
        system("CLS");
        playerTurn(1);
        system("PAUSE");
        system("CLS");
    }
}

void checkWinner()
{
    if (playerOne.getScore() > playerTwo.getScore())
    {
        cout << "Player One you have won!!!" << endl;
        system("PAUSE");
        exit(0);
    }
    else
    {
        cout << "Player Two you have won!!!" << endl;
        system("PAUSE");
        exit(0);
    }
}

int main()
{
    welcome();
    system("CLS");
    topScreen();
    playerStartUp(1);
    system("CLS");
    topScreen();
    playerStartUp(2);
    system("CLS");
    topScreen();
    while ((playerOne.isDead() == false) && (playerTwo.isDead() == false))
    {
        playOneRound(rounds);
        rounds++;
    }
    void checkWinner();

    return 0;
}