/*
*
* vkdoujinmusic.fdb
*
*/

CREATE TABLE vkgroup
(
	id INTEGER,
	vk_id VARCHAR(50),
	vkdomain VARCHAR(50),
	name VARCHAR(100),
	
	PRIMARY KEY ( id )	
);

CREATE TABLE vkpost
(
	id INTEGER, --uniq post id in the table
	vk_id VARCHAR(50), --post id in a vk group
	vkgroup_id INTEGER,
	unix_time DECIMAL,
	post_text VARCHAR(1000),
	likes INTEGER,
	reposts INTEGER,
	comments INTEGER,
	
	photo_count SMALLINT,
	audio_count SMALLINT,
	
	FOREIGN KEY ( vkgroup_id ) REFERENCES vkgroup ( id ),
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
	--duration INTEGER,
	--unix_time DECIMAL, --iru ka
	--url VARCHAR(100),
	--lyrics_id VARCHAR(50),
	--vkalbum_id INTEGER,
	--vkgenre_id INTEGER,
	vkpost_id INTEGER,

	FOREIGN KEY ( vkpost_id ) REFERENCES  vkpost ( id ),
	PRIMARY KEY ( id )
);

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
	--unix_time DECIMAL,
	access_key VARCHAR(50),
	vkpost_id INTEGER,
	
	FOREIGN KEY ( vkpost_id ) REFERENCES vkpost ( id ),
	PRIMARY KEY ( id )
);

CREATE TABLE comments
(
	id INTEGER,
	vkpost_id INTEGER,
	commentator VARCHAR(20),
	
	FOREIGN KEY ( vkpost_id ) REFERENCES vkpost ( id ),
	PRIMARY KEY ( id )
);

CREATE TABLE docs
(
	id INTEGER,
	
	owner_id VARCHAR(20),
	title VARCHAR(200),
	size INTEGER,
	ext VARCHAR(10),
	url VARCHAR(200),
	access_key VARCHAR(50),
	vkpost_id INTEGER,
	
	FOREIGN KEY ( vkpost_id ) REFERENCES vkpost ( id ),
	PRIMARY KEY ( id )	
);
