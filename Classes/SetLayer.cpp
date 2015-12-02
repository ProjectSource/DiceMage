#pragma once
#include "SetLayer.h"
#include "MainScene.h"
#include "EnmuResource.h"
SetLayer::SetLayer()
{
	CCLOG("========== SetLayer =========");
}

SetLayer::~SetLayer()
{
	CCLOG("========== ~SetLayer =========");
}

bool SetLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void SetLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}
