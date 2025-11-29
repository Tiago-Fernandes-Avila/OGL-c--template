#include <iostream>
#include "glad/glad.h" 
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    // 1. Inicializa o GLFW
    glfwInit();
    // Configura a versão do OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // 2. Cria a janela
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL Window", NULL, NULL);
    if (window == NULL) {
        std::cout << "Falha ao criar janela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    // 3. Inicializa o GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Falha ao inicializar GLAD" << std::endl;
        return -1;
    }    
    
    // Configura a viewport
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 4. Loop de Renderização Principal
    while (!glfwWindowShouldClose(window)) {
        // Renderização (Aqui é onde você colocará o código do LearnOpenGL)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Cor de fundo
        glClear(GL_COLOR_BUFFER_BIT);

        // Verifica eventos e troca buffers
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    // 5. Termina o GLFW
    glfwTerminate();
    return 0;
}

// Função de callback para redimensionamento da janela
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}