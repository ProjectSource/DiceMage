#pragma once
#include "BagLayer.h"
#include "EnmuResource.h"
BagLayer::BagLayer()
{
	CCLOG("========== BagLayer =========");
}

BagLayer::~BagLayer()
{
	CCLOG("========== ~BagLayer =========");
}

bool BagLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void BagLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}
