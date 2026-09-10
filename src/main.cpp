#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
	void setupHasCompleted() {
		PlayLayer::setupHasCompleted();
		if (!Mod::get()->getSettingValue<bool>("enabled") || !m_uiLayer || !m_uiLayer->m_pauseBtn) return;
		CCNode* targetNode = !Mod::get()->getSettingValue<bool>("unclickable") ? static_cast<CCNode*>(m_uiLayer->m_pauseBtn->getChildByType<CCSprite*>(0)) : static_cast<CCNode*>(m_uiLayer->m_pauseBtn);
		if (!targetNode) return;
		targetNode->setScale(0);
	}
};
