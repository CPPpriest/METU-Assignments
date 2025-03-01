#ifndef __TETRIS__HEADER__
#define __TETRIS__HEADER__



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glew.h>
//#include <OpenGL/gl3.h>   // The GL Header File
#include <GLFW/glfw3.h> // The GLFW header
#include <glm/glm.hpp> // GL Math library header
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 
#include <ft2build.h>
#include FT_FREETYPE_H

#define BUFFER_OFFSET(i) ((char*)NULL + (i))

using namespace std;




// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    GLuint Advance;    // Horizontal offset to advance to next glyph
};



struct CUBE{
    double x, y, z;


    CUBE(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool isCollide(){
        return y < -3.5;
    }
    
    void drawCube(){

        glm::mat4 transformMatrix = glm::translate(glm::mat4(1.f), glm::vec3(x ,y ,z));

        glUseProgram(gProgram[1]); 
        GLint modelMatrixLocation = glGetUniformLocation(gProgram[1], "modelingMatrix");
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(transformMatrix));

        glLineWidth(3);

        for (int i = 0; i < 6; ++i){
            glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, BUFFER_OFFSET(gTriangleIndexDataSizeInBytes + i * 4 * sizeof(GLuint)));
        }

        glUseProgram(gProgram[0]); 
        modelMatrixLocation = glGetUniformLocation(gProgram[0], "modelingMatrix");
        glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(transformMatrix));

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    } 

};



struct BOARD{
    int boardSize;
    double cubeSize;
    double boardX, boardY, boardZ;
    std::vector<CUBE> grid;

    BOARD(int bs, double cs, double bx, double by, double bz){
        
        // initialize BOARD variables
        boardSize = bs;
        cubeSize = cs;
        boardX = bx;
        boardY = by;
        boardZ = bz;
        
        
        for (int row = 0; row < boardSize; ++row) {
            for (int col = 0; col < boardSize; ++col) {
                grid.push_back( CUBE( boardX + col * cubeSize, boardY, boardZ + row * cubeSize ) );
            }
        }

    }

    //void drawBoard(){}

    void insertCube(CUBE cubeInstance)
    {   
        grid.push_back(cubeInstance);
    }

};


extern GLuint gProgram[3];
extern int gWidth;
extern int gHeight;
extern GLuint gVertexAttribBuffer;
extern GLuint gTextVBO;
extern GLuint gIndexBuffer;
extern GLuint gTex2D;
extern int gVertexDataSizeInBytes;
extern int gNormalDataSizeInBytes;
extern int gTriangleIndexDataSizeInBytes;
extern int gLineIndexDataSizeInBytes;
extern GLint modelingMatrixLoc[2];
extern GLint viewingMatrixLoc[2];
extern GLint projectionMatrixLoc[2];
extern GLint eyePosLoc[2];
extern GLint lightPosLoc[2];
extern GLint kdLoc[2];
extern std::map<GLchar, Character> Characters;
extern glm::mat4 projectionMatrix;
extern glm::mat4 viewingMatrix;
extern glm::mat4 modelingMatrix;
extern glm::vec3 eyePos;
extern glm::vec3 lightPos;
extern glm::vec3 kdCubes;
extern int activeProgramIndex;

extern CUBE mainCube;




// Global Vector of all transitions ( instances )
extern std::vector<glm::mat4> sceneObjects;

extern bool isRotated;


bool ReadDataFromFile(const string& fileName, string& data);
GLuint createVS(const char* shaderName);
GLuint createFS(const char* shaderName);

void insertCube(float x, float y, float z);
void insertGrid();
void initScene();


void initFonts(int windowWidth, int windowHeight);
void initShaders();
void initVBO();
void init();
void drawFramedCube(const glm::mat4& transformMatrix);
void renderText(const std::string& text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
void display();
void reshape(GLFWwindow* window, int w, int h);
void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
void mainLoop(GLFWwindow* window);





#endif