/**
 * File:        main.cpp
 * Author:      chedr
 * Description: GameSave editor entry point
 */

#include "GameSave.h"
#include <iostream>


/**
 * Entry point
 */
int main(int argc, char *argv[])
{
    if (argc == 2) { //Read mode
        GameSave game_save(argv[1]);
        game_save.print();
    } else if (argc == 3) { //Write mode
        GameSave game_save(argv[1]);
        game_save.print();
        game_save.clone_character(1, 0);
        game_save.rename_character(1, "Trombone");
        game_save.print();
        game_save.save(argv[2]);
    } else { //Invalid arguments
        std::cerr << "Usage: " << argv[0] <<
                " input_file [output_file]" << std::endl;
        return 1;
    }
    return 0;
}
