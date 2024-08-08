#include <stdio.h>

int main() {
	
	float a, b, c;
	system("color b3");
	
	printf("A: ");
	scanf("%f", &a);

	printf("B: ");
	scanf("%f", &b);
	
	c = a + b;
	
	printf("A soma de %.1f e %.1f e: %.1f", a, b, c);
	
	 	
	return 0;
}
