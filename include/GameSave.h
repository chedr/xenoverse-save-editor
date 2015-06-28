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
#include <map>
#include <endian.h>

#define GAME_SAVE_MAGIC       (be32toh(0x23534156))
#define ZENI_MAX_VALUE        999999999
#define N_CHARACTERS          8
#define CHARACTER_NAME_LENGTH 16

/** On-disk game save character sub-section */
typedef struct character_data
{
    char     character_name[CHARACTER_NAME_LENGTH]; /* 0x30B10 */
    int8_t   pad_00[88];
    int32_t  level;              /* 0x30B78 */
    int32_t  experience;         /* 0x30B7C */
    int32_t  attribute_points;   /* 0x30B80 */
    int32_t  max_health;         /* 0x30B84 */
    int32_t  max_ki;             /* 0x30B88 */
    int32_t  basic_attack;       /* 0x30B8C */
    int32_t  strike_super;       /* 0x30B90 */
    int32_t  ki_blast_super;     /* 0x30B94 */
    int32_t  max_stamina;        /* 0x30B98 */
    int8_t   pad_01[56];
    int32_t  super_attack_2;     /* 0x30BD4 */
    int32_t  super_attack_1;     /* 0x30BD8 */
    int32_t  super_attack_3;     /* 0x30BDC */
    int32_t  super_attack_4;     /* 0x30BE0 */
    int32_t  ultimate_attack_2;  /* 0x30BE4 */
    int32_t  ultimate_attack_1;  /* 0x30BE8 */
    int32_t  evasive_move;       /* 0x30BEC */
    int8_t   pad_02[656];
} __attribute__((packed)) character_data_t; /* sizeof() = 0x370 */


/** Game save on-disk structure */
typedef struct game_save_data
{
    uint32_t         magic;
    int8_t           pad_00[12];
    int32_t          zeni;
    int8_t           pad_01[199420];
    character_data_t characters[N_CHARACTERS];
    int8_t           pad_02[4336];
} __attribute__((packed)) game_save_data_t; /* sizeof() = 0x33780 */


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


    /**
     * Clone character from slot to another slot
     * Params: to slot
     *         from slot
     */
    void clone_character(size_t to, size_t from);


    /**
     * Rename character
     * Params: n
     *         name
     */
    void rename_character(size_t n, std::string name);


    /**
     * Set character level
     * Params: n
     *         level
     */
    void set_character_level(size_t n, uint32_t level);


    /**
     * Set character exp
     * Params: n
     *         experience
     */
    void set_character_experience(size_t n, uint32_t experience);


    /**
     * Set character attribute points
     * Params: n
     *         points
     */
    void set_character_attribute_points(size_t n, uint32_t points);


    /**
     * Set character health points
     * Params: n
     *         points
     */
    void set_character_max_health(size_t n, uint32_t points);


    /**
     * Set character basic attack points
     * Params: n
     *         points
     */
    void set_character_basic_attack(size_t n, uint32_t points);


    /**
     * Set character strike super points
     * Params: n
     *         points
     */
    void set_character_strike_super(size_t n, uint32_t points);


    /**
     * Set character ki blast super points
     * Params: n
     *         points
     */
    void set_character_ki_blast_super(size_t n, uint32_t points);


    /**
     * Set character max stamina points
     * Params: n
     *         points
     */
    void set_character_max_stamina(size_t n, uint32_t points);


    /**
     * Set character max stamina points
     * Params: n
     *         points
     */
    void set_character_max_ki(size_t n, uint32_t points);


    /**
     * Set character super attack
     * Params: n
     *         name
     */
    void set_character_super_attack_1(size_t n, std::string name);
    void set_character_super_attack_2(size_t n, std::string name);
    void set_character_super_attack_3(size_t n, std::string name);
    void set_character_super_attack_4(size_t n, std::string name);


    /**
     * Set character ultimate attack
     * Params: n
     *         name
     */
    void set_character_ultimate_attack_1(size_t n, std::string name);
    void set_character_ultimate_attack_2(size_t n, std::string name);


    /**
     * Set character ultimate attack
     * Params: n
     *         name
     */
    void set_character_evasive_move(size_t n, std::string name);

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

    /** Super attack id -> name map */
    static std::map<int32_t, std::string> super_attacks;

    /** Ultimate attack id -> name map */
    static std::map<int32_t, std::string> ultimate_attacks;

    /** Evasive move id -> name map */
    static std::map<int32_t, std::string> evasive_moves;
};

#endif //XENOVERSE_GAMESAVE_H
