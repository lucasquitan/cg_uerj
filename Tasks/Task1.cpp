/*
*   Tarefa 1 - Questão 1 - Desenvolva um código que: desenha uma casa simples com OpenGL; 
*   Ao pressionar a tecla de espaço do teclado a tela escurece; 
*   Se o fundo estiver escuro e o usuário pressionar qualquer tecla o fundo torna-se branco. 
*/

#include <GL/glut.h>

void init(void);
void display(void);
void applyDark(void);
void applyLigth(void);

int ligth = 0;

void init(void) {
    // Ligth background
    glClearColor(1, 1, 1, 1);

    // Vizualization system
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void applyDark() {
    ligth = 1;
    glClearColor(0, 0, 0, 0);
}

void applyLigth() {
    ligth = 0;
    glClearColor(1, 1, 1, 1);
}

void handleKeyboard(unsigned char key, int x, int y) {
    if (key == 32) {
        if (!ligth) {
            applyDark();
        }
        else if (ligth) {
            applyLigth();
        }
    }
    else {
        if (ligth) {
            applyLigth();
        }
    }

    display();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Base
    glBegin(GL_POLYGON);
  	    glColor3f(0.5f, 0, 1.0f);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.1, 0);
        glVertex3f(-0.5, 0.1, 0);        
  	glEnd();

    // Roof
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex3f(-0.5, 0.1, 0);
        glVertex3f(0.5, 0.1, 0);
        glVertex3f(0, 0.6, 0);
    glEnd();

    // Door
    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glVertex3f(-0.1, -0.5, 0);
        glVertex3f(0.1, -0.5, 0);
        glVertex3f(0.1, -0.1, 0);        
        glVertex3f(-0.1, -0.1, 0);        
    glEnd();

    // Window
    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glVertex3f(0.2, -0.2, 0);
        glVertex3f(0.4, -0.2, 0);
        glVertex3f(0.4, 0, 0);
        glVertex3f(0.2, 0, 0);
    glEnd();

    // Window detail
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex3f(0.2, -0.1, 0);
        glVertex3f(0.4, -0.1, 0);
        glVertex3f(0.3, -0.2, 0);
        glVertex3f(0.3, 0, 0);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Tarefa 1");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);

    glutMainLoop();

    return 0;

}