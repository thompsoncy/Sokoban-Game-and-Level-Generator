#pragma once
#include "IModel.h"
#include <string>
#include <memory>

/**
 * Implementation of a basic Sokoban model
 *
 * The model is what holds and generates and interacts with the the level
 * Is the intermediary for controller
 */

class BasicModel : public IModel  {
public:
	// constructs the model 
	BasicModel();
	// deconstructs the model 
	~BasicModel();
	// returns a string representation of the model
	string toString() const;
	// checks if the player has won
	bool hasWon() const;
	// moves player in given direction
	bool move(int xchange, int ychange);
	// creates a new level
	void NewLevel();
private:
	// the sukoban level
	shared_ptr<ILevel> level;
};