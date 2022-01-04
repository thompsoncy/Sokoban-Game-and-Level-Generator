#pragma once
#include "IEntity.h"
#include <iostream>

using namespace std;
/**
 * Implementation of a basic Sokoban entity goal
 *
 * the objective is to get the boxes to these goal
 */
class Goal : public IEntity {
public:
	// basic constructor destructor
	Goal();
	~Goal();
	// functions that return bollean information for movment interactions
	bool moveFromActive(const IEntity * ac) const;
	bool moveTo(const IEntity * e) const;
	bool moveFromNonActive(const IEntity * nc) const;
	EntityType getType() const;
};
