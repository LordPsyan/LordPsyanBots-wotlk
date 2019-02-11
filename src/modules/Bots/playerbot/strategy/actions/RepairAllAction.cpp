#include "botpch.h"
#include "../../playerbot.h"
#include "RepairAllAction.h"

#include "../../ServerFacade.h"

using namespace ai;

bool RepairAllAction::Execute(Event event)
{
    list<ObjectGuid> npcs = AI_VALUE(list<ObjectGuid>, "nearest npcs");
    for (list<ObjectGuid>::iterator i = npcs.begin(); i != npcs.end(); i++)
    {
        Creature *unit = bot->GetNPCIfCanInteractWith(*i, UNIT_NPC_FLAG_REPAIR);
        if (!unit)
            continue;

        if (bot->hasUnitState(UNIT_STAT_FEIGN_DEATH))
            bot->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

        sServerFacade.SetFacingTo(bot, unit);
        float discountMod = bot->GetReputationPriceDiscount(unit);
        uint32 totalCost = bot->DurabilityRepairAll(true, discountMod, false);

        ostringstream out;
        out << "Repair: " << chat->formatMoney(totalCost) << " (" << unit->GetName() << ")";
        ai->TellMasterNoFacing(out.str());

        return true;
    }

    ai->TellMaster("Cannot find any npc to repair at");
    return false;
}
