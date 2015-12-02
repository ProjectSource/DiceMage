#pragma once
#include "GameScene.h"

#define PLAYERACTIONDONE "playerdone"
#define MONSTERACTIONDONE "monsterdone"

Scene * GameScene::createScene()
{
	auto scene = Scene::create();
	GameScene * layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

GameScene::GameScene()
{
	CCLOG("========== GameScene ==========");
	_shadowlayer = nullptr;

	__String * sParam = __String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMGAMESCENE);
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameScene::RemoveShadow), sParam->getCString(), nullptr);

	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameScene::PlayerActionDoneCallback), PLAYERACTIONDONE, nullptr);
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameScene::MonsterActionDoneCallback), MONSTERACTIONDONE, nullptr);
}

GameScene::~GameScene()
{
	CCLOG("========== ~GameScene ==========");
	_shadowlayer = nullptr;

	__String * sParam = __String::createWithFormat("%d", NotifycationID_REMOVESHADOWFROMGAMESCENE);
	NotificationCenter::getInstance()->removeObserver(this, sParam->getCString());

	NotificationCenter::getInstance()->removeObserver(this, PLAYERACTIONDONE);
	NotificationCenter::getInstance()->removeObserver(this, MONSTERACTIONDONE);
}

bool GameScene::init()
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

void GameScene::RemoveShadow(Ref* pSender)
{
	if (_shadowlayer && _shadowlayer->isVisible())
	{
		_shadowlayer->setVisible(false);
	}
}

void GameScene::PlayerActionDoneCallback(Ref * pSender)
{
	String * str = dynamic_cast<String*>(pSender);
	_player->SetPlayerState(E_PlayerState_WAIT);
}

void GameScene::MonsterActionDoneCallback(Ref * pSender)
{
	String * str = dynamic_cast<String*>(pSender);
	_monster->SetPlayerState(E_MonsterState_WAIT);
}
