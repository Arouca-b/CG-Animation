#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float horizontal = 0, vertical = 0, escalar=1;

void display(void);
void keyboard(unsigned char key, int x, int y);
void Special_keyboard(GLint tecla, int x, int y);
void DesenhaTexto(char *string);
void Coqueiros(int pos);
void Mar();
void helice(int bol, int angle);
void Helicoptero();
void Areia();
void Sol();
void Barco();
void nuvens();
void nuvemModel1(float posx, float posy);
void nuvemModel2(float posx, float posy);
void nuvemModel3(float posx, float posy);
void Casco(float raio, float x, float y, int numSeg);

void Tronco(int posx);
void coco(int posx);
void folhas(int posx);
void arbusto(int posx);

void Circulo(float raio, float x, float y, int numSeg);

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  glutInitWindowSize (1720, 1080); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (100, 100); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutCreateWindow (argv[1]); //Cria uma nova janela com valor de retorno (não usado)
  // que a identifica, caso tenha mais de uma
  glClearColor(0.0, 0.5, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-15, 15,-15, 15, -1 ,1); //define as coordenadas do volume de recorte (clipping volume),
  glutDisplayFunc(display); //Função callback chamada para fazer o desenho
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutSpecialFunc(Special_keyboard); // Registra a função para tratamento das teclas NÂO ASCII
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  return 0;
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT); //Limpa a janela de visualização com a cor de fundo especificada

  //Céu
  glBegin(GL_POLYGON);
      glColor3ub(200, 250, 255);
      glVertex2f(-15, 0.0);

      glColor3ub(100, 150, 200);
      glVertex2f(-15, 15);

      glColor3ub(150, 200, 250);
      glVertex2f(15, 15);

      glColor3ub(200, 250, 255);
      glVertex2f(15, 0);
    glEnd();

  //Chamando as funções que vão desenhar o cenário e os objetos na tela
  Sol();
  nuvens();
  Mar();
  Areia();
  Barco();
  Helicoptero();
  Coqueiros(11);
  Coqueiros(-13);
  glFlush(); // Executa os comandos OpenGL para renderização
}
//Função responsável pela modelagem do mar
void Mar(){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(25, 124, 251);
    glVertex2f(-15.0, -15);
    glVertex2f(-15.0, 0);
    glVertex2f(15, 0);
    glVertex2f(15, -15);
  glEnd();
}

//Função responsável pela modelagem do sol
void Sol(){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub (255, 185, 0);
    Circulo(4.5, 0, 0, 180);
  glEnd();
}

