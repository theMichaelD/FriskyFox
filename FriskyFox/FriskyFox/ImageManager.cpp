#include "stdafx.h"
#include "ImageManager.h"

void ImageManager::addImage( std::string key, sf::Image * image )
{
	_images.insert( std::pair<std::string, sf::Image *>( key, image ) );
}

const sf::Image * ImageManager::getImage( std::string key )
{
	std::map<std::string, sf::Image *>::iterator it = _images.find( key );

	if( it != _images.end() )
		return it->second;
	else
		return new sf::Image( 50, 50, sf::Color( 255, 255, 255 ) );
}

std::map<std::string, sf::Image *> ImageManager::_images;