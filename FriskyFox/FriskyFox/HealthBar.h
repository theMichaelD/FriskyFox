#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "stdafx.h"

class HealthBar
{
	public:
		HealthBar( int currentHealth, int maxHealth );
		~HealthBar();
		void updateHealth( int currentHealth );
		void displayHealth( int currentHealth, sf::RenderWindow & window );

	private:
		int _maxWidth;
		int _height;
		int _lastCurrentHealth;
		sf::Shape _maxRect;
		sf::Shape _currentRect;
};

#endif // HEALTHBAR_H