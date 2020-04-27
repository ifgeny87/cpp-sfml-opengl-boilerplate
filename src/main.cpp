#include <iostream>
#include <SFML/Graphics.hpp>
#include <OpenGL/glu.h>

using namespace sf;

int main(int argc, char *argv[]) {
    Window window{
            VideoMode(600, 400),
            "OpenGL with SFML",
    };

    glClearColor(.3, .6, .9, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, window.getSize().x / window.getSize().y, 1, 500);
    glMatrixMode(GL_MODELVIEW);

    bool isRunning = true;
    Event event{};

    while (isRunning) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                isRunning = false;
            } else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                isRunning = false;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        {
            glColor3b(127, 0, 0);
            glVertex3f(0, 2, -5);
            glColor3b(0, 127, 0);
            glVertex3f(-2, -2, -5);
            glColor3b(0, 0, 127);
            glVertex3f(2, -2, -5);
        }
        glEnd();

        window.display();
    }
}