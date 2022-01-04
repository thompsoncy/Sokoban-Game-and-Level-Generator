
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <memory>
#include "ILevel.h"
using namespace std;

/**
 * Implementation of a basic level for Sokoban model
 *
 * The level is what holds all the information and functionality of the level
 * This includes creation and keeping track of all entities and moving entities
 * As well as detecting if the game is over
 */
class BasicLevel : public ILevel {
public:
	// constructs the level
	BasicLevel();
	// deconstructs the level
	~BasicLevel();
	// checks if level is valid
	bool isLevelValid() const;
	// converts level to string
	string toString() const;
	// adds entity at given location
	void addEntity(int x, int y, EntityType entitytype);
	// checks if the player has won
	bool hasWon() const;
	// attempts to move the player and returns whether the move happened
	bool move(int xchange, int ychange);
private:
	// the level itself
	shared_ptr<list < shared_ptr<IEntity>>> level[25][25];
	// count of the number of goals
	int goalcount;
	// the list of goal 
	vector<int> goals;
	// the list of boxes
	vector<int> boxes;
	// players current location x
	int playerx;
	// players current location y 
	int playery;
};