#pragma once

#include "Player.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
Player::Player()
{
	CCLOG("========== Player ==========");
	_playerState = E_PlayerState_NONE;
	player_skeletonNode = nullptr;
	_hp = 0;
	_magic = 0;
	_mp = 0;
}

Player::~Player()
{
	CCLOG("========== ~Player ==========");
	_playerState = E_PlayerState_NONE;
	player_skeletonNode = nullptr;
	_hp = 0;
	_magic = 0;
	_mp = 0;
}

bool Player::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size VisibleSize = Director::getInstance()->getVisibleSize();
	player_skeletonNode = new SkeletonAnimation("player.json", "player.atlas");
	player_skeletonNode->setAnimation(0, "wait", true);
	player_skeletonNode->setPosition(Vec2(VisibleSize.width / 2 - 80, VisibleSize.height / 2));
	this->addChild(player_skeletonNode, 200);
	this->scheduleUpdate();
	return true;
}

void Player::update(float delta)
{
	switch (_playerState)
	{
	case E_PlayerState_WAIT:
		SetAnimation(player_skeletonNode,"player","wait", true);
		break;
	case E_PlayerState_ATTACK:
		SetAnimation(player_skeletonNode,"player", "attack", true);
		break;
	case E_PlayerState_BEATTACK:
		SetAnimation(player_skeletonNode,"player", "beattack", true);
		break;
	default:
		break;
	}
	SetPlayerState(E_PlayerState_NONE);
}

void Player::SetPlayerState(PlayerState state)
{
	_playerState = state;
}

PlayerState Player::GetPlayerState()
{
	return _playerState;
}

void Player::RoolDice()
{
	SimpleAudioEngine::getInstance()->playEffect(EFFECT);

}

void Player::AgainRoolDice()
{
	SimpleAudioEngine::getInstance()->playEffect(EFFECT);
}
