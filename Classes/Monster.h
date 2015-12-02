#ifndef _MONSTER_H
#define _MONSTER_H

#include "cocos2d.h"
#include "EventManager.h"
#include "EnmuResource.h"
#include <spine/spine-cocos2dx.h>
#include "spine/spine.h"
using namespace spine;
USING_NS_CC;

class Monster : public EventManager
{
public:
	Monster();
	~Monster();
	virtual bool init();
	void update(float delta);
	void SetPlayerState(MonsterState state);
	MonsterState GetPlayerState();
protected:
private:
	SkeletonAnimation * monster_skeletonNode;
	MonsterState _monsterState;
};

#endif
