#include <string>
#include "Direction.hpp"
#include <map>

using namespace std;

namespace ariel{
    class Board{
  
    private:
        unsigned int min_row=INT8_MAX;
        unsigned int max_row=0;
        unsigned int min_cols=INT8_MAX;
        unsigned int max_cols=0;
        std::map<unsigned int,std::map<unsigned int,string>> board;
 
    public:
        void post(unsigned int row, unsigned int col, Direction d, string msg);
        string read(unsigned int row, unsigned int col, Direction d, unsigned int len);
        void show();
    };
}