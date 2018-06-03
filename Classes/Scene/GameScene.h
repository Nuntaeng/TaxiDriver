#ifndef GameScene_h
#define GameScene_h

#include "cocos2d.h"
USING_NS_CC;

/**
 @brief 全体的なゲームの流れ
 @author Heewon Kim (nabicore@icloud.com)
 @date 2018-06-03 23:30:05
 */
class GameScene : public Scene {
    
public:
    explicit GameScene() {}
    virtual ~GameScene() {}
    
    virtual void onEnter() override;
    virtual void update(float) override;
    
    CREATE_FUNC(GameScene);
    
private:
    
};


#endif /* GameScene_hpp */
