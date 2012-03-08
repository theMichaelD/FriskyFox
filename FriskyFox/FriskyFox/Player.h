#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include "VisibleObject.h"
#include "CombatStats.h"

/**********************************************/
// Player is the player's character. it will
// handle all its movement, attributes, etc.
/**********************************************/

class Player : public VisibleObject
{
	public:
		Player();
		~Player();
		void update( float elapsedTime );
		CombatStats * getCombatStats();

	private:
		int _moveSpeed;
		// std::vector<Item &> _itemBag;
		CombatStats _combatStats;
};

#endif // PLAYER_H