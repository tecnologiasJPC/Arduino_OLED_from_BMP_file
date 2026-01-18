#include <Wire.h>                 // incluimos la libreria para comunicacion I2C
#include <Adafruit_SSD1306.h>     // la libreria para pantalla OLED
#include "image_code.h"           // el archivo con la imagen a mostrar

#define SCREEN_WIDTH    128        // definimos el ancho de pantalla OLED en pixeles
#define SCREEN_HEIGHT   64         // el alto de pantalla OLED en pixeles  
#define OLED128         0x3C       // definimos la direccion para pantalla OLED

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);  // creamos el objeto para la pantalla OLED

void testdrawbitmap(void) {   // creamos la funcion para dibujar una imagen en pantalla
  display.clearDisplay();     // limpiamos la pantalla OLED
  display.drawBitmap(         // dibujamos la imagen al centro de la pantalla
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();          // mostramos lo dibujado en pantalla
}

void setup() {  // creamos la funcion setup
  Serial.begin(115200); // inicializamos la comunicacion serial
  while (!Serial);      // esperamos a que la comunicacion serial se inicie
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED128)) {// inicializamos la pantalla OLED
    Serial.println(F("Failed to initialize OLED. Verify connections"));
    while (1);
  }
  display.clearDisplay(); // enviamos comando para limpiar la pantalla OLED

  testdrawbitmap();       // mostramos la imagen en la pantalla OLED
}

void loop() { // creamos la funcion loop vacia
}
