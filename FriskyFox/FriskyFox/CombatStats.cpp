#include "stdafx.h"
#include "CombatStats.h"
#include "PlayerMoves.h"

CombatStats::CombatStats()
	: _health( 100 ),
	  _maxHealth( 100 ),
	  _special( 100 ),
	  _baseDamage( 5 )
{ }

CombatStats::~CombatStats()
{ }

int CombatStats::getHealth() const
{
	return _health;
}

int CombatStats::getMaxHealth() const
{
	return _maxHealth;
}

int CombatStats::getSpecial() const
{
	return _special;
}

void CombatStats::useAttack(/*Enemy * target*/ )
{
	// for now, just decrement own health by base damage
	this->decrementHealth( _baseDamage );
}

void CombatStats::useSpecial( std::string attackName/*, Enemy * target*/ )
{

}

void CombatStats::decrementHealth( int amount )
{
	if( ( _health - amount ) < 0 )
		_health = 0;
	else
		_health -= amount;
}

void CombatStats::incrementHealth( int amount )
{
	if( (_health + amount ) > _maxHealth )
		_health = _maxHealth;
	else
		_health += amount;
}