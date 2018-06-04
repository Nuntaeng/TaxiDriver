#include "TestScene.h"


Scene* TestScene::createScene() {
    Scene* ret = Scene::create();
    TestScene* layer = TestScene::create();
    ret->addChild(layer);
    return ret;
}

bool TestScene::init() {
    if (!Layer::init()) {
        return false;
    }
    
    return true;
}

void TestScene::onEnter() {
    Layer::onEnter();
    scheduleUpdate();
}

void TestScene::update(float dt) {
    
}

void TestScene::onExit() {
    Layer::onExit();
}
