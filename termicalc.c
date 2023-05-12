/********************************************************************************
 *  termicalc.c
 *  created: 2023-05-10
 *       _______                  _  _____      _      
 *      |__   __|                (_)/ ____|    | |     
 *         | | ___ _ __ _ __ ___  _| |     __ _| | ___ 
 *         | |/ _ \ '__| '_ ` _ \| | |    / _` | |/ __|
 *         | |  __/ |  | | | | | | | |___| (_| | | (__ 
 *         |_|\___|_|  |_| |_| |_|_|\_____\__,_|_|\___|
 *  
 *  TermiCalc  --  simple console calculator with trigonometric functions
 *  Copyright (C) 2023 Dmitriy Eliseev
 *  <dmitriy.software@gmail.com>
 *
 *  TermiCalc is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  TermiCalc is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TermiCalc.  If not, see <http://www.gnu.org/licenses/>.
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tinyexpr.h"

void print_help()
{
    puts("\nTermiCalc v1.3");
    puts("Copyright (C) 2023 Dmitriy Eliseev");
    puts("Based on TinyExpr: https://github.com/codeplea/tinyexpr\n");
    
    puts("This program comes with ABSOLUTELY NO WARRANTY");
    puts("This is free software, and you are welcome to redistribute it");
    puts("under certain conditions.\n");

    puts("This is a simple console calculator that allows you to calculate arithmetic");
    puts("and trigonometric expressions.\n");
    
    puts("Usage:\n");

    puts("$ calc [expression ...]\n");

    puts("$ calc [expression1] [expression2] [expression ...]\n");
    
    puts("$ calc\n");

    puts("If no expressions are specified, the program runs interactively and accepts");
    puts("expressions from the keyboard. To exit interactive mode, enter q.\n");

    puts("If one or more expressions are specified, the program calculates them and");
    puts("displays the results on the screen.\n");

    puts("To get help on the program, use the \"help\" or \"--help\" parameters or enter \"h\"");
    puts("or \"?\" in the interactive mode line.\n");
    
    puts("Examples:\n");

    puts("$ calc");
    puts("Enter an expression to calculate or q to exit:");
    puts("> 2+2");
    puts("= 4");
    puts("> 3*4-5/2");
    puts("= 9.5");
    puts("> sin(pi/6)");
    puts("= 0.5");
    puts("> 12^(sqrt(20-48/12))");
    puts("= 20736");
    puts("> h");
    puts("> q\n");

    puts("$ calc 18-3 145/4+12*14 pi*12^2");
    puts("18-3 = 15");
    puts("145/4+12*14 = 204.25");
    puts("pi*12^2 = 452.389\n");

    puts("$ calc help\n");
}

int main(int argc, char *argv[]) 
{
    char input[1000];
    double result;
    int error;
    int i;

    if (argc > 1) {
        if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "h") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "?") == 0) {
            print_help();
            return 0;
        }

        // calculating expressions in parameters
        for (i = 1; i < argc; i++) {
            result = te_interp(argv[i], &error);
            if (error) {
                printf("%s = error\n", argv[i]);
            } else {
                printf("%s = %g\n", argv[i], result);
            }
        }

        return 0;
    }

    // Interactive mode
    printf("TermiCalc v1.3\nCopyright (C) 2023 Dmitriy Eliseev\n\nEnter an expression to calculate or q to exit:\n");
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q' || input[0] == 'Q') break;
        if (input[0] == 'h' || input[0] == 'H' || input[0] == '?') print_help();
        
        else {
            result = te_interp(input, &error);
            if (error) {
                printf("Error: invalid expression\n");
            } else {
                printf("= %g\n", result);
            }
        }
    }

    return 0;
}