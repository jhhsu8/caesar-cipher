#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>

/* Implement a program that encrypts messages using Caesar’s cipher 
by shifting each letter by some number of places */

int key, ascii, index, new_index, new_ascii;

int main(int argc, string argv[]) {
    //Accept a number as a command-line argument
    if (argc == 2) {
        string input;
        printf("Enter a message: ");
        input = GetString();

        for (int i = 0, n = strlen(input); i < n; i++) {
            // Extract each character from the message
            ascii = input[i];

            // Only encypt alphabets
            if (isalpha(ascii)) {
                // Convert the number to an integer
                key = atoi(argv[1]);

                if (isupper(ascii)) {
                    // Convert each uppercase character into 0 - 25 indexes
                    index = ascii - 65;

                    // Shift each index by the integer (key) and the key is maintained at 1 (a) to 26 (z)
                    new_index = (index + key) % 26;
                    
                    // Convert the new index into the new character
                    new_ascii = new_index + 65;

                } else if (islower(ascii)) {
                    // Convert each lowercase character into 0 - 25 indexes
                    index = ascii - 97;

                    // Shift each index by the integer
                    new_index = (index + key) % 26;

                    // Convert the new index into the new character
                    new_ascii = new_index + 97;
                }

            } else {
                // Non-alphabet characters remain unchanged
                new_ascii = ascii;
            }
            printf("%c", (char) new_ascii);
        }
        printf("\n");

    } else {
        printf("see instructions\n");
        return 1;
    }
    return 0;
}
