#pragma once

class tictac
{
    private:
        void show_board(int board[]);
        int player_swap(int x);
        int get_target();
        int check_write(int target, int board[]);
        int check_winer_O(int board[]);
        int check_winer_X(int board[]);
        void update(int x, int board[], int player);
    public:
        void gra();
};