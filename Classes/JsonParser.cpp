#pragma once

#include "JsonParser.h"

JsonParser::JsonParser()
{

}

JsonParser::~JsonParser()
{
}

std::string JsonParser::ReadJson(const char * FileName, int row, const char * name)
{
	string str_data = nullptr;
	string jsonFileName = FileName;
	string path = FileUtils::getInstance()->fullPathForFilename(jsonFileName);
	string data = FileUtils::getInstance()->getStringFromFile(path);

	rapidjson::Document _doc;

	if (_doc.Parse<0>(data.c_str()).HasParseError())
	{
		CCLOG("_doc is Error");
		return nullptr;
	}

	if (_doc[row].IsObject())
	{
		if (_doc[row][name].IsObject())
		{
			CCLOG("%s", _doc[row][name].GetString());
			str_data = _doc[row][name].GetString();
		}
		if (_doc[row][name].IsNumber())
		{
			CCLOG("%d", _doc[row][name].GetInt());
			str_data = String::createWithFormat("%d", _doc[row][name].GetInt())->getCString();
		}
		if (_doc[row][name].IsString())
		{
			CCLOG("%s", _doc[row][name].GetString());
			str_data = _doc[row][name].GetString();
		}
	}
	if (str_data.c_str() == nullptr)
	{
		CCLOG("Error!");
		return NULL;
	}
	return str_data;
}

std::string JsonParser::ReadJson(const char * FileName, int row, const char * name, int ChilderRow, const char* ChilderName)
{
	string str_data = "";
	string jsonFileName = FileName;
	std::string path = FileUtils::getInstance()->getWritablePath() + jsonFileName;
	string data = FileUtils::getInstance()->getStringFromFile(path);

	rapidjson::Document _doc;

	if (_doc.Parse<0>(data.c_str()).HasParseError())
	{
		CCLOG("_doc is Error");
		return nullptr;
	}

	if (_doc[name][0].IsObject())
	{
		if (_doc[name][0][ChilderName].IsObject())
		{
			CCLOG("%d", _doc[name][ChilderRow][ChilderName].GetInt());
			str_data = String::createWithFormat("%d", _doc[name][ChilderRow][ChilderName].GetInt())->getCString();
		}
		if (_doc[name][0][ChilderName].IsNumber())
		{
			CCLOG("%d", _doc[name][ChilderRow][ChilderName].GetInt());
			str_data = String::createWithFormat("%d", _doc[name][ChilderRow][ChilderName].GetInt())->getCString();
		}
		if (_doc[name][0][ChilderName].IsString())
		{
			CCLOG("%s", _doc[name][ChilderRow][ChilderName].GetString());
			str_data = _doc[name][ChilderRow][ChilderName].GetString();
		}
	}
	if (str_data.c_str() == nullptr)
	{
		CCLOG("Error!");
		return nullptr;
	}
	return str_data;
}

void JsonParser::SetJson(const char * FileName, int row, const char * name, int ChilderRow, const char * ChilderName,int Num,const char * str)
{
	string jsonFileName = FileName;
	std::string path = FileUtils::getInstance()->getWritablePath() + jsonFileName;
	string data = FileUtils::getInstance()->getStringFromFile(path);
	rapidjson::Document _doc;
	_doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
	if (_doc.Parse<0>(data.c_str()).HasParseError())
	{
		CCLOG("_doc is Error");
		return ;
	}
	if (_doc[name][0].IsObject())
	{
		if (_doc[name][0][ChilderName].IsNumber())
		{
			_doc[name][0][ChilderName].SetInt(Num);
		}
		if (_doc[name][0][ChilderName].IsString())
		{
			_doc[name][0][ChilderName].SetString(str,sizeof(str));
		}
	}

	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	_doc.Accept(writer);
	FILE * file = fopen(path.c_str(), "w");
	if (file) {
		fputs(buffer.GetString(), file);
		fclose(file);
	}
}
