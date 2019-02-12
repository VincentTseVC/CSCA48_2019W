#include <stdio.h>
#include <string.h>

void reverse_string(char *string) {
	int end = strlen(string) - 1;
	char temp;

	for (int i = 0; i < strlen(string)/2; i++) {
		temp = string[i];
		string[i] = string[end];
		string[end] = temp;

      	end--;
   	}
}

void search_and_replace(char *string, char query, char target) {
	for (int i = 0; i < strlen(string); i++) {
		// if (strcmp(&string[i], &query) == 0) {
		if (string[i] == query) {
			string[i] = target;
		}
	}
}

int main(int argc, char const *argv[]) {
	char string[] = "Now I know how to program in C!";
	printf("%s\n", string);
	reverse_string(string);
	printf("%s\n", string);
	search_and_replace(string, 'o', 'a');
	printf("%s\n", string);

	return 0;
}