#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CCScene.hpp>

using namespace geode::prelude;

// W Click GUI starter for Geometry Dash 2.2081 / Geode Android.
// This source deliberately provides the settings/config scaffold first.
// CBFH is not yet a frame-perfect input automation engine.

class $modify(WClickMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto button = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("W", 30, false, "bigFont.fnt", "GJ_button_05.png", 40.f, 1.f),
            this,
            menu_selector(WClickMenuLayer::onWClick)
        );
        if (button) {
            button->setID("w-click-gui-button");
            auto menu = CCMenu::create();
            menu->setID("w-click-gui-menu");
            menu->addChild(button);
            menu->setPosition({0, 0});
            button->setPosition({winSize.width - 28.f, winSize.height - 28.f});
            this->addChild(menu, 1000);
        }
        return true;
    }

    void onWClick(CCObject*) {
        FLAlertLayer::create(
            "W Click GUI",
            "CBFH: <cy>configured timing helper</c>\n"
            "Frame window: <cg>" + numToString(Mod::get()->getSettingValue<int64_t>("frame-window")) + "</c>\n\n"
            "Use Geode mod settings to enable CBFH and choose 1-20 frames.\n"
            "Automatic frame-perfect jumping is not implemented in this starter build.",
            "OK"
        )->show();
    }
};
