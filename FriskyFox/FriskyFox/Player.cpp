#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "ImageManager.h"

Player::Player()
	: _moveSpeed( 200 ),
	  _combatStats()
{
		_sprite.SetImage( *( ImageManager::getImage( "player" ) ) );
		_sprite.SetCenter( ImageManager::getImage( "player" )->GetWidth() / 2, ImageManager::getImage( "player" )->GetHeight() / 2 );
		_sprite.SetPosition( Game::SCREEN_WIDTH /2, Game::SCREEN_HEIGHT / 2 );
}

Player::~Player()
{ }

// update will take user input and have the PC
// react accordingly.
// PARAM - elapsedTime: the time elapsed since the
//		   last iteration through the game loop
void Player::update( float elapsedTime )
{
	float moveDistance = _moveSpeed * elapsedTime;
	sf::Vector2f coords = _sprite.GetPosition();

	if( Game::getInput().IsKeyDown( sf::Key::Left ) )
	{
		if( !( coords.x < 0 ) )
			_sprite.Move( -moveDistance, 0 );
	}
	else if( Game::getInput().IsKeyDown( sf::Key::Right ) )
	{
		if( !( coords.x > Game::SCREEN_WIDTH ) )
			_sprite.Move( moveDistance, 0 );
	}
	else if( Game::getInput().IsKeyDown( sf::Key::Up ) )
	{
		if( !( coords.y < 0 ) )
			_sprite.Move( 0, -moveDistance );
	}
	else if( Game::getInput().IsKeyDown( sf::Key::Down ) )
	{
		if( !( coords.y > Game::SCREEN_HEIGHT ) )
			_sprite.Move( 0, moveDistance );
	}
}

CombatStats * Player::getCombatStats()
{
	CombatStats * combatPtr = &_combatStats;
	return combatPtr;
}