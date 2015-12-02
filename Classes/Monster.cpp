#pragma once

#include "Monster.h"

Monster::Monster()
{
	CCLOG("========== Monster ==========");
	_monsterState = E_MonsterState_NONE;
	monster_skeletonNode = nullptr;
}

Monster::~Monster()
{
	CCLOG("========== ~Monster ==========");
	_monsterState = E_MonsterState_NONE;
	monster_skeletonNode = nullptr;
}

bool Monster::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size VisibleSize = Director::getInstance()->getVisibleSize();
	monster_skeletonNode = new SkeletonAnimation("monster.json", "monster.atlas");
	monster_skeletonNode->setAnimation(0, "wait", true);
	monster_skeletonNode->setPosition(Vec2(VisibleSize.width / 2 + 80, VisibleSize.height / 2));
	this->addChild(monster_skeletonNode, 200);

	this->scheduleUpdate();
	return true;
}

void Monster::update(float delta)
{
	switch (_monsterState)
	{
	case E_MonsterState_WAIT:
		SetAnimation(monster_skeletonNode, "monster", "wait", true);
		break;
	case E_MonsterState_ATTACK:
		SetAnimation(monster_skeletonNode, "monster", "attack", true);
		break;
	case E_MonsterState_BEATTACK:
		SetAnimation(monster_skeletonNode, "monster", "beattack", true);
		break;
	default:
		break;
	}
	SetPlayerState(E_MonsterState_NONE);
}

void Monster::SetPlayerState(MonsterState state)
{
	_monsterState = state;
}

MonsterState Monster::GetPlayerState()
{
	return _monsterState;
}
