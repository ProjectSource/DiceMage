#pragma once
#include "EquipLayer.h"
#include "EnmuResource.h"

EquipLayer::EquipLayer()
{
	CCLOG("========== EquipLayer =========");
}

EquipLayer::~EquipLayer()
{
	CCLOG("========== ~EquipLayer =========");
}

bool EquipLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void EquipLayer::CloseLayerCallBack(Ref * pSender)
{
	String* sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->postNotification(sParam->getCString(), this);
	this->removeFromParentAndCleanup(true);
}
