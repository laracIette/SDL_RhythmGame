#include "HitSoundManager.h"

namespace RythmGame::Sound
{

    HitSoundManager::HitSoundManager()
    {
        hitSounds[0] = "assets/Skins/BaseSkin/HitObjects/Notes/Hit.ogg";
        hitSounds[1] = "assets/Skins/BaseSkin/HitObjects/Holds/Hit.ogg";
        hitSounds[2] = "assets/Skins/BaseSkin/HitObjects/Doubles/Hit.ogg";
        hitSounds[3] = "assets/Skins/BaseSkin/HitObjects/Mashs/Hit.ogg";
        hitSounds[4] = "assets/Skins/BaseSkin/HitObjects/Ghosts/Hit.ogg";
        hitSounds[5] = "assets/Skins/BaseSkin/HitObjects/Coins/Hit.ogg";
        hitSounds[6] = "assets/Skins/BaseSkin/HitObjects/Hammers/Hit.ogg";
        hitSounds[7] = "assets/Skins/BaseSkin/HitObjects/Chainsaws/Hit.ogg";

        audioChannels = 0;
        lastAudioChannels = 0;
    }
    HitSoundManager::~HitSoundManager()
    {
    }

    void HitSoundManager::Update()
    {
        for( int i{ 0 }, j{ 0 }; i < playingHitSounds.size(); ++i, ++j )
        {
            if( !playingHitSounds[j]->Playing() )
            {
                playingHitSounds[j]->Close();
                playingHitSounds.erase( playingHitSounds.begin() + j-- );

                if( audioChannels != 0 )
                {
                    audioChannels--;
                }
                else
                {
                    std::cout << "already 0 channels affected" << std::endl;
                }
            }
        }

        if( audioChannels != lastAudioChannels )
        {
            lastAudioChannels = audioChannels;
            std::cout << "Audio channels : " << (int)lastAudioChannels << std::endl;
        }
    }

    void HitSoundManager::Play( int pos )
    {
        if( audioChannels == 255 )
        {
            std::cout << "max number of channels affected" << std::endl;
            return;
        }

        playingHitSounds.push_back( new HitSound( hitSounds[pos-1], audioChannels++) );
        playingHitSounds.back()->SetVolume( 1 );
        playingHitSounds.back()->Play();
    }

    void HitSoundManager::Close()
    {
        for( HitSound *hitSound : playingHitSounds )
        {
            hitSound->Close();

            if( audioChannels != 0 )
            {
                audioChannels--;
            }
            else
            {
                std::cout << "already 0 channels affected" << std::endl;
            }
        }
        playingHitSounds.clear();
    }

}