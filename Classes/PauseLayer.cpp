#pragma once

#include "PauseLayer.h"
#include "EnmuResource.h"

PauseLayer::PauseLayer()
{
	CCLOG("========== PauseLayer =========");
}

PauseLayer::~PauseLayer()
{
	CCLOG("========== ~PauseLayer =========");
}

bool PauseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void PauseLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}
