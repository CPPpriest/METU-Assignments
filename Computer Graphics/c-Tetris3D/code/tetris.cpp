#include "tetris.h"







// Initialize the vector of transitions
void initScene()
{
    mainBoard = BOARD(0,0,0);
    mainCube = {10,10,10};
}




void mainLoop(GLFWwindow* window)
{
    while (!glfwWindowShouldClose(window))
    {
        if(isCollide())
        {
            mainBoard.insertCube( mainCube);
            mainCube = CUBE(10,10,10);
            
        }

        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}









void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if ((key == GLFW_KEY_Q || key == GLFW_KEY_ESCAPE) && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        if(!isRotated) 
            mainCube.x -= 1;
        else 
            mainCube.z -= 1;
    }    
    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        if(!isRotated) 
            mainCube.x += 1;
        else 
            mainCube.z += 1;
    }  
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
        mainCube.y -= 1;

    if (key == GLFW_KEY_W && action == GLFW_PRESS)
        mainCube.y += 1;

    if (key == GLFW_KEY_K && action == GLFW_PRESS)
    {
        if (isRotated)
            isRotated = false;
        else
            isRotated = true;    
    }   

}







void display()
{
    glClearColor(0, 0, 0, 1);
    glClearDepth(1.0f);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);







    insertCube( mainCube.x , mainCube.y , mainCube.z);

    // Loop through each transformation matrix in the sceneObjects array
    for (const auto& transformMatrix : sceneObjects)
    {
        drawFramedCube(transformMatrix);
    }


    sceneObjects.resize(sceneObjects.size() - 27); 

    mainCube.y -= 0.008;


    //renderText("tetrisGL", gWidth / 2 - 55, gHeight / 2 - 60, 0.75, glm::vec3(1, 1, 0));

    assert(glGetError() == GL_NO_ERROR);
}











