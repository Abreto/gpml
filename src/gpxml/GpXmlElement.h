/* GpXmlElement.h
 * 
 * 	Copyright (c) 2012 by Abreto Fu<m@abreto.net>
 * 
 * 
 */
#ifndef H_GPXMLELEMENT
#define H_GPXMLELEMENT
#include "GpXmlGlobal.h"

GPXML_NAMESPACE_START

/**
 *	属性类 
 */
class Attribute
{
public:
	Attribute();				// 默认构造函数
	Attribute(string, string);	// 指定属性名与属性值
	Attribute(string);			// 通过表达式(属性名="属性值")初始化对象
	Attribute(const Attribute &);	// 复制构造函数
	~Attribute();
private:
	string name;	// 属性名
	string value;	// 属性值
};
typedef Attribute* pAttribute;

/**
 * 标签类
 */
class Tag
{
public:
	Tag();
	Tag(pAttribute);
	~Tag();
	
	bool add_attr(Attribute);
protected:
	string 		name;	// 标签名
	pAttribute 	atts;	// 标签属性
};
typedef Tag *pTag;

/**
 * 元素类
 */
class Element
{
public:
	Element();
	Element(const Element &);
	~Element();

	bool add_child(Element);
	
	list<Element> get_children();
	
	typedef list<Element>::iterator iterator;
protected:
	pTag tag;		// 元素标签
	list<Element> *children;	// 子元素集合
};

GPXML_NAMESPACE_END

#endif	// H_GPXMLELEMENT
