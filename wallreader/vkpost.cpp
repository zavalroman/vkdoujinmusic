
#include "vkpost.h"

Vkpost::Vkpost()
{
    photo_post = false;
    poll_post = false;
    audio_post = false;

}

void Vkpost::addNewPhoto()
{
    photos.push_back(photo);
}

void Vkpost::addNewTrack()
{
    tracks.push_back(track);
}

void Vkpost::addNewDoc()
{
    docs.push_back(doc);
}
