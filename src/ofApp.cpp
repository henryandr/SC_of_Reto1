#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    xStep = 6;
    yStep = 6;
    distDiv = 50;
    amplitud = 150;
    flagAmp = true;
    sphereSelected = false;
    selectedSphereIndex = -1; // Índice de la esfera seleccionada
    
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
        if (selectedSphereIndex == i) {
            ofSetColor(ofColor(255, 255, 255));
        }
        else {
            ofSetColor(spheresColor[i]);
        }
        
        ofPushMatrix();
        ofTranslate(spherePositions[i]);
        sphereMesh.draw();
        ofPopMatrix();
    }
    ofDisableDepthTest();
    myCam.end();

    // Mostrar la información de la esfera seleccionada
    if (sphereSelected) {
        ofSetColor(255,255,255);
        ofDrawBitmapString("Esfera seleccionada:", 20, 20);
        ofDrawBitmapString("X: " + ofToString(selectedSpherePosition.x), 20, 40);
        ofDrawBitmapString("Y: " + ofToString(selectedSpherePosition.y), 20, 60);
        ofDrawBitmapString("Z: " + ofToString(selectedSpherePosition.z), 20, 80);
    }

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
    // Convertir las coordenadas del mouse en un rayo 3D
    glm::vec3 rayStart, rayEnd;
    convertMouseToRay(x, y, rayStart, rayEnd);

    // Comprobar si el rayo intersecta alguna esfera
    sphereSelected = false;
    selectedSphereIndex = -1;
    for (int i = 0; i < spherePositions.size(); i++) {
        glm::vec3 intersectionPoint;
        glm::vec3 rayDir = glm::normalize(rayEnd - rayStart);
        if (rayIntersectsSphere(rayStart, rayDir, spherePositions[i], 5.0, intersectionPoint)) {
            // EN ESTA PARTE Debes adicionar la lógica para indicarle
            // a la aplicación la esfera seleccionada.
            sphereSelected = true;
            selectedSpherePosition = spherePositions[i];
            selectedSphereIndex = i; // Guardar índice de la esfera seleccionada
            selectedSphereColor = ofColor(255, 255, 255); // Cambiar color a blanco
            
            break; // Salimos del loop al encontrar la primera esfera seleccionada
        }
    }

}

void ofApp::convertMouseToRay(int mouseX, int mouseY, glm::vec3& rayStart, glm::vec3& rayEnd) {
    // Obtener matrices de proyección y modelo/vista de la cámara
    glm::mat4 modelview = myCam.getModelViewMatrix();
    glm::mat4 projection = myCam.getProjectionMatrix();
    ofRectangle viewport = ofGetCurrentViewport();

    // Convertir coordenadas del mouse a Normalized Device Coordinates (NDC)
    float x = 2.0f * (mouseX - viewport.x) / viewport.width - 1.0f;
    float y = 1.0f - 2.0f * (mouseY - viewport.y) / viewport.height;

    // Crear el rayo en NDC
    glm::vec4 rayStartNDC(x, y, -1.0f, 1.0f); // Near plane
    glm::vec4 rayEndNDC(x, y, 1.0f, 1.0f);   // Far plane

    // Convertir a coordenadas mundiales
    glm::vec4 rayStartWorld = glm::inverse(projection * modelview) * rayStartNDC;
    glm::vec4 rayEndWorld = glm::inverse(projection * modelview) * rayEndNDC;

    rayStartWorld /= rayStartWorld.w;
    rayEndWorld /= rayEndWorld.w;

    rayStart = glm::vec3(rayStartWorld);
    rayEnd = glm::vec3(rayEndWorld);
}

// Detectar si el rayo intersecta una esfera
bool ofApp::rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir, const glm::vec3& sphereCenter, float sphereRadius, glm::vec3& intersectionPoint) {
    glm::vec3 oc = rayStart - sphereCenter;

    float a = glm::dot(rayDir, rayDir);
    float b = 2.0f * glm::dot(oc, rayDir);
    float c = glm::dot(oc, oc) - sphereRadius * sphereRadius;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    else {
        float t = (-b - sqrt(discriminant)) / (2.0f * a);
        intersectionPoint = rayStart + t * rayDir;
        return true;
    }
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
