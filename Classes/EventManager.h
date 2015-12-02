#ifndef _EVENTMANAGER_H
#define _EVENTMANAGER_H

#include "cocos2d.h"
#include "EnmuResource.h"
#include <spine/spine-cocos2dx.h>
#include "spine/spine.h"
using namespace spine;
USING_NS_CC;

class EventManager : public Layer
{
public:
	EventManager();
	virtual ~EventManager();
	virtual void SetAnimation(SkeletonAnimation * skeletonNode,const char * personName, const char * animation_name, bool floop);
protected:
public:
	CREATE_FUNC(EventManager);
};
#endif
