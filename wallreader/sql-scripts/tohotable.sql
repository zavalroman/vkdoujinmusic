/*
CREATE TABLE vkgroup
(
	id INTEGER,
	vk_id VARCHAR(50),
	vkdomain VARCHAR(50),
	name VARCHAR(100),
	
	PRIMARY KEY ( id )	
);
*/

CREATE TABLE vkpost
(
	id INTEGER, --uniq post id within the table
	vk_id VARCHAR(50), --post id within a vk group
	vkgroup_id INTEGER,
	unix_time DECIMAL,
	post_text VARCHAR(1000),
	likes INTEGER,
	reposts INTEGER,
	comments INTEGER,
	
	photo_count SMALLINT,
	audio_count SMALLINT,
	--poll CHAR(1),
	
	--FOREIGN KEY ( vkgroup_id ) REFERENCES vkgroup ( id ),
	PRIMARY KEY ( id )
);

CREATE TABLE vktrack
(
	id INTEGER,
	vk_id VARCHAR(50),
	--from_id VARCHAR(50),
	to_id VARCHAR(50), --owner_id
	artist VARCHAR(100),
	title VARCHAR(100),
	duration INTEGER,
	--unix_time DECIMAL, --iru ka
	--url VARCHAR(100),
	--lyrics_id VARCHAR(50),
	--vkalbum_id INTEGER,
	--vkgenre_id INTEGER,
	vkpost_id INTEGER,

	FOREIGN KEY ( vkpost_id ) REFERENCES  vkpost ( id ),
	PRIMARY KEY ( id )
);

/*
CREATE TABLE translit
(
	id INTEGER,
	romaji VARCHAR(500),
	unicode VARCHAR(1000), --CHAR(x) CHARACTER SET UNICODE_FSS
	eng VARCHAR(500),
	rus VARCHAR(500),
	
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE translate
(
	id INTEGER,
	--romaji VARCHAR(500),
	--unicode VARCHAR(1000), --CHAR(x) CHARACTER SET UNICODE_FSS
	eng VARCHAR(500),
	rus VARCHAR(500),
	
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE link
(
	id INTEGER,
	web VARCHAR(500),
	wiki VARCHAR(500),
	twitter VARCHAR(500),
	facebook VARCHAR(500),
	vk VARCHAR(500),
	youtube VARCHAR(500),
	nico VARCHAR(500),
	pixiv VARCHAR(500),
	email VARCHAR(500),
	address VARCHAR(500),
	tel VARCHAR(100),
	
	link1 VARCHAR(500),
	link2 VARCHAR(500),
	link3 VARCHAR(500),
	link4 VARCHAR(500),
	
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE eventtype
(
	id INTEGER,
	title VARCHAR(100),
	link_id INTEGER,
	
	FOREIGN KEY ( link_id ) REFERENCES link ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE event
(
	id INTEGER,
	name VARCHAR(100),
	type_id INTEGER,
	occured CHAR(6), --format yymmdd
	link_id INTEGER,
	
	FOREIGN KEY ( type_id ) REFERENCES eventtype ( id ),
	FOREIGN KEY ( link_id ) REFERENCES link ( id ),
	PRIMARY KEY ( id )
);
*/
CREATE TABLE circle
(
	id INTEGER,
	--name_id INTEGER,
	name_unic VARCHAR(100),
	name_roma VARCHAR(100),
	link_id INTEGER,
	
	--FOREIGN KEY ( name_id ) REFERENCES translit ( id ),
	FOREIGN KEY ( link_id ) REFERENCES link ( id ),
	PRIMARY KEY ( id )
);

CREATE TABLE album
(
	id INTEGER,
	--title_id INTEGER,
	title_unic VARCHAR(100),
	title_roma VARCHAR(100),
	circle_id INTEGER,
	track_count SMALLINT,
	duration INTEGER,
	catalog_n VARCHAR(100),
	event_id INTEGER,
	link_id INTEGER,
	vktime DECIMAL,
	
	--FOREIGN KEY ( title_id ) REFERENCES translit ( id ),
	FOREIGN KEY ( circle_id ) REFERENCES circle ( id ),
	--FOREIGN KEY ( event_id ) REFERENCES event ( id ),
	--FOREIGN KEY ( link_id ) REFERENCES link ( id ),
	PRIMARY KEY ( id )
);
/*
CREATE TABLE albumXcircle
( --use for multi-circle albums only
	id INTEGER,
	album_id INTEGER,
	circle_id INTEGER,
	
	FOREIGN KEY ( album_id ) REFERENCES album ( id ),
	FOREIGN KEY ( circle_id ) REFERENCES circle ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE people
(
	id INTEGER,
	--name_id INTEGER,
	name_unic VARCHAR(100),
	name_roma VARCHAR(100),
	circle_id INTEGER,
	link_id INTEGER,
	
	--FOREIGN KEY( name_id ) REFERENCES translit ( id ),
	FOREIGN KEY ( circle_id ) REFERENCES circle ( id ),
	FOREIGN KEY ( link_id ) REFERENCES link ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE fandom
(
	id INTEGER,
	name VARCHAR(100),
	link_id INTEGER,
	
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE lyric
(
	id INTEGER,
	unicode VARCHAR(4000),
	romaji VARCHAR(4000),
	eng VARCHAR(4000),
	rus VARCHAR(4000),
	
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE poetry
(
	id INTEGER,
	lyric_id INTEGER,
	poet_id INTEGER,
	
	FOREIGN KEY ( lyric_id ) REFERENCES lyric ( id ),
	FOREIGN KEY ( poet_id ) REFERENCES people ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE sourcetype
(
	id INTEGER,
	name VARCHAR(100),
	
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE source
(
	id INTEGER,
	--name_id INTEGER,
	name_unic VARCHAR(100),
	name_roma VARCHAR(100),
	type_id INTEGER,
	author_id INTEGER,
	circle_id INTEGER,
	link_id INTEGER,
	
	--FOREIGN KEY ( name_id ) REFERENCES translit ( id ),
	FOREIGN KEY ( type_id ) REFERENCES sourcetype ( id ),
	FOREIGN KEY ( author_id ) REFERENCES people ( id ),
	FOREIGN KEY ( circle_id ) REFERENCES circle ( id ),
	FOREIGN KEY ( link_id ) REFERENCES link ( id ),
	PRIMARY KEY ( id )	
);
*/

