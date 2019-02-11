#ifndef _ServerFacade_H
#define _ServerFacade_H

#include "Common.h"
#include "PlayerbotAIBase.h"
#include "PlayerbotAIConfig.h"

using namespace std;

class ServerFacade
{
    public:
        ServerFacade();
        virtual ~ServerFacade();
        static ServerFacade& instance()
        {
            static ServerFacade instance;
            return instance;
        }

	public:
        bool UnitIsDead(Unit *unit)
        {
            return unit->isDead();
        }

        float GetDistance2d(Unit *unit, WorldObject* wo);

        float GetDistance2d(Unit *unit, float x, float y);

        DeathState GetDeathState(Unit *unit)
        {
            return unit->getDeathState();
        }

        bool isSpawned(GameObject *go)
        {
            return go->IsSpawned();
        }

        bool IsAlive(Unit *unit)
        {
            return unit->isAlive();
        }

        bool isMoving(Unit *unit)
        {
            return unit->IsMoving();
        }

        bool IsInCombat(Unit *unit)
        {
            return unit->isInCombat();
        }

        bool IsFrozen(Unit *unit)
        {
            return unit->isFrozen();
        }

        bool IsInRoots(Unit *unit)
        {
            return unit->isInRoots();
        }

        bool IsCharmed(Unit *unit)
        {
            return unit->HasCharmer();
        }

        bool IsFeared(Unit *unit)
        {
            return unit->isFeared();
        }

        bool IsInFront(Unit *unit, WorldObject const* target, float distance,  float arc /*= M_PI_F*/)
        {
            return unit->isInFront(target, distance, arc);
        }

        HostileRefManager& GetHostileRefManager(Unit *unit)
        {
            return unit->getHostileRefManager();
        }

        ThreatManager& GetThreatManager(Unit *unit)
        {
            return unit->getThreatManager();
        }

        void SendPacket(Player *player, WorldPacket &packet)
        {
            return player->GetSession()->SendPacket(packet);
        }

        void SendMessageToSet(Player *player, WorldPacket &packet, bool self)
        {
            return player->SendMessageToSet(packet, self);
        }

        SpellEntry const* LookupSpellInfo(uint32 spellId)
        {
            return sSpellTemplate.LookupEntry<SpellEntry>(spellId);
        }

        uint32 GetSpellInfoRows()
        {
            return sSpellTemplate.GetMaxEntry();
        }

        bool IsWithinLOSInMap(Player* bot, WorldObject *wo)
        {
            float x = wo->GetPositionX(), y = wo->GetPositionY(), z = wo->GetPositionZ();
            return //bot->GetMapId() == wo->GetMapId() &&
                (
                    bot->IsWithinLOS(x, y, z + 0.5f, true) ||
                    GetDistance2d(bot, wo) <= sPlayerbotAIConfig.tooCloseDistance
                );
        }

        bool IsDistanceLessThan(float dist1, float dist2);
        bool IsDistanceGreaterThan(float dist1, float dist2);
        bool IsDistanceGreaterOrEqualThan(float dist1, float dist2);
        bool IsDistanceLessOrEqualThan(float dist1, float dist2);

        void SetFacingTo(Player* bot, WorldObject* wo, bool force = false);

        bool IsFriendlyTo(Unit* bot, Unit* to);
        bool IsHostileTo(Unit* bot, Unit* to);

        bool IsSpellReady(Player* bot, uint32 spell);
};

#define sServerFacade ServerFacade::instance()

#endif
