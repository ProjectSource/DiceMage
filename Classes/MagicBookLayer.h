#ifndef _MAGICBOOKLAYER_H
#define _MAGICBOOKLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
class MagicBookLayer : public Layer
{
public:
	MagicBookLayer();
	~MagicBookLayer();
	virtual bool init();

	CREATE_FUNC(MagicBookLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif