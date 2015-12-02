#ifndef _JSONPARSER_H
#define _JSONPARSER_H

#include "cocos2d.h"
#include "Singleton.h"
#include "json/document.h"
#include "json/rapidjson.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

USING_NS_CC;
using namespace std;

class JsonParser:public Singleton<JsonParser>
{
public:
	JsonParser();
	~JsonParser();

	string ReadJson(const char * FileName, int row, const char * name);
	string ReadJson(const char * FileName, int row, const char * name,int ChilderRow,const char* ChilderName);

	void SetJson(const char * FileName, int row, const char * name, int ChilderRow, const char* ChilderName, int Num, const char * str);
protected:
private:
};
#endif
