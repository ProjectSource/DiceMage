#ifndef _MAINSCENE_H
#define _MAINSCENE_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ShopLayer.h"
#include "SetLayer.h"
#include "ShadowLayer.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;

class MainScene : public Layer
{
public:
	static Scene* createScene();
	MainScene();
	~MainScene();

	virtual bool init();

	CREATE_FUNC(MainScene);
protected:
private:
	ShopLayer * _shoplayer;
	SetLayer * _setlayer;
	ShadowLayer * _shadowlayer;
public:
	void OpenShopLayer(Ref * pSender);
	void OpenSetLayer(Ref * pSender);
	void StartGameScene(Ref* pSender);
	void RemoveShadow(Ref* pSender);
};
#endif
