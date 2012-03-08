#include "stdafx.h"
#include "HealthBar.h"

HealthBar::HealthBar( int currentHealth, int maxHealth )
	: _maxRect(),
	  _currentRect(),
	  _lastCurrentHealth( currentHealth )
{
	// the current and max healths are multiplied by two just for a larger representation in the bar
	_maxRect =  sf::Shape::Rectangle( 20, 20, ( maxHealth * 2 ) + 20, 40, sf::Color( 0, 0, 0 ) );
	_currentRect =  sf::Shape::Rectangle( 20, 20, ( currentHealth * 2 ) + 20, 40, sf::Color( 255, 0, 0 ) );
}

HealthBar::~HealthBar()
{ }

void HealthBar::updateHealth( int currentHealth )
{
	_currentRect = sf::Shape::Rectangle( 20, 20, ( currentHealth * 2 ) + 20, 40, sf::Color( 255, 0, 0 ) );
}

void HealthBar::displayHealth( int currentHealth, sf::RenderWindow & window )
{
	// I'm trying to make a smooth sort of transition down the health bar, rather than an abrupt change
	/*while( _lastCurrentHealth != currentHealth )
	{
		updateHealth( _lastCurrentHealth - 1 );
		_lastCurrentHealth--;
		window.Draw( _maxRect );
		window.Draw( _currentRect );
	}*/

	updateHealth( currentHealth );
	_lastCurrentHealth = currentHealth;

	window.Draw( _maxRect );
	window.Draw( _currentRect );
}