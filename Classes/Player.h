#ifndef _PLAYER_H
#define _PLAYER_H

#include "cocos2d.h"
#include "EventManager.h"
#include "EnmuResource.h"
#include <spine/spine-cocos2dx.h>
#include "spine/spine.h"
using namespace spine;
USING_NS_CC;

class Player : public EventManager
{
public:
	Player();
	~Player();
	virtual bool init();
	void update(float delta);
	void SetPlayerState(PlayerState state);
	PlayerState GetPlayerState();
protected:
	CC_SYNTHESIZE(int, _hp, HP);
	CC_SYNTHESIZE(int, _mp, MP);
	CC_SYNTHESIZE(int, _magic, Mage);
private:
	PlayerState _playerState;
	SkeletonAnimation * player_skeletonNode;
	void RoolDice();
	void AgainRoolDice();
public:
};

#endif
