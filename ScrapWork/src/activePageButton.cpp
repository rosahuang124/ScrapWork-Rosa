#include "activePageButton.h"

activePageButtonRef activePageButton::create(){
    activePageButtonRef ref = std::shared_ptr<activePageButton>(new activePageButton);
    ref->setup();
    return ref;
};

activePageButton::activePageButton(){}

void activePageButton::setup(){
   
    //inactive btn
    btnFastFashionTex = gl::Texture::create(loadImage(loadAsset("activePage_btnFastFasion.png")));
    btnBiotextileTex = gl::Texture::create(loadImage(loadAsset("activePage_btnBiotextile.png")));
    btnTextileTex = gl::Texture::create(loadImage(loadAsset("activePage_btnTextile.png")));
    btnDyeTex = gl::Texture::create(loadImage(loadAsset("activePage_btnDye.png")));
    
    btnFastFashion = po::scene::Image::create(btnFastFashionTex);
    btnBiotextile = po::scene::Image::create(btnBiotextileTex);
    btnTextile = po::scene::Image::create(btnTextileTex);
    btnDye = po::scene::Image::create(btnDyeTex);
    
    btnFastFashion->setPosition(ci::vec2 (1046.f, 290.f));
    btnBiotextile->setPosition(ci::vec2 (1046.f, 290+80.f));
    btnTextile->setPosition(ci::vec2 (1046.f, 290+ 80*2.f));
    btnDye->setPosition(ci::vec2 (1046.f, 290+ 80*3.f));
    
    btnFastFashion->setDrawBounds(true);
    
    addChild(btnFastFashion);
    addChild(btnBiotextile);
    addChild(btnTextile);
    addChild(btnDye);
    
    //active btn
    btnFastFashionActiveTex = gl::Texture::create(loadImage(loadAsset("activePage_btnFastFasion2.png")));
    btnBiotextileActiveTex = gl::Texture::create(loadImage(loadAsset("activePage_btnBiotextile2.png")));
    btnTextileActiveTex = gl::Texture::create(loadImage(loadAsset("activePage_btnTextile2.png")));
    btnDyeActiveTex = gl::Texture::create(loadImage(loadAsset("activePage_btnDye2.png")));
    
    btnFastFashionActive = po::scene::Image::create(btnFastFashionActiveTex);
    btnBiotextileActive = po::scene::Image::create(btnBiotextileActiveTex);
    btnTextileActive = po::scene::Image::create(btnTextileActiveTex);
    btnDyeActive = po::scene::Image::create(btnDyeActiveTex);
    
    btnFastFashionActive->setPosition(ci::vec2 (1046.f, 290.f));
    btnBiotextileActive->setPosition(ci::vec2 (1046.f, 290+80.f));
    btnTextileActive->setPosition(ci::vec2 (1046.f, 290+ 80*2.f));
    btnDyeActive->setPosition(ci::vec2 (1046.f, 290+ 80*3.f));
    
    addChild(btnFastFashionActive);
    addChild(btnBiotextileActive);
    addChild(btnTextileActive);
    addChild(btnDyeActive);
    
    btnFastFashionActive->setAlpha(0.f);
    btnBiotextileActive->setAlpha(0.f);
    btnTextileActive->setAlpha(0.f);
    btnDyeActive->setAlpha(0.f);

    
    rect = po::scene::Shape::createRect(500.f, 350.f);
    addChild(rect);
    rect->setAlpha(0.f);
    
    getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&activePageButton::mousedown, this, std::placeholders::_1));
}

void activePageButton::mousedown( po::scene::MouseEvent &event ){
    switch (event.getType()) {
        case po::scene::MouseEvent::DOWN_INSIDE:
            if (event.getWindowPos().x >= btnFastFashion->getPosition().x && event.getWindowPos().x <= btnFastFashion->getPosition().x+234 && event.getWindowPos().y >= btnFastFashion->getPosition().y && event.getWindowPos().y <= btnFastFashion->getPosition().y + 53){
                btnFastFashionIsActive =! btnFastFashionIsActive;
                if (btnFastFashionIsActive == true){
                    rect->setAlpha(1.f);
                    btnFastFashionActive->setAlpha(1.f);
                    btnFastFashion->setAlpha(0.f);
                } else {
                    rect->setAlpha(0.f);
                    btnFastFashionActive->setAlpha(0.f);
                    btnFastFashion->setAlpha(1.f);
                }
            }
            if (event.getWindowPos().x >= btnBiotextile->getPosition().x && event.getWindowPos().x <= btnBiotextile->getPosition().x+234 && event.getWindowPos().y >= btnBiotextile->getPosition().y && event.getWindowPos().y <= btnBiotextile->getPosition().y + 53){
                btnBiotextileIsActive =! btnBiotextileIsActive;
                if (btnFastFashionIsActive == true){
                    rect->setAlpha(1.f);
                    btnBiotextileActive->setAlpha(1.f);
                    btnBiotextile->setAlpha(0.f);
                } else {
                    rect->setAlpha(0.f);
                    btnBiotextileActive->setAlpha(0.f);
                    btnBiotextile->setAlpha(1.f);
                }
            }
            
            

            
            
            break;
        default:
            break;
    }

}



