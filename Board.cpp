#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
    void Board::post(unsigned int row, unsigned int col, Direction d, string msg )
    {
        if (d == Direction::Horizontal)
        {
            max_cols= max(max_cols,col+ unsigned(msg.length()));
        }
        else
        {
            max_row = max(max_row,row+ unsigned(msg.length()));
        }
        min_cols=min(min_cols,col);
        min_row= min(min_row,row);

        for (unsigned int i = 0; i < msg.length(); i++)
        {
            board[row][col] = msg.at(i);
            if (d == Direction::Vertical)
            {
               row++;
            }
            else
            {
                col++;
            }         
        }       
    }

    string Board::read(unsigned int row, unsigned int col, Direction dierction, unsigned int len)
    {
        string ans;
        for (int i = 0; i < len; i++)
        {
            if( board[row].find(col)== board[row].end() || board.find(row) == board.end())
            {
                ans.append("_");
            }
            else{
                ans.append(board[row][col]);
            }
            if (dierction == Direction::Vertical)
            {
               row++;
            }
            else
            {
                col++;
            } 
        }
        
        return ans;
    }

    void Board::show()
    {
        for (unsigned int i = min_row; i < max_row; i++)
        {
            for (unsigned int k = min_cols; k < max_cols; k++)
            {
                cout << board[i][k] <<" ";    
            }
            cout<<endl;
        }

    }
} 

