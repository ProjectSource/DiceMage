#pragma once
#include "ExitLayer.h"
#include "MainScene.h"
#include "EnmuResource.h"

ExitLayer::ExitLayer()
{
	CCLOG("========== ExitLayer =========");
}

ExitLayer::~ExitLayer()
{
	CCLOG("========== ~ExitLayer =========");
}

bool ExitLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void ExitLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}
