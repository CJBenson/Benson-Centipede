// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../AttractorMode.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene( new AttractorMode() );

	AddTexture("Blaster", "blaster.png");
	AddTexture("Bullet", "bullet.png");
	AddTexture("Mushroom", "mushroom.png");
	AddTexture("Flea", "flea.png");
	AddTexture("Centipede Head", "centipede_head.png");
	AddTexture("Centipede Body", "centipede_segment.png");
	AddTexture("Scorpion", "scorpion.png");
	AddTexture("Spider", "spider.png");
	AddTexture("Blaster Explosion", "death.png");
	AddTexture("CentipedeFont", "FONTwPLAYER.bmp");


	AddFont("MyDefaultFont", "../Game Components/TEAL/Arial.ttf");
}

