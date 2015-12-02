#pragma once

#include "LoadingScene.h"
#include "MainScene.h"

Scene* LoadingScene::createScene()
{
	auto scene = Scene::create();
	LoadingScene * layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}


LoadingScene::LoadingScene()
{
	CCLOG("========== LoadingScene ==========");
}

LoadingScene::~LoadingScene()
{
	CCLOG("========== ~LoadingScene ==========");
}

bool LoadingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void LoadingScene::StartToMainScene(Ref * pSender)
{
	Director::getInstance()->replaceScene(MainScene::createScene());
}
