#include <iostream>
#include "ufo_functions.hpp"

int main()
{
    // Declare the codeword and the player's current answer
    std::string codeword = "adventure";
    std::string answer = "__________";

    // Track the number of incorrect guesses
    int misses = 0;

    // Store incorrect guessed letters
    std::vector<char> incorrect;

    // Track if the current guess is correct
    bool guess = false;

    // Store the player's guessed letter
    char letter;

    // Show the game greeting and instructions
    greet();

    // Main game loop: keep playing until the word is guessed or max misses reached
    while (answer != codeword && misses < 7)
    {
        // Reset guess status for this turn
        guess = false;

        // Ask the player for a letter guess
        std::cout << "\nPlease enter your guess: ";
        std::cin >> letter;

        // Check if the guessed letter is in the codeword
        for (int i = 0; i < codeword.length(); i++)
        {

            if (letter == codeword[i])
            {
                // Update the answer with the correct letter
                answer[i] = letter;
                // Mark guess as correct
                guess = true;
            }
        }

        // If the guess was correct, let the player knows
        if (guess == true)
        {

            std::cout << "\nCorrect! You're closer to cracking the codeword.\n";
        }
        else
        {
            // If the guess was incorrect, update misses and store the letter
            std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";

            incorrect.push_back(letter);

            misses++;
        }

        // Show the current UFO status and incorrect guesses
        display_misses(misses);
        display_status(incorrect, answer);
    }

    // Show the final game result
    end_game(answer, codeword);
}
