#include <iostream>
#include <string>

using namespace std;

/**
 * \namespace HomeWork2 A program using strings to sift through user input and print out
 * the smallest and largest words of the users input
 */

/*! Function that reads the words of a users input.
 *
 *  Asks user for input and proceeds to find largest and smallest word in input, if there are no words return
 *  status 0
 *
 */
int main()
{
    cout << "Enter Input: "; /**< Asks user for a line of input */
    string input; /**< Intitilizes string variable */
    getline(cin, input); /**< Assigns user input to string variable including spaces */
    string shortest; /**< Intitilizes string variable */
    string longest; /**< Intitilizes string variable */

    if (input.length() == 0) { /**< checks if input is empty */
        return 1; /**< Return Line */
        }
    else if (input.find_first_not_of(" ", 0) == string::npos) { /**< checks if input is all whitespace */
        return 1; /**< Return Line */
    }
    else {
        string temp; /**< Intitilizes string variable */
        for (int index = 0; index < input.length(); index++) { /**< iterates through the string input*/
            if (index == input.length() -1 && input.substr(index, 1) != " ") { /**< checks if index is at the end of the input and if it isnt whitespace*/
                temp += input.substr(index, 1); /**< adds the charcter at the index to the string */
                if (temp.length() < shortest.length() || shortest.length() == 0) { /**< checks if temp is smaller the shortest */
                shortest = temp; /**< assgins the string in temp to this string */
                }
                if (temp.length() > longest.length()) { /**< checks if temp is larger the the longest */
                    longest = temp;  /**< assgins the string in temp to this string */
                }
                temp.clear(); /**< clears the string temp back to empty */
            }
            else if (input.substr(index, 1) != " ") { /**< checks if the part of the string the index is at is whitespace*/
                temp += input.substr(index, 1); /**< adds the charcter at the index to the string */
            }
            else {
                if (temp.length() < shortest.length() && temp.length() != 0) { /**< checks if temp is smaller the shortest */
                    shortest = temp; /**< assgins the string in temp to this string */
                }
                if(shortest.length() == 0) { /**< checks if temp is equal to the shortest */
                    shortest = temp; /**< assgins the string in temp to this string */
                }
                if (temp.length() > longest.length()) { /**< checks if temp is larger the the longest */
                    longest = temp; /**< assgins the string in temp to this string */
                }
                temp.clear(); /**< clears the string temp back to empty */
            }


        }

    }

    string shortestOutput = string("Shortest word is:") + " " + shortest; /**< adds the shortest work in input to the final output */
    string longestOutput = string("Longest word is:") + " " + longest; /**< adds the longest word in input to the final output */
    cout << shortestOutput << endl; /**< Prints out the final output */
    cout << longestOutput << endl; /**< Prints out the final output */


}