//Função responsável pela modelagem do helicóptero
void Helicoptero(){
  //Estrutura/corpo do helicóptero
  glPushMatrix();
  glTranslated(-9.5 + horizontal, 9.590 + vertical, 0);
  glScalef(escalar, escalar, 0);
  glTranslated(+9.5 + horizontal, -9.590 + vertical, 0);
  glBegin(GL_POLYGON); //Iniciando construção de um polígono //Iniciando a definição do corpo do helicóptero como um polígono
    
    glColor3ub (158, 0, 0); //Fizemos alterações de cor, por isso, não  uma cor fixa (cor dinâmica)

    // Definimos os vértices do polígono que forma o corpo do helicóptero
    glVertex2f(- 5.832,  9.040);
    glVertex2f(- 5.811,  9.808);
    glVertex2f(- 5.975, 10.512);
    glVertex2f(- 6.238, 11.025);
    glVertex2f(- 6.722, 11.423);
    glVertex2f(- 7.270, 11.665);
    glVertex2f(- 8.082, 11.656);
    glVertex2f(- 8.977, 11.631);
    glVertex2f(- 9.555, 11.414);
    glVertex2f(-10.287, 11.071);
    glVertex2f(-10.754, 10.489);
    glVertex2f(-11.144,  9.724);
    glVertex2f(-11.752,  9.408);
    glVertex2f(-12.386,  9.276);
    glVertex2f(-12.906,  9.233);
    glVertex2f(-13.544,  9.136);
    glVertex2f(-13.880,  9.320);
    glVertex2f(-14.064,  9.840);
    glVertex2f(-14.461,  9.860);
    glVertex2f(-14.603,  9.404);
    glVertex2f(-14.351,  8.973);
    glVertex2f(-13.987,  8.559);
    glVertex2f(-13.370,  8.559);
    glVertex2f(-12.662,  8.559);
    glVertex2f(-11.954,  8.627);
    glVertex2f(-11.337,  8.627);
    glVertex2f(-10.812,  8.719);
    glVertex2f(-10.355,  8.627);
    glVertex2f(- 9.945,  8.424);
    glVertex2f(- 9.641,  8.091);
    glVertex2f(- 9.223,  7.860);
    glVertex2f(- 8.717,  7.687);
    glVertex2f(- 8.182,  7.687);
    glVertex2f(- 7.648,  7.745);
    glVertex2f(- 7.041,  7.817);
    glVertex2f(- 6.492,  8.005);
    glVertex2f(- 6.059,  8.424);
    glVertex2f(- 5.832,  9.040); //Fechando o polígono
  glEnd();

  //janela
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub (0, 0, 0);
    glVertex2f(-8.082, 11.656);
    glVertex2f(-8.082,  9.613);
    glVertex2f(-8.070,  9.590);
    glVertex2f(-8.058,  9.574);
    glVertex2f(-8.043,  9.565);
    glVertex2f(-8.025,  9.560);
    glVertex2f(-7.982,  9.556);
    glVertex2f(-5.819,  9.560);
    glVertex2f(-5.811,  9.808);
    glVertex2f(-5.975, 10.512);
    glVertex2f(-6.238, 11.025);
    glVertex2f(-6.722, 11.423);
    glVertex2f(-7.270, 11.665); //Fechando o polígono
  glEnd();

  //base suporte hélice
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-8.334, 11.656);
    glVertex2f(-8.334, 11.749);
    glVertex2f(-8.297, 11.769);
    glVertex2f(-8.182, 11.770);
    glVertex2f(-7.982, 11.769);
    glVertex2f(-7.883, 11.770);
    glVertex2f(-7.853, 11.742);
    glVertex2f(-7.853, 11.656); //Fechando o polígono
  glEnd();

  //suporte da hélice
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-8.182, 11.770);
    glVertex2f(-8.182, 12.056);
    glVertex2f(-8.142, 12.094);
    glVertex2f(-8.082, 12.112);
    glVertex2f(-8.025, 12.096);
    glVertex2f(-7.982, 12.056);
    glVertex2f(-7.982, 11.769); //Fechando o polígono
  glEnd();

