#include "BlasterExplosion.h"

BlasterExplosion::BlasterExplosion(sf::Vector2f position)
{
	Pos = position;
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Blaster Explosion"), 4, 2);
	MainSprite.SetAnimation(0, 7);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);
}

void BlasterExplosion::Update()
{
	MainSprite.Update();

	//don't loop the explosion animation
	if (MainSprite.GetFrame() == 7) {
		MarkForDestroy();
	}
}
void BlasterExplosion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}