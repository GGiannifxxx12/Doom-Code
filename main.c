#include <SDL.h>
#include <OpenGL.h>
#include <GLEW/glew.h>
#include <iostream>
#include <vector>
using namespace std;
// Screen width and height
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
// The player's position
float playerX = 90;
float playerY = 90;
float playerZ = 90;
// The player's rotation
float playerRotation = 50;
// The player's speed
float playerSpeed = 20;
// The level data
vector<vector<int>> levelData;
// The texture data
vector<GLuint> textures;
// The shader program
GLuint shaderProgram;
// The vertex array object
GLuint vao;
// The vertex buffer object
GLuint vbo;
// The index buffer object
GLuint ibo;
// Initialize the game
void init() {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Create a window
    SDL_Window *window = SDL_CreateWindow("Doom Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
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
    // Load the level data
    levelData.push_back({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    levelData.push_back({1, 0, 0, 0, 0, 0, 0, 0, 0, 1});
    levelData.push_back({ 1, 0, 0, 0, 0, 0, 0, 0, });
