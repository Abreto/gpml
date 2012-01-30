#include "GpXmlElement.h"

/*
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

/*
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

Tag::~Tag()
{
	if(name) delete [] name;
}

list<Attribute> & Tag::get_atts(void)
{
	return atts;
}

bool Tag::add_attr(Attribute attr)
{
	atts.push_back( attr );
}


