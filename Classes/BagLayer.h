#ifndef _BAGLAYER_H
#define _BAGLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
class BagLayer : public Layer
{
public:
	BagLayer();
	~BagLayer();
	virtual bool init();

	CREATE_FUNC(BagLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif
