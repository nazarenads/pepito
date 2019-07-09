#include "pep_view.h"
#include <vector>

#ifndef PEP_FILE_H_238947239847
#define PEP_FILE_H_238947239847

namespace pep
{
	int			fileToMemory		(const ::pep::view<const char> & fileName, ::std::vector<char> & file);
}

#endif // PEP_FILE_H_238947239847