//base circular hélice
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-8.182, 12.056);
    glVertex2f(-8.240, 12.064);
    glVertex2f(-8.264, 12.081);
    glVertex2f(-8.253, 12.113);
    glVertex2f(-8.223, 12.137);
    glVertex2f(-8.182, 12.156);
    glVertex2f(-8.121, 12.166);
    glVertex2f(-8.057, 12.166);
    glVertex2f(-7.982, 12.156);
    glVertex2f(-7.944, 12.137);
    glVertex2f(-7.913, 12.115);
    glVertex2f(-7.924, 12.065);
    glVertex2f(-7.924, 12.065);
    glVertex2f(-8.182, 12.056);
    glVertex2f(-8.142, 12.094);
    glVertex2f(-8.082, 12.112);
    glVertex2f(-8.025, 12.096);
    glVertex2f(-7.982, 12.056); //Fechando o polígono
  glEnd();

  //hélice direita
  helice(0, 0);
  //hélice esquerda
  helice(1, 0);


  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-14.233, 9.053);
    glVertex2f(-14.246, 9.140);
    glVertex2f(-14.238, 9.215);
    glVertex2f(-14.168, 9.262);
    glVertex2f(-14.067, 9.275);
    glVertex2f(-14.001, 9.258);
    glVertex2f(-13.941, 9.213);
    glVertex2f(-13.918, 9.145);
    glVertex2f(-13.941, 9.067);
    glVertex2f(-13.996, 9.016);
    glVertex2f(-14.068, 8.983);
    glVertex2f(-14.147, 8.994); //Fechando o polígono
  glEnd();

  //hélices traseiras
  glPushMatrix();
    glTranslatef (-12, 4.2, 0.0);
    glScaled(0.27, 0.4, 0);
    helice(0, 45);
  glPopMatrix();

  glPushMatrix();
    glTranslatef (-12, 4.2, 0.0);
    glScaled(0.27, 0.4, 0);
    helice(1, 45);
  glPopMatrix();
  
  //fim hélices traseiras

  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-8.809, 8.134);
    glVertex2f(-8.799, 8.184);
    glVertex2f(-8.765, 8.224);
    glVertex2f(-8.710, 8.230);
    glVertex2f(-8.644, 8.222);
    glVertex2f(-8.616, 8.185);
    glVertex2f(-8.611, 8.135);
    glVertex2f(-8.985, 7.348);
    glVertex2f(-9.191, 7.349); //Fechando o polígono
  glEnd();

  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-7.715, 7.355);
    glVertex2f(-7.917, 7.356);
    glVertex2f(-7.688, 8.068);
    glVertex2f(-7.680, 8.141);
    glVertex2f(-7.630, 8.208);
    glVertex2f(-7.559, 8.229);
    glVertex2f(-7.489, 8.197);
    glVertex2f(-7.468, 8.138);
    glVertex2f(-7.482, 8.056); //Fechando o polígono
  glEnd();

  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-9.782, 7.347);
    glVertex2f(-7.075, 7.350);
    glVertex2f(-7.015, 7.332);
    glVertex2f(-6.974, 7.295);
    glVertex2f(-6.951, 7.244);
    glVertex2f(-6.974, 7.198);
    glVertex2f(-7.016, 7.168);
    glVertex2f(-7.072, 7.145);
    glVertex2f(-9.790, 7.144);
    glVertex2f(-9.829, 7.164);
    glVertex2f(-9.874, 7.191);
    glVertex2f(-9.897, 7.246);
    glVertex2f(-9.897, 7.246);
    glVertex2f(-9.882, 7.296);
    glVertex2f(-9.832, 7.329); //Fechando o polígono
  glEnd();
  glPopMatrix();
}

// Função responsável pela modelagem das hélices
void helice(int bol, int angle){
  glPushMatrix();
  glTranslatef (-7.986, 12.062, 0.0);
  (bol==1)?glRotatef (180+angle, 0.0, 0.0, 1.0) : glRotatef (angle, 0.0, 0.0, 1.0);
  
  glTranslatef (7.986, -12.062, 0.0);

  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glVertex2f(-7.986, 12.137);
    glVertex2f(-7.986, 12.062);
    glVertex2f(-7.986, 11.987);
    glVertex2f(-2.915, 11.955);
    glVertex2f(-2.861, 11.958);
    glVertex2f(-2.795, 11.971);
    glVertex2f(-2.707, 12.011);
    glVertex2f(-2.667, 12.045);
    glVertex2f(-2.617, 12.082);
    glVertex2f(-2.584, 12.113);
    glVertex2f(-2.566, 12.144);
    glVertex2f(-2.551, 12.200);
    glVertex2f(-2.548, 12.241);
    glVertex2f(-2.546, 12.283);
    glVertex2f(-2.544, 12.320);
    glVertex2f(-2.550, 12.376);
    glVertex2f(-2.557, 12.440);
    glVertex2f(-2.577, 12.498);
    glVertex2f(-2.599, 12.544);
    glVertex2f(-2.635, 12.583);
    glVertex2f(-2.670, 12.609);
    glVertex2f(-2.707, 12.630);
    glVertex2f(-2.766, 12.652);
    glVertex2f(-2.815, 12.666);
    glVertex2f(-2.898, 12.670); //Fechando o polígono
  glEnd();
  glPopMatrix();
}

