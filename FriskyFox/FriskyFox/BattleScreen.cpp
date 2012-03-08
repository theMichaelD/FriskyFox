#include "stdafx.h"
#include "BattleScreen.h"

void BattleScreen::setScreen( const sf::Image * image )
{
	_background.SetImage( *image );
}

void BattleScreen::displayScreen( sf::RenderWindow & window )
{
	window.Draw( _background );
}

sf::Sprite BattleScreen::_background;