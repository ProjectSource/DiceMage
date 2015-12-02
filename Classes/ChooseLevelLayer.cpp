#pragma once
#include "ChooseLevelLayer.h"
#include "EnmuResource.h"

ChooseLevelLayer::ChooseLevelLayer()
{
	CCLOG("========== ChooseLevelLayer =========");
}

ChooseLevelLayer::~ChooseLevelLayer()
{
	CCLOG("========== ~ChooseLevelLayer =========");
}

bool ChooseLevelLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void ChooseLevelLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}
