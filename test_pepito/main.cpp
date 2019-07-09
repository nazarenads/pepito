#include "pep_size.h"
#include "pep_file.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

#define generateHTMLTagFromList(content_, items_, count_, printf_) {	\
	for(uint32_t iItem = 0; iItem < count_; ++iItem) {					\
		const char				* item				= items_[iItem];	\
		buffer.resize(strlen(item) + 1024);								\
		int						lenToAppend			= printf_;			\
		content_.append(&buffer[0], lenToAppend);						\
	}																	\
}

int							htmlGenerateGallery			(::std::string & content, ::pep::view<const char*> images) {
	::std::vector<char>				buffer						= {};
	content.append("<div class=\"slideshow-container\">");
	generateHTMLTagFromList(content, images, images.Count, sprintf_s(&buffer[0], buffer.size(), "<div class=\"mySlides fade\"> <div class=\"numbertext\">%u / %u</div> <img src=\"%s\"></div>", iItem + 1, images.Count, images[iItem]));
	content.append("<a class=\"prev\" onclick=\"plusSlides(-1)\">&lt;</a>");
	content.append("<a class=\"next\" onclick=\"plusSlides(1)\">&gt;</a>");
	content.append("</div>");
	// ctrl + alt + L - Solution Explorer
	// alt + 2 - output window
	// atl + 7 - call stack
	content.append("<div style=\"text-align:center\">");
	generateHTMLTagFromList(content, images, images.Count, sprintf_s(&buffer[0], buffer.size(),"<span class=\"dot\" onclick=\"currentSlide(%lu)\"></span>", iItem + 1));
	content.append("</div>");
	return 0;
}

const char * sections [] = 
	{	"Inicio"	
	,	"Quienes Somos"	
	,	"Nuestros Servicios"	
	,	"Contacto"	
	};

const char * scripts [] = 
	{	"test.js"
	};

const char * images [] =
	{	"https://1stwebdesigner.com/wp-content/uploads/2014/04/Wallpapers-For-Designers-37.png"
	,	"http://www.bluthemes.com/assets/img/blog/12/mountains-dark.jpg"
	,	"http://cdn.wonderfulengineering.com/wp-content/uploads/2014/04/code-wallpaper-1.png"
	,	"https://images2.minutemediacdn.com/image/upload/c_crop,h_1193,w_2121,x_0,y_175/f_auto,q_auto,w_1100/v1554921998/shape/mentalfloss/549585-istock-909106260.jpg"
	};

int main(){
	const char				http_headers	[] = "content-type: text/html \r\n\r\n";
	const char				title			[] = "My Page";

	const char				head			[] = "<head><title>%s</title><style>%s</style></head>";
	const char				script			[] = "<script>%s</script>";
	const char				body			[] = "<body>%s</body>";		


	::std::string			content;
	content.append("<table><tr>");
	::std::vector<char>		buffer					= {};
	const char				background_color	[]	= "FFCCAA";

	generateHTMLTagFromList(content, sections, ::pep::size(sections), sprintf_s(&buffer[0], buffer.size(), "<td style=\"background-color: %s;\">%s</td>", background_color, sections[iItem]));
	content.append("</tr></table>");

	content.append("<h1>Gallery Title</h1>");
	::htmlGenerateGallery(content, images);

	// 
	printf(http_headers);
	printf("<html>");
	{
		::std::vector<char>		gallery_css;
		if(0 <= ::pep::fileToMemory("./gallery.css", gallery_css))
			printf(head, title, &gallery_css[0]);
	}
	printf(body, &content[0]);
	{
		::std::vector<char>		gallery_js;
		if(0 <= ::pep::fileToMemory("./gallery.js", gallery_js))
			printf(script, &gallery_js[0]);
	}
	printf("</html>");
	return 0;
}
