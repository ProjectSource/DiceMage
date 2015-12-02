#ifndef _PAUSELAYER_H
#define _PAUSELAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
class PauseLayer : public Layer
{
public:
	PauseLayer();
	~PauseLayer();
	virtual bool init();

	CREATE_FUNC(PauseLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif

