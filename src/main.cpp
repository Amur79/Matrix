//////////////////////////////
// Реализация вращения фигуры

#include <GL/glut.h>
static GLfloat xRot = 0.0f; // угол поворота по X
static GLfloat yRot = 0.0f; // угол поворота по Y

GLfloat light_position[] = {0.0f, 0.0f, 1.0f, 1.0f}; // позиция света
GLfloat ambient_light[] = {0.2f, 0.2f, 0.2f, 1.0f};  // окружающее
GLfloat diffuse_light[] = {0.8f, 0.8f, 0.8f, 1.0f};  // диффузионное
GLfloat specular_light[] = {1.0f, 1.0f, 1.0f, 1.0f}; // зеркальное

GLfloat material_ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat material_diffuse[] = {0.0f, 1.0f, 0.0f, 1.0f}; // материал будет зеленого цвета
GLfloat material_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat material_shininess = 50.f;

void initLighting() // инициализация освещения
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_shininess);
}

void display() // функция отрисовки
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // устанавливаем синий фон
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //  glTranslatef(0.0f, 0.0f, -0.5f); // перенос в позицию на экране
    glRotatef(xRot, 1.0f, 0.0f, 0.0f); // вращаем вокруг оси X
    glRotatef(yRot, 0.0f, 1.0f, 0.0f); // вращаем вокруг оси Y

    glLineWidth(3); // толщина линий
    // рисуем оси
    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); // ось X
    glVertex3f(1.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); // ось Y
    glVertex3f(0.0f, 1.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f); // ось Z
    glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();

    // Рисуем танк
    glBegin(GL_QUADS);

    // остов танка
    glNormal3f(0.0f, 0.0f, -1.0f); // нормаль к грани
    glVertex3f(-0.5, 0.1, 0.4);    // левая грань
    glVertex3f(-0.4, -0.1, 0.4);
    glVertex3f(-0.4, -0.1, -0.4);
    glVertex3f(-0.5, 0.1, -0.4);

    glNormal3f(0.0f, 0.0f, 1.0f); // нормаль к грани
    glVertex3f(0.5, 0.1, -0.4);   // правая грань
    glVertex3f(0.4, -0.1, -0.4);
    glVertex3f(0.4, -0.1, 0.4);
    glVertex3f(0.5, 0.1, 0.4);

    glNormal3f(-1.0f, 0.0f, 0.0f); // нормаль к грани
    glVertex3f(0.5, 0.1, -0.4);    // задняя грань
    glVertex3f(0.4, -0.1, -0.4);
    glVertex3f(-0.4, -0.1, -0.4);
    glVertex3f(-0.5, 0.1, -0.4);

    glNormal3f(1.0f, 0.0f, 0.0f); // нормаль к грани
    glVertex3f(0.5, 0.1, 0.4);    // передняя грань
    glVertex3f(0.4, -0.1, 0.4);
    glVertex3f(-0.4, -0.1, 0.4);
    glVertex3f(-0.5, 0.1, 0.4);

    glNormal3f(0.0f, -1.0f, 0.0f); // нормаль к грани
    glVertex3f(0.4, -0.1, -0.4);   // нижняя грань
    glVertex3f(0.4, -0.1, 0.4);
    glVertex3f(-0.4, -0.1, 0.4);
    glVertex3f(-0.4, -0.1, -0.4);

    glNormal3f(0.0f, 1.0f, 0.0f); // нормаль к грани
    glVertex3f(0.5, 0.1, -0.4);   // верхняя грань
    glVertex3f(0.5, 0.1, 0.4);
    glVertex3f(-0.5, 0.1, 0.4);
    glVertex3f(-0.5, 0.1, -0.4);

    // башня танка
    glNormal3f(0.0f, 0.0f, -1.0f); // нормаль к грани
    glVertex3f(-0.2, 0.3, 0.2);    // левая грань
    glVertex3f(-0.3, 0.1, 0.3);
    glVertex3f(-0.3, 0.1, -0.3);
    glVertex3f(-0.2, 0.3, -0.2);

    glNormal3f(0.0f, 0.0f, 1.0f); // нормаль к грани
    glVertex3f(0.2, 0.3, -0.2);   // правая грань
    glVertex3f(0.3, 0.1, -0.3);
    glVertex3f(0.3, 0.1, 0.3);
    glVertex3f(0.2, 0.3, 0.2);

    glNormal3f(-1.0f, 0.0f, 0.0f); // нормаль к грани
    glVertex3f(0.2, 0.3, -0.2);    // задняя грань
    glVertex3f(0.3, 0.1, -0.3);
    glVertex3f(-0.3, 0.1, -0.3);
    glVertex3f(-0.2, 0.3, -0.2);

    glNormal3f(1.0f, 0.0f, 0.0f); // нормаль к грани
    glVertex3f(0.2, 0.3, 0.2);    // передняя грань
    glVertex3f(0.3, 0.1, 0.3);
    glVertex3f(-0.3, 0.1, 0.3);
    glVertex3f(-0.2, 0.3, 0.2);

    glNormal3f(0.0f, -1.0f, 0.0f); // нормаль к грани
    glVertex3f(0.3, 0.1, -0.3);    // нижняя грань
    glVertex3f(0.3, 0.1, 0.3);
    glVertex3f(-0.3, 0.1, 0.3);
    glVertex3f(-0.3, 0.1, -0.3);

    glNormal3f(0.0f, 1.0f, 0.0f); // нормаль к грани
    glVertex3f(0.2, 0.3, -0.2);   // верхняя грань
    glVertex3f(0.2, 0.3, 0.2);
    glVertex3f(-0.2, 0.3, 0.2);
    glVertex3f(-0.2, 0.3, -0.2);

    // ствол танка
    glNormal3f(0.0f, 0.0f, -1.0f); // нормаль к грани
    glVertex3f(0.2, 0.25, -0.025); // левая грань
    glVertex3f(0.25, 0.2, -0.025);
    glVertex3f(0.25, 0.2, 0.025);
    glVertex3f(0.2, 0.25, 0.025);

    glNormal3f(0.0f, 0.0f, 1.0f);  // нормаль к грани
    glVertex3f(0.5, 0.25, -0.025); // правая грань
    glVertex3f(0.5, 0.2, -0.025);
    glVertex3f(0.5, 0.2, 0.025);
    glVertex3f(0.5, 0.25, 0.025);

    glNormal3f(-1.0f, 0.0f, 0.0f); // нормаль к грани
    glVertex3f(0.5, 0.25, -0.025); // задняя грань
    glVertex3f(0.5, 0.2, -0.025);
    glVertex3f(0.25, 0.2, -0.025);
    glVertex3f(0.2, 0.25, -0.025);

    glNormal3f(1.0f, 0.0f, 0.0f); // нормаль к грани
    glVertex3f(0.5, 0.25, 0.025); // передняя грань
    glVertex3f(0.5, 0.2, 0.025);
    glVertex3f(0.25, 0.2, 0.025);
    glVertex3f(0.2, 0.25, 0.025);

    glNormal3f(0.0f, -1.0f, 0.0f); // нормаль к грани
    glVertex3f(0.5, 0.2, -0.025);  // нижняя грань
    glVertex3f(0.5, 0.2, 0.025);
    glVertex3f(0.25, 0.2, 0.025);
    glVertex3f(0.25, 0.2, -0.025);

    glNormal3f(0.0f, 1.0f, 0.0f);  // нормаль к грани
    glVertex3f(0.5, 0.25, -0.025); // верхняя грань
    glVertex3f(0.5, 0.25, 0.025);
    glVertex3f(0.2, 0.25, 0.025);
    glVertex3f(0.2, 0.25, -0.025);

    glEnd(); // заканчиваем рисовать

    glutSwapBuffers();
}

// Управление клавишами по осям
void SpecialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_UP) // нажаклавиша Вверх
        xRot -= 5.0f;

    if (key == GLUT_KEY_DOWN) // нажаклавиша Вниз
        xRot += 5.0f;

    if (key == GLUT_KEY_LEFT) // нажаклавиша Влево
        yRot -= 5.0f;

    if (key == GLUT_KEY_RIGHT) // нажаклавиша Вправо
        yRot += 5.0f;

    xRot = (GLfloat)((const int)xRot % 360); // вычисляем угол поворота по X
    yRot = (GLfloat)((const int)yRot % 360); // вычисляем угол поворота по Y

    // обновляем окно
    glutPostRedisplay();
}

// основная функция
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    // позиция окна
    glutInitWindowPosition(250, 50);
    glutCreateWindow("Rotate Tank");

    initLighting(); // вызываем настройку освещенности

    glutSpecialFunc(SpecialKeys); // поворот по осям с помощью клавиш курсора
    glutDisplayFunc(display);
    glutIdleFunc(display); // вызываем display для обновления сцены
    glutMainLoop();

    return 0;
}