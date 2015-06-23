/**
 * File:        GameSave.h
 * Author:      chedr
 * Description: GameSave declarations
 */

#ifndef XENOVERSE_GAMESAVE_H
#define XENOVERSE_GAMESAVE_H

#include "XenoverseException.h"
#include <string>
#include <fstream>
#include <endian.h>

#define GAME_SAVE_MAGIC (be32toh(0x23534156))
#define ZENI_MAX_VALUE   999999999

typedef struct game_save_data
{
    uint32_t magic;
    int8_t   pad_00[12];
    int32_t  zeni;
    int8_t   pad_01[199420];
    char     character_name[104]; //May contain other data
    uint16_t level;
    int8_t   pad_02[2];
    int32_t  experience;
    int32_t attribute_points;
    int32_t  v5;
    int8_t   pad_03[4];
    int32_t  v6;
    int32_t  strike_super;
    uint16_t ki_blast_super;
    int8_t   pad_04[2];
    int32_t  v9;
    int8_t   pad_05[11236];
} __attribute__((packed)) game_save_data_t; //TODO: identify the stats


class GameSave
{

public:

    /**
     * Constructor
     */
    GameSave(std::string file) throw(XenoverseException);


    /**
     * Destructor
     */
    ~GameSave(void);


    /**
     * Get game save file
     * Return: file
     */
    const std::string file(void) const throw();


    /**
     * Save game save file
     * Params: output file
     */
    void save(std::string file) const throw(XenoverseException);


    /**
     * Print game save data
     */
    void print(void) const throw();


    /**
     * Set zeni
     * Params: zeni
     */
    void set_zeni(int32_t zeni);


protected:

    /**
     * Copy constructor
     * Params: other
     */
    GameSave(const GameSave &other);


    /**
     * Move constructor
     * Params: other
     */
    GameSave(GameSave &&other);


    /**
     * Copy assignment
     * Params: other
     */
    GameSave &operator=(const GameSave &other);


    /**
     * Move assignment
     * Params: other
     */
    GameSave &operator=(GameSave &&other);


private:

    /** Game save file */
    std::string _file;

    /** Game save file input stream */
    std::fstream in_stream;

    /** Game save data */
    game_save_data_t data;

};

#endif //XENOVERSE_GAMESAVE_H
