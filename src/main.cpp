#include <Geode/Geode.hpp>
#include <Geode/modify/CCSprite.hpp>

using namespace geode::prelude;

class $modify(CCSprite) {
	static CCSprite* createWithSpriteFrameName(char const* frameName) {
        CCSprite* sprite = CCSprite::createWithSpriteFrameName(frameName);

        if (strcmp(frameName, "GJ_pauseBtn_clean_001.png") == 0 && Mod::get()->getSettingValue<bool>("enabled"))
			sprite->setVisible(false); // hide pause button
        return sprite;
    }
};
