#include<iostream>
#include <cstdlib>    // For rand() function
#include<ctime>       // For seeding rand() function
using namespace std;
//Global variables use
//Define the game board array globally
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char turn = 'X';  //initially set player[X] turn 
bool Isdraw = false;   // initially set draw possibility false
int row, col;
// Colors
const string RESET = "\033[0m";
const string RED = "\033[31m"; // Red color for the error
const string BLUE = "\033[34m"; // Blue color for player 1
const string GREEN = "\033[32m"; // Green color for player 2
const string PINK = "\033[95m"; // Pink color for display board
const string ORANGE = "\033[33m"; // Orange color for player win or draw
const string SKY_BLUE = "\033[36m"; // Sky blue color for title
const string DARK_ORANGE = "\033[38;5;130m"; // Dark orange color for instructions

// display instructions
void displayInstructions()
{
	cout << " " << DARK_ORANGE << "\n Instructions:" << RESET << endl;
	cout << " " << DARK_ORANGE << "1. Player 1's symbol is " << ORANGE << "X" << RESET << DARK_ORANGE << " and Player 2's symbol is " << GREEN << "O." << RESET << endl;
	cout << " " << DARK_ORANGE << "2. Enter a number between 1 and 9 to place your mark on the board." << RESET << endl;
	cout << " " << DARK_ORANGE << "3. If you enter a wrong number, an error message will be displayed." << RESET << endl;
	cout << " " << DARK_ORANGE << "4. If you choose a position that is already occupied, an error message will be displayed." << RESET << endl;
}
// function to display the Tic-Toe-Toe board
void displayBoard()
{
	system("cls"); // board update
	cout << SKY_BLUE << "****************************************************************************************************" << RESET << endl;
	cout << " " << SKY_BLUE << "                                         TIC-TAC-TOE                                       " << RESET << endl;
	cout << SKY_BLUE << "****************************************************************************************************" << RESET << endl;
	displayInstructions();
	//cout << "\n\tTICK TAC TOE GAME" << endl;
	cout << " " << BLUE << "\n\tPlayer1 [X]" << RESET;
	cout << " " << GREEN << "\n\tPlayer2 [O]\n\n" << RESET;
	// Loop through each row of the board
	for (int i = 0; i < 3; i++)
	{
		// Print the top line of the row
		cout << " " << PINK << "\t\t     |     |     \n" << RESET;
		// Print the values of the cells in the current row
		cout << " " << PINK << "\t\t  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  \n" << RESET;

		// If not the last row, print the row separator
		if (i < 2)
		{
			cout << " " << PINK << "\t\t_____|_____|_____\n" << RESET;
		}
		else
		{
			// For the last row, print the bottom line
			cout << " " << PINK << "\t\t     |     |     \n" << RESET;
		}
	}
}
// function for player turn 
void playerTurn()
{
	// Display on screen which player turn
	if (turn == 'X')
		cout << " " << BLUE << "\n\tPlayer1 [X] turns:" << RESET;
	else
		cout << " " << GREEN << "\n\tPlayer2 [O] turns:" << RESET;
	// Prompt the user to enter choice (1-9)
	int choice;
	cin >> choice;
	// Pompt the user to enter valid choice
	while (choice < 1 || choice > 9 || cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
		cout << " " << RED << "\n\tERROR! Enter valid Choice: (1-9) " << RESET;
		cin >> choice;
	}
	// according to user choice check which box were marked
	switch (choice)
	{
	case 1:
		row = 0; col = 0; // Box 1
		break;
	case 2:
		row = 0; col = 1; // Box 2
		break;
	case 3:
		row = 0; col = 2; // Box 3
		break;
	case 4:
		row = 1; col = 0; // Box 4
		break;
	case 5:
		row = 1; col = 1; // Box 5
		break;
	case 6:
		row = 1; col = 2; // Box 6
		break;
	case 7:
		row = 2; col = 0; // Box 7
		break;
	case 8:
		row = 2; col = 1; // Box 8
		break;
	case 9:
		row = 2; col = 2; // Box 9
		break;
	default:
		cout << "Invalid Choice\n";
		break;
	}
	// Check now which player turn 
	// Here && condition apply to ensure that the choice user choose the box are free or not
	if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'X';
		// After player[X] turn give the turn to player[O]
		turn = 'O';
	}
	else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'O';
		// After player[O] turn give the turn to player[X] for game flow
		turn = 'X';
	}
	//if user choose same box number which is already filled display error 
	else
	{
		cout << " " << RED << "\n\tBox already filled!\n\tPlease try again!! \n\n" << RESET;
		// Again call player turn function for valid choice
		playerTurn();
	}
	displayBoard();  //Update Board 
}
//function to check the player won the game or not
bool gameOver()
{
	//check win
	for (int i = 0; i < 3; i++)
	{
		// Check win row or column wise
		if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
		{
			return false; // player win game over!
		}
	}
	// Check Diagonals both possibilities
	if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
	{
		return false; // player win game over!
	}
	//Check if there is any box not filled yet
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')
			{
				return true;   //no game over
			}

		}
	}
	Isdraw = true;  //if all box filled and no one win the game then game is draw!!!
	return false;   // game over

}
// Function to make the computer's move
void computerTurn() 
{
	int choice;
	do 
	{
		choice = rand() % 9 + 1;   // Randomly choose a position (1-9)
		switch (choice) 
		{
		case 1: row = 0; col = 0; break;
		case 2: row = 0; col = 1; break;
		case 3: row = 0; col = 2; break;
		case 4: row = 1; col = 0; break;
		case 5: row = 1; col = 1; break;
		case 6: row = 1; col = 2; break;
		case 7: row = 2; col = 0; break;
		case 8: row = 2; col = 1; break;
		case 9: row = 2; col = 2; break;
		}
	} while (board[row][col] == 'X' || board[row][col] == 'O');
	board[row][col] = 'O';
	turn = 'X';
	displayBoard();
}

