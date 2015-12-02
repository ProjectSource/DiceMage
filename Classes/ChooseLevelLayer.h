#ifndef _CHOOSELEVELLAYER_
#define _CHOOSELEVELLAYER_

#include "cocos2d.h"
USING_NS_CC;

class ChooseLevelLayer : public Layer
{
public:
	ChooseLevelLayer();
	~ChooseLevelLayer();
	virtual bool init();

	CREATE_FUNC(ChooseLevelLayer);
protected:
private:
	void CloseLayerCallBack(Ref * pSender);
};

#endif