// Função que esenha os coqueiros, chamando funções menores que desenham cada parte do coqueiro
void Coqueiros(int pos) {
    Tronco(pos);
    coco(pos);
    folhas(pos);
    arbusto(pos);
}

//Função responsável por chamar as funções que desenham as nuvens no céu
void nuvens(){
  nuvemModel1(0, 0);
  nuvemModel2(0, 0);
  nuvemModel3(-18, 4);
  nuvemModel1(10, 3);
  nuvemModel2(23, 2.5);
  nuvemModel3(-5, -1);
  nuvemModel3(-10, 3);
}

//Função responsável pela modelagem do barco
void Barco() {
    //Parte superior do barco
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
        glColor3ub(0, 0, 0);
        glVertex2d(-2.312, -0.677);
        glVertex2d(-2.380, 0.407);
        glVertex2d(-1.328, 0.444);
        glVertex2d(-1.273, -0.635);
    glEnd();

    //Estrutura do barco
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
        glColor3ub(232, 247, 253);
        glVertex2d(-4.5, -3);
        glVertex2d(-4.643, -0.708);
        glVertex2d(-0.992, -0.539);
        glVertex2d(-0.895, -2.764);
    glEnd();

    //Parte inferior do barco
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
        glColor3ub(233, 54, 62);
        glVertex2d(-3.017, -2.772);
        glVertex2d(-3.120, -1.578);
        glVertex2d(-2.153, -1.496);
        glVertex2d(-2.042, -2.708);
    glEnd();

    //Janelas (Círculos)
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
        glColor3ub(179, 232, 255);
        Circulo(0.35, -3.798, -1.955, 360);
    glEnd();

    glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(179, 232, 255);
        Circulo(0.35, -1.485, -1.699, 360);
    glEnd();

    //Casco do barco
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
        glColor3ub(0, 0, 0); // Cor do casco do barco
        Casco(3.0, -2.0, -2.5, 100);
    glEnd();

    //Bolhas de ar decorativas
    glColor3ub(255, 255, 255); // Cor branca para as bolhas
    Circulo(0.15, -2.1, 0.7, 100); // Bolha 1
    Circulo(0.1, -1.7, 1.0, 100);  // Bolha 2
    Circulo(0.1, -2.3, 1.3, 100);  // Bolha 3
    Circulo(0.12, -1.5, 1.5, 100); // Bolha 4
    Circulo(0.08, -2.0, 1.7, 100); // Bolha 5
}

//Função que desenha um círculo ou um semi-círculo
void Circulo(float raio, float x, float y, int numSeg) {
    glBegin(GL_POLYGON); //Iniciando construção de um polígono

    //Se for um semi-círculo, desenha de 0 a pi (180 graus), caso contrário, desenha de 0 a 2pi (360 graus)
    float anguloMax = 2.0f * M_PI;

    for (int i = 0; i <= numSeg; i++) {
        float angulo = anguloMax * i / numSeg; // Ângulo em radianos
        float dx = raio * cos(angulo); // Coordenada x
        float dy = raio * sin(angulo); // Coordenada y

        //Inverte a coordenada y para que o semi-círculo fique virado para cima
        glVertex2f(x + dx, y + dy); // Ponto na borda do círculo ou semi-círculo
    }

    glEnd();
}

//Função que desenha o semi-círculo que forma o casco do barco
void Casco(float raio, float x, float y, int numSeg) {
    glBegin(GL_POLYGON); //Iniciando construção de um polígono

    //Como é um semi-círculo, desenha de 0 a pi (180 graus)
    float anguloMax = M_PI;

    for (int i = 0; i <= numSeg; i++) {
        float angulo = anguloMax * i / numSeg; // Ângulo em radianos
        float dx = raio * cos(angulo); // Coordenada x
        float dy = raio * sin(angulo); // Coordenada y

        // Para inverter a boca do semi-círculo, inverta a coordenada y
        glVertex2f(x + dx, y + (-dy)); // Inverte dy
    }

    glEnd();
}

