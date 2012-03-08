#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    glEnable(GL_DEPTH_TEST);
    degrees = 0.0f;
    xDeg = 0.0f; yDeg = 0.0f; zDeg =0.0f;
    ofSetFrameRate(60);

    prepareShape();
    prepareGUI();

}

//--------------------------------------------------------------
void testApp::draw()
{
    glPushMatrix();
   // camera.begin();
    glTranslatef(x, y, z);
    ofScale(100,100,100);
    ofRotateX(xDeg);
    ofRotateY(yDeg);
    ofRotateZ(zDeg);
    vbo.drawElements(GL_TRIANGLE_FAN, 12);
    glPopMatrix();

    glPushMatrix();
    for(int i=0;i<1000;i++)
    {
        ofRotateY(degrees);
        //glTranslatef(ofRandom(100), ofRandom(100), ofRandom(100));
        vbo.drawElements(GL_TRIANGLE_FAN, 12);
    }
    glPopMatrix();
    degrees += 1.0f;
    if(degrees>360)
    {
        degrees = 0;
    }
}

void testApp::prepareGUI()
{
    gui = new ofxUICanvas(0,0,320,320);		//ofxUICanvas(float x, float y, float width, float height)		
    
    gui->addWidgetDown(new ofxUILabel("Generative Texture ", OFX_UI_FONT_LARGE)); 
    gui->addWidgetDown(new ofxUISlider(304,16,0.0,255.0,100.0,"BACKGROUND VALUE")); 
    gui->addWidgetDown(new ofxUISlider(304,16,0.0,ofGetWindowWidth()*2,0.5,"X-Coordinate")); 
    gui->addWidgetDown(new ofxUISlider(304,16,0.0,ofGetWindowHeight()*2,0.5,"Y-Coordinate")); 
    gui->addWidgetDown(new ofxUISlider(304,16,0.0,640,0.5,"Z-Coordinate")); 
    gui->addWidgetDown(new ofxUISlider(304,16,0.0,360,0.5,"X-Axis")); 
    gui->addWidgetDown(new ofxUISlider(304,16,0.0,360,0.5,"Y-Axis"));
    gui->addWidgetDown(new ofxUISlider(304,16,0.0,360,0.5,"Z-Axis"));
    gui->addWidgetDown(new ofxUIToggle(20, 20, false, "FULLSCREEN"));
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent); 
    gui->loadSettings("GUI/guiSettings.xml"); 
   

    
    

}
//--------------------------------------------------------------
void testApp::prepareShape()
{  

    ofVboMesh mesh;
    

    ofFloatColor c1, c2, c3, c4;
    c1.r = 1.0f;
    c1.g = 0.0f;
    c1.b = 0.0f;
    // Front face

    mesh.addColor(c1);
    mesh.addTexCoord(ofVec2f(0.0f,0.0f)); mesh.addVertex(ofVec3f(-1.0f, -1.0f, 1.0f));mesh.addNormal(ofVec3f(0.0f, 0.0f, 1.0f));
    mesh.addTexCoord(ofVec2f(0.0f, 1.0f)); mesh.addVertex(ofVec3f(1.0f, -1.0f, 1.0f));mesh.addNormal(ofVec3f(0.0f, 0.0f, 1.0f));
    mesh.addTexCoord(ofVec2f(1.0f, 1.0f)); mesh.addVertex(ofVec3f(0.0f, 1.0f, 0.0f));mesh.addNormal(ofVec3f(0.0f, 0.0f, 1.0f));
//
    c2.r = 0.0f;
    c2.g = 1.0f;
    c2.g = 0.0f;
// Right face

    mesh.addColor(c2);
    mesh.addTexCoord(ofVec2f(0.0f,0.0f)); mesh.addVertex(ofVec3f(1.0f, -1.0f, 1.0f));mesh.addNormal(ofVec3f(1.0f, 0.0f, 0.0f));
    mesh.addTexCoord(ofVec2f(1.0f, 1.0f)); mesh.addVertex(ofVec3f(1.0f, -1.0f, -1.0f));mesh.addNormal(ofVec3f(1.0f, 0.0f, 0.0f));
    mesh.addTexCoord(ofVec2f(0.0f, 1.0f)); mesh.addVertex(ofVec3f(0.0f, 1.0f, 0.0f));mesh.addNormal(ofVec3f(1.0f, 0.0f, 0.0f));
// Back face
    c3.r = 0.0f;
    c3.g = 0.0f;
    c3.b = 1.0f;
    mesh.addColor(c3);
    mesh.addTexCoord(ofVec2f(0.0f, 0.0f)); mesh.addVertex(ofVec3f(1.0f, -1.0f, -1.0f));mesh.addNormal(ofVec3f(0.0f, 0.0f, -1.0f));
    mesh.addTexCoord(ofVec2f(0.0f, 1.0f)); mesh.addVertex(ofVec3f(-1.0f, -1.0f, -1.0f));mesh.addNormal(ofVec3f(0.0f, 0.0f, -1.0f));
    mesh.addTexCoord(ofVec2f(1.0f, 1.0f)); mesh.addVertex(ofVec3f(0.0f, 1.0f, 0.0f));mesh.addNormal(ofVec3f(0.0f, 0.0f, -1.0f));
// Left face
    c4.r = 1.0f;
    c4.g = 0.0f;
    c4.b = 1.0f;
    mesh.addColor(c4);
    mesh.addTexCoord(ofVec2f(0.0f, 0.0f)); mesh.addVertex(ofVec3f( -1.0f, -1.0f, -1.0f));mesh.addNormal(ofVec3f(-1.0f, 0.0f, 0.0f));
    mesh.addTexCoord(ofVec2f(1.0f, 0.0f)); mesh.addVertex(ofVec3f( -1.0f, -1.0f, 1.0f));mesh.addNormal(ofVec3f(-1.0f, 0.0f, 0.0f));
    mesh.addTexCoord(ofVec2f(1.0f, 1.0f)); mesh.addVertex(ofVec3f(0.0f, 1.0f, 0.0f));mesh.addNormal(ofVec3f(-1.0f, 0.0f, 0.0f));
    
    mesh.setupIndicesAuto();
    vbo.setMesh(mesh, GL_STATIC_DRAW);
        
}

void testApp::exit()
{
	gui->saveSettings("GUI/guiSettings.xml");     
    delete gui; 
}

void testApp::guiEvent(ofxUIEventArgs &e)
{
	if(e.widget->getName() == "BACKGROUND VALUE")	
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;    
        ofBackground(slider->getScaledValue());
    }   
    else if(e.widget->getName() == "FULLSCREEN")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue()); 
    }    
    else if(e.widget->getName() == "X-Coordinate")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;    
        x = slider->getScaledValue(); 
    }
    else if(e.widget->getName() == "Y-Coordinate")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;    
        y = slider->getScaledValue(); 
    }
    else if(e.widget->getName() == "Z-Coordinate")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;    
        z = slider->getScaledValue(); 
    }
    else if(e.widget->getName() == "X-Axis")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;    
        xDeg = slider->getScaledValue(); 
    }
    else if(e.widget->getName() == "Y-Axis")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;    
        yDeg = slider->getScaledValue(); 
    }
    else if(e.widget->getName() == "Z-Axis")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;    
        zDeg = slider->getScaledValue(); 
    }

}