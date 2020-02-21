#include "HelloWorldScene.h"

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
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
    //listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{
    CCLOG("MULTI TOUCH BEGAN");
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event)
{
    CCLOG("MULTI TOUCHES HAVE MOVED");
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
