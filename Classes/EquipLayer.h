#ifndef _EQUIPLAYER_H
#define _EQUIPLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
class EquipLayer : public Layer
{
public:
	EquipLayer();
	~EquipLayer();
	virtual bool init();

	CREATE_FUNC(EquipLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif
