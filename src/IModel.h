#pragma once
#include "ILevel.h"
#include <string>

/**
 * Interface of a basic Sokoban model
 *
 * The model is what holds and generates and interacts with the the level
 * Is the intermediary for controller
 */

class IModel {
public:
	// convers model to a string 
	virtual string toString() const = 0;
	// checks if the player has won
	virtual bool hasWon() const = 0;
	// attempts to move the player
	virtual bool move(int xchange, int ychange)  = 0;
	// creates a new level
	virtual void NewLevel() = 0;
};