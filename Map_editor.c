#include <iostream>
#include <vector>
using namespace std;
// The map data
vector <vector<int>> mapData;
// The texture data
vector <GLuint> textures;
// The shader program
GLuint shaderProgram;
// The vertex array object
GLuint vao;
// The vertex buffer object
GLuint vbo;
// The index buffer object
GLuint ibo;
// Initialize the map editor
void init() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Create a window
    SDL_Window *window = SDL_CreateWindow("Doom Engine Map Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    // Create an OpenGL context
    SDL_GLContext context = SDL_GL_CreateContext(window);
    // Initialize GLEW
    glewInit();
    // Set the clear color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    // Enable culling
    glEnable(GL_CULL_FACE);
    // Load the map data
    mapData.push_back({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    mapData.push_back({1, 0, 0, 0, 0, 0, 0, 0, 0, 1});
    mapData.push_back({1, 0, 0, 0, 0, 0, 0, 0, 0, 1});
    // Load the texture data
    textures.push_back(loadTexture("wall.png"));
    textures.push_back(loadTexture("floor.png"));
    textures.push_back(loadTexture("ceiling.png"));
    // Create the shader program
    shaderProgram = createShaderProgram("vertexShader.glsl", "fragmentShader.glsl");
    // Create the vertex array object
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    // Create the vertex