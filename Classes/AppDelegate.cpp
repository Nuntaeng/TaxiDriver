#include "AppDelegate.h"
#include "GameScene.h"
#include "Constant.h"


void AppDelegate::initGLContextAttrs() {
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("ProjectClicker", cocos2d::Rect(0, 0, Constant::RES_WIDTH, Constant::RES_HEIGHT));
#else
        glview = GLViewImpl::create("ProjectClicker");
#endif
        director->setOpenGLView(glview);
    }

    director->setDisplayStats(true);
    director->setAnimationInterval(1.0f / 60);
    glview->setDesignResolutionSize(Constant::RES_WIDTH, Constant::RES_HEIGHT, ResolutionPolicy::NO_BORDER);
    
    auto scene = GameScene::create();
    director->runWithScene(scene);

    return true;
}


void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}


void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
