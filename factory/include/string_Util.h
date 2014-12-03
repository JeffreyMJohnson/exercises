#pragma once
#include <cstring>
#include <cctype>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Trim white space. </summary>
///
/// <remarks>	Caswal, 3/08/2010. </remarks>
///
/// <param name="line">	[in,out] If non-null, the text to trim. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

inline void trimWhiteSpace(char* line)
{
	int i = strlen(line)-1;

	for(; i >= 0; i--)
	{
		if ( isspace(line[i]) )
		{
			line[i] = 0;
		}
		else
		{
			return;
		}
	}
}