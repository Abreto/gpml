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
	Attribute(void);						// 默认构造函数
	Attribute(const char *, const char *);	// 指定属性名与属性值
	Attribute(const char *);				// 通过表达式(属性名="属性值")初始化对象
	Attribute(const Attribute &);			// 复制构造函数
	~Attribute(void);
	
	int get_name( char ** );
	int get_value( char ** );
	
	Attribute & operator () (const char *, const char *);
	Attribute & operator () (const char *);
private:
	char* name;		// 属性名
	char* value;	// 属性值
};
typedef Attribute* pAttribute;

/**
 * 标签类
 */
class Tag
{
public:
	Tag(void);
	Tag(const char *);
	Tag(const Tag &);
	~Tag(void);
	
	list<Attribute> & get_atts(void);
	
	void add_attr(Attribute);
	void add_atts(pAttribute, int);
protected:
	char *name;	// 标签名
	list<Attribute> atts;	// 标签属性
};
typedef Tag *pTag;

/**
 * 元素类
 */
class Element
{
public:
	Element(void);
	Element(Tag);
	Element(const Element &);
	~Element(void);

	bool has_child(void);

	void add_child(Element);
	
	iterator begin(void);
	iterator end(void);
	
	typedef list<Element>	 e_list;
	typedef e_list::iterator iterator;
protected:
	pTag 	tag;		// 元素标签
	e_list *children;	// 子元素集合
};

GPXML_NAMESPACE_END

#endif	// H_GPXMLELEMENT
