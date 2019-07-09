#include <cstdint>

#ifndef PEP_SIZE_H_201909071546
#define PEP_SIZE_H_201909071546

namespace pep
{
	template<typename _tType, size_t _sizeToReturn>	
	constexpr		uint32_t			size			(const _tType(&)[_sizeToReturn])		{ return (uint32_t)_sizeToReturn; }
}

#endif // PEP_SIZE_H_201909071546
