#pragma once
#include "IEntity.h"
#include <iostream>

using namespace std;
/**
 * Implementation of a basic Sokoban entity Wall
 *
 * wall is stationary entity
 */
class Wall : public IEntity {
public:
	// basic constructor destructor
	Wall();
	~Wall();
	// functions that return bollean information for movment interactions
	bool moveFromActive(const IEntity * ac) const;
	bool moveTo(const IEntity * e) const;
	bool moveFromNonActive(const IEntity * nc) const;
	EntityType getType() const;
};
