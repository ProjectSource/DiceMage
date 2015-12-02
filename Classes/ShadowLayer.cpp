#include "ShadowLayer.h"


ShadowLayer::ShadowLayer()
{
}

ShadowLayer::~ShadowLayer()
{
}

bool ShadowLayer::init()
{
	if (!LayerColor::init())
	{
		return false;
	}
	Size visibleSize = CCDirector::getInstance()->getVisibleSize();
	auto layer = LayerColor::create(ccc4(0, 0, 0, 110));
	addChild(layer, 2);
	MenuItemImage* item = MenuItemImage::create();
	item->setContentSize(CCSizeMake(visibleSize.width, visibleSize.height));
	CCMenu* menu = CCMenu::create(item, NULL);

	this->addChild(menu);
	return true;
}

