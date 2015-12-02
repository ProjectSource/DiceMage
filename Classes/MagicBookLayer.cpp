#pragma once

#include "MagicBookLayer.h"
#include "EnmuResource.h"

MagicBookLayer::MagicBookLayer()
{
	CCLOG("========== MagicBookLayer =========");
}

MagicBookLayer::~MagicBookLayer()
{
	CCLOG("========== ~MagicBookLayer =========");
}

bool MagicBookLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void MagicBookLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}
