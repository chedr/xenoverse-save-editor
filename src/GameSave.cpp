/**
 * File:        GameSave.c
 * Author:      chedr
 * Description: GameSave definitions
 */

#include "GameSave.h"
#include <iostream>
#include <string.h>

std::map<int32_t, std::string> GameSave::super_attacks = {
        {140, "Acid"},
        {20, "Afterimage Strike"},
        {115, "Afterimage"},
        {310, "All Clear"},
        {352, "Angry Hit"},
        {152, "Arm Crash"},
        {600, "Beam Rifle"},
        {390, "Big Bang Attack"},
        {510, "Big Bang Kamehameha"},
        {400, "Blaster Shell"},
        {533, "Bloody Saucer (CPU)"},
        {511, "Bluff Kamehameha"},
        {541, "Boiling Ball"},
        {150, "Bomber DX"},
        {442, "Boulder Break"},
        {441, "Boulder Toss"},
        {260, "Burning Attack"},
        {265, "Burning Slash"},
        {491, "Burst Attack"},
        {490, "Burst Attack"},
        {493, "Burst Reflection"},
        {492, "Burst Reflection"},
        {80, "Burst Rush"},
        {262, "Change the Future"},
        {50, "Charge"},
        {52, "Consecutive Energy Blast"},
        {107, "Cross Arm Drive"},
        {210, "Crusher Ball"},
        {422, "Dancing Parapara"},
        {532, "Darkness Mixer (CPU)"},
        {302, "Deadly Dance"},
        {240, "Death Beam"},
        {243, "Death Crasher"},
        {241, "Death Psyco Bomb"},
        {242, "Death Slash"},
        {244, "Death Slicer"},
        {101, "Destructo-Disc"},
        {621, "Diabolic Cyclone"},
        {620, "Diabolic Mine"},
        {380, "Die Die Missle Barrage"},
        {120, "Dodon Ray"},
        {271, "Double Buster"},
        {130, "Double Sunday"},
        {500, "Dragon Flash Bullet"},
        {502, "Dragon Thunder"},
        {293, "Drain Charge"},
        {291, "Drain Field"},
        {520, "Dynamite Kick"},
        {341, "Eagle Kick"},
        {670, "Elite Beam"},
        {671, "Elite Shooting"},
        {230, "Emperor's Sign"},
        {301, "Endless Shoot"},
        {540, "Energy Cannon"},
        {591, "Energy Charge"},
        {590, "Energy Shot"},
        {622, "Eternal Charge"},
        {90, "Evil Explosion"},
        {94, "Evil Eyes"},
        {92, "Evil Flight Strike"},
        {60, "Evil Ray Strike"},
        {61, "Evil Rise Strike"},
        {71, "Evil Whirlwind"},
        {354, "Explosive Buu Buu Punch"},
        {116, "Fake Death"},
        {420, "Feint Shot"},
        {220, "Fighting Pose A"},
        {213, "Fighting Pose B"},
        {183, "Fighting Pose C"},
        {190, "Fighting Pose D"},
        {202, "Fighting Pose E"},
        {223, "Fighting Pose F"},
        {214, "Fighting Pose G"},
        {184, "Fighting Pose H"},
        {191, "Fighting Pose I"},
        {203, "Fighting Pose J"},
        {204, "Fighting Pose K"},
        {495, "Fighting Sun"},
        {494, "Fighting Sun"},
        {272, "Final Cannon"},
        {162, "Finish Breaker"},
        {270, "Finsih Buster"},
        {290, "Flash Bomber"},
        {161, "Flash Strike"},
        {281, "Freedom Kick"},
        {481, "Freezing Beam"},
        {480, "Freezing Beam"},
        {592, "Full Power Charge"},
        {381, "Galactic Donuts"},
        {160, "Galick Gun"},
        {151, "Genocide Shell"},
        {401, "Gigantic Omega"},
        {402, "Gigantic Slam"},
        {261, "God Breaker"},
        {410, "God of Destruction's Anger"},
        {411, "God of Destruction's Rampage"},
        {412, "God of Destruction's Wrath"},
        {311, "Gravity Impact"},
        {440, "Great Ape Beam"},
        {182, "Guldo Fighting Pose"},
        {342, "Hawk Charge"},
        {672, "Hero's Pose"},
        {221, "Holstein Shock"},
        {295, "Hyper Drain"},
        {483, "Ice Claw"},
        {482, "Ice Claw"},
        {485, "Ice Field"},
        {484, "Ice Field"},
        {361, "III Bomber"},
        {360, "III Flash"},
        {362, "III Rain"},
        {350, "Innocence Bullet"},
        {351, "Innocence Cannon"},
        {5, "Instant Transmission"},
        {82, "Justice Pose"},
        {340, "Justice Rush"},
        {652, "Kai Kai"},
        {102, "Kaioken"},
        {0, "Kamehameha"},
        {40, "Kamekameha Boost"},
        {53, "Kamekameha"},
        {81, "Ki Blast Cannon"},
        {111, "Ki Blast Thrust"},
        {93, "Light Grenade"},
        {106, "Lullaby Punch"},
        {193, "Mach Kick"},
        {192, "Mach Punch"},
        {370, "Majin Kamehameha"},
        {62, "Masenko"},
        {593, "Maximum Charge"},
        {594, "Meteor Blow"},
        {596, "Meteor Crash"},
        {595, "Meteor Strike"},
        {222, "Milky Cannon"},
        {100, "Orin Combo"},
        {373, "Pearl Flash"},
        {312, "Perfect Shot"},
        {141, "Poison"},
        {300, "Power Blitz"},
        {43, "Power Pole Combo"},
        {42, "Power Pole"},
        {44, "Power Pole"},
        {650, "Prelude to Destruction"},
        {421, "Prepare to be Punished"},
        {522, "Present for You"},
        {391, "Pressure Sign"},
        {372, "Quick Sleep"},
        {534, "Rage Saucer (CPU)"},
        {11, "Rebellion Spear"},
        {200, "Recoome Eraser Gun"},
        {201, "Recoome Kick"},
        {10, "Riot Javelin"},
        {124, "Rise to Action"},
        {521, "Rolling Hercule Punch"},
        {142, "Saibabeam"},
        {131, "Saturday Crash"},
        {211, "Sauzer Blade"},
        {41, "Scissors, Paper, Rock"},
        {531, "Seasoning Arrow"},
        {163, "Shine Shot"},
        {132, "Shining Friday"},
        {264, "Shining Slash"},
        {280, "Side Bridge"},
        {164, "Sledgehammer"},
        {282, "Smile Charge"},
        {123, "Solar Flare"},
        {4, "Spirit Bomb (Time Patroller)"},
        {6, "Spirit Bomb Tower (Time Patroller)"},
        {125, "Spirit Boost"},
        {392, "Split Finger Shot"},
        {51, "Stone Bullet"},
        {651, "Strike of Revelation"},
        {3, "Super Dragon Fist"},
        {70, "Super Dragon Flight"},
        {294, "Super Drain"},
        {382, "Super Ghost Kamikaze Attack"},
        {2, "Super God Fist"},
        {14, "Super Guard"},
        {330, "Taunt"},
        {292, "Thunder Eraser"},
        {180, "Time Control"},
        {530, "Time Shackles"},
        {121, "Tri-Beam"},
        {542, "Tricky Strike"},
        {105, "Turtle Style Last Resort"},
        {12, "Tyrant Lancer"},
        {371, "Vanishing Ball"},
        {122, "Volleyball Fist"},
        {91, "Wall of Defense"},
        {501, "Whirlwhind Blade"},
        {110, "Wolf Fang Fist"},
        {21, "x10 Kamekameha"},
        {104, "X20 Kaioken"},
        {103, "X3 Kaioken"},
        {353, "ZigZag Express"},
        {623, "Unknown (ID 623)"},
        {630, "Unknown (ID 630)"},
        {631, "Unknown (ID 631)"},
        {632, "Unknown (ID 632)"},
        {633, "Unknown (ID 633)"},
        {673, "Unknown (ID 673)"},
        {674, "Unknown (ID 674)"},
        {675, "Unknown (ID 675)"},
        {800, "Unknown (ID 800)"},
        {801, "Unknown (ID 801)"},
        {810, "Unknown (ID 810)"},
        {811, "Unknown (ID 811)"},
        {820, "Unknown (ID 820)"},
        {821, "Unknown (ID 821)"}
};


std::map<int32_t, std::string> GameSave::ultimate_attacks = {
        {5360, "Assault Rain"},
        {5531, "Baked Sphere"},
        {5190, "Blue Hurricane"},
        {5220, "Body Change"},
        {5540, "Boiling Burg"},
        {5150, "Break Cannon"},
        {5490, "Burning Spin"},
        {5491, "Burning Spin"},
        {5100, "Chain Destructo-disc Barrage"},
        {5351, "Cookie Beam"},
        {5210, "Crusher Volcano"},
        {5240, "Death Ball"},
        {5241, "Death Meteor"},
        {5301, "Dual Destructo-Disc"},
        {5670, "Elite Combo"},
        {5532, "Energy Jet"},
        {5060, "Explosive Assault"},
        {5070, "Father-Son Kamehameha"},
        {5161, "Final Flash"},
        {5170, "Final Shine Attack"},
        {5050, "Full Power Energy Blast Volley"},
        {5151, "Giant Storm"},
        {5400, "Gigantic Meteor"},
        {5260, "Heat Dome Attack"},
        {5620, "Hell's Circle"},
        {5091, "Hellzone Grenade"},
        {5480, "Ice Cannon"},
        {5481, "Ice Cannon"},
        {5350, "Innocence Breath"},
        {5340, "Justice Combination"},
        {5420, "Maiden Blast"},
        {5500, "Minus Energy Power Ball"},
        {5120, "Neo Tri-Beam"},
        {5180, "Paralysis"},
        {5310, "Perfect Kamehameha"},
        {5080, "Potential Unleashed (CPU)"},
        {5010, "Saiyan Spirit"},
        {5101, "Scatter Kamehameha"},
        {5140, "Self-Destruct"},
        {5290, "Shocking Death Ball"},
        {5090, "Special Beam Cannon"},
        {5410, "Sphere of Destruction"},
        {5110, "Spirit Ball"},
        {5390, "Spirit Sword"},
        {5280, "Super Electric Strike"},
        {5380, "Super Ghost Kamikaze Attack"},
        {5440, "Super Great Ape Beam"},
        {5000, "Super Kamehameha"},
        {5002, "Super Saiyan 2"},
        {5003, "Super Saiyan 3 (CPU)"},
        {5001, "Super Saiyan"},
        {5040, "Super Spirit Bomb"},
        {5370, "Super Vanishing Ball"},
        {5162, "Super Vegeta 2"},
        {5160, "Super Vegeta"},
        {5230, "Supernova"},
        {5650, "Symphonic Destruction"},
        {5371, "Teleporting Vanishing Ball"},
        {5520, "The Saviour Has Come"},
        {5200, "Ultra Fighting Bomber"},
        {5061, "Unrelenting Barrage"},
        {5131, "Vacation Delete"},
        {5270, "Victory Rush"},
        {5534, "Villainous Mode (Super Saiyan 2)"},
        {5533, "Villainous Mode (Super Saiyan)"},
        {5530, "Villainous Mode"},
        {5130, "Weekend"},
        {5510, "X 100 Big Bang Kamehameha"},
        {5630, "Unknown (ID 5630)"},
        {5631, "Unknown (ID 5631)"},
        {5671, "Unknown (ID 5671)"},
        {5800, "Unknown (ID 5800)"},
        {5810, "Unknown (ID 5810)"},
        {5820, "Unknown (ID 5820)"},
        {5821, "Unknown (ID 5821)"}
};


std::map<int32_t, std::string> GameSave::evasive_moves = {
        {10480, "Absolute Zero"},
        {10370, "Angry Shout"},
        {10260, "Armored Boost"},
        {10400, "Blaster Meteor"},
        {10130, "Break Strike"},
        {10351, "Buu Buu Ball"},
        {10350, "Candy Beam"},
        {10360, "Dimension Cannon"},
        {10490, "Dragon Burn"},
        {10670, "Elite Barrage"},
        {10310, "Energy Barrier"},
        {10540, "Energy Boil"},
        {10280, "Energy Field"},
        {10160, "Explosive Wave"},
        {10200, "Final Pose"},
        {10390, "Force Shield"},
        {10410, "Headshot"},
        {10050, "High Tenstion Turn"},
        {10440, "Howl"},
        {10331, "Instant Rise"},
        {10190, "Mach Dash"},
        {10420, "Maiden Burst"},
        {10181, "Miracle Kneel"},
        {10240, "Psychic Move"},
        {10180, "Psycho Escape"},
        {10300, "Rolling Bullet"},
        {10210, "Spinning Blades"},
        {10000, "Spirit Explosion"},
        {10060, "Spirit Slash"},
        {10101, "Spread Shot Retreat"},
        {10340, "Super Back Jump"},
        {10090, "Super Explosive Wave"},
        {10341, "Super Front Jump"},
        {10001, "Turn Retreat"},
        {10510, "Vanisher Guard"},
        {10380, "Victory Cannon"},
        {10650, "Warp"},
        {10630, "Unknown (ID 10630)"}
};


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
    std::cout << "Zeni:              " <<  this->data.zeni << std::endl
    << std::endl;
    for (int i = 0; i < N_CHARACTERS; ++i) {
        std::cout <<
        "Name:              " <<  this->data.characters[i].character_name
        << std::endl <<
        "Level:             " <<  this->data.characters[i].level
        << std::endl <<
        "Experience         " <<  this->data.characters[i].experience
        << std::endl <<
        "Attribute Pts:     " <<  this->data.characters[i].attribute_points
        << std::endl <<
        "Max Health:        " <<  this->data.characters[i].max_health
        << std::endl <<
        "Basic Attack:      " <<  this->data.characters[i].basic_attack
        << std::endl <<
        "Strike Super:      " <<  this->data.characters[i].strike_super
        << std::endl <<
        "Ki Blast Super:    " <<  this->data.characters[i].ki_blast_super
        << std::endl <<
        "Max Stamina:       " <<  this->data.characters[i].max_stamina
        << std::endl <<
        "Max Ki:            " <<  this->data.characters[i].max_ki
        << std::endl <<
        "Super Attack 1:    " <<  GameSave::super_attacks[this->data.characters[i].super_attack_1]
        << std::endl <<
        "Super Attack 2:    " <<  GameSave::super_attacks[this->data.characters[i].super_attack_2]
        << std::endl <<
        "Super Attack 3:    " <<  GameSave::super_attacks[this->data.characters[i].super_attack_3]
        << std::endl <<
        "Super Attack 4:    " <<  GameSave::super_attacks[this->data.characters[i].super_attack_4]
        << std::endl <<
        "Ultimate Attack 1: " <<  GameSave::ultimate_attacks[this->data.characters[i].ultimate_attack_1]
        << std::endl <<
        "Ultimate Attack 2: " <<  GameSave::ultimate_attacks[this->data.characters[i].ultimate_attack_2]
        << std::endl <<
        "Evasive Move:      " <<  GameSave::evasive_moves[this->data.characters[i].evasive_move]
        << std::endl << std::endl;
    }
}


void GameSave::set_zeni(int32_t zeni)
{
    this->data.zeni = zeni;
}


void GameSave::clone_character(size_t to, size_t from)
{
    memcpy(&this->data.characters[to],
           &this->data.characters[from],
           sizeof(character_data_t));
}


void GameSave::rename_character(size_t n, std::string name)
{
    snprintf((char *) &(this->data.characters[n].character_name),
             CHARACTER_NAME_LENGTH - 1, "%s", name.c_str());
}


void GameSave::set_character_level(size_t n, uint32_t level)
{
        this->data.characters[n].level = level;
}


void GameSave::set_character_experience(size_t n, uint32_t experience)
{
        this->data.characters[n].experience = experience;
}


void GameSave::set_character_attribute_points(size_t n, uint32_t points)
{
        this->data.characters[n].attribute_points = points;
}


void GameSave::set_character_max_health(size_t n, uint32_t points)
{
        this->data.characters[n].max_health = points;
}


void GameSave::set_character_basic_attack(size_t n, uint32_t points)
{
        this->data.characters[n].basic_attack = points;
}


void GameSave::set_character_strike_super(size_t n, uint32_t points)
{
        this->data.characters[n].strike_super = points;
}


void GameSave::set_character_ki_blast_super(size_t n, uint32_t points)
{
        this->data.characters[n].ki_blast_super = points;
}


