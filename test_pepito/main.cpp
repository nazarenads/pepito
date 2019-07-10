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

	const char				head			[] = "<head><title>%s</title><style>%s</style><style>%s</style></head>";
	const char				script			[] = "<script>%s</script>";
	const char				body			[] = "<body>%s</body>";		

	::std::string			content;
	::std::vector<char>		buffer					= {};
	const char				background_color	[]	= "FFCCAA";
	const char				brandname           []	= "Pepito";
	const char				logoURL				[]	= "https://www.logocrea.com/2/wp-content/uploads/2016/07/aguila1.png";

	//navbar
	content.append("<div class=\"navbar\"><div class=\"navbar__wrapper\"><nav class=\"navbar__menu\">");
	buffer.resize(strlen(brandname) + strlen(logoURL) + 2048);
	int  newlenToAppend = sprintf_s(&buffer[0], buffer.size(),"<a class=\"navbar__brand\" href=\"#\">%s<img src=\"%s\" alt=\"\"></a>", brandname, logoURL);
	content.append(&buffer[0], newlenToAppend);
	content.append("<ul class=\"navbar__nav\">");
	generateHTMLTagFromList(content, sections, ::pep::size(sections) , sprintf_s(&buffer[0], buffer.size(), "<li class=\"navbar__link after-transform\"><a class=\"active\" href=\"#\">%s</a></li>", sections[iItem]));


	content.append("</ul>");
	content.append("</nav></div></div>");
	
	//gallery
	content.append("<h1>Gallery Title</h1>");
	::htmlGenerateGallery(content, images);

	// 
	printf(http_headers);
	printf("<html>");
	{
		::std::vector<char>		gallery_css;
		::std::vector<char>		header_css;
		if(0 <= ::pep::fileToMemory("./gallery.css", gallery_css) && 0 <= ::pep::fileToMemory("./header.css", header_css))
			printf(head, title, &gallery_css[0], &header_css[0]);
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
//const char headerHTML = <div class="header">                                                       
//  <div class="navbar"><div class="navbar__wrapper"><nav class="navbar__menu"><a class="navbar__brand" href="#">Brand<img src="#" alt=""/></a><div id="nav-icon3"><span></span><span></span><span></span><span></span></div>
//		  <ul class="navbar__nav">
//          <li class="navbar__link after-transform"><a class="active" href="#">Inicio</a></li>
//          <li class="navbar__link after-transform"><a href="#">Nosotros</a></li>
//          <li class="navbar__link after-transform"><a href="#">Galeria</a></li>
//          <li class="navbar__link after-transform"><a href="#">Blog</a></li>
//          <li class="navbar__link after-transform"><a href="#">Contacto</a></li>
//        </ul>
//      </nav>
//    </div>
//  </div>
//  <div class="navbar-responsive">
//    <ul class="navbar-responsive__nav">
//      <li class="navbar-responsive__link after-transform"><a class="active" href="#">Inicio</a></li>
//      <li class="navbar-responsive__link after-transform"><a href="#">Nosotros</a></li>
//      <li class="navbar-responsive__link after-transform"><a href="#">Galeria</a></li>
//      <li class="navbar-responsive__link after-transform"><a href="#">Blog</a></li>
//      <li class="navbar-responsive__link after-transform"><a href="#">Contacto</a></li>
//    </ul>
//  </div>
//</div>





