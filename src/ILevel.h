
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "IEntity.h"
using namespace std;

/**
 * Interface of a basic level for Sokoban model
 *
 * The level is what holds all the information and functionality of the level
 * This includes creation and keeping track of all entities and moving entities
 * As well as detecting if the game is over
 */

class ILevel  {
public:
	// checks if level is valid
	virtual bool isLevelValid() const = 0;
	// converts level to a string
	virtual string toString() const = 0;
	// adds entity to level
	virtual void addEntity(int x, int y, EntityType entitytype) = 0;
	// checks if player has won
	virtual bool hasWon() const = 0;
	// moves the player
	virtual bool move(int xchange, int ychange) = 0;
};