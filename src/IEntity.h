#ifndef Entity_hpp
#define Entity_hpp

#include "EntityType.cpp"
/**
 * interface for a basic entity for Sokoban model
 *
 * The entity is the most basic interactive item in the game
 * this is used to abstractly query movment interactions
 */
class IEntity {
public:
	// functions that return bollean information for movment interactions
	virtual bool moveTo(const IEntity * e) const = 0;
	virtual bool moveFromActive(const IEntity * ac) const = 0;
	virtual bool moveFromNonActive(const IEntity * nc) const = 0;
	virtual EntityType getType() const = 0;
};


#endif /* Entity_hpp */
