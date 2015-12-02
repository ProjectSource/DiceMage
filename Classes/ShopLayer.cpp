#pragma once
#include "ShopLayer.h"
#include "SimpleAudioEngine.h"
#include "EnmuResource.h"
using namespace CocosDenshion;

ShopLayer::ShopLayer()
{
	CCLOG("========== ShopLayer =========");
}

ShopLayer::~ShopLayer()
{
	CCLOG("========== ~ShopLayer =========");
}

bool ShopLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void ShopLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}

