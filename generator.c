// Generator used to create my_first_calculator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *C_file = fopen("my_first_calculator.c", "w");

	char equation[8];
	char signs[5] = "+-/*\0";
	int min_num = 0, max_num = 50, equals = 0;

	fprintf(C_file,
		"#include <stdio.h>\n"
		"#include <stdlib.h>\n"
		"// my_first_calculator.c by Shellc0d3\n"
		"// C implementation of my_first_calculator.py by AceLewis\n"
		"// TODO: Make it work for all floating point numbers too\n\n"
		"int main () {\n"
		"	char number[3];\n"
		"	char sign;\n"
	    	"	printf(\"Welcome to this calculator!\\n\");\n"
		"	printf(\"It can add, subtract, multiply and divide whole numbers from %d to %d\\n\");\n"
		"	printf(\"Please choose your first number: \");\n"
		"	fgets(number, 3, stdin);\n"
		"	getchar();\n"
		"	int num1 = atoi(number);\n"
		"	printf(\"What do you want to do? +, -, /, or *: \");\n"
		"	sign = fgetc(stdin);\n"
		"	getchar();\n"
		"	printf(\"Please choose your second number: \");\n"
		"	fgets(number, 3, stdin);\n"
		"	int num2 = atoi(number);\n\n", min_num, max_num);

	for (int i=0; i<strlen(signs); i++) {
		for (int n1=min_num; n1<max_num+1; n1++) {
			for (int n2=min_num; n2<max_num+1; n2++) {
				sprintf(equation, "%d %c %d", n1, signs[i], n2);
				switch (signs[i]) {
					case '+' : equals = n1 + n2; break;
					case '-' : equals = n1 - n2; break;
					case '*' : equals = n1 * n2; break;
					case '/' : if (n1 != 0 && n2 != 0) equals = n1 / n2; break;
				}
				fprintf(C_file, "	if (num1 == %d && sign == \'%c\' && num2 == %d) ", n1, signs[i], n2);
				if ( signs[i] == '/' && n2 == 0 && n1 == 0 ) {
					fprintf(C_file, "printf(\"%s = Undefined\\n\");\n", equation);
				} else if ( signs[i] == '/' && n2 == 0 && n1 != 0 ) {
					fprintf(C_file, "printf(\"%s = Inf\\n\");\n", equation);
				} else {
					fprintf(C_file, "printf(\"%s = %d\\n\");\n", equation, equals);
				}
			}
		}
	}

	fprintf(C_file, "\n");
	fprintf(C_file, "	printf(\"Thanks for using this calculator, goodbye :)\\n\");\n");
	fprintf(C_file, "	return 0;\n}");

	fclose(C_file);
	return 0;
}
