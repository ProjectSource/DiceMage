#pragma once

#define EFFECT "effect.ogg"

enum PlayerState
{
	E_PlayerState_NONE = 1 << 0,
	E_PlayerState_WAIT = 1 << 1,
	E_PlayerState_ATTACK = 1 << 2,
	E_PlayerState_BEATTACK = 1 << 3,
};

enum MonsterState
{
	E_MonsterState_NONE = 1 << 4,
	E_MonsterState_WAIT = 1 << 5,
	E_MonsterState_ATTACK = 1 << 6,
	E_MonsterState_BEATTACK = 1 << 7,
};

enum e_Notifycation_ID
{
	NotifycationID_None = -1,
	NotifycationID_REMOVESHADOWFROMMAINSCENE,
	NotifycationID_REMOVESHADOWFROMGAMESCENE,
};