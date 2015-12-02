#ifndef _SHOPLAYER_H
#define _SHOPLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
class ShopLayer : public Layer
{
public:
	ShopLayer();
	~ShopLayer();
	virtual bool init();
	CREATE_FUNC(ShopLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif
