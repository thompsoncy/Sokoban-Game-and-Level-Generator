#pragma once
#include "IEntity.h"
#include <iostream>

using namespace std;
/**
 * Implementation of a basic Sokoban entity Box
 *
 * the box is pushed to the goals
 */
class Box : public IEntity {
public:
	// basic constructor destructor
	Box();
	~Box();
	// functions that return bollean information for movment interactions
	 bool moveTo(const IEntity * e) const ;
	 bool moveFromActive(const IEntity * ac) const ;
	 bool moveFromNonActive(const IEntity * nc) const ;
	 EntityType getType() const ;
};
