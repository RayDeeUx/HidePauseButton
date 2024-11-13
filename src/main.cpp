#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!Mod::get()->getSettingValue<bool>("enabled")) return;
		auto uiLayer = getChildByID("UILayer");
		if (!uiLayer) return;
		auto pauseButton = uiLayer->getChildByIDRecursive("pause-button");
		if (!pauseButton) return;
		if (!Mod::get()->getSettingValue<bool>("unclickable")) {
			static_cast<CCSprite*>(pauseButton->getChildren()->objectAtIndex(0))->setScale(0);
		} else {
			pauseButton->setScale(0);
		}
	}
};
