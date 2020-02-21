#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    mySprite = Sprite::create("CloseNormal.png");
    
    mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    
    this->addChild(mySprite);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/mainMainMusic.mp3");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/mainMainMusic.mp3", true);

    this->scheduleOnce(schedule_selector(HelloWorld::PauseMusic), 5);
    this->scheduleOnce(schedule_selector(HelloWorld::ResumeMusic), 10);
    
    return true;
}

void HelloWorld::PauseMusic(float dt)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void HelloWorld::ResumeMusic(float dt)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
