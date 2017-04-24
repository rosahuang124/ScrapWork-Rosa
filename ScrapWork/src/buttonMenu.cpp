#include "buttonMenu.h"

using namespace po::scene;

buttonMenuRef buttonMenu::create()
{
    buttonMenuRef ref(new buttonMenu());
    ref->setup();
    return ref;
}

void buttonMenu::setup(){
    
    btn1Texture = gl::Texture::create(loadImage(loadAsset("activePage_btnFastFasion.png")));
    btn2Texture = gl::Texture::create(loadImage(loadAsset("activePage_btnBiotextile.png")));
    btn3Texture = gl::Texture::create(loadImage(loadAsset("activePage_btnTextile.png")));
    btn4Texture = gl::Texture::create(loadImage(loadAsset("activePage_btnDye.png")));
    
    btn1ActiveTexture = gl::Texture::create(loadImage(loadAsset("activePage_btnFastFasion2.png")));
    btn2ActiveTexture = gl::Texture::create(loadImage(loadAsset("activePage_btnBiotextile2.png")));
    btn3ActiveTexture = gl::Texture::create(loadImage(loadAsset("activePage_btnTextile2.png")));
    btn4ActiveTexture = gl::Texture::create(loadImage(loadAsset("activePage_btnDye2.png")));

    btn1 = Button::create(btn1Texture, btn1ActiveTexture);
    btn1->setPosition(ci::vec2 (1046.f, 290.f));
    btn1->setID(1);
    addChild(btn1);
    
    btn2 = Button::create(btn2Texture, btn2ActiveTexture);
    btn2->setPosition(ci::vec2 (1046.f, 290 + 78.f));
    btn2->setID(2);
    addChild(btn2);
    
    btn3 = Button::create(btn3Texture, btn3ActiveTexture);
    btn3->setPosition(ci::vec2 (1046.f, 290 + (78 * 2)));
    btn3->setID(3);
    addChild(btn3);
    
    btn4 = Button::create(btn4Texture, btn4ActiveTexture);
    btn4->setPosition(ci::vec2 (1046.f, 290 + (78 * 3)));
    btn4->setID(4);
    addChild(btn4);
    
    btn1->getbtnChangeStateSignal().connect(std::bind(&buttonMenu::updateMenuState, this, std::placeholders::_1));
    btn2->getbtnChangeStateSignal().connect(std::bind(&buttonMenu::updateMenuState, this, std::placeholders::_1));
    btn3->getbtnChangeStateSignal().connect(std::bind(&buttonMenu::updateMenuState, this, std::placeholders::_1));
    btn4->getbtnChangeStateSignal().connect(std::bind(&buttonMenu::updateMenuState, this, std::placeholders::_1));

}

void buttonMenu::updateMenuState(int number)
{
    switch (number) {
        case 1:
            cout<<"recieved signal 1"<<endl;
            btn2->setToNormal();
            btn3->setToNormal();
            btn4->setToNormal();
            break;

        case 2:
            cout<<"recieved signal 2"<<endl;
            btn1->setToNormal();
            btn3->setToNormal();
            btn4->setToNormal();
            break;
        case 3:
            cout<<"recieved signal 2"<<endl;
            btn1->setToNormal();
            btn2->setToNormal();
            btn4->setToNormal();
            break;
        case 4:
            cout<<"recieved signal 2"<<endl;
            btn1->setToNormal();
            btn2->setToNormal();
            btn3->setToNormal();
            break;

        default:
            break;
    }
}














