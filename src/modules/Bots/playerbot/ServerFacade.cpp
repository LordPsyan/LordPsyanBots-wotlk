#include "../botpch.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "ServerFacade.h"

#include "../../modules/Bots/ahbot/AhBot.h"
#include "DatabaseEnv.h"
#include "PlayerbotAI.h"

#include "../../modules/Bots/ahbot/AhBotConfig.h"

ServerFacade::ServerFacade() {}
ServerFacade::~ServerFacade() {}

float ServerFacade::GetDistance2d(Unit *unit, WorldObject* wo)
{
    float dist =
    sqrt(unit->GetDistance2d(wo->GetPositionX(), wo->GetPositionY(), DIST_CALC_NONE));
    return round(dist * 10.0f) / 10.0f;
}

float ServerFacade::GetDistance2d(Unit *unit, float x, float y)
{
    float dist =
    sqrt(unit->GetDistance2d(x, y, DIST_CALC_NONE));
    return round(dist * 10.0f) / 10.0f;
}

bool ServerFacade::IsDistanceLessThan(float dist1, float dist2)
{
    return dist1 - dist2 < sPlayerbotAIConfig.targetPosRecalcDistance;
}

bool ServerFacade::IsDistanceGreaterThan(float dist1, float dist2)
{
    return dist1 - dist2 > sPlayerbotAIConfig.targetPosRecalcDistance;
}

bool ServerFacade::IsDistanceGreaterOrEqualThan(float dist1, float dist2)
{
    return !IsDistanceLessThan(dist1, dist2);
}

bool ServerFacade::IsDistanceLessOrEqualThan(float dist1, float dist2)
{
    return !IsDistanceGreaterThan(dist1, dist2);
}

void ServerFacade::SetFacingTo(Player* bot, WorldObject* wo, bool force)
{
    float angle = bot->GetAngle(wo);
    MotionMaster &mm = *bot->GetMotionMaster();
    if (force) mm.Clear();
    if (!force && isMoving(bot)) bot->SetFacingTo(bot->GetAngle(wo));
    else
    {
        bot->SetOrientation(angle);
        bot->SendHeartBeat();
    }
}

bool ServerFacade::IsFriendlyTo(Unit* bot, Unit* to)
{
    return bot->IsFriend(to);
}

bool ServerFacade::IsHostileTo(Unit* bot, Unit* to)
{
    return bot->IsEnemy(to);
}


bool ServerFacade::IsSpellReady(Player* bot, uint32 spell)
{
    return bot->IsSpellReady(spell);
}