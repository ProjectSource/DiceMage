#pragma once
#include "ResultLayer.h"
#include "EnmuResource.h"

ResultLayer::ResultLayer()
{
	CCLOG("========== ResultLayer =========");
}

ResultLayer::~ResultLayer()
{
	CCLOG("========== ~ResultLayer =========");
}

bool ResultLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void ResultLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}
