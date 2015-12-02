#ifndef _LOTTERYLAYER_H
#define _LOTTERYLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;
class LotteryLayer : public Layer
{
public:
	LotteryLayer();
	~LotteryLayer();
	virtual bool init();

	CREATE_FUNC(LotteryLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif

