/*******************************************************************************
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
 *  <code.eliseev2003.dmitriy@yandex.com>
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
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tinyexpr.h"

void print_help(void)
{
   puts("\
\nTermiCalc v1.3\n\
Copyright (C) 2023 Dmitriy Eliseev\n\
Based on TinyExpr: https://github.com/codeplea/tinyexpr\n\n\
\
This program comes with ABSOLUTELY NO WARRANTY\n\
This is free software, and you are welcome to redistribute it\n\
under certain conditions.\n\n\
\
This is a simple console calculator that allows you to calculate arithmetic\n\
and trigonometric expressions.\n\n\
\
Usage:\n\n\
\
$ calc [expression ...]\n\n\
\
$ calc [expression1] [expression2] [expression ...]\n\n\
\
$ calc\n\n\
\
If no expressions are specified, the program runs interactively and accepts\n\
expressions from the keyboard. To exit interactive mode, enter \"q\"\n\n\
\
If one or more expressions are specified, the program calculates them and\n\
displays the results on the screen.\n\n\
\
To get help on the program, use the \"help\" or \"--help\" parameters or enter \"h\"\n\
or \"?\" in the interactive mode line.\n\n\
\
Examples:\n\n\
\
$ calc\n\
Enter an expression to calculate or q to exit:\n\
> 2+2\n\
= 4\n\
> 3*4-5/2\n\
= 9.5\n\
> sin(pi/6)\n\
= 0.5\n\
> 12^(sqrt(20-48/12))\n\
= 20736\n\
> h\n\
> q\n\n\
\
$ calc 18-3 145/4+12*14 pi*12^2\n\
18-3 = 15\n\
145/4+12*14 = 204.25\n\
pi*12^2 = 452.389\n\n\
\
$ calc help\n");
}

void to_lower(char str[])
{
    int i;
    for ( i=0; str[i]!='\0'; i++ )
        str[i] = tolower((unsigned char)str[i]);
}

int main(int argc, char *argv[]) 
{
    char input[1000];
    double result;
    int error;
    int i;

    if ( argc > 1 ) {
        if ( strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help" ) == 0 ||
            strcmp(argv[1], "h") == 0 || strcmp(argv[1], "-h") == 0 ||
            strcmp(argv[1], "?") == 0) {
            print_help();
            return 0;
        }

        /* calculating expressions in parameters */
        for ( i=1; i<argc; i++ ) {
            to_lower(argv[i]);
            result = te_interp(argv[i], &error);
            if ( argc > 2 )
            	printf("%s ", argv[i]);
            
            if ( error )
                printf("= error\n");
            else
                printf("= %g\n", result);
        }

        return 0;
    }

    // Interactive mode
    printf("TermiCalc v1.3\nCopyright (C) 2023 Dmitriy Eliseev\n\n"
           "Enter an expression to calculate or q to exit:\n");
    while ( 1 ) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        
        if ( input[0] == '\n' )
            continue;

        to_lower(input);
        
        if ( input[0] == 'q' )
            break;
        
        if ( input[0] == 'h' || input[0] == 'H' || input[0] == '?' )
            print_help();
        else {
            result = te_interp(input, &error);
            if ( error )
                printf("Error: invalid expression\n");
            else
                printf("= %g\n", result);
        }
    }

    return 0;
}
