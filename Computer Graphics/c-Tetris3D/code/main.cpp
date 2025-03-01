#include "tetris.h"

// Define the variables (actual memory allocation happens here)
GLuint gProgram[3];
int gWidth = 600;
int gHeight = 1000;
GLuint gVertexAttribBuffer;
GLuint gTextVBO;
GLuint gIndexBuffer;
GLuint gTex2D;
int gVertexDataSizeInBytes;
int gNormalDataSizeInBytes;
int gTriangleIndexDataSizeInBytes;
int gLineIndexDataSizeInBytes;
GLint modelingMatrixLoc[2];
GLint viewingMatrixLoc[2];
GLint projectionMatrixLoc[2];
GLint eyePosLoc[2];
GLint lightPosLoc[2];
GLint kdLoc[2];
std::map<GLchar, Character> Characters;
glm::mat4 projectionMatrix;
glm::mat4 viewingMatrix;
glm::mat4 modelingMatrix = glm::translate(glm::mat4(1.f), glm::vec3(-0.5, -0.5, -0.5));
glm::vec3 eyePos = glm::vec3(0, 0, 24);
glm::vec3 lightPos = glm::vec3(0, 0, 7);
glm::vec3 kdCubes(0.86, 0.11, 0.31);
int activeProgramIndex = 0;





std::vector<glm::mat4> sceneObjects;


CUBE mainCube;
BOARD mainBoard;




int main(int argc, char** argv)   // Create Main Function For Bringing It All Together
{
    GLFWwindow* window;
    if (!glfwInit())
    {
        exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(gWidth, gHeight, "tetrisGL", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Initialize GLEW to setup the OpenGL Function pointers
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    char rendererInfo[512] = {0};
    strcpy(rendererInfo, (const char*) glGetString(GL_RENDERER));
    strcat(rendererInfo, " - ");
    strcat(rendererInfo, (const char*) glGetString(GL_VERSION));
    glfwSetWindowTitle(window, rendererInfo);

    init();

    glfwSetKeyCallback(window, keyboard);
    glfwSetWindowSizeCallback(window, reshape);


    isRotated = false;


    reshape(window, gWidth, gHeight); // need to call this once ourselves
    mainLoop(window); // this does not return unless the window is closed

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}




