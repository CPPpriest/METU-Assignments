






void drawFramedCube(const glm::mat4& transformMatrix)
{
    // Activate shader program for edges and set transformation matrix
    glUseProgram(gProgram[1]); // Program for cube edges
    GLint modelMatrixLocation = glGetUniformLocation(gProgram[1], "modelingMatrix");
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(transformMatrix));

    glLineWidth(3);
    for (int i = 0; i < 6; ++i)
    {
        glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT,
                       BUFFER_OFFSET(gTriangleIndexDataSizeInBytes + i * 4 * sizeof(GLuint)));
    }

    // Activate shader program for filled cube and set transformation matrix
    glUseProgram(gProgram[0]); // Program for cube shading
    modelMatrixLocation = glGetUniformLocation(gProgram[0], "modelingMatrix");
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(transformMatrix));

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}




// Global Vector of all transitions ( instances )
std::vector<glm::mat4> sceneObjects;




// Initialize the vector of transitions
void initScene()
{
    // Clear any existing objects
    sceneObjects.clear();

    // Add a few cubes with different transformations
    sceneObjects.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(-2.0f, 0.0f, 0.0f))); // Cube on the left
    sceneObjects.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)));  // Cube in the center
    sceneObjects.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 0.0f, 0.0f)));  // Cube on the right
}



void display()
{
    glClearColor(0, 0, 0, 1);
    glClearDepth(1.0f);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // Loop through each transformation matrix in the sceneObjects array
    for (const auto& transformMatrix : sceneObjects)
    {
        drawFramedCube(transformMatrix);
    }

    renderText("tetrisGL", gWidth / 2 - 55, gHeight / 2 - 60, 0.75, glm::vec3(1, 1, 0));

    assert(glGetError() == GL_NO_ERROR);
}


