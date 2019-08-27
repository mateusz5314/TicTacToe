#include <iostream>
#include "tictac.hpp"

constexpr int board_size = 9;

void tictac::gra()
{
    system("clear");
    int WIN = 0;
    int board[board_size]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    show_board(board);

    for (int i = 0; i<board_size; i++)
    {
        board[i] = ' ';
    }

    int player = 0;
    int target = 0;
    int draw = 0;

    std::cout << "Press enter\n";
    std::cin.get();

    int write_error = 1;
    int X_won = 0;
    int O_won = 0;

    while(WIN!=1)
    {
        system("clear");
        show_board(board);
        
        std::cout << "\n";
        player = player_swap(player);
        std::cout << "-\nGracz: " << (char)player << "\n-\n";

        write_error = 1;

        while(write_error!=0)
        {   
            target = get_target();

            write_error = check_write(target, board);
            if (write_error == 1)
            {
                std::cout << "Field is corrupted\n";
            }
        }
        update(target, board, player);
        
    if (player == 'X')
    {
        X_won = check_winer_X(board);
    }
    else
    {
        O_won = check_winer_O(board);
    }
    if (O_won == 1)
    {
        show_board(board);
        std::cout << "Wygrywa O\n";
        WIN = 1;
    }
    else if (X_won == 1)
    {
        show_board(board);
        std::cout << "Wygrywa X\n";
        WIN = 1;
    }
    draw++;
    if (draw == 9)
    {
        std::cout << "Remis!\n";
        WIN = 1;
    }
    }
}

int tictac::get_target()
{
    char result = '0';
    int check = 0;
    do
    {
    std::cout << "Where you want to set char\n";
    std::cin >> result;
    if (result < '1' || result > '9')
    {
        std::cout << "Enter 1-9 value\n"; 
    }
    else 
    {
        check = 1;
    }
    } 
    while (check != 1);
    
    
    return result-'0';
}
int tictac::player_swap(int x)
{
    int new_player = 0;

    if(x == 'O')
    {
        new_player = 'X';
    }
    else
    {
        new_player = 'O';
    }
    
    return new_player;
}

void tictac::show_board(int board[])
{
    std::cout << "Plansza do gry:\n";
    std::cout << " " << (char)board [0] << " | " << (char)board[1] << " | " << (char)board[2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << (char)board [3] << " | " << (char)board[4] << " | " << (char)board[5] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << (char)board [6] << " | " << (char)board[7] << " | " << (char)board[8] << " \n";
}

int tictac::check_winer_O(int board[])
{
    int winner_O = 0;
    if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
    {
        winner_O = 1;
    }
    else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
    {
        winner_O = 1;
    }
    else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
    {
        winner_O = 1;
    }
    else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
    {
        winner_O = 1;
    }
    else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
    {
        winner_O = 1;
    }
    else if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
    {
        winner_O = 1;
    }
    else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
    {
        winner_O = 1;
    }
    else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
    {
        winner_O = 1;
    }

    return winner_O;
}

int tictac::check_winer_X(int board[])
{
    int winner_X = 0;
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
    {
        winner_X = 1;
    }
    else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
    {
        winner_X = 1;
    }
    else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
    {
        winner_X = 1;
    }
    else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
    {
        winner_X = 1;
    }
    else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
    {
        winner_X = 1;
    }
    else if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
    {
        winner_X = 1;
    }
    else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
    {
        winner_X = 1;
    }
    else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
    {
        winner_X = 1;
    }

    return winner_X;
}

int tictac::check_write(int target, int board[])
{
    int OK = 0;
    
    if ((char)board[target-1] == 'X' || (char)board[target-1] == 'O')
    {
        OK = 1;
    }

    return OK;
}

void tictac::update(int x, int board[], int player)
{
    if (player == 'X')
    {
        board[x-1] = 'X';
    }
    else 
    {
        board[x-1] = 'O';
    }
}