// Função responsável pela modelagem do tronco do coqueiro
void Tronco(int posx) {
    //Formando o tronco, utilizando círculos
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(115, 97, 84); //Marrom
        Circulo(0.8, 1 + posx, -6 + 2, 360);
        Circulo(0.8, 1 + posx, -7 + 2, 360);
        Circulo(0.8, 1 + posx, -8 + 2, 360);
        Circulo(0.8, 1 + posx, -9 + 2, 360);
        Circulo(0.8, 1 + posx, -10 + 2, 360);
        Circulo(0.8, 1 + posx, -11 + 2, 360);
        Circulo(0.8, 1 + posx, -12 + 2, 360);
        Circulo(0.8, 1 + posx, -13 + 2, 360);
        Circulo(0.8, 1 + posx, -14 + 2, 360);
        Circulo(0.8, 1 + posx, -15 + 2, 360);
        Circulo(0.8, 1 + posx, -16 + 2, 360);
    glEnd();
}

// Função responsável pela modelagem dos cocos pendurados
void coco(int posx) {
    //Formando os cocos através de círculos
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(64, 171, 81);//Verde um pouco mais claro
        Circulo(0.5, posx + 1 - 0.5, -6.5 + 1.8, 360);
        Circulo(0.5, posx + 1 + 0.5, -6.5 + 1.8, 360);
        Circulo(0.5, posx + 1, -7.0 + 1.8, 360);
    glEnd();
}

// Função responsável pela modelagem da folhagem dos coqueiros
void folhas(int posx){
    //Desenhando cada parte que forma as folhas
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(50, 130, 20);//Verde escuro
        glVertex2f( 0.9665 + posx, -6.2274 + 2);
        glVertex2f( 0.2737 + posx, -6.5353 + 2);
        glVertex2f(-0.3934 + posx, -7.2923 + 2);
        glVertex2f(-0.9708 + posx, -8.2289 + 2);
        glVertex2f(-1.3428 + posx, -9.0757 + 2);
        glVertex2f(-1.4583 + posx, -8.3829 + 2);
        glVertex2f(-1.3428 + posx, -7.1640 + 2);
        glVertex2f(-0.6243 + posx, -5.8296 + 2);
        glVertex2f(-0.2009 + posx, -5.3036 + 2);
        glVertex2f(-0.9066 + posx, -5.3164 + 2);
        glVertex2f(-1.8047 + posx, -5.6372 + 2);
        glVertex2f(-2.4334 + posx, -6.0991 + 2);
        glVertex2f(-2.9081 + posx, -6.5866 + 2);
        glVertex2f(-2.7285 + posx, -5.6500 + 2);
        glVertex2f(-1.9459 + posx, -4.7904 + 2);
        glVertex2f(-1.0221 + posx, -4.4183 + 2);
        glVertex2f(-0.1240 + posx, -4.2900 + 2);
        glVertex2f(-1.3942 + posx, -3.7896 + 2);
        glVertex2f(-2.2795 + posx, -3.5458 + 2);
        glVertex2f(-2.9723 + posx, -3.5458 + 2);
        glVertex2f(-2.3401 + posx, -3.2531 + 2);
        glVertex2f(-1.5616 + posx, -3.0711 + 2);
        glVertex2f(-1.0000 + posx, -3.0000 + 2);
        glVertex2f(-0.5000 + posx, -3.0000 + 2);
        glVertex2f( 0.0408 + posx, -3.1419 + 2);
        glVertex2f( 0.5867 + posx, -3.4249 + 2);
        glVertex2f( 0.8092 + posx, -3.5665 + 2);
        glVertex2f( 1.5674 + posx, -2.7425 + 2);
        glVertex2f( 2.3105 + posx, -2.3482 + 2);
        glVertex2f( 3.2030 + posx, -2.2637 + 2);
        glVertex2f( 3.0000 + posx, -2.5000 + 2);
        glVertex2f( 2.4363 + posx, -2.9785 + 2);
        glVertex2f( 2.0846 + posx, -3.5378 + 2);
        glVertex2f( 1.9463 + posx, -3.8433 + 2);
        glVertex2f( 2.0731 + posx, -3.8664 + 2);
        glVertex2f( 2.5458 + posx, -3.5781 + 2);
        glVertex2f( 3.3010 + posx, -3.3014 + 2);
        glVertex2f( 3.9064 + posx, -3.2264 + 2);
        glVertex2f( 4.4368 + posx, -3.3014 + 2);
        glVertex2f( 4.6904 + posx, -3.3936 + 2);
        glVertex2f( 4.2984 + posx, -3.6012 + 2);
        glVertex2f( 3.1339 + posx, -4.1546 + 2);
        glVertex2f( 2.4420 + posx, -4.6621 + 2);
        glVertex2f( 3.0128 + posx, -4.6677 + 2);
        glVertex2f( 4.0330 + posx, -5.3036 + 2);
        glVertex2f( 4.8284 + posx, -6.1632 + 2);
        glVertex2f( 5.1107 + posx, -7.1896 + 2);
        glVertex2f( 5.0466 + posx, -7.6772 + 2);
        glVertex2f( 4.6616 + posx, -7.2153 + 2);
        glVertex2f( 3.9560 + posx, -6.5866 + 2);
        glVertex2f( 3.0000 + posx, -6.0000 + 2);
        glVertex2f( 2.2752 + posx, -5.8681 + 2);
        glVertex2f( 1.6594 + posx, -5.9194 + 2);
        glVertex2f( 1.4290 + posx, -5.8776 + 2);
        glVertex2f( 1.1906 + posx, -5.9607 + 2);
        glVertex2f( 0.9800 + posx, -6.1000 + 2);
    glEnd();
}

