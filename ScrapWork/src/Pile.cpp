#include "Pile.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Pile::Pile(){};

void Pile::setup(){
    
    //pile img setup
    bgSurface = loadImage( loadAsset( "bg.png" )) ;
    pileWaitSurface = loadImage(loadAsset("wait_pile.png"));
    pileActive1Surface = loadImage(loadAsset("active_pile_1.png"));
    pileActive2Surface = loadImage(loadAsset("active_pile_2.png"));
    pileActive3Surface = loadImage(loadAsset("active_pile_3.png"));

    bgTexture = gl::Texture::create(bgSurface);
    pileWaitTexture = gl::Texture::create(pileWaitSurface);
    pileActive1Texture = gl::Texture::create(pileActive1Surface);
    pileActive2Texture = gl::Texture::create(pileActive2Surface);
    pileActive3Texture = gl::Texture::create(pileActive3Surface);

}

void Pile::draw(){
        
}

void Pile::mousedown( MouseEvent event ) {
    
}

void Pile::swirl(){
    
}
