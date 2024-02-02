#include "Geode/platform/cplatform.h"
#include <Geode/Geode.hpp>
#include <Geode/modify/CCSprite.hpp>

using namespace geode::prelude;

class $modify(CCSprite) {
	static CCSprite* createWithSpriteFrameName(char const* frameName) {
        CCSprite* sprite = CCSprite::createWithSpriteFrameName(frameName);
        
        if (!Mod::get()->getSettingValue<bool>("enabled")) return sprite;
        if (strcmp(frameName, "GJ_pauseBtn_clean_001.png") == 0) {
            sprite->setVisible(false); // hide pause button
            #ifdef GEODE_IS_DESKTOP
            if (Mod::get()->getSettingValue<bool>("unclickable"))
                sprite->setScale(0.0); // make pause button unclickable
            #endif
        }
        return sprite;
    }
};
