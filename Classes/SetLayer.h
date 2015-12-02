#ifndef _SETLAYER_H
#define _SETLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;
class SetLayer : public Layer
{
public:
	SetLayer();
	~SetLayer();
	virtual bool init();

	CREATE_FUNC(SetLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif

