#pragma once
#include "IEntity.h"
#include <iostream>

using namespace std;
/**
 * Implementation of a basic Sokoban entity player
 *
 * the player pushes the boxes and is user controlled
 */
class Player : public IEntity {
public:
	// basic constructor destructor
	Player();
	~Player();
	// functions that return bollean information for movment interactions
	bool moveFromActive(const IEntity * ac) const;
	bool moveTo(const IEntity * e) const;
	bool moveFromNonActive(const IEntity * nc) const;
	EntityType getType() const;
};
