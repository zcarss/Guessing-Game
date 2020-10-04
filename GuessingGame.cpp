// Generate a random number between 0 and 200
// Create a loop that allows you to enter a number and exists if the guess is correct
//      Allow a guess number to be entered in the console
//      Print “higher” or “lower” depending on the guess
//      If the guess is correct, print “you got it!” and then exit the application


// Plan
// Find out how to
//      Look up Do while loop "number is not = guess        https://beginnersbook.com/2017/08/cpp-do-while-loop/
//      Get random int withing bound        https://www.bitdegree.org/learn/random-number-generator-cpp#:~:text=cryptography%20and%20cybersecurity.-,The%20main%20function%20for%20a%20random%20number%20generation,add%20the%20header.
//      Create Int Var      https://beginnersbook.com/2017/08/cpp-variables/
//      Stop and ask user for input         https://www.w3schools.com/cpp/cpp_user_input.asp

// Problems
// Rand was always making the number 42... https://stackoverflow.com/questions/9459035/why-does-rand-yield-the-same-sequence-of-numbers-on-every-run
// Window closing before use can see "You got it!".. Wnat to add a "press any key to close"  https://stackoverflow.com/questions/21257544/c-wait-for-user-input
// It stops after "cout << "A random number between 0 and 200 has been generated";" but not cout << "You got it!";??   
// Brakes if guess is not int   https://www.techiedelight.com/convert-string-to-int-cpp/   
// Spases make for 2 guesses  https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces and https://en.cppreference.com/w/cpp/algorithm/remove
// Git hub change

#include <iostream>
#include <ctime> // Added to get "time" workling in "srand((unsigned int)time(NULL));"
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(){
    srand((unsigned int)time(NULL)); // Added to Stop the same number all the time. 
    std::string UserInput = "";
    int MagicNumber, Guess; 
    MagicNumber = (rand() % 199) + 1;
    cout << "A random number between 0 and 200 has been generated. \nGuess it!! \n";
    system("pause"); // Added to stop it asking for input after last line

    do{
        cout << "Type in a guess: ";
        std::getline(std::cin, UserInput);
        UserInput.erase(std::remove_if(UserInput.begin(), 
                                        UserInput.end(), 
                                        [](unsigned char x){return std::isspace(x);}), 
                     UserInput.end());
        std::istringstream(UserInput) >> Guess;
        if (Guess != 0){
            if (Guess > MagicNumber){
                cout << "Lower \n";
            }
            if (Guess < MagicNumber){
                cout << "Higher \n";
            }
        }
        else
        {
            cout << "Invalid Input!! \n";
        }

    } while (MagicNumber != Guess);

    cout << "You got it! \n";
    system("pause"); // Added to stop window closing before use can see "You got it!"
    return 0;    
}
