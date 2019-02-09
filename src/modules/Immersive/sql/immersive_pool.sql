-- cleanup
delete from pool_template where description like 'Immersive%';
delete from pool_gameobject where description like 'Immersive%';
drop table if exists immersive_pool;

-- temp index
-- create index idx_pool_template_desc on pool_template(description);

-- prepare chance data
create table immersive_pool 
(
name varchar(255),
divider decimal,
type int,
chance decimal,
max_limit int
);
insert into immersive_pool (name, type, chance) values 
-- 1 = Herbs
('Silverleaf', 1, 0),
('Peacebloom', 1, 0),
('Earthroot', 1, 0),
('Mageroyal', 1, 0),
('Briarthorn', 1, 0),
('Bruiseweed', 1, 0),
('Wild Steelbloom', 1, 0),
('Kingsblood', 1, 0),
('Grave Moss', 1, 0),
('Liferoot', 1, 0),
('Fadeleaf', 1, 0),
('Khadgar''s Whisker', 1, 0),
('Wintersbite', 1, 0),
('Stranglekelp', 1, 0),
('Goldthorn', 1, 0),
('Firebloom', 1, 0),
('Purple Lotus', 1, 0),
('Arthas'' Tears', 1, 0),
('Sungrass', 1, 0),
('Blindweed', 1, 0),
('Ghost Mushroom', 1, 0),
('Gromsblood', 1, 0),
('Golden Sansam', 1, 0),
('Dreamfoil', 1, 0),
('Mountain Silversage', 1, 0),
('Plaguebloom', 1, 0),
('Icecap', 1, 0),
('Black Lotus', 1, 0),
('Bloodthistle', 1, 0),
('Felweed', 1, 0),
('Dreaming Glory', 1, 0),
('Ragveil', 1, 0),
('Flame Cap', 1, 0),
('Terocone', 1, 0),
('Ancient Lichen', 1, 0),
('Netherbloom', 1, 0),
('Nightmare Vine', 1, 0),
('Mana Thistle', 1, 0),
('Netherdust Bush', 1, 0),

-- 2 = Fish
('School of Fish', 2, 0),
('School of Tastyfish', 2, 0),
('Muddy Churning Waters', 2, 0),
('Oily Blackmouth School', 2, 0),
('Floating Debris', 2, 10),
('Sagefish School', 2, 0),
('Firefin Snapper School', 2, 0),
('School of Deviate Fish', 2, 0),
('Oil Spill', 2, 0),
('Floating Wreckage', 2, 10),
('Greater Sagefish School', 2, 0),
('Stonescale Eel Swarm', 2, 0),
('Patch of Elemental Water', 2, 10),
('Pure Water', 2, 10),
('Steam Pump Flotsam', 2, 10),
('Sporefish School', 2, 0),
('Brackish Mixed School', 2, 0),
('School of Darter', 2, 0),
('Highland Mixed School', 2, 0),
('Mudfish School', 2, 0),
('Bluefish School', 2, 0),
('Strange Pool', 2, 10),

-- 3 = Other
('Hidden Strongbox', 3, 0),
('Giant Clam', 3, 0),
('Horde Supply Crate', 3, 0),
('Un''Goro Dirt Pile', 3, 0),
('Blue Power Crystal', 3, 0),
('Green Power Crystal', 3, 0),
('Red Power Crystal', 3, 0),
('Yellow Power Crystal', 3, 0),
('Bloodpetal Sprout', 3, 0),
('Blood of Heroes', 3, 0),
('Shellfish Trap', 3, 0),
('Practice Lockbox', 3, 0),
('Battered Footlocker', 3, 0),
('Waterlogged Footlocker', 3, 0),
('Dented Footlocker', 3, 0),
('Mossy Footlocker', 3, 0),
('Scarlet Footlocker', 3, 0),
('Burial Chest', 3, 0),
('Glowcap', 3, 0),
('Wicker Chest', 3, 0),
('Primitive Chest', 3, 0),
('Solid Fel Iron Chest', 3, 0),
('Bound Fel Iron Chest', 3, 0),
('Bound Adamantite Chest', 3, 0),
('Solid Adamantite Chest', 3, 0),
('Netherwing Egg', 3, 0),
('Cleansed Night Dragon', 3, 0),
('Cleansed Songflower', 3, 0),
('Cleansed Windblossom', 3, 0),
('Cleansed Whipper Root', 3, 0),

