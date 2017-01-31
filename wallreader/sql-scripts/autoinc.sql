
CREATE GENERATOR vkgroupInc;

SET TERM ^ ;
CREATE TRIGGER vkgroupInc FOR vkgroup ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (vkgroupInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR vkpostInc;

SET TERM ^ ;
CREATE TRIGGER vkpostInc FOR vkpost ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (vkpostInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR vktrackInc;

SET TERM ^ ;
CREATE TRIGGER vktrackInc FOR vktrack ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (vktrackInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR vkpostvktrackInc;

SET TERM ^ ;
CREATE TRIGGER vkpostvktrackInc FOR vkpostXvktrack ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (vkpostvktrackInc, 1);
END^
SET TERM ; ^

/*
CREATE GENERATOR translitInc;

SET TERM ^ ;
CREATE TRIGGER translitInc FOR translit ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (translitInc, 1);
END^
SET TERM ; ^
*/

CREATE GENERATOR linkInc;

SET TERM ^ ;
CREATE TRIGGER linkInc FOR link ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (linkInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR eventtypeInc;

SET TERM ^ ;
CREATE TRIGGER eventtypeInc FOR eventtype ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (eventtypeInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR eventInc;

SET TERM ^ ;
CREATE TRIGGER eventInc FOR event ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (eventInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR albumInc;

SET TERM ^ ;
CREATE TRIGGER albumInc FOR album ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (albumInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR circleInc;

SET TERM ^ ;
CREATE TRIGGER circleInc FOR circle ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (circleInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR albumxcircleInc;

SET TERM ^ ;
CREATE TRIGGER albumxcircleInc FOR albumxcircle ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (albumxcircleInc, 1);
END^
SET TERM ; ^

CREATE GENERATOR peopleInc;


SET TERM ^ ;
CREATE TRIGGER peopleInc FOR people ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (peopleInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR fandomInc;

SET TERM ^ ;
CREATE TRIGGER fandomInc FOR fandom ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (fandomInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR lyricInc;

SET TERM ^ ;
CREATE TRIGGER lyricInc FOR lyric ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (lyricInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR poetryInc;

SET TERM ^ ;
CREATE TRIGGER poetryInc FOR poetry ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (poetryInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR vocalInc;

SET TERM ^ ;
CREATE TRIGGER vocalInc FOR vocal ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (vocalInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR arrangmentInc;

SET TERM ^ ;
CREATE TRIGGER arrangmentInc FOR arrangment ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (arrangmentInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR compositionInc;

SET TERM ^ ;
CREATE TRIGGER compositionInc FOR composition ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (compositionInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR sourcetypeInc;

SET TERM ^ ;
CREATE TRIGGER sourcetypeInc FOR sourcetype ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (sourcetypeInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR sourceInc;

SET TERM ^ ;
CREATE TRIGGER sourceInc FOR source ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (sourceInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR trackInc;

SET TERM ^ ;
CREATE TRIGGER trackInc FOR track ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (trackInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR inheritanceInc;

SET TERM ^ ;
CREATE TRIGGER inheritanceInc FOR inheritance ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (inheritanceInc, 1);
END^
SET TERM ; ^

/*
CREATE GENERATOR vktracktrackInc;

SET TERM ^ ;
CREATE TRIGGER vktracktrackInc FOR vktrackXtrack ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (vktracktrackInc, 1);
END^
SET TERM ; ^
*/

CREATE GENERATOR musicvideoInc;

SET TERM ^ ;
CREATE TRIGGER musicvideoInc FOR musicvideo ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (musicvideoInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR genreInc;

SET TERM ^ ;
CREATE TRIGGER genreInc FOR genre ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (genreInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR trackgenreInc;

SET TERM ^ ;
CREATE TRIGGER trackgenreInc FOR trackgenre ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (trackgenreInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR vkphotoInc;

SET TERM ^ ;
CREATE TRIGGER vkphotoInc FOR vkphoto ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (vkphotoInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR albumcoverInc;

SET TERM ^ ;
CREATE TRIGGER albumcoverInc FOR albumcover ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (albumcoverInc, 1);
END^
SET TERM ; ^


CREATE GENERATOR albumXvkpostInc;

SET TERM ^ ;
CREATE TRIGGER albumXvkpostInc FOR albumXvkpost ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (albumXvkpostInc, 1);
END^
SET TERM ; ^


