#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Pile{
public:
    Pile();
    void setup();
    void update();
    void draw();
    void mousedown( MouseEvent event );
    void swirl();
    
    
private:
    ci::Surface8u   bgSurface;
    ci::Surface8u   pileWaitSurface;
    ci::Surface8u   pileActive1Surface;
    ci::Surface8u   pileActive2Surface;
    ci::Surface8u   pileActive3Surface;

    gl::TextureRef  bgTexture;
    gl::TextureRef  pileWaitTexture;
    gl::TextureRef  pileActive1Texture;
    gl::TextureRef  pileActive2Texture;
    gl::TextureRef  pileActive3Texture;
};