//Função responsável pela modelagem dos arbustos que ficam debaixo dos coqueiros
void arbusto(int posx) {
    //Desenhando cada detalhe dos arbustos
    glBegin(GL_POLYGON); //Iniciando construção de um polígono
        glColor3ub(1, 119, 2);
        glVertex2f(-4.2120 + posx, -16.6907);
        glVertex2f(-4.0529 + posx, -16.2670);
        glVertex2f(-3.2217 + posx, -15.6197);
        glVertex2f(-3.0000 + posx, -15.5000);
        glVertex2f(-3.2762 + posx, -15.3813);
        glVertex2f(-3.2830 + posx, -15.1973);
        glVertex2f(-2.7515 + posx, -14.7749);
        glVertex2f(-2.4449 + posx, -14.6658);
        glVertex2f(-2.0633 + posx, -14.5841);
        glVertex2f(-2.0581 + posx, -14.5037);
        glVertex2f(-2.4710 + posx, -14.3525);
        glVertex2f(-2.2950 + posx, -14.2081);
        glVertex2f(-1.9565 + posx, -14.0388);
        glVertex2f(-1.4601 + posx, -13.7997);
        glVertex2f(-1.6316 + posx, -13.5560);
        glVertex2f(-1.8087 + posx, -13.4370);
        glVertex2f(-1.4799 + posx, -13.2932);
        glVertex2f(-1.3018 + posx, -13.3069);
        glVertex2f(-0.8459 + posx, -13.0138);
        glVertex2f(-0.6551 + posx, -13.2487);
        glVertex2f(-0.3396 + posx, -12.6616);
        glVertex2f(0.2328 + posx, -13.1606);
        glVertex2f(0.3273 + posx, -12.8328);
        glVertex2f(0.4702 + posx, -12.8016);
        glVertex2f(0.9392 + posx, -12.5336);
        glVertex2f(1.0687 + posx, -12.5291);
        glVertex2f(0.9169 + posx, -12.9222);
        glVertex2f(1.0167 + posx, -12.9333);
        glVertex2f(1.2883 + posx, -12.7508);
        glVertex2f(1.5093 + posx, -12.6981);
        glVertex2f(1.5924 + posx, -12.7042);
        glVertex2f(1.6106 + posx, -12.7488);
        glVertex2f(1.5194 + posx, -13.3326);
        glVertex2f(1.6466 + posx, -13.4359);
        glVertex2f(2.4561 + posx, -13.1862);
        glVertex2f(2.6455 + posx, -13.2379);
        glVertex2f(2.5938 + posx, -13.5737);
        glVertex2f(2.7661 + posx, -13.8751);
        glVertex2f(3.0158 + posx, -13.7373);
        glVertex2f(3.4636 + posx, -13.6081);
        glVertex2f(4.1870 + posx, -13.7976);
        glVertex2f(3.7133 + posx, -14.2454);
        glVertex2f(3.8167 + posx, -14.3746);
        glVertex2f(4.1870 + posx, -14.4607);
        glVertex2f(4.9017 + posx, -14.6760);
        glVertex2f(5.3409 + posx, -14.9688);
    glEnd();
}

