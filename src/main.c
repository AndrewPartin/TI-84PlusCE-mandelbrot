#include <graphx.h>
#include <math.h>
#include <ti/getcsc.h>
// #include <stdint.h>

#define ITERATIONS 50

struct Complex {
	double real, imag;
};

double absolute(struct Complex c) {
	return sqrt((c.real * c.real) + (c.imag * c.imag));
}

uint8_t mbrot(int x, int y) {
	
	uint8_t n = 0;
	
	struct Complex c;
	c.real = 3.0 * x / GFX_LCD_WIDTH - 2;
	c.imag = 2.0 * y / GFX_LCD_HEIGHT - 1;
	
	struct Complex z;
	z.real = 0;
	z.imag = 0;

    while (absolute(z) <= 2 && n < ITERATIONS) {
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		n++;
    }
	
	return 2*n;
}

int main(void) {
	
	int x, y;
	uint8_t n;
	
	gfx_Begin();
	gfx_FillScreen(0);
	
	for (x = 0; x < GFX_LCD_WIDTH; x++) {
		
		for (y = 0; y < GFX_LCD_HEIGHT; y++) {
			
			n = mbrot(x, y);
			gfx_SetColor(n);
			gfx_SetPixel(x, y);
			
			if (os_GetCSC()) {
				goto quit;
			}
		}
	}
	
	while (!os_GetCSC());
	
	quit:
	gfx_End();
	return 0;
}