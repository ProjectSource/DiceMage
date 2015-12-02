#ifndef _GAMESCENE_H
#define _GAMESCENE_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ShadowLayer.h"
#include "EnmuResource.h"

#include "Player.h"
#include "Monster.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;

class GameScene : public Layer
{
public:
	static Scene * createScene();
	GameScene();
	~GameScene();

	virtual bool init();

	CREATE_FUNC(GameScene);
protected:
	ShadowLayer * _shadowlayer;
	Player * _player;
	Monster * _monster;
private:
	void RemoveShadow(Ref* pSender);
	void PlayerActionDoneCallback(Ref * pSender);
	void MonsterActionDoneCallback(Ref * pSender);
};
#endif
