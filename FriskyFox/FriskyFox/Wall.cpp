#include "stdafx.h"
#include "Wall.h"
#include "ImageManager.h"
#include "Game.h"

Wall::Wall()
{
	_sprite.SetImage( *( ImageManager::getImage( "wall" ) ) );
	_sprite.SetCenter( ImageManager::getImage( "wall" )->GetWidth() / 2, ImageManager::getImage( "wall" )->GetHeight() / 2 );
	_sprite.SetPosition( sf::Randomizer::Random( 0.0f, float( Game::SCREEN_WIDTH ) ), sf::Randomizer::Random( 0.0f, float( Game::SCREEN_HEIGHT ) ) ); // This is only for testing purposes.
}

Wall::~Wall()
{ }

void Wall::update( float elapsedTime )
{
	// TODO: possibly check for collision? could be left to Player though... or perhaps to something altogether different
}