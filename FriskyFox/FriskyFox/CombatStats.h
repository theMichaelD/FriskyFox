#ifndef COMBATSTATS_H
#define COMBATSTATS_H

#include "stdafx.h"
#include "PlayerMoves.h"
/******************************************************************/
// CombatStats will hold all the combat-related data for the	  //
// Player, party members, and perhaps NPC's. Combat sprites		  //
// and animations will probably be held elsewhere, in keeping     //
// with MVC philosophies.										  //
/******************************************************************/
class CombatStats
{
	public:
		CombatStats();
		~CombatStats();
		int getHealth() const;
		int getMaxHealth() const;
		int getSpecial() const;

		void useAttack( /*Enemy * target*/ );
		void useSpecial( std::string attackName/*, Enemy * target*/ );
		void decrementHealth( int amount );
		void incrementHealth( int amount );
		
	private:
		int _health;
		int _maxHealth;
		int _special;
		int _baseDamage;
		std::map<std::string, Move> _moves;

		const static int MAX_SPECIAL = 100;
};

#endif // COMBATSTATS_H