/**
 * Author:  Andrew Whitney
 * Date: 6/6/2019
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Player.h"
using std::cout;
using std::cin;
using std::endl;

Player::Player(int pNumber){
    lives = 1;
    score = 0;
    playerNumber = pNumber;
    distanceFromCenter = 0;
    ammo = 0;
    x = 0;
    y = 0;
    
}

void Player::setLocation(int distance, int x, int y){
    distanceFromCenter = distance;
    Player::x = x;
    Player::y = y;
}

void Player::addScore(int scoreIncrease)
{
    score = score + scoreIncrease;
}
void Player::removeLife()
{
    lives = lives - 1;
}
void Player::walkForward(int numSteps)
{
    distanceFromCenter = distanceFromCenter - numSteps;
}
void Player::walkBackward(int numSteps)
{
    distanceFromCenter = distanceFromCenter + numSteps;
}

void Player::shoot()
{
    ammo = ammo - 1;
}

int Player::getX() {
    return x;
}

int Player::getY() {
    return y;
}

int Player::getDistance() {
    return distanceFromCenter;
}


void Player::reload() {
    ammo = 1;
}

bool Player::shotAt(int x, int y, int distance){
    if ((Player::x == x) && (Player::y == y))
    {
        removeLife();
        cout << "Player " << playerNumber << " has been shot!" << endl;
        isDead();
        return true;
    }
    else 
    {
        score++;
        cout << "You have missed!!  You are now out of ammo!  You have died while attempting to flee the scene!" << endl;
        return false;
    }
}

void Player::printInfo()
{
    cout << "Lives:     " << lives << endl;
    cout << "Score:     " << score << endl;
    cout << "Ammo:      " << ammo << endl; 
}

bool Player::isDead(){
    if (lives == 0){
        return true;
    }
    else {
        return false;
    }
}

int Player::getScore()
{
    return score;
}

bool Player::checkAmmo() {
    if (ammo == 0){
        return false;
    }
    else{
        return true;
    }
}

