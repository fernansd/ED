/*!
	\file  macros.hpp
	\brief Macros para el diseño de pantallas
*/

#ifndef MACROS_HPP
#define MACROS_HPP

/// Macro que permite situar el cursor en cualquier posición de la consola
#define LUGAR(x,y)   printf("\033[%d;%dH",x,y)
/// Macro que borra por completo la consola de comandos
#define BORRAR       printf("\33[2J") 
/// Macro que crea un efecto parpadeante sobre texto
#define PARPADEO     printf("%c[5m",27)
/// Macro que desactiva los efectos de texto, a partir de su uso
#define APAGA        printf("%c[0m",27)
/// Macro que invierte los colores aplicados sobre el texto
#define INVERSO      printf("%c[7m",27)
/// Macro que crea un efecto de subrayado sobre el texto
#define SUBRAYADO    printf("%c[4m",27)
/// Macro que resalta el texto
#define INTENSIDAD   printf("%c[1m",27)

#endif
