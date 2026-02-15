#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_uiLayer || !m_uiLayer->m_pauseBtn) return;
		if (!Mod::get()->getSettingValue<bool>("unclickable")) {
			static_cast<CCSprite*>(m_uiLayer->m_pauseBtn->getChildren()->objectAtIndex(0))->setScale(0);
		} else {
			m_uiLayer->m_pauseBtn->setScale(0);
		}
	}
};