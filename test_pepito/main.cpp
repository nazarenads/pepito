﻿#include "pepito.h"
#include <stdio.h>
#include <string>
#include <vector>

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


const char gallery_css []	=
"\n* {																			   "
"\n  box-sizing: border-box;													   "
"\n}																			   "
"\n																				   "
"\nbody {																		   "
"\n  font-family: Verdana,sans-serif;											   "
"\n  margin: 0;																	   "
"\n}																			   "
"\n																				   "
"\n.mySlides {																	   "
"\n  display: none;																   "
"\n}																			   "
"\n																				   "
"\n.mySlides img {																   "
"\n  height: 50%;																   "
"\n  width: 100%;																   "
"\n}																			   "
"\n																				   "
"\n/* Slideshow container */													   "
"\n.slideshow-container {														   "
"\n  max-width: 1000px;															   "
"\n  position: relative;														   "
"\n  margin: 0 auto;															   "
"\n}																			   "
"\n																				   "
"\n/* Next & previous buttons */												   "
"\n.prev, .next {																   "
"\n  cursor: pointer;															   "
"\n  position: absolute;														   "
"\n  top: 50%;																	   "
"\n  width: auto;																   "
"\n  padding: 16px;																   "
"\n  margin-top: -22px;															   "
"\n  color: white;																   "
"\n  font-weight: bold;															   "
"\n  font-size: 18px;															   "
"\n  transition: 0.6s ease;														   "
"\n  border-radius: 0 3px 3px 0;												   "
"\n}																			   "
"\n																				   "
"\n/* Position the \"next button\" to the right */								   "
"\n.next {																		   "
"\n  right: 0;																	   "
"\n  border-radius: 3px 0 0 3px;												   "
"\n}																			   "
"\n																				   "
"\n/* On hover, add a black background color with a little bit see-through */	   "
"\n.prev:hover, .next:hover {													   "
"\n  background-color: rgba(0,0,0,0.8);											   "
"\n}																			   "
"\n																				   "
"\n/* Caption text */															   "
"\n.text {																		   "
"\n  color: #f2f2f2;															   "
"\n  font-size: 15px;															   "
"\n  padding: 8px 12px;															   "
"\n  position: absolute;														   "
"\n  bottom: 8px;																   "
"\n  width: 100%;																   "
"\n  text-align: center;														   "
"\n}																			   "
"\n																				   "
"\n/* Number text (1/3 etc) */													   "
"\n.numbertext {																   "
"\n  color: #f2f2f2;															   "
"\n  font-size: 12px;															   "
"\n  padding: 8px 12px;															   "
"\n  position: absolute;														   "
"\n  top: 0;																	   "
"\n}																			   "
"\n																				   "
"\n/* The dots/bullets/indicators */											   "
"\n.dot {																		   "
"\n  cursor:pointer;															   "
"\n  height: 13px;																   "
"\n  width: 13px;																   "
"\n  margin: 0 2px;																   "
"\n  background-color: #bbb;													   "
"\n  border-radius: 50%;														   "
"\n  display: inline-block;														   "
"\n  transition: background-color 0.6s ease;									   "
"\n}																			   "
"\n																				   "
"\n.active, .dot:hover {														   "
"\n  background-color: #717171;													   "
"\n}																			   "
"\n																				   "
"\n/* Fading animation */														   "
"\n.fade {																		   "
"\n  -webkit-animation-name: fade;												   "
"\n  -webkit-animation-duration: 1.5s;											   "
"\n  animation-name: fade;														   "
"\n  animation-duration: 1.5s;													   "
"\n}																			   "
"\n																				   "
"\n@-webkit-keyframes fade {													   "
"\n  from {opacity: .4} 														   "
"\n  to {opacity: 1}															   "
"\n}																			   "
"\n																				   "
"\n@keyframes fade {															   "
"\n  from {opacity: .4} 														   "
"\n  to {opacity: 1}															   "
"\n}																			   "
"\n																				   "
"\n/* On smaller screens, decrease text size */									   "
"\n@media only screen and (max-width: 300px) {									   "
"\n  .prev, .next,.text {font-size: 11px}										   "
"\n}																			   "
;

const char gallery_js []	=		"var slideIndex = 0;												"
	"\n	showSlides();																					"
	"\n																									"
	"\n	function showSlides() {																			"
	"\n		var i;																						"
	"\n		var slides = document.getElementsByClassName('mySlides');									"
	"\n		var dots = document.getElementsByClassName('dot');											"
	"\n																									"
	"\n		for(i = 0; i< slides.length; i++) {															"
	"\n			slides[i].style.display = 'none';														"
	"\n		}																							"
	"\n																									"
	"\n		slideIndex++;																				"
	"\n		if(slideIndex > slides.length) {															"
	"\n			slideIndex = 1;																			"
	"\n		}																							"
	"\n																									"
	"\n		for(i = 0; i < dots.length; i++) {															"
	"\n			dots[i].className = dots[i].className.replace(' active', '');							"
	"\n		}																							"
	"\n																									"
	"\n		slides[slideIndex-1].style.display = 'block';												"
	"\n		dots[slideIndex-1].className += ' active';													"
	"\n																									"
	"\n		setTimeout(showSlides, 2000) //Changes ever 2 seconds;										"
	"\n																									"
	"\n	}";

int main(){
	const char				http_headers	[] = "content-type: text/html \r\n\r\n";
	const char				title			[] = "My Page";

	const char				head			[] = "<head><title>%s</title><style>%s</style></head>";
	const char				script			[] = "<script>%s</script>";
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

	content.append("<h1>Gallery Title</h1>");

	content.append("<div class=\"slideshow-container\">");

	for(uint32_t iImage = 0; iImage < ::std::size(images); ++iImage) {
		buffer.resize(strlen(sections[iImage]) + 1024);
		int						lenToAppend			= sprintf_s(&buffer[0], buffer.size(), "<div class=\"mySlides fade\"> <div class=\"numbertext\">%lu / %zu</div> <img src=\"%s\"></div>", iImage + 1, ::std::size(images), images[iImage]);
		content.append(&buffer[0], lenToAppend);
	}

	content.append("<a class=\"prev\" onclick=\"plusSlides(-1)\">&lt;</a>");
	content.append("<a class=\"prev\" onclick=\"plusSlides(1)\">&gt;</a>");
	content.append("</div>");

	content.append("<div style=\"text-align:center\">");
	for(uint32_t iImage = 0; iImage < ::std::size(images); ++iImage) {
		buffer.resize(strlen(sections[iImage]) + 1024);
        int						lenToAppend			= sprintf_s(&buffer[0], buffer.size(),"<span class=\"dot\" onclick=\"currentSlide(%lu)\"></span>", iImage + 1);
		content.append(&buffer[0], lenToAppend);
	}
	content.append("</div>");


	// 
	printf(http_headers);
	printf("<html>");
	printf(head, title, gallery_css);
	printf(body, &content[0]);
	printf(script, gallery_js);
	printf("</html>");
	return 0;
}