//Função responsável pela modelagem de uma nuvem
void nuvemModel1(float posx, float posy){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(255, 255, 255);
    Circulo(1.2, -6.6 + posx, 12.5 - posy, 360);
    Circulo(1.2, -5.7 + posx, 13.5 - posy, 360);
    Circulo(1.2, -4.9 + posx, 12.5 - posy, 360);
    Circulo(1.2, -4.0 + posx, 13.5 - posy, 360);
    Circulo(1.2, -3.2 + posx, 12.5 - posy, 360);
  glEnd();
}

//Função responsável pela modelagem de uma nuvem
void nuvemModel2(float posx, float posy){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(255, 255, 255);
    Circulo(.7, -10 + posx, 3.5 + posy, 360);
    Circulo(.7, -11.5 + posx, 4 + posy, 360);
    Circulo(.7, -12 + posx, 3.5 + posy, 360);
    Circulo(.7, -10.5 + posx, 4 + posy, 360);
    Circulo(.7, -11 + posx, 3.5 + posy, 360);
  glEnd();
}

//Função responsável pela modelagem de uma nuvem
void nuvemModel3(float posx, float posy){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub(255, 255, 255);
    Circulo(.3, 12.3 + posx, 2.3 + posy, 360);
    Circulo(.2, 12.45 + posx, 2.6 + posy, 360);
    Circulo(.3, 12.6 + posx, 2.3 + posy, 360);
    Circulo(.2, 12.75 + posx, 2.6 + posy, 360);
    Circulo(.3, 13 + posx, 2.3 + posy, 360);
  glEnd();
}

