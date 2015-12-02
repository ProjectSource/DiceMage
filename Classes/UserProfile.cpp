#pragma once
#include "UserProfile.h"
#include "JsonParser.h"

#define  USERINFO_NAME  "UserInfo.Json"
#define  EQUIP_NAME  "EquipInfo.Json"
UserProfile::UserProfile()
{

}

UserProfile::~UserProfile()
{
	
}

void UserProfile::Initialize()
{

}

void UserProfile::Refresh()
{
}

void UserProfile::LoadData()
{
}

void UserProfile::NewData()
{
	InitUserInfo();
}

void UserProfile::CheckData()
{
	std::string strFilePath = FileUtils::getInstance()->getWritablePath() + USERINFO_NAME;
	if (!FileUtils::getInstance()->isFileExist(strFilePath))
	{
		NewData();
	}
}

int UserProfile::GetDiamond()
{
	return std::atoi(JsonParser::instance()->ReadJson("UserInfo.json", 0, "UserInfo", 0, "Diamond").c_str());
}

void UserProfile::SetDiamond(int _diamond)
{
	JsonParser::instance()->SetJson("UserInfo.json", 0, "UserInfo", 0, "Diamond", _diamond, "");
}

void UserProfile::InitUserInfo()
{
	rapidjson::Document document;

	document.SetObject();
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

	//player
	rapidjson::Value PlayerArray(rapidjson::kArrayType);
	rapidjson::Value PlayerObj(rapidjson::kObjectType);
	PlayerObj.AddMember("Diamond", 0, allocator);
	PlayerObj.AddMember("Attack", 10, allocator);
	PlayerObj.AddMember("HP", 100, allocator);
	PlayerObj.AddMember("MP", 100, allocator);
	PlayerArray.PushBack(PlayerObj, allocator);
	document.AddMember("UserInfo", PlayerArray, allocator);

	//monster
	rapidjson::Value MonsterArray(rapidjson::kArrayType);
	rapidjson::Value MonsterObj(rapidjson::kObjectType);
	MonsterObj.AddMember("Attack", 10, allocator);
	MonsterObj.AddMember("HP", 100, allocator);
	MonsterObj.AddMember("MP", 100, allocator);
	MonsterArray.PushBack(MonsterObj, allocator);
	document.AddMember("MonsterInfo", MonsterArray, allocator);

	StringBuffer buffer;
	rapidjson::Writer<StringBuffer> writer(buffer);
	document.Accept(writer);
	std::string _str = StringUtils::format("%s", buffer.GetString());

	auto path = FileUtils::getInstance()->getWritablePath();
	path.append(USERINFO_NAME);
	FILE* fp = std::fopen(path.c_str(), "at+");
	CCASSERT(fp != NULL, "file open error");
	auto length = _str.length();
	fwrite(_str.c_str(), length, 1, fp);
	fclose(fp);
}

