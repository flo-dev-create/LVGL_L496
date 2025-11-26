#ifndef ILI9341_H
#define ILI9341_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"  // Adapte selon ta famille STM32 (ex: stm32f4xx_hal.h)
#include <stdint.h>

#define BLACK       	0x0000
#define NAVY        	0x000F
#define DARKGREEN   	0x03E0
#define DARKCYAN    	0x03EF
#define MAROON      	0x7800
#define PURPLE      	0x780F
#define OLIVE       	0x7BE0
#define LIGHTGREY   	0xC618
#define DARKGREY    	0x7BEF
#define BLUE        	0x001F
#define GREEN       	0x07E0
#define CYAN        	0x07FF
#define RED         	0xF800
#define MAGENTA     	0xF81F
#define YELLOW      	0xFFE0
#define WHITE       	0xFFFF
#define ORANGE      	0xFD20
#define GREENYELLOW 	0xAFE5
#define PINK        	0xF81F

/*
    Ce header correspond à l'implémentation fournie pour un écran ILI9341
    piloté via SPI (HiLetgo). Les broches RESET, CS, DC et la handle SPI
    (hspi1) doivent être définis dans main.h ou un fichier de configuration
    matériel équivalent.
*/

//// Orientation de l’écran
//typedef enum {
//    ROTATE_O = 0,
//    ROTATE_90,
//    ROTATE_180,
//    ROTATE_270
//} LCD_Horizontal_t;

// Dépendances externes (définies ailleurs)
extern void Error_Handler(void);
extern SPI_HandleTypeDef hspi1;

// API publique

// Initialisation/Reset
void ILI9341_Init(void);
void ILI9341_Reset(void);
void ILI9341_SoftReset(void);

// Accès registres (commandes/données)
void LCD_WR_REG(uint8_t data);

// Affichage bas niveau
void ILI9341_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t end_y);
void ILI9341_WritePixel(uint16_t x, uint16_t y, uint16_t color);

// Blitting d’images (16-bit RGB565)
void ILI9341_DrawBitmap(uint16_t w, uint16_t h, uint8_t *s);
void ILI9341_DrawBitmapDMA(uint16_t w, uint16_t h, uint8_t *s);
void ILI9341_EndOfDrawBitmap(void);

// Utilitaires de portage (implémentés dans le .c)
void sendSPI(uint8_t *data, int size);
void Delay(uint16_t ms);

#ifdef __cplusplus
}
#endif

#endif // ILI9341_H
