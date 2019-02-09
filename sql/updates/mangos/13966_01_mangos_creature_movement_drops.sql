ALTER TABLE db_version CHANGE COLUMN required_13965_01_mangos_questgiver_greeting required_13966_01_mangos_creature_movement_drops bit;

ALTER TABLE creature_movement DROP COLUMN textId1;
ALTER TABLE creature_movement DROP COLUMN textId2;
ALTER TABLE creature_movement DROP COLUMN textId3;
ALTER TABLE creature_movement DROP COLUMN textId4;
ALTER TABLE creature_movement DROP COLUMN textId5;
ALTER TABLE creature_movement DROP COLUMN emote;
ALTER TABLE creature_movement DROP COLUMN spell;
ALTER TABLE creature_movement DROP COLUMN model1;
ALTER TABLE creature_movement DROP COLUMN model2;

ALTER TABLE creature_movement_template DROP COLUMN textId1;
ALTER TABLE creature_movement_template DROP COLUMN textId2;
ALTER TABLE creature_movement_template DROP COLUMN textId3;
ALTER TABLE creature_movement_template DROP COLUMN textId4;
ALTER TABLE creature_movement_template DROP COLUMN textId5;
ALTER TABLE creature_movement_template DROP COLUMN emote;
ALTER TABLE creature_movement_template DROP COLUMN spell;
ALTER TABLE creature_movement_template DROP COLUMN model1;
ALTER TABLE creature_movement_template DROP COLUMN model2;


