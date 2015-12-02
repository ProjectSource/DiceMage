#pragma once

#include "MainScene.h"
#include "GameScene.h"
#include "EnmuResource.h"
Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	MainScene * layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

MainScene::MainScene()
{
	CCLOG("========== MainScene ==========");
	_setlayer = nullptr;
	_shoplayer = nullptr;

	String * sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->addObserver(this,callfuncO_selector(MainScene::RemoveShadow),sParam->getCString(),nullptr);
}

MainScene::~MainScene()
{
	CCLOG("========== ~MainScene ==========");
	_setlayer = nullptr;
	_shoplayer = nullptr;
	String * sParam = String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMMAINSCENE);
	NotificationCenter::getInstance()->removeObserver(this, sParam->getCString());
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	_shadowlayer = ShadowLayer::create();
	_shadowlayer->setVisible(false);
	this->addChild(_shadowlayer, 5);
	return true;
}

void MainScene::OpenShopLayer(Ref * pSender)
{
	_shoplayer = ShopLayer::create();
	this->addChild(_shoplayer,10);
}

void MainScene::OpenSetLayer(Ref * pSender)
{
	_setlayer = SetLayer::create();
	this->addChild(_setlayer,10);
}

void MainScene::StartGameScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(GameScene::createScene());
}

void MainScene::RemoveShadow(Ref* pSender)
{
	if (_shadowlayer && _shadowlayer->isVisible())
	{
		_shadowlayer->setVisible(false);
	}
}
