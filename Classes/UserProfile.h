#ifndef USERPROFILE_H
#define USERPROFILE_H

#include "cocos2d.h"
#include "Singleton.h"
#include "json/document.h"
#include "json/rapidjson.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
USING_NS_CC;
using namespace rapidjson;
class UserProfile :public Singleton<UserProfile>
{
public:
	UserProfile();
	~UserProfile();
	void Initialize();
	void Refresh();
	void LoadData();
	void NewData();
	void CheckData();
protected:
public:
	int GetDiamond();
	void SetDiamond(int _diamond);
private:
	void InitUserInfo();

};

#endif
