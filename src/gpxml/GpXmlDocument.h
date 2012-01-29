/*
 * 
 * 
 */
#ifndef H_GPXMLDOCUMENT
#define H_GPXMLDOCUMENT
#include "GpXmlGlobal.h"

GPXML_NAMESPACE_START

class Element;

/**
 * 文档类
 */
class Document
{
public:
	Document();
	Document(const char *filename);
	Document(string filename);
	Document(const Document &);
	~Document();

private:
	cstring file;		// 文档文件名
	Element	root;		// 根元素
};

GPXML_NAMESPACE_END

#endif 	// H_GPXMLDOCUMENT
