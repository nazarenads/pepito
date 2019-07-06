#include "pepito.h"
#include <stdio.h>
#include <string>
#include <vector>

const char * sections [] = 
	{	"Inicio"	
	,	"Quienes Somos"	
	,	"Nuestros Servicios"	
	,	"Contacto"	
	};

int main(){
	const char				http_headers	[] = "content-type: text/html \r\n\r\n";
	const char				title			[] = "My Page";

	const char				head			[] = "<head><title>%s</title></head>";
	const char				body			[] = "<body>%s</body>";

	::std::string			content;
	content.append("<table><tr>");
	::std::vector<char>		buffer = {};
	const char				background_color	[]	= "FFCCAA";
	for(uint32_t iSection = 0; iSection < ::std::size(sections); ++iSection) {
		buffer.resize(strlen(sections[iSection]) + 1024);
		int						lenToAppend			= sprintf_s(&buffer[0], buffer.size(), "<td style=\"background-color: %s;\">%s</td>", background_color, sections[iSection]);
		content.append(&buffer[0], lenToAppend);
	}
	content.append("</tr></table>");

	// 
	printf(http_headers);
	printf("<html>");
	printf(head, title);
	printf(body, &content[0]);
	printf("</html>");
	return 0;
}