-- 4 = Chest
('Battered Chest', 4, 0),
('Tattered Chest', 4, 0),
('Solid Chest', 4, 0),
('Water Barrel', 4, 0),
('Barrel of Melon Juice', 4, 0),
('Armor Crate', 4, 0),
('Weapon Crate', 4, 0),
('Food Crate', 4, 0),
('Barrel of Milk', 4, 0),
('Barrel of Sweet Nectar', 4, 0),
('Alliance Strongbox', 4, 0),
('Box of Assorted Parts', 4, 0),
('Scattered Crate', 4, 0),
('Large Iron Bound Chest', 4, 0),
('Large Solid Chest', 4, 0),
('Large Battered Chest', 4, 0),
('Buccaneer''s Strongbox', 4, 0),
('Large Mithril Bound Chest', 4, 0),
('Large Darkwood Chest', 4, 0),
('Fel Iron Chest', 4, 0),
('Heavy Fel Iron Chest', 4, 0),
('Adamantite Bound Chest', 4, 0),
('Felsteel Chest', 4, 0)
;

update immersive_pool set divider = 150, max_limit = 1 where type = 1;
update immersive_pool set divider = 5, max_limit = 1 where type = 2;
update immersive_pool set divider = 150, max_limit = 1 where type = 3;
update immersive_pool set divider = 200, max_limit = 5 where type = 4;

-- pool_template
INSERT INTO pool_template (entry, max_limit, description)
SELECT 
 @rn := @rn + 1, 
 1,
 ds
FROM 
 (select @rn := max(entry) from pool_template) r,
 (
  select ds, sum(max_limit) from 
  (select concat('Immersive ', map, floor(o.position_x / ip.divider), floor(o.position_y / ip.divider), floor(o.position_z / ip.divider)) ds, ip.max_limit
   from gameobject o
   join gameobject_template t on t.entry = o.id
   left join pool_gameobject pg on pg.guid = o.guid
   join immersive_pool ip on ip.name = t.name
   where t.type in (3, 25, 17) and o.map in(0,1,530) and pg.guid is null
   )a group by ds
 )b;

-- pool_gameobject
INSERT INTO pool_gameobject (guid, pool_entry, chance, description)
SELECT 
 o.guid, 
 (select entry from pool_template where description = concat('Immersive ', map, floor(o.position_x / ip.divider), floor(o.position_y / ip.divider), floor(o.position_z / ip.divider))),
 (select chance from immersive_pool where name = t.name),
 concat('Immersive ', t.name, ' ', o.guid)
FROM 
 gameobject o
join gameobject_template t on t.entry = o.id
left join pool_gameobject pg on pg.guid = o.guid
join immersive_pool ip on ip.name = t.name
where t.type in (3, 25, 17) and o.map in(0,1,530) and pg.guid is null;

-- applying chances
create table immersive_tmp as
select 
(100 - (select sum(chance) from pool_gameobject pg where pg.pool_entry = p.pool_entry)) / (select count(*) - 1 from pool_gameobject pg where pg.pool_entry = p.pool_entry) as chance,
p.guid
from pool_gameobject p
where description like 'Immersive%' and chance = 0 and (select sum(chance) from pool_gameobject pg where pg.pool_entry = p.pool_entry) > 0;
create index idx_immersive_tmp on immersive_tmp(guid);
update pool_gameobject p set p.chance = ifnull((select chance from immersive_tmp where guid = p.guid),0)
where p.description like 'Immersive%' and p.chance = 0;
drop table immersive_tmp;

-- check
SELECT 
 o.guid, o.position_x, o.position_y, o.position_z,
 t.type, t.name,
 pg.chance, pg.description, pg.guid,
 pt.max_limit, pt.description, pt.entry
FROM gameobject o
 join gameobject_template t on t.entry = o.id
 join pool_gameobject pg on pg.guid = o.guid
 join pool_template pt on pt.entry = pg.pool_entry
where t.type in (3, 25, 17) and o.map in(0,1,530) and t.name in ('Floating Debris');

-- fixing chances <> 100
create table immersive_tmp as
select pg.pool_entry, sum(chance) from pool_gameobject pg 
where pg.description like 'Immersive%' 
group by pg.pool_entry having sum(chance) <> 100 and sum(chance) <> 0;
update pool_gameobject p set p.chance = 0 where pool_entry in (select pool_entry from immersive_tmp)
and p.description like 'Immersive%';
drop table immersive_tmp;

-- tmp check
SELECT count(ds)
FROM 
 (select distinct ds from (select concat('Immersive ', map, floor(o.position_x / ip.divider), floor(o.position_y / ip.divider), floor(o.position_z / ip.divider)) ds from
 gameobject o
join gameobject_template t on t.entry = o.id
left join pool_gameobject pg on pg.guid = o.guid
join immersive_pool ip on ip.name = t.name
where t.type in (3, 25, 17) and o.map in(0,1,530) and pg.guid is null)a)b;