//Função responsável pela modelagem da areia
void Areia(){
  glBegin(GL_POLYGON); //Iniciando construção de um polígono
    glColor3ub (206, 193, 174);
    glVertex2f(-17.139, -15.042);
    glVertex2f(-15.003, -13.729);
    glVertex2f(-14.390, -13.249);
    glVertex2f(-13.545, -13.066);
    glVertex2f(-12.932, -12.785);
    glVertex2f(-12.270, -12.570);
    glVertex2f(-11.789, -12.271);
    glVertex2f(-11.000, -12.000);
    glVertex2f(-10.249, -11.791);
    glVertex2f(- 9.636, -11.377);
    glVertex2f(- 8.962, -11.303);
    glVertex2f(- 8.242, -11.043);
    glVertex2f(- 7.807, -10.434);
    glVertex2f(- 7.043, -10.179);
    glVertex2f(- 6.279, -10.154);
    glVertex2f(- 5.482, -10.064);
    glVertex2f(- 4.775, -10.050);
    glVertex2f(- 4.071, -10.145);
    glVertex2f(- 3.446, -10.104);
    glVertex2f(- 2.997, - 9.902);
    glVertex2f(- 2.383, - 9.499);
    glVertex2f(- 1.578, - 9.245);
    glVertex2f(- 0.858, - 9.140);
    glVertex2f(- 0.082, - 8.943);
    glVertex2f(  0.729, - 8.984);
    glVertex2f(  1.473, - 9.166);
    glVertex2f(  1.998, - 9.470);
    glVertex2f(  2.902, - 9.688);
    glVertex2f(  3.489, -10.241);
    glVertex2f(  4.242, -10.458);
    glVertex2f(  5.030, -10.726);
    glVertex2f(  5.582, -10.877);
    glVertex2f(  6.202, -10.944);
    glVertex2f(  7.057, -10.877);
    glVertex2f(  7.917, -10.943);
    glVertex2f(  8.715, -11.011);
    glVertex2f(  9.318, -11.397);
    glVertex2f( 10.055, -11.732);
    glVertex2f( 10.917, -11.943);
    glVertex2f( 11.529, -12.234);
    glVertex2f( 11.981, -12.502);
    glVertex2f( 12.415, -12.478);
    glVertex2f( 12.965, -12.675);
    glVertex2f( 13.691, -12.910);
    glVertex2f( 14.183, -13.087);
    glVertex2f( 14.634, -13.323);
    glVertex2f( 15.027, -13.794);
    glVertex2f( 15.917, -14.943);
  glEnd();
}

//Função que trata a entrada de teclas comuns
void keyboard(unsigned char key, int x, int y) {
    //Exibe uma mensagem indicando que uma tecla foi pressionada
    printf("*** Tratamento de teclas comuns\n");
    printf(">>> Tecla pressionada: %c\n", key);

    switch (key) {
      //Se a tecla pressionada for a tecla 'ESC' (código 27), encerra o programa
      case 27:
        exit(0);
        break;

      //Se a tecla pressionada for a barra de espaço (código 32)
      case 32:
        //Ocorre a atualização da tela, através do redrawing (re-renderização)
        glutPostRedisplay();
        break;
             
      case 43:
        escalar += 0.1;
        glutPostRedisplay();
        break;

      case 45:
        escalar -= 0.1;
        glutPostRedisplay();
        break;
    }
}

//Função que trata a entrada de teclas especiais (teclas de função e direcionais)
void Special_keyboard(GLint tecla, int x, int y) {
    //O parâmetro 'tecla' é o código da tecla especial pressionada
    switch (tecla) {
        /*Movimentação horizontal para a direita.
          Essa função move o helicóptero para direita, através da seta para a direita*/
        case GLUT_KEY_RIGHT:
            horizontal += 0.8;
            glutPostRedisplay(); // Atualiza a tela
            break;

        /*Movimentação horizontal para a esquerda
          Essa função move o helicóptero para direita, através da seta para a esquerda*/
        case GLUT_KEY_LEFT:
            horizontal -= 0.8; // Diminui a posição horizontal
            glutPostRedisplay(); // Atualiza a tela
            break;

        /*Movimentação vertical para cima
          Essa função move o helicóptero para cima, usando a seta para cima*/
        case GLUT_KEY_UP:
            vertical += 0.8; // Aumenta a posição vertical
            glutPostRedisplay(); // Atualiza a tela
            break;

        /*Movimentação vertical para baixo
           Essa função move o helicóptero para baixo, usando a seta para baixo*/
        case GLUT_KEY_DOWN:
            vertical -= 0.8; // Diminui a posição vertical
            glutPostRedisplay(); // Atualiza a tela
            break;
    }
}

void DesenhaTexto(char *string) {
  	glColor3ub(0,0,0);
  	glPushMatrix();
        // Posição no universo onde o texto será colocado
        glRasterPos2f(5,-14.8);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();
	glColor3ub(255,255,255);
}