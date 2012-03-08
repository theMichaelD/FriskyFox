// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
//All files included are in here are only compiled once (to save time).

#pragma once //Similar to #ifndef. Makes sure that the file is only included once.

//DEFAULT files to include in this class:

#include "targetver.h" //This file determines what "Windows Platform" you are using.  Automatically determines
						// that you are using the most up-to-date version.

#include <stdio.h> //The C "standard library header" / the C standard input/output library
#include <tchar.h> //Gives access to functions that work for both Unicode an non-Unicode environments.
					//i.e. _tprintf instead of _printf



// TODO: reference additional headers your program requires here s
// OPTIONAL files to include:

//SFML libraries:
#include <SFML/System.hpp> //Includes these files in all projects.
#include <SFML/Graphics.hpp>  
#include <SFML/Window.hpp> 
#include <SFML/Audio.hpp>

#include <cassert> //Gives access to the assert statement. This is like testing assert statements in Java.
					//The program is terminated if an assert statement fails.