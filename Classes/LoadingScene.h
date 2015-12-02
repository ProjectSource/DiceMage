#ifndef _LOADINGSCENE_H
#define _LOADINGSCENE_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

class LoadingScene : public Layer
{
public:
	LoadingScene();
	~LoadingScene();
	static Scene* createScene();

	virtual bool init();

	void StartToMainScene(Ref * pSender);
	CREATE_FUNC(LoadingScene);
protected:
private:
};
#endif
