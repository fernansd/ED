/*!
	\file  macros.hpp
	\brief Macros para el diseño de pantallas
*/

#ifndef MACROS_HPP
#define MACROS_HPP

#define LUGAR(x,y)   printf("\033[%d;%dH",x,y)
#define BORRAR       printf("\33[2J") 
#define PARPADEO     printf("%c[5m",27)
#define APAGA        printf("%c[0m",27)
#define INVERSO      printf("%c[7m",27)
#define SUBRAYADO    printf("%c[4m",27)
#define INTENSIDAD   printf("%c[1m",27)

#endif
