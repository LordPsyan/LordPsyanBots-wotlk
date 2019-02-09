#pragma once
#include "GossipDef.h"

using namespace std;

namespace immersive
{
    enum ImmersiveEffectiveChance
    {
        IMMERSIVE_EFFECTIVE_CHANCE_MISS,
        IMMERSIVE_EFFECTIVE_CHANCE_DODGE,
        IMMERSIVE_EFFECTIVE_CHANCE_PARRY,
        IMMERSIVE_EFFECTIVE_CHANCE_BLOCK,
        IMMERSIVE_EFFECTIVE_CHANCE_CRIT,
        IMMERSIVE_EFFECTIVE_CHANCE_SPELL_MISS,
        IMMERSIVE_EFFECTIVE_ATTACK_DISTANCE
    };

    class ImmersiveAction
    {
    public:
        ImmersiveAction() {}

    public:
        virtual bool Run(Player* player, Player* bot) = 0;
        virtual string GetMessage() = 0;
    };

    class Immersive
    {
    public:
        Immersive();

    public:
        void GetPlayerLevelInfo(Player *player, PlayerLevelInfo* info);
        void OnGossipSelect(Player *player, uint32 gossipListId, GossipMenuItemData *menuData);
        float GetFallDamage(float zdist);
        void OnDeath(Player *player);
        void OnGiveXP(Player *player, uint32 xp, Unit* victim);
        void OnReputationChange(Player* player, FactionEntry const* factionEntry, int32& standing, bool incremental);
        void OnRewardQuest(Player* player, Quest const* quest);
        bool OnFishing(Player* player, bool success);
        int32 CalculateEffectiveChance(int32 difference, const Unit* attacker, const Unit* victim, ImmersiveEffectiveChance type);
        uint32 GetModifierValue(uint32 owner);
        uint32 GetStatsValue(uint32 owner, Stats type);
        void SetStatsValue(uint32 owner, Stats type, uint32 value);
        uint32 GetTotalStats(Player *player);

    private:
        void PrintHelp(Player *player, bool detailed = false);
        void IncreaseStat(Player *player, uint32 type);
        void ChangeModifier(Player *player, uint32 type);
        void ResetStats(Player *player);
        void SendMessage(Player *player, string message);
        uint32 CalculateEffectiveChanceDelta(const Unit* unit);

    private:
        uint32 GetUsedStats(Player *player);
        uint32 GetStatCost(Player *player);

    private:
        void RunAction(Player* player, ImmersiveAction* action);

    private:
        uint32 GetValue(uint32 owner, string type);
        void SetValue(uint32 owner, string type, uint32 value);

    private:
        static map<Stats, string> statValues;
        static map<Stats, string> statNames;
        map<uint32, map<string, uint32> > valueCache;
    };
}


#define sImmersive MaNGOS::Singleton<immersive::Immersive>::Instance()