CREATE TABLE track
(
	id INTEGER,
	vktrack_id INTEGER,
	--title_id INTEGER,
	title_unic VARCHAR(100),
	title_roma VARCHAR(100),
	album_id INTEGER,
	circle_id INTEGER,
	fandom_id INTEGER,
	duration INTEGER,
	bpm SMALLINT,
	
	FOREIGN KEY ( vktrack_id ) REFERENCES vktrack ( id ),
	--FOREIGN KEY ( title_id ) REFERENCES translit ( id ),
	FOREIGN KEY ( album_id ) REFERENCES album ( id ),
	FOREIGN KEY ( circle_id ) REFERENCES circle ( id ),
	FOREIGN KEY ( fandom_id ) REFERENCES fandom ( id ),
	
	PRIMARY KEY ( id )
);

/*
CREATE TABLE inheritance
(
	id INTEGER,
	parent_id INTEGER,
	remix_id INTEGER,
	source_id INTEGER,
	
	FOREIGN KEY ( parent_id ) REFERENCES track ( id ),
	FOREIGN KEY ( remix_id ) REFERENCES track ( id ),
	FOREIGN KEY ( source_id ) REFERENCES source ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE vocal
(
	id INTEGER,
	song_id INTEGER,
	singer_id INTEGER,
	
	FOREIGN KEY ( song_id ) REFERENCES track ( id ),
	FOREIGN KEY ( singer_id ) REFERENCES people ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE arrangment
(
	id INTEGER,
	track_id INTEGER,
	musician_id INTEGER,
	
	FOREIGN KEY ( track_id ) REFERENCES track ( id ),
	FOREIGN KEY ( musician_id ) REFERENCES people ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE composition
(
	id INTEGER,
	track_id INTEGER,
	composer_id INTEGER,
	
	FOREIGN KEY ( track_id ) REFERENCES track ( id ),
	FOREIGN KEY ( composer_id ) REFERENCES people ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE vktrackXtrack
(
	id INTEGER,
	vktrack_id INTEGER,
	track_id INTEGER,
	
	FOREIGN KEY ( vktrack_id ) REFERENCES vktrack ( id ),
	FOREIGN KEY ( track_id ) REFERENCES track ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE musicvideo
(
	id INTEGER,
	track_id INTEGER,
	link_id INTEGER,
	
	FOREIGN KEY ( track_id ) REFERENCES track ( id ),
	FOREIGN KEY ( link_id ) REFERENCES link ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE genre
(
	id INTEGER,
	name VARCHAR(100),
	link_id INTEGER,
	
	FOREIGN KEY ( link_id ) REFERENCES link ( id ),
	PRIMARY KEY ( id )
);
*/
/*
CREATE TABLE trackgenre
(
	id INTEGER,
	track_id INTEGER,
	genre_id INTEGER,
	
	FOREIGN KEY ( track_id ) REFERENCES track ( id ),
	FOREIGN KEY ( genre_id ) REFERENCES genre ( id ),
	PRIMARY KEY ( id )	
);
*/
/*
CREATE TABLE trackosu
(
	osu_beatmap_set INTEGER,
	track_id INTEGER,
		
	FOREIGN KEY ( track_id ) REFERENCES track ( id ),
	PRIMARY KEY ( osu_beatmap_set )
);
*/
CREATE TABLE vkphoto
(
	id INTEGER,
	vk_id VARCHAR(20),
	photo_75 VARCHAR(500),
	photo_130 VARCHAR(500),
	photo_604 VARCHAR(500),
	photo_807 VARCHAR(500),
	photo_1280 VARCHAR(500),
	photo_2560 VARCHAR(500),
	width INTEGER,
	height INTEGER,
	text VARCHAR(1000),
	unix_time DECIMAL,
	access_key VARCHAR(50),
	vkpost_id INTEGER, --to delete. have to create new table for clip tables
	
	FOREIGN KEY ( vkpost_id ) REFERENCES vkpost ( id ),
	PRIMARY KEY ( id )
);

CREATE TABLE albumcover
(
	id INTEGER,
	vkpost_id INTEGER,
	album_id INTEGER,
	vkphoto_id INTEGER,
	author_id INTEGER,
	
	FOREIGN KEY ( vkpost_id ) REFERENCES vkpost ( id ),
	FOREIGN KEY ( album_id ) REFERENCES album ( id ),
	FOREIGN KEY ( vkphoto_id ) REFERENCES vkphoto ( id ),
	FOREIGN KEY ( author_id ) REFERENCES people ( id ),
	PRIMARY KEY ( id )	
);

CREATE TABLE albumXvkpost
(
	id INTEGER,
	album_id INTEGER,
	vkpost_id INTEGER,
	
	FOREIGN KEY ( album_id ) REFERENCES album ( id ),
	FOREIGN KEY ( vkpost_id ) REFERENCES vkpost ( id ),
	PRIMARY KEY ( id )
);
