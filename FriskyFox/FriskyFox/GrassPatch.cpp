#include "stdafx.h"
#include "GrassPatch.h"
#include "Game.h"
#include "ImageManager.h"

GrassPatch::GrassPatch()
	: _accumulatedTime( 0.0f ),
	  _flipped( false )
{
	_sprite.SetImage( *( ImageManager::getImage( "grass patch" ) ) );
	_sprite.SetCenter( ImageManager::getImage( "grass patch" )->GetWidth(), ImageManager::getImage( "grass patch" )->GetHeight() );
	_sprite.SetPosition( sf::Randomizer::Random( 0.0f, float( Game::SCREEN_WIDTH ) ), sf::Randomizer::Random( 0.0f, float( Game::SCREEN_HEIGHT ) ) );
}

GrassPatch::~GrassPatch()
{ }

void GrassPatch::update( float elapsedTime )
{
	_accumulatedTime += elapsedTime;

	// mirroring the sprite is a bit more efficient here, I think
	// However, when we animate the character and other more complex
	// sprites, a sheet will be a better option
	if( _accumulatedTime >= MAX_TIME &&  !_flipped )
	{
		_sprite.FlipX( true );
		_flipped = true;
		_accumulatedTime = 0.0f;
	}
	if( _accumulatedTime >= MAX_TIME && _flipped )
	{
		_sprite.FlipX( false );
		_flipped = false;
		_accumulatedTime = 0.0f;
	}
}

const float GrassPatch::MAX_TIME = 0.5f;