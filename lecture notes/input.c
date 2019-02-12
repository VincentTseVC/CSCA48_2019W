#include<stdio.h>

int main (){
	// reading from terminal (standerd input)
	int x, y;
	float pi;
	char c;

	// input sanitization
	// if (scanf("%d %d %f%c", &x, &y, &pi, &c) != 4 || c != '\n') {
	// 	printf("%s\n", "INVALD!!!!");
	// } else {
	// 	printf("your input was: %d %d %f\n", x, y, pi);
	// }

	while (1) {
		if (scanf("%d %d %f%c", &x, &y, &pi, &c) == 4 && c == '\n')
			break;
		printf("%s\n", "INVALD!!!!");
	}
	printf("your input was: %d %d %f\n", x, y, pi);




	// reading a string from terminal (standerd input)
	// char s[1024];

	// fgets(s, 1024, stdin);

	// printf("The input was: %s\n", s);

}