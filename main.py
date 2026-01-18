from PIL import Image

if __name__ == '__main__':
    print('Convertir BMP a binarios')
    # 1. Abrir la imagen
    img = Image.open("LogoNegro bits.bmp")

    # Convertir a escala de grises y luego a binario (1-bit)
    # El umbral (threshold) se aplica automáticamente
    img_binaria = img.convert("1")


    # Obtener los valores (0 para negro, 1 para blanco)
    pixels = list(img_binaria.getdata())  # la imagen es de 80x41
    #print(pixels[:50])  # Muestra los primeros 50 valores
    for i, pix in enumerate(pixels):
        if pix == 255:
            print(0, end='')
        else:
            print(1, end='')

        if i % 8 != 0:
            pass
        else:
            print(', ', end='')
            if i % 80 == 0:
                print()
            print('0b', end='')


