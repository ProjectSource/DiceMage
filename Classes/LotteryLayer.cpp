#pragma once
#include "LotteryLayer.h"
#include "SimpleAudioEngine.h"
#include "EnmuResource.h"
using namespace CocosDenshion;
LotteryLayer::LotteryLayer()
{
	CCLOG("========== LotteryLayer =========");
}

LotteryLayer::~LotteryLayer()
{
	CCLOG("========== ~LotteryLayer =========");
}

bool LotteryLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void LotteryLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}

