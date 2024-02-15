#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	static void onModify(auto & self)
    {
        self.setHookPriority("PlayLayer::init", 1000);
    }
	bool init(GJGameLevel* p0, bool p1, bool p2) {
		if (!PlayLayer::init(p0, p1, p2)) return false;
		if (!Mod::get()->getSettingValue<bool>("enabled")) return true;
		auto uiLayer = getChildByID("UILayer");
        auto pauseButton = uiLayer->getChildByIDRecursive("pause-button");
		if (pauseButton == nullptr) return true;
        if (!Mod::get()->getSettingValue<bool>("unclickable")) {
            auto pauseButtonSprite = pauseButton->getChildren()->objectAtIndex(0);
            typeinfo_cast<CCSprite*>(pauseButtonSprite)->setScale(0);
        } else {
            pauseButton->setScale(0);
        }
		return true;
	}
};