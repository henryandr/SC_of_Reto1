#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;

		void convertMouseToRay(int mouseX, int mouseY, glm::vec3& rayStart, glm::vec3& rayEnd);
		bool rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir, const glm::vec3& sphereCenter, float sphereRadius, glm::vec3& intersectionPoint);


    void generateSpheres();
    float xStep, yStep, distDiv, amplitud;
    //vector<ofSpherePrimitive> spheres;
    ofEasyCam myCam;
    vector<ofColor> spheresColor;
	ofColor selectedSphereColor; // Color de la esfera seleccionada
	int selectedSphereIndex; // Índice de la esfera seleccionada

    ofLight light;
    bool flagAmp;
	bool sphereSelected;
    // Malla de una sola esfera para instancing
    ofVboMesh sphereMesh;

    // Vectores para posiciones y colores de las esferas
    vector<glm::vec3> spherePositions;
	glm::vec3 selectedSpherePosition;

    
		
};
