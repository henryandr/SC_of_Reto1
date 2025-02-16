#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    xStep = 6;
    yStep = 6;
    distDiv = 50;
    amplitud = 150;
    flagAmp = true;
    
    ofEnableDepthTest();
    ofSetBackgroundColor(0);
    light.setPosition(-500, 500, 500);
    light.enable();
    myCam.setPosition(0, 0, 1500);
    
    generateSpheres();
}
//--------------------------------------------------------------
void ofApp::generateSpheres() {
    sphereMesh.clear(); // Limpiar el mesh
    spheresColor.clear();

    ofSpherePrimitive sphereTemplate;
    sphereTemplate.setRadius(10);
    sphereTemplate.setResolution(6); // Reducir resolución mejora el rendimiento

    sphereMesh = sphereTemplate.getMesh(); // Usar una sola malla de referencia

    for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += xStep) {
        for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += yStep) {
            float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
            glm::vec3 pos(x, y, z);

            // Color basado en la altura
            float normalizedZ = ofMap(z, -amplitud, amplitud, 0, 1);
            ofColor sphereColor = ofColor::fromHsb(ofMap(normalizedZ, 0, 1, 120, 0), 255, 255);

            spheresColor.push_back(sphereColor);
            spherePositions.push_back(pos);
        }
    }
}



//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    myCam.begin();
    ofEnableDepthTest();
    for(int i = 0; i < spherePositions.size(); i++){
        ofSetColor(spheresColor[i]);
        ofPushMatrix();
        ofTranslate(spherePositions[i]);
        sphereMesh.draw();
        ofPopMatrix();
    }
    ofDisableDepthTest();
    myCam.end();

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'f':
        case 'F':
            ofToggleFullscreen();
            break;
            
        case OF_KEY_ESC:
            ofExit();
            break;
        
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
