#include "pep_file.h"
#include <Windows.h>

int						pep::fileToMemory		(const ::pep::view<const char> & fileName, ::std::vector<char> & file) {
	FILE						* fp					= 0;
	fopen_s(&fp, &fileName[0], "rb");
	if(0 == fp) {
		OutputDebugStringA(&fileName[0]);
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	int							fileSize				= ftell(fp);
	file.resize(fileSize);
	fseek(fp, 0, SEEK_SET);
	fread(&file[0], sizeof(char), fileSize, fp);
	fclose(fp);
	file.push_back('\0');
	return 0;
}
