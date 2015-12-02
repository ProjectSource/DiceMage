#ifndef _EXITLAYER_H
#define _EXITLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
class ExitLayer : public Layer
{
public:
	ExitLayer();
	~ExitLayer();
	virtual bool init();

	CREATE_FUNC(ExitLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif