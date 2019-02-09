/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_SPELLTARGETDEFINES_H
#define MANGOS_SPELLTARGETDEFINES_H

enum SpellTarget
{
    TARGET_NONE                                        = 0,
    TARGET_UNIT_CASTER                                 = 1,
    TARGET_UNIT_ENEMY_NEAR_CASTER                      = 2,
    TARGET_UNIT_FRIEND_NEAR_CASTER                     = 3,
    TARGET_UNIT_NEAR_CASTER                            = 4,
    TARGET_UNIT_CASTER_PET                             = 5,
    TARGET_UNIT_ENEMY                                  = 6,
    TARGET_ENUM_UNITS_SCRIPT_AOE_AT_SRC_LOC            = 7,
    TARGET_ENUM_UNITS_SCRIPT_AOE_AT_DEST_LOC           = 8,
    TARGET_LOCATION_CASTER_HOME_BIND                   = 9,
    TARGET_LOCATION_CASTER_DIVINE_BIND_NYI             = 10,
    TARGET_PLAYER_NYI                                  = 11,
    TARGET_PLAYER_NEAR_CASTER_NYI                      = 12,
    TARGET_PLAYER_ENEMY_NYI                            = 13,
    TARGET_PLAYER_FRIEND_NYI                           = 14,
    TARGET_ENUM_UNITS_ENEMY_AOE_AT_SRC_LOC             = 15,
    TARGET_ENUM_UNITS_ENEMY_AOE_AT_DEST_LOC            = 16,
    TARGET_LOCATION_DATABASE                           = 17,
    TARGET_LOCATION_CASTER_DEST                        = 18,
    TARGET_UNK_19                                      = 19,
    TARGET_ENUM_UNITS_PARTY_WITHIN_CASTER_RANGE        = 20,
    TARGET_UNIT_FRIEND                                 = 21,
    TARGET_LOCATION_CASTER_SRC                         = 22,
    TARGET_GAMEOBJECT                                  = 23,
    TARGET_ENUM_UNITS_ENEMY_IN_CONE_24                 = 24,
    TARGET_UNIT                                        = 25,
    TARGET_LOCKED                                      = 26,
    TARGET_UNIT_CASTER_MASTER                          = 27,
    TARGET_ENUM_UNITS_ENEMY_AOE_AT_DYNOBJ_LOC          = 28,
    TARGET_ENUM_UNITS_FRIEND_AOE_AT_DYNOBJ_LOC         = 29,
    TARGET_ENUM_UNITS_FRIEND_AOE_AT_SRC_LOC            = 30,
    TARGET_ENUM_UNITS_FRIEND_AOE_AT_DEST_LOC           = 31,
    TARGET_LOCATION_UNIT_MINION_POSITION               = 32,
    TARGET_ENUM_UNITS_PARTY_AOE_AT_SRC_LOC             = 33,
    TARGET_ENUM_UNITS_PARTY_AOE_AT_DEST_LOC            = 34,
    TARGET_UNIT_PARTY                                  = 35,
    TARGET_ENUM_UNITS_ENEMY_WITHIN_CASTER_RANGE        = 36,
    TARGET_UNIT_FRIEND_AND_PARTY                       = 37,
    TARGET_UNIT_SCRIPT_NEAR_CASTER                     = 38,
    TARGET_LOCATION_CASTER_FISHING_SPOT                = 39,
    TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER               = 40,
    TARGET_LOCATION_CASTER_FRONT_RIGHT                 = 41,
    TARGET_LOCATION_CASTER_BACK_RIGHT                  = 42,
    TARGET_LOCATION_CASTER_BACK_LEFT                   = 43,
    TARGET_LOCATION_CASTER_FRONT_LEFT                  = 44,
    TARGET_UNIT_FRIEND_CHAIN_HEAL                      = 45,
    TARGET_LOCATION_SCRIPT_NEAR_CASTER                 = 46,
    TARGET_LOCATION_CASTER_FRONT                       = 47,
    TARGET_LOCATION_CASTER_BACK                        = 48,
    TARGET_LOCATION_CASTER_LEFT                        = 49,
    TARGET_LOCATION_CASTER_RIGHT                       = 50,
    TARGET_ENUM_GAMEOBJECTS_SCRIPT_AOE_AT_SRC_LOC      = 51,
    TARGET_ENUM_GAMEOBJECTS_SCRIPT_AOE_AT_DEST_LOC     = 52,
    TARGET_LOCATION_CASTER_TARGET_POSITION             = 53,
    TARGET_ENUM_UNITS_ENEMY_IN_CONE_54                 = 54,
    TARGET_LOCATION_CASTER_FRONT_LEAP                  = 55,
    TARGET_ENUM_UNITS_RAID_WITHIN_CASTER_RANGE         = 56,
    TARGET_UNIT_RAID                                   = 57,
    TARGET_UNIT_RAID_NEAR_CASTER                       = 58,
    TARGET_ENUM_UNITS_FRIEND_IN_CONE                   = 59,
    TARGET_ENUM_UNITS_SCRIPT_IN_CONE_60                = 60,
    TARGET_UNIT_RAID_AND_CLASS                         = 61,
    TARGET_PLAYER_RAID_NYI                             = 62,
    TARGET_LOCATION_UNIT_POSITION                      = 63,
    TARGET_LOCATION_UNIT_FRONT                         = 64,
    TARGET_LOCATION_UNIT_BACK                          = 65,
    TARGET_LOCATION_UNIT_RIGHT                         = 66,
    TARGET_LOCATION_UNIT_LEFT                          = 67,
    TARGET_LOCATION_UNIT_FRONT_RIGHT                   = 68,
    TARGET_LOCATION_UNIT_BACK_RIGHT                    = 69,
    TARGET_LOCATION_UNIT_BACK_LEFT                     = 70,
    TARGET_LOCATION_UNIT_FRONT_LEFT                    = 71,
    TARGET_LOCATION_CASTER_RANDOM_SIDE                 = 72,
    TARGET_LOCATION_CASTER_RANDOM_CIRCUMFERENCE        = 73,
    TARGET_LOCATION_UNIT_RANDOM_SIDE                   = 74,
    TARGET_LOCATION_UNIT_RANDOM_CIRCUMFERENCE          = 75,
    TARGET_LOCATION_DYNOBJ_POSITION                    = 76,
    TARGET_UNIT_CHANNEL_TARGET                         = 77,
    TARGET_LOCATION_NORTH                              = 78,
    TARGET_LOCATION_SOUTH                              = 79,
    TARGET_LOCATION_EAST                               = 80,
    TARGET_LOCATION_WEST                               = 81,
    TARGET_LOCATION_NE                                 = 82,
    TARGET_LOCATION_NW                                 = 83,
    TARGET_LOCATION_SE                                 = 84,
    TARGET_LOCATION_SW                                 = 85,
    TARGET_LOCATION_RANDOM_SIDE                        = 86,
    TARGET_LOCATION_CURRENT_REFERENCE                  = 87,
    TARGET_ENUM_UNITS_SCRIPT_AOE_AT_DYNOBJ_LOC         = 88,
    TARGET_LOCATION_TRAJECTORY                         = 89,
    TARGET_UNIT_CASTER_COMPANION                       = 90,
    TARGET_LOCATION_RANDOM_CIRCUMFERENCE               = 91,
    TARGET_UNIT_CASTER_SUMMONER                        = 92,
    TARGET_CORPSE_ENEMY_NEAR_CASTER_NYI                = 93,
    TARGET_UNIT_CASTER_VEHICLE                         = 94,
    TARGET_UNIT_CASTER_DRIVER                          = 95,
    TARGET_UNIT_CASTER_PASSENGER_0                     = 96,
    TARGET_UNIT_CASTER_PASSENGER_1                     = 97,
    TARGET_UNIT_CASTER_PASSENGER_2                     = 98,
    TARGET_UNIT_CASTER_PASSENGER_3                     = 99,
    TARGET_UNIT_CASTER_PASSENGER_4                     = 100,
    TARGET_UNIT_CASTER_PASSENGER_5                     = 101,
    TARGET_UNIT_CASTER_PASSENGER_6                     = 102,
    TARGET_UNIT_CASTER_PASSENGER_7                     = 103,
    TARGET_ENUM_UNITS_ENEMY_IN_CONE_104                = 104,
    TARGET_UNIT_105_NYI                                = 105,
    TARGET_LOCATION_106_NYI                            = 106,
    TARGET_UNK_107                                     = 107,
    TARGET_ENUM_GAMEOBJECTS_IN_CONE                    = 108,
    TARGET_UNK_109                                     = 109,
    TARGET_ENUM_UNITS_SCRIPT_IN_CONE_110               = 110,

    MAX_SPELL_TARGETS
};

enum SpellTargetImplicitType
{
    TARGET_TYPE_UNKNOWN         = 0,
    TARGET_TYPE_LOCATION,
    TARGET_TYPE_GAMEOBJECT,
    TARGET_TYPE_UNIT,
    TARGET_TYPE_PLAYER,
    TARGET_TYPE_CORPSE,
    TARGET_TYPE_LOCK,
};

enum SpellTargetEnumerator
{
    TARGET_ENUMERATOR_UNKNOWN   = 0,
    TARGET_ENUMERATOR_SINGLE,
    TARGET_ENUMERATOR_CHAIN,                                  // Sorted list
    TARGET_ENUMERATOR_AOE,                                    // Unsorted list
    TARGET_ENUMERATOR_CONE,                                   // Unsorted list
};

enum SpellTargetFilter
{
    TARGET_NEUTRAL              = 0,
    TARGET_HARMFUL,
    TARGET_HELPFUL,
    TARGET_PARTY,                                            // Same party (subgroup) only
    TARGET_GROUP,                                            // Same group only
    TARGET_SCRIPT,
};

struct SpellTargetInfo
{
    char const* name;
    SpellTargetImplicitType type;
    SpellTargetFilter filter;
    SpellTargetEnumerator enumerator;

    SpellTargetInfo(char const* name = "", SpellTargetImplicitType type = TARGET_TYPE_UNKNOWN, SpellTargetFilter filter = TARGET_NEUTRAL, SpellTargetEnumerator enumerator = TARGET_ENUMERATOR_UNKNOWN);
};

extern SpellTargetInfo SpellTargetInfoTable[MAX_SPELL_TARGETS];

#endif
