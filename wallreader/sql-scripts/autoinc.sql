
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

CREATE GENERATOR commentsInc;

SET TERM ^ ;
CREATE TRIGGER commentsInc FOR comments ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (commentsInc, 1);
END^
SET TERM ; ^

CREATE GENERATOR vkdocInc;

SET TERM ^ ;
CREATE TRIGGER vkdocInc FOR vkdoc ACTIVE
BEFORE INSERT POSITION 1
AS
BEGIN
    if (new.ID is null) then
    new.ID = gen_id (vkdocInc, 1);
END^
SET TERM ; ^