// Function to choose the game mode
void chooseGameMode() 
{
	int choice;
	cout << PINK << "\n |**************************|" << RESET << endl;
	cout <<  " " << PINK << "|     Choose Game Mode     |\n" << RESET;
	cout << PINK << " ****************************\n" << RESET << endl;
	cout << " " << PINK << "1. One Player (Against Computer)\n" << RESET;
	cout << " " << PINK << "2. Two Players (With Friend)\n" << RESET;
	cout << " " << ORANGE << "\n Enter your choice: " << RESET;
	cin >> choice;
	while (choice < 1 || choice > 2 || cin.fail())
	{
		cin.clear(); // Clear the error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
		cout << " " << RED << "\n ERROR!\n Enter valid Choice: (1 OR 2) " << RESET;
		cin >> choice;
	}
	switch (choice) 
	{
	case 1:
		while (gameOver()) 
		{
			displayBoard();
			playerTurn();
			if (!gameOver())
			{
				break;
			}
			computerTurn();
		}
		break;
	case 2:
		while (gameOver()) 
		{
			displayBoard();
			playerTurn();
			gameOver();
		}
		break;
	default:
		cout << " " << RED << "\n Invalid choice. Please try again.\n" << RESET;
		chooseGameMode();
		break;
	}
}
// Main function
int main() 
{
	srand(time(0)); // Initialize random seed
	cout << SKY_BLUE << "****************************************************************************************************" << RESET << endl;
	cout << " " << SKY_BLUE << "                                      TIC-TAC-TOE GAME                                      " << RESET << endl;
	cout << SKY_BLUE << "****************************************************************************************************" << RESET << endl;
	chooseGameMode();
	// if Player[X] turn remaining and decided game over than Player[O] win the game  
	if (turn == 'X' && Isdraw == false)
	{
		cout << " " << ORANGE << "\n\n  Player2 [O] Wins!! Congratulation\n" << RESET;
	}
	// if Player[O] turn remaining and decided game over than Player[X] win the game  
	else if (turn == 'O' && Isdraw == false)
	{
		cout << " " << ORANGE << "\n\n  Player1 [X] Wins!! Congratulation\n" << RESET;
	}
	//if all box filled and no one won the game then the game is draw
	else
	{
		cout << " " << ORANGE << " \n\n  Game Draw!!! \n" << RESET;
	}
	return 0;
}