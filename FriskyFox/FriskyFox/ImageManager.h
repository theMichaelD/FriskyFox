#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include "stdafx.h"

class ImageManager
{
	public:
		static void addImage( std::string key, sf::Image * image );
		const static sf::Image * getImage( std::string key );

	private:
		static std::map<std::string, sf::Image *> _images;
};

#endif // IMAGEMANAGER_H