ALTER TABLE db_version CHANGE COLUMN required_13962_01_mangos_game_event_group required_13964_01_mangos_comments bit;

ALTER TABLE conditions MODIFY comments VARCHAR(500) DEFAULT '';

ALTER TABLE dbscript_random_templates ADD comments VARCHAR(500) DEFAULT '' AFTER chance;

ALTER TABLE pickpocketing_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;
ALTER TABLE mail_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;

ALTER TABLE creature_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;
ALTER TABLE gameobject_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;
ALTER TABLE reference_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;

ALTER TABLE disenchant_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;
ALTER TABLE fishing_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;
ALTER TABLE item_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;
ALTER TABLE prospecting_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;
ALTER TABLE skinning_loot_template ADD comments VARCHAR(300) DEFAULT '' AFTER condition_id;


