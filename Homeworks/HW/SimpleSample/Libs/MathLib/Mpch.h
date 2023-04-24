#pragma once

#include <math.h>


namespace Math
{
	template< typename type >
	inline const type& Min(const type& left, const type& right)
	{
		return (left < right) ? left : right;
	}
	template< typename type >
	inline const type& Max(const type& left, const type& right)
	{
		return (left > right) ? left : right;
	}

	template< typename type >
	const type& Clamp(const type& value, const type& min_value, const type& max_value)
	{
		//if( value < min_value )
		//{
		//	return min_value;
		//}
		//if( value > max_value )
		//{
		//	return max_value;
		//}
		//
		//return value;

		if (value <= min_value)
		{
			return min_value;
		}

		return Math::Min(value, max_value);

	}
}
