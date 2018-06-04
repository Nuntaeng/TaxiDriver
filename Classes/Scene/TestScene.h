#pragma once
#include "cocos2d.h"
USING_NS_CC;

/**
 @brief     ゲームに導入されるActorたちのテスト用仮シーン
 @author    Heewon Kim (nabicore@icloud.com)
 @date      2018-06-06
 */


class TestScene : public Layer {
public:
    explicit TestScene() {}
    virtual ~TestScene() {}
    
    static Scene* createScene();
    virtual bool init() override;
    virtual void onEnter() override;
    virtual void update(float) override;
    virtual void onExit() override;
    
    CREATE_FUNC(TestScene);
    
private:
    
};
