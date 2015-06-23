/**
 * File:        GameSave.c
 * Author:      chedr
 * Description: GameSave definitions
 */

#include "GameSave.h"
#include <iostream>


GameSave::GameSave(std::string file)
throw(XenoverseException) : _file(file),
                            in_stream(file, std::ios_base::in)

{
    this->in_stream.read((char *) &this->data, sizeof(game_save_data_t));
    if (data.magic != GAME_SAVE_MAGIC) {
        throw XenoverseException("Invalid game save magic number");
    }
}



GameSave::~GameSave(void)
{

}


GameSave::GameSave(const GameSave &other) : _file(other._file),
                                            in_stream(other._file,
                                                      std::ios_base::in)
{

}


GameSave::GameSave(GameSave &&other) : _file(other._file),
                                       in_stream(other._file, std::ios_base::in)
{

}


GameSave &GameSave::operator=(const GameSave &other)
{
    if (&other != this) {
        this->_file = other._file;
        this->in_stream.open(other._file, std::ios_base::in);
    }
    return *this;
}


GameSave &GameSave::operator=(GameSave &&other)
{
    if (&other != this) {
        this->_file = other._file;
        this->in_stream.open(other._file, std::ios_base::in);
    }
    return *this;
}


const std::string GameSave::file(void) const throw()
{
    return this->_file;
}


void GameSave::save(std::string file) const throw(XenoverseException)
{
    std::fstream out_stream(file, std::ios_base::out);
    out_stream.write((char *) &this->data, sizeof(game_save_data_t));
}


void GameSave::print(void) const throw() //TODO: label stats
{
    std::cout <<
    "Name:           " <<  this->data.character_name << std::endl <<
    "Zeni:           " <<  this->data.zeni << std::endl <<
    "Level:          " <<  this->data.level << std::endl <<
    "Experience      " <<  this->data.experience << std::endl <<
    "Attribute Pts:  " <<  this->data.attribute_points << std::endl <<
    "Unknown         " <<  this->data.v5 << std::endl <<
    "Unknown         " <<  this->data.v6 << std::endl <<
    "Strike Super:   " <<  this->data.strike_super << std::endl <<
    "Ki Blast Super: " <<  this->data.ki_blast_super << std::endl <<
    "Unknown         " <<  this->data.v9 << std::endl;
}


void GameSave::set_zeni(int32_t zeni)
{
    this->data.zeni = zeni;
}
