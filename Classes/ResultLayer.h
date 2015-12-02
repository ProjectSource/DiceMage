#ifndef _RESULTLAYER_H
#define _RESULTLAYER_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace std;
using namespace ui;

class ResultLayer : public Layer
{
public:
	ResultLayer();
	~ResultLayer();

	virtual bool init();

	CREATE_FUNC(ResultLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};
#endif
#pragma once