void GameSave::set_character_max_stamina(size_t n, uint32_t points)
{
        this->data.characters[n].max_stamina = points;
}


void GameSave::set_character_max_ki(size_t n, uint32_t points)
{
        this->data.characters[n].max_ki = points;
}


void GameSave::set_character_super_attack_1(size_t n, std::string name)
{
        int32_t id = this->data.characters[n].super_attack_1;
        std::map<int32_t, std::string>::iterator it;
        for (it = GameSave::super_attacks.begin();
             it != GameSave::super_attacks.end(); ++it) {
                if (it->second == name) {
                        id = it->first;
                        break;
                }
        }
        this->data.characters[n].super_attack_1 = id;
}


void GameSave::set_character_super_attack_2(size_t n, std::string name)
{
        int32_t id = this->data.characters[n].super_attack_2;
        std::map<int32_t, std::string>::iterator it;
        for (it = GameSave::super_attacks.begin();
             it != GameSave::super_attacks.end(); ++it) {
                if (it->second == name) {
                        id = it->first;
                        break;
                }
        }
        this->data.characters[n].super_attack_2 = id;
}


void GameSave::set_character_super_attack_3(size_t n, std::string name)
{
        int32_t id = this->data.characters[n].super_attack_3;
        std::map<int32_t, std::string>::iterator it;
        for (it = GameSave::super_attacks.begin();
             it != GameSave::super_attacks.end(); ++it) {
                if (it->second == name) {
                        id = it->first;
                        break;
                }
        }
        this->data.characters[n].super_attack_3 = id;
}


void GameSave::set_character_super_attack_4(size_t n, std::string name)
{
        int32_t id = this->data.characters[n].super_attack_4;
        std::map<int32_t, std::string>::iterator it;
        for (it = GameSave::super_attacks.begin();
             it != GameSave::super_attacks.end(); ++it) {
                if (it->second == name) {
                        id = it->first;
                        break;
                }
        }
        this->data.characters[n].super_attack_4 = id;
}


void GameSave::set_character_ultimate_attack_1(size_t n, std::string name)
{
        int32_t id = this->data.characters[n].ultimate_attack_1;
        std::map<int32_t, std::string>::iterator it;
        for (it = GameSave::ultimate_attacks.begin();
             it != GameSave::ultimate_attacks.end(); ++it) {
                if (it->second == name) {
                        id = it->first;
                        break;
                }
        }
        this->data.characters[n].ultimate_attack_1 = id;
}


void GameSave::set_character_ultimate_attack_2(size_t n, std::string name)
{
        int32_t id = this->data.characters[n].ultimate_attack_2;
        std::map<int32_t, std::string>::iterator it;
        for (it = GameSave::ultimate_attacks.begin();
             it != GameSave::ultimate_attacks.end(); ++it) {
                if (it->second == name) {
                        id = it->first;
                        break;
                }
        }
        this->data.characters[n].ultimate_attack_2 = id;
}


void GameSave::set_character_evasive_move(size_t n, std::string name)
{
        int32_t id = this->data.characters[n].evasive_move;
        std::map<int32_t, std::string>::iterator it;
        for (it = GameSave::evasive_moves.begin();
             it != GameSave::evasive_moves.end(); ++it) {
                if (it->second == name) {
                        id = it->first;
                        break;
                }
        }
        this->data.characters[n].evasive_move = id;
}
