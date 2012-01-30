#include "GpXmlElement.h"

Attribute::Attribute()
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

Attribute::~Attribute()
{
	if(name) delete [] name;
	if(value) delete [] value;
}
