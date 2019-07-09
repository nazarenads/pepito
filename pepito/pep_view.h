#include <cstdint>

#ifndef PEP_VIEW_H_201909071543
#define PEP_VIEW_H_201909071543

namespace pep 
{
	template<typename _tType>
	struct view {
		_tType			* FirstElement;
		uint32_t		Count;
						
		template<size_t _size>
						view		(_tType (&data)[_size])			: FirstElement(data), Count(_size)			{}
						view		(_tType * data, size_t size)	: FirstElement(data), Count((uint32_t)size)	{}


		_tType &		operator[]	(uint32_t index)				{ return FirstElement[index]; }
		const _tType &	operator[]	(uint32_t index)		const	{ return FirstElement[index]; }
	};
}

#endif // PEP_VIEW_H_201909071543
