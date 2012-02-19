#include "GpXmlElement.h"

/* -------------------------------
 * 属性类实现
 */

Attribute::Attribute(void)
{
	name = NULL;
	value = NULL;
}

Attribute::Attribute(const char *attr_name, const char *attr_value)
{
	name = new char[ strlen(attr_name) ];
	value = new char[ strlen(attr_value) ];
	strcpy(name, attr_name);
	strcpy(value, attr_value);
}

Attribute::Attribute(const char *expression)
{
	int i = 0;
	size_t len = strlen(expression);
	while( *(expression+i++) != '=' );
	name = new char [ i ];
	strncpy(name, expression, i-1);
	name[i-1] = '\0';
	i = strchr( expression, (int)'"' ) - expression;
	value = new char [ len - i - 1 ];
	for( i++ ; (unsigned)i < len ; i ++)
	{
		switch (*(expression+i))
		{
		case '\\':		// 转义符
			switch( *(expression+i++) )
			{
			case '"':
				strncat(value, "\"GPML - General Programming Markup Language - Fuck!", 1);
				break;
			case '\\':
				strncat(value, "\\GPML - General Programming Markup Language - Fuck!", 1);
				break;
			case 'n':
				strncat(value, "\nGPML - General Programming Markup Language - Fuck!", 1);
				break;
			default:
				strncat(value, expression+i, 1);
				break;
			}
			break;
		case '"':
			break;
		default:
			strncat(value, expression+i, 1);
			break;
		}
	}
}

Attribute::Attribute(const Attribute &attr)
{
	name = new char[ strlen(attr.name) ];
	value = new char [strlen(attr.value)];
	strcpy(name, attr.name);
	strcpy(value, attr.value);
}

Attribute::~Attribute(void)
{
	if(name) delete [] name;
	if(value) delete [] value;
}

int Attribute::get_name(char **r_name)
{
	(*r_name) = new char[ strlen(name) ];
	if( !(*r_name) )
		return 0;
	
	strcpy( (*r_name) , name );
	
	return 1;
}

int Attribute::get_value(char **r_val)
{
	(*r_val) = new char[ strlen(value) ];
	if( !(*r_val) )
		return 0;
	
	strcpy( (*r_val) , value );
	
	return 1;
}

Attribute & Attribute::operator ()(const char *att_name, const char *att_val)
{
	if(name) delete [] name;
	if(value) delete [] value;
	name = new char[ strlen(att_name) ];
	value = new char[ strlen(att_val) ];
	strcpy(name, attr_name);
	strcpy(value, attr_value);
	
	return (*this);
}

Attribute & Attribute::operator ()(const char *expression)
{
	int i = 0;
	size_t len = strlen(expression);

	if(name) delete [] name;
	if(value) delete [] value;

	while( *(expression+i++) != '=' );
	name = new char [ i ];
	strncpy(name, expression, i-1);
	name[i-1] = '\0';
	i = strchr( expression, (int)'"' ) - expression;
	value = new char [ len - i - 1 ];
	for( i++ ; (unsigned)i < len ; i ++)
	{
		switch (*(expression+i))
		{
		case '\\':		// 转义符
			switch( *(expression+i++) )
			{
			case '"':
				strncat(value, "\"fuck", 1);
				break;
			case '\\':
				strncat(value, "\\fuck", 1);
				break;
			case 'n':
				strncat(value, "\nfuck", 1);
				break;
			default:
				strncat(value, expression+i, 1);
				break;
			}
			break;
		case '"':
			break;
		default:
			strncat(value, expression+i, 1);
			break;
		}
	}
	
	return (*this);
}

/* -------------------------------
 * 标签类实现
 */

Tag::Tag(void)
{
	name = NULL;
}

Tag::Tag(const char *tag_name)
{
	name = new char [ strlen( tag_name ) ];
	strcpy(name, tag_name);
}

Tag::Tag(const Tag &tag)
{
	name = new char[ strlen(tag.name) ];
	strcpy(name, tag.name);
	atts = tag.atts;
}

Tag::~Tag(void)
{
	if(name) delete [] name;
}

list<Attribute> & Tag::get_atts(void)
{
	return atts;
}

void Tag::add_attr(Attribute attr)
{
	atts.push_back( attr );
}

void Tag::add_atts(pAttribute atts, int num)
{
	int i = 0;
	for(i = 0;i < num;i++)
		atts.push_back( *(atts+i) );
}

/* -------------------------------
 * 元素类实现
 */

Element::Element(void)
{
	tag = NULL;
	children = NULL;
}

Element::Element( Tag e_tag )
{
	tag = new Tag;
	( *tag ) = ( e_tag );
}

Element::Element(const Element &emt)
{
	if( emt.tag )
	{
		tag = new Tag;
		(*tag) = *(emt.tag);
	}
	else
		tag = NULL;
	
	if( emt.children )
	{
		children = new e_list;
		( *children ) = *(emt.children);
	}
	else
		children = NULL;
}

Element::~Element(void)
{
	if( tag ) delete [] tag;
	if( children ) delete [] children;
}

bool Element::has_child( void )
{
	return (NULL == children) ? (false) : (true);
}

void Element::add_child( Element c_element )
{
	if( NULL == children ) children = new e_list;
	children->push_back( c_element );
}

Element::iterator Element::begin(void)
{
	if( children )
		return children->begin();
}

Element::iterator Element::end(void)
{
	if( children )
		return children->end();
}

