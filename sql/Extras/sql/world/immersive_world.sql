-- backup
drop table if exists creature_template_backup;
create table creature_template_backup 
SELECT * FROM creature_template where TrainerTemplateId <> 0 and TrainerClass <> 0 and GossipMenuId = 0;

-- cleanup
DELETE FROM `gossip_menu` where entry > 60000;
DELETE FROM `gossip_menu_option` where menu_id in (60000, 60001, 60002, 60003, 60004);
DELETE FROM `gossip_menu_option` where option_text = 'Manage attributes';

-- root menu
INSERT INTO `gossip_menu` (`entry`, `text_id`, `script_id`, `condition_id`)
VALUES (60001, 1, 0, 0);

INSERT INTO `gossip_menu` (`entry`, `text_id`, `script_id`, `condition_id`)
VALUES (60002, 1, 0, 0);

INSERT INTO `gossip_menu` (`entry`, `text_id`, `script_id`, `condition_id`)
VALUES (60003, 1, 0, 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60001, 0, 7, 'Help', 18, 16, 0, 0, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60001, 1, 3, '+1 Strength', 18, 16, 0, 1, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60001, 2, 3, '+1 Agility', 18, 16, 0, 2, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60001, 3, 3, '+1 Stamina', 18, 16, 0, 3, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60001, 4, 3, '+1 Intellect', 18, 16, 0, 4, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60001, 5, 3, '+1 Spirit', 18, 16, 0, 5, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60001, 7, 4, 'Unlearn all attributes', 1, 16, 60002, 0, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60002, 6, 4, 'I am sure I do want to unlearn all attributes', 18, 16, 0, 6, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60001, 8, 4, 'Temporary reduce attributes', 1, 16, 60003, 0, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60003, 11, 3, 'Disable', 18, 16, 0, 11, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60003, 12, 3, 'Reduce by 90%', 18, 16, 0, 12, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60003, 14, 3, 'Reduce by 70%', 18, 16, 0, 14, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60003, 16, 3, 'Reduce by 50%', 18, 16, 0, 16, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60003, 18, 3, 'Reduce by 30%', 18, 16, 0, 18, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60003, 19, 3, 'Reduce by 20%', 18, 16, 0, 19, 0, 0, 0, '', 0);

INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`,
`box_money`, `box_text`, `condition_id`) VALUES (60003, 20, 3, 'Reduce by 10%', 18, 16, 0, 20, 0, 0, 0, '', 0);

-- add to trainers
INSERT INTO `gossip_menu_option`
(`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`, `box_money`, `box_text`, `condition_id`) 
SELECT menu_id, 61, 3, 'Manage attributes', 1, 16, 60001, 0, 0, 0, 0, '', 0 FROM `gossip_menu_option` where `action_menu_id` = 4461;

-- add missing gossips to trainers
update creature_template set GossipMenuId = 4537 where entry in (select entry from one_world.creature_template_backup);
