#include "EventManager.h"

#define PLAYERACTIONDONE "playerdone"
#define MONSTERACTIONDONE "monsterdone"

EventManager::EventManager()
{
	
}

EventManager::~EventManager()
{
}

void EventManager::SetAnimation(SkeletonAnimation * skeletonNode, const char * personName,const char * animation_name, bool floop)
{
	if (!strcmp(personName, "player"))
	{
		skeletonNode->setAnimation(0, animation_name, floop);
		skeletonNode->setEndListener([&](int trackIndex) {
			String * sParam = String::createWithFormat("%s", animation_name);
			NotificationCenter::getInstance()->postNotification(PLAYERACTIONDONE, sParam);
		});
	}
	else
	{
		skeletonNode->setAnimation(0, animation_name, floop);
		skeletonNode->setEndListener([&](int trackIndex) {
			String * sParam = String::createWithFormat("%s", animation_name);
			NotificationCenter::getInstance()->postNotification(MONSTERACTIONDONE, sParam);
		});
	}
}


