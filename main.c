#include <GL/glut.h> //O arquivo glut.h inclui, além dos protótipos das funções GLUT, os arquivos gl.h e glu.h,
#include <stdlib.h>
#include <stdio.h>

int R = 158, G=0, B = 0;
float horizontal = 0, vertical = 0;

void display(void);
void keyboard(unsigned char key, int x, int y);
void Special_keyboard(GLint tecla, int x, int y);
void DesenhaTexto(char *string);
void Coqueiros();
void Mar();
void Helicoptero();
void Areia();
void Sol();

int main(int argc, char** argv){
  glutInit(&argc, argv); //Estabelece contato com sistema de janelas
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Cores dos pixels serão expressos em RGB
  glutInitWindowSize (900, 700); //Posição inicial do canto superior esquerdo da janela a ser criada
  glutInitWindowPosition (400, 100); //Estabelece o tamanho (em pixels) da janela a ser criada
  glutCreateWindow (argv[1]); //Cria uma nova janela com valor de retorno (não usado)
  // que a identifica, caso tenha mais de uma
  glClearColor(0.0, 0.5, 1.0, 0.0); //selecionar cor de fundo (Branco)
  glOrtho (-15, 15,-15, 15, -1 ,1); //define as coordenadas do volume de recorte (clipping volume),
  glutDisplayFunc(display); //Função callback chamada para fazer o desenho
  glutKeyboardFunc(keyboard); //Chamada sempre que uma tecla for precionada
  glutSpecialFunc(Special_keyboard); // Registra a função para tratamento das teclas NÂO ASCII
  glutMainLoop(); //Depois de registradas as callbacks, o controle é entregue ao sistema de janelas
  printf("\nTestando... \n");
  return 0;
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela de visualização com a cor de fundo especificada
  DesenhaTexto("Exemplo de texto para a atividade 2");

  // Primeiro polígono (retângulo)
  glBegin(GL_POLYGON);
      // Defina a cor do primeiro vértice
      glColor3ub(200, 250, 255);  // Azul
      glVertex2f(-15, 0.0);

      // Defina a cor do segundo vértice
      glColor3ub(100, 150, 200);  // Azul mais claro
      glVertex2f(-15, 15);

      // Defina a cor do terceiro vértice
      glColor3ub(150, 200, 250);  // Ainda mais claro
      glVertex2f(15, 15);

      // Defina a cor do quarto vértice
      glColor3ub(200, 250, 255);  // Muito claro
      glVertex2f(15, 0);
    glEnd();

  Sol();
  Mar();
  Areia();
  Coqueiros();
  Helicoptero();
  glFlush(); // Executa os comandos OpenGL para renderização
}

//Função que desenha os coqueiros
void Coqueiros(){
    //Caule
    glBegin(GL_POLYGON);
      glColor3ub (115,97,84);
      glVertex2f(13.7803600150306, -14.8764401474643);
      glVertex2f(13.7039502039936, -14.0741371531182);
      glVertex2f(13.5277067453969, -12.6378766696399);
      glVertex2f(13.3792085070861, -11.0177447937042);
      glVertex2f(13.0705679965504, -9.8579789472445);
      glVertex2f(12.7369802609057, -8.6718892523558);
      glVertex2f(12.4898782345021, -7.337538345606);
      glVertex2f(12.1933558028179, -5.9537670349025);
      glVertex2f(11.8968333711337, -4.7553222390253);
      glVertex2f(12.615636188807, -4.1030371320075);
      glVertex2f(13.2929598203136, -4.6688365321064);
      glVertex2f(13.5129256764009, -6.0511072096564);
      glVertex2f(13.7130332651996, -7.0780812248491);
      glVertex2f(13.9354250889627, -8.1282648088651);
      glVertex2f(14.2383010146873, -9.280954450598);
      glVertex2f(14.6399703891976, -10.4255687740677);
      glVertex2f(14.7632168774145, -11.649468590566);
      glVertex2f(14.8744127892961, -12.8355582854547);
      glVertex2f(15.1175317081792, -14.2460592233352);
      glVertex2f(15.3276586885311, -15.1820793834057);
      glVertex2f(14.7927900112717, -15.3157965491301);
      glVertex2f(14.2579213340123, -15.1629769311594);
    glEnd();

    //Folha 2
    glBegin(GL_POLYGON);
      glColor3ub (0, 151, 74);
      glVertex2f(12.615636188807, -4.1030371320075);
      glVertex2f(12.0026179586968, -3.5007000808097);
      glVertex2f(11.6385040409938, -2.8973113191036);
      glVertex2f(11.139147811001, -2.0546477036175);
      glVertex2f(11.5804731109728, -1.9121329794533);
      glVertex2f(11.251626560187, -1.6061790688559);
      glVertex2f(11.0379450195017, -1.0105570842821);
      glVertex2f(11.2010470547684, -0.8819574060825);
      glVertex2f(10.9908963554824, -0.8505916309119);
      glVertex2f(10.916009714903, -0.3905003063585);
      glVertex2f(11.2963754728916, -0.2115046603466);
      glVertex2f(10.7033187471483, 0.1919875438553);
      glVertex2f(11.2624429842079, 0.1757023723394);
      glVertex2f(11.5501476887142, 0.0779913432439);
      glVertex2f(11.7509981428035, -0.1120023244417);
      glVertex2f(11.9341844318289, -0.4068034450673);
      glVertex2f(11.827248451105, -0.6700304674736);
      glVertex2f(12.057572101895, -0.6618046230234);
      glVertex2f(12.1689842229354, -0.9534028527637);
      glVertex2f(12.3426927237694, -1.4039592647039);
      glVertex2f(12.3043474420272, -1.6653576459474);
      glVertex2f(12.3043474420272, -1.6653576459474);
      glVertex2f(12.4621173180928, -1.6753787899691);
      glVertex2f(12.90724535148, -2.5547780518282);
      glVertex2f(14.1266240800897, -1.4659032965679);
      glVertex2f(14.7060504267952, -1.2437898696282);
      glVertex2f(15.3917049370632, -1.1665330254753);
      glVertex2f(15.1406201868242, -1.7652735676605);
      glVertex2f(14.7639930614657, -1.7363022511032);
      glVertex2f(14.8122785903578, -1.9777298890811);
      glVertex2f(14.5998222632325, -2.3446998988076);
      glVertex2f(14.1459382916466, -2.3736712153649);
      glVertex2f(15.1116488694889, -2.9530975465119);
      glVertex2f(14.8895354365852, -3.3973244003913);
      glVertex2f(15.478618889069, -3.2428107120855);
      glVertex2f(16.2705015628998, -4.5561770626854);
      glVertex2f(15.1309630810458, -4.1892070529589);
      glVertex2f(15, -4);
      glVertex2f(14.7446788499089, -4.1505786308825);
      glVertex2f(14.0311121515416, -4.1426457059904);
      glVertex2f(12.615636188807, -4.1030371320075);
      glVertex2f(12.0026179586968, -3.5007000808097);
      glVertex2f(11.6385040409938, -2.8973113191036);
    glEnd();

    //Folha 3
    glBegin(GL_POLYGON);
      glColor3ub (0, 151, 74);
      glVertex2f(11.4530497112561, -4.0895625441295);
      glVertex2f(10.7750338932979, -3.6567488984923);
      glVertex2f(10.150838605807, -3.0845699003227);
      glVertex2f(9.6204051018847, -2.9334408658706);
      glVertex2f(9, -3);
      glVertex2f(8.3704326904685, -3.1343076890937);
      glVertex2f(7.8492224044029, -3.2524216274682);
      glVertex2f(7.1105300945526, -3.4622773916771);
      glVertex2f(6.7711874825186, -4.6048238251301);
      glVertex2f(7.218009417477, -4.0548394358671);
      glVertex2f(7.5721959052185, -3.9960574402244);
      glVertex2f(7.8662279850013, -4.0651976948806);
      glVertex2f(8.7334447039381, -4.1198447011011);
      glVertex2f(8.9406489924354, -4.1239075301783);
      glVertex2f(9.2, -4.4);
      glVertex2f(10.188246631937293, -4.713112570388626);
      glVertex2f(10.480422455826, -4.7200691374373);
      glVertex2f(10.5, -4.5);
    glEnd();

    //Folha 4
    glBegin(GL_POLYGON);
      glColor3ub (0, 151, 74);
      glVertex2f(12.615636188807, -4.1030371320075);
      glVertex2f(12.0026179586968, -3.5007000808097);
      glVertex2f(11.6385040409938, -2.8973113191036);
      glVertex2f(11.139147811001, -2.0546477036175);
      glVertex2f(10.51495252351, -1.1599678155705);
      glVertex2f(9.9843865291427, -0.8686766892296);
      glVertex2f(9.1417228910299, -0.7022246170348);
      glVertex2f(8.7672057185353, -0.8582734347174);
      glVertex2f(9.7139019045633, -1.2223873426435);
      glVertex2f(9.0793033622808, -1.3056133787409);
      glVertex2f(9.3705944964432, -2.0338411945931);
      glVertex2f(9.6202726114396, -2.0130346855688);
      glVertex2f(9.5058368087329, -2.3147290664218);
      glVertex2f(10.0364028031003, -2.8244885375184);
      glVertex2f(10.2340646441391, -2.7932787739819);
      glVertex2f(10.150838605807, -3.0845699003227);
      glVertex2f(10.7750338932979, -3.6567488984923);
      glVertex2f(11.4530497112561, -4.0895625441295);
    glEnd();

    //folha 5
    glBegin(GL_POLYGON);
      glColor3ub (0, 151, 74);
      glVertex2f(12.615636188807, -4.1030371320075);
      glVertex2f(11.8968333711337, -4.7553222390253);
      glVertex2f(11.1495510657925, -5.664577019342);
      glVertex2f(10.8257653310147, -6.2792190226907);
      glVertex2f(10.4605185231622, -6.3246543924754);
      glVertex2f(10.6277798467268, -6.4592643709282);
      glVertex2f(9.9563850821554, -7.0709795844457);
      glVertex2f(9.8220154521728, -6.8191737132715);
      glVertex2f(9.7673696634755, -7.0779361514944);
      glVertex2f(8.7134543780228, -7.3705211829738);
      glVertex2f(8.7343240797291, -6.0835562789731);
      glVertex2f(8.9865019673727, -6.177618733241);
      glVertex2f(8.9360645295571, -5.8192067311243);
      glVertex2f(9.5621555807472, -5.1444197274051);
      glVertex2f(10.1882466319373, -4.7131125703886);
      glVertex2f(10.480422455826, -4.7200691374373);
      glVertex2f(10.5, -4.5);
      glVertex2f(11.4530497112561, -4.0895625441295);
    glEnd();

    //folha 6
    glBegin(GL_POLYGON);
      glColor3ub (0, 151, 74);
      glVertex2f(12.615636188807, -4.1030371320075);
      glVertex2f(14.0311121515416, -4.1426457059904);
      glVertex2f(15, -4.5);
      glVertex2f(15.7231305413822, -5.2565577827254);
      glVertex2f(15.7231305413822, -5.2565577827254);
      glVertex2f(16.033333912853, -5.8205638975279);
      glVertex2f(16.1602352920911, -6.6524729168617);
      glVertex2f(16.1038346790964, -7.4702817833254);
      glVertex2f(15.5398285491495, -8.1188888153483);
      glVertex2f(15.3283262504194, -7.2164790316642);
      glVertex2f(15.046323185446, -6.3845700123305);
      glVertex2f(14.5528178217425, -5.6372619102171);
      glVertex2f(13.8055096995628, -5.0591556425445);
      glVertex2f(13.2929598203136, -4.6688365321064);
    glEnd();
}

void Areia(){
  glBegin(GL_POLYGON);
    glColor3ub (238, 224, 199);
    glVertex2f(-17.1398512151135, -15.0429933771048);
    glVertex2f(-15.0031819671612, -13.7295215413454);
    glVertex2f(-14.3903388495315, -13.2491850566414);
    glVertex2f(-13.5456091468527, -13.0669884589951);
    glVertex2f(-12.9327660292229, -12.7854118989962);
    glVertex2f(-12.2702329290827, -12.5700886472324);
    glVertex2f(-11.789896431481, -12.2719487601747);
    glVertex2f(-11, -12);
    glVertex2f(-10.2495069736549, -11.7916122754708);
    glVertex2f(-9.6366638560252, -11.3775290990018);
    glVertex2f(-8.9625586214218, -11.3031104773561);
    glVertex2f(-8.2425586214218, -11.0431104773561);
    glVertex2f(-7.807965825296, -10.4344137501686);
    glVertex2f(-7.0436315484242, -10.1796356578779);
    glVertex2f(-6.2792972715523, -10.1541578486489);
    glVertex2f(-5.4828965254878, -10.0644196142994);
    glVertex2f(-4.7758229890539, -10.0505207293656);
    glVertex2f(-4.0712460896765, -10.1450853534886);
    glVertex2f(-3.44608661096, -10.104752483894);
    glVertex2f(-2.9971921024031, -9.9023014888114);
    glVertex2f(-2.3831409629641, -9.4999921215927);
    glVertex2f(-1.5785222285268, -9.2459019949283);
    glVertex2f(-0.8586002029777, -9.1400311088181);
    glVertex2f(-0.0825586214218, -8.9431104773561);
    glVertex2f(0.7296137245264, -8.9847933323074);
    glVertex2f(1.4732461676395, -9.166570151735);
    glVertex2f(1.9982684892748, -9.4706591863395);
    glVertex2f(2.902818127685, -9.6884211363271);
    glVertex2f(3.4891003007286, -10.2412014709111);
    glVertex2f(4.2428916660704, -10.4589634208988);
    glVertex2f(5.0301848698719, -10.7269781285759);
    glVertex2f(5.5829652044559, -10.8777364016442);
    glVertex2f(6.2027492159592, -10.9447400785635);
    glVertex2f(7.0570460966799, -10.8777364016442);
    glVertex2f(7.9174413785782, -10.9431104773561);
    glVertex2f(8.7153871004319, -11.0117437554828);
    glVertex2f(9.3184201927054, -11.3970148977686);
    glVertex2f(10.0554606388174, -11.732033282365);
    glVertex2f(10.9174413785782, -11.9431104773561);
    glVertex2f(11.5295415310414, -12.2345608592595);
    glVertex2f(11.9818163502465, -12.5025755669366);
    glVertex2f(12.4152291626948, -12.4788541512764);
    glVertex2f(12.9652145042092, -12.6752774822573);
    glVertex2f(13.6919808483531, -12.9109854794343);
    glVertex2f(14.1830391889909, -13.0877664773171);
    glVertex2f(14.6348128623776, -13.3234744744941);
    glVertex2f(15.0276595348879, -13.7948904688482);
    glVertex2f(15.9174413785782, -14.9431104773561);
  glEnd();
}

void Mar(){
  glBegin(GL_POLYGON);
    glColor3ub(25, 124, 251);
    glVertex2f(-15.0, -15);
    glVertex2f(-15.0, 0);
    glVertex2f(15, 0);
    glVertex2f(15, -15);
    glVertex2f(0, -15);
  glEnd();
}

void Sol(){
  glBegin(GL_POLYGON);
    glColor3ub (200, 200, 0);
    glVertex2f(-5.0825586214218, 0);
    glVertex2f(-5.117976244464, 0.7645673990468);
    glVertex2f(-5.1471847806776, 1.4609660475186);
    glVertex2f(-5.0786406888882, 2.260647118394);
    glVertex2f(-4.8501603829239, 3.197416372848);
    glVertex2f(-4.4617438627844, 3.9285533519341);
    glVertex2f(-3.9133911284698, 4.7967785145988);
    glVertex2f(-3.1594061187873, 5.5050674630884);
    glVertex2f(-2.4054211091048, 5.7792438302457);
    glVertex2f(-1.5371959464401, 6.0762682279994);
    glVertex2f(-0.7390719464804, 6.2670820733407);
    glVertex2f(-0.0792051085438, 6.3358182022924);
    glVertex2f(0.6493978583444, 6.2945765249214);
    glVertex2f(1.5567147605071, 6.2120931701793);
    glVertex2f(2.2990649531857, 5.9096542027917);
    glVertex2f(2.9864262427029, 5.4559957517104);
    glVertex2f(3.7185241475, 4.7838371570815);
    glVertex2f(4.4056312724334, 3.9782632864699);
    glVertex2f(4.7323239180766, 3.2151979478843);
    glVertex2f(4.9110378533511, 2.2803865941408);
    glVertex2f(4.9930131046909, 1.5512369477127);
    glVertex2f(4.9660267565125, 0.7956862087836);
    glVertex2f(4.8486866771206, 0.0);
  glEnd();
}

void Helicoptero(){
  glBegin(GL_POLYGON);
    glColor3ub (R, G, B);
    glVertex2f(-5.832928370436 + horizontal, 9.0401452436051 + vertical);
    glVertex2f(-5.8115850100531 + horizontal, 9.8085062173898 + vertical);
    glVertex2f(-5.9752174396554 + horizontal, 10.5128371100258 + vertical);
    glVertex2f(-6.2384522177112 + horizontal, 11.0250777592156 + vertical);
    glVertex2f(-6.7222350530572 + horizontal, 11.4234871530299 + vertical);
    glVertex2f(-7.2700479695518 + horizontal, 11.6653785707029 + vertical);
    glVertex2f(-8.0825586214218 + horizontal, 11.6568895226439 + vertical);
    glVertex2f(-8.9774372996019 + horizontal, 11.631106943557 + vertical);
    glVertex2f(-9.5552676330925 + horizontal, 11.414420568498 + vertical);
    glVertex2f(-10.2871346366497 + horizontal, 11.0714714695067 + vertical);
    glVertex2f(-10.7542655750856 + horizontal, 10.489892034913 + vertical);
    glVertex2f(-11.1443010501918 + horizontal, 9.7242668430379 + vertical);
    glVertex2f(-11.7525806223829 + horizontal, 9.4088783293972 + vertical);
    glVertex2f(-12.3866362671966 + horizontal, 9.2764483345827 + vertical);
    glVertex2f(-12.9066835673382 + horizontal, 9.2331110595709 + vertical);
    glVertex2f(-13.54414128698 + horizontal, 9.1366356960698 + vertical);
    glVertex2f(-13.8806024664937 + horizontal, 9.3201599758046 + vertical);
    glVertex2f(-14.0641267462284 + horizontal, 9.840145435053 + vertical);
    glVertex2f(-14.4617626856536 + horizontal, 9.8605370216902 + vertical);
    glVertex2f(-14.603735130515 + horizontal, 9.4042130776963 + vertical);
    glVertex2f(-14.3512594010648 + horizontal, 8.9730874095001 + vertical);
    glVertex2f(-13.9870779171056 + horizontal, 8.559164303765 + vertical);
    glVertex2f(-13.3704207036963 + horizontal, 8.559164303765 + vertical);
    glVertex2f(-12.6624068660782 + horizontal, 8.559164303765 + vertical);
    glVertex2f(-11.9543930284601 + horizontal, 8.6276817719216 + vertical);
    glVertex2f(-11.3377358150508 + horizontal, 8.6276817719216 + vertical);
    glVertex2f(-10.8124352258503 + horizontal, 8.7190383961303 + vertical);
    glVertex2f(-10.3556521048063 + horizontal, 8.6276817719216 + vertical);
    glVertex2f(-9.9453031081987 + horizontal, 8.424148592684 + vertical);
    glVertex2f(-9.6419421831161 + horizontal, 8.0918961509269 + vertical);
    glVertex2f(-9.2230151913354 + horizontal, 7.8607640175306 + vertical);
    glVertex2f(-8.7174136495311 + horizontal, 7.6874149174834 + vertical);
    glVertex2f(-8.1829205910523 + horizontal, 7.6874149174834 + vertical);
    glVertex2f(-7.6484275325735 + horizontal, 7.7451979508325 + vertical);
    glVertex2f(-7.0417056824083 + horizontal, 7.8174267425188 + vertical);
    glVertex2f(-6.4927668655922 + horizontal, 8.0052216009033 + vertical);
    glVertex2f(-6.0593941154742 + horizontal, 8.424148592684 + vertical);
    glVertex2f(-5.832928370436 + horizontal, 9.0401452436051 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3ub (0, 0, 0);
    glVertex2f(-8.0825586214218 + horizontal, 11.6568895226439 + vertical);
    glVertex2f(-8.0825853112324 + horizontal, 9.6138166626064 + vertical);
    glVertex2f(-8.0705656727889 + horizontal, 9.5906359313225 + vertical);
    glVertex2f(-8.0580155178343 + horizontal, 9.5742658955127 + vertical);
    glVertex2f(-8.0433024306799 + horizontal, 9.5655470290508 + vertical);
    glVertex2f(-8.0258646977561 + horizontal, 9.560642666666 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 9.5568895226439 + vertical);
    glVertex2f(-5.8197366354602 + horizontal, 9.56 + vertical);
    glVertex2f(-5.8115850100531 + horizontal, 9.8085062173898 + vertical);
    glVertex2f(-5.9752174396554 + horizontal, 10.5128371100258 + vertical);
    glVertex2f(-6.2384522177112 + horizontal, 11.0250777592156 + vertical);
    glVertex2f(-6.7222350530572 + horizontal, 11.4234871530299 + vertical);
    glVertex2f(-7.2700479695518 + horizontal, 11.6653785707029 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.3343377055376 + horizontal, 11.6568895226439 + vertical);
    glVertex2f(-8.3343377055376 + horizontal, 11.7490475001811 + vertical);
    glVertex2f(-8.2976917986704 + horizontal, 11.769705104695 + vertical);
    glVertex2f(-8.1820173228921 + horizontal, 11.7701061969863 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 11.7693515615288 + vertical);
    glVertex2f(-7.8830829565941 + horizontal, 11.7709245424658 + vertical);
    glVertex2f(-7.8538164500946 + horizontal, 11.7428774737371 + vertical);
    glVertex2f(-7.8538164500946 + horizontal, 11.6568895226439 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.1820173228921 + horizontal, 11.7701061969863 + vertical);
    glVertex2f(-8.1825586214218 + horizontal, 12.0568895226439 + vertical);
    glVertex2f(-8.1428465541292 + horizontal, 12.094923061773 + vertical);
    glVertex2f(-8.0826225013754 + horizontal, 12.1126633497135 + vertical);
    glVertex2f(-8.0257621940304 + horizontal, 12.0960071762184 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 12.0568895226439 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 11.7693515615288 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.1825586214218 + horizontal, 12.0568895226439 + vertical);
    glVertex2f(-8.2404168542116 + horizontal, 12.064567857303 + vertical);
    glVertex2f(-8.2642673720095 + horizontal, 12.0819136884287 + vertical);
    glVertex2f(-8.2534262275559 + horizontal, 12.1133530073442 + vertical);
    glVertex2f(-8.2230710230859 + horizontal, 12.1372035251421 + vertical);
    glVertex2f(-8.1825586214218 + horizontal, 12.1568895226439 + vertical);
    glVertex2f(-8.121164265222 + horizontal, 12.1664746151668 + vertical);
    glVertex2f(-8.0572015129458 + horizontal, 12.1664746151668 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 12.1568895226439 + vertical);
    glVertex2f(-7.9448957602006 + horizontal, 12.1377810320856 + vertical);
    glVertex2f(-7.913014291713 + horizontal, 12.1155212362349 + vertical);
    glVertex2f(-7.9249395506119 + horizontal, 12.0656519717483 + vertical);
    glVertex2f(-7.9249395506119 + horizontal, 12.0656519717483 + vertical);
    glVertex2f(-8.1825586214218 + horizontal, 12.0568895226439 + vertical);
    glVertex2f(-8.1428465541292 + horizontal, 12.094923061773 + vertical);
    glVertex2f(-8.0826225013754 + horizontal, 12.1126633497135 + vertical);
    glVertex2f(-8.0257621940304 + horizontal, 12.0960071762184 + vertical);
    glVertex2f(-7.9825586214218 + horizontal, 12.0568895226439 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.2230710230859 + horizontal, 12.1372035251421 + vertical);
    glVertex2f(-13.4828279997543 + horizontal, 12.6704440390004 + vertical);
    glVertex2f(-13.5473639725382 + horizontal, 12.6546055453838 + vertical);
    glVertex2f(-13.5962316485838 + horizontal, 12.6306508022242 + vertical);
    glVertex2f(-13.6795941547793 + horizontal, 12.5731594186411 + vertical);
    glVertex2f(-13.7227126924666 + horizontal, 12.5329154501329 + vertical);
    glVertex2f(-13.7380437280887 + horizontal, 12.4955460508039 + vertical);
    glVertex2f(-13.7639148507011 + horizontal, 12.4198490624195 + vertical);
    glVertex2f(-13.7744549376913 + horizontal, 12.3575667302045 + vertical);
    glVertex2f(-13.785953214408 + horizontal, 12.2809115520938 + vertical);
    glVertex2f(-13.7849950246816 + horizontal, 12.1927580972664 + vertical);
    glVertex2f(-13.7673373268627 + horizontal, 12.1176788772957 + vertical);
    glVertex2f(-13.7400859963752 + horizontal, 12.0642243444164 + vertical);
    glVertex2f(-13.7002571287396 + horizontal, 12.0160104520154 + vertical);
    glVertex2f(-13.6468025958603 + horizontal, 11.991903505815 + vertical);
    glVertex2f(-13.5545673234412 + horizontal, 11.9667484315188 + vertical);
    glVertex2f(-13.4825586214218 + horizontal, 11.9568895226439 + vertical);
    glVertex2f(-8.2642673720095 + horizontal, 12.0819136884287 + vertical);
    glVertex2f(-8.2534262275559 + horizontal, 12.1133530073442 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-7.9448957602006 + horizontal, 12.1377810320856 + vertical);
    glVertex2f(-7.913014291713 + horizontal, 12.1155212362349 + vertical);
    glVertex2f(-7.9066087725749 + horizontal, 12.0874407335408 + vertical);
    glVertex2f(-2.9158811413846 + horizontal, 11.9554344993213 + vertical);
    glVertex2f(-2.8617574934807 + horizontal, 11.9582954896744 + vertical);
    glVertex2f(-2.7955246707007 + horizontal, 11.9718575526314 + vertical);
    glVertex2f(-2.707701066638 + horizontal, 12.0113781744595 + vertical);
    glVertex2f(-2.667082649759 + horizontal, 12.0454098210338 + vertical);
    glVertex2f(-2.6171459956125 + horizontal, 12.0827099584177 + vertical);
    glVertex2f(-2.5847480209503 + horizontal, 12.1134731141824 + vertical);
    glVertex2f(-2.566085505087 + horizontal, 12.1442113756043 + vertical);
    glVertex2f(-2.5517756815271 + horizontal, 12.2007982677334 + vertical);
    glVertex2f(-2.5485207842745 + horizontal, 12.241915135124 + vertical);
    glVertex2f(-2.5463251941729 + horizontal, 12.2836313470538 + vertical);
    glVertex2f(-2.5441296040713 + horizontal, 12.3209563787804 + vertical);
    glVertex2f(-2.550716374376 + horizontal, 12.3769439263703 + vertical);
    glVertex2f(-2.5573031446807 + horizontal, 12.4406160393158 + vertical);
    glVertex2f(-2.5770634555948 + horizontal, 12.4987991770073 + vertical);
    glVertex2f(-2.5990193566105 + horizontal, 12.5449065691402 + vertical);
    glVertex2f(-2.6352465932863 + horizontal, 12.5833293959176 + vertical);
    glVertex2f(-2.6703760349114 + horizontal, 12.6096764771364 + vertical);
    glVertex2f(-2.707701066638 + horizontal, 12.6305345831013 + vertical);
    glVertex2f(-2.7668651020663 + horizontal, 12.652064306904 + vertical);
    glVertex2f(-2.8153656576781 + horizontal, 12.6668253455685 + vertical);
    glVertex2f(-2.8988666482607 + horizontal, 12.6700432105244 + vertical);
  glEnd();


  glBegin(GL_POLYGON);
    glVertex2f(-14.2334135422169 + horizontal, 9.0538196868763 + vertical);
    glVertex2f(-14.2464067668349 + horizontal, 9.1409466093606 + vertical);
    glVertex2f(-14.2380444127215 + horizontal, 9.2151330305986 + vertical);
    glVertex2f(-14.1681203582804 + horizontal, 9.262379013329 + vertical);
    glVertex2f(-14.0679588748919 + horizontal, 9.2756078884935 + vertical);
    glVertex2f(-14.0018144990693 + horizontal, 9.2585993347106 + vertical);
    glVertex2f(-13.9413396411743 + horizontal, 9.2132431912894 + vertical);
    glVertex2f(-13.9186615694637 + horizontal, 9.1452089761575 + vertical);
    glVertex2f(-13.9410707291296 + horizontal, 9.0679840970036 + vertical);
    glVertex2f(-13.9961449811416 + horizontal, 9.0166999031307 + vertical);
    glVertex2f(-14.0688697357434 + horizontal, 8.9836911351945 + vertical);
      glVertex2f(-14.147724441952 + horizontal, 8.9945676463957 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-14.2334135422169 + horizontal, 9.0538196868763 + vertical);
    glVertex2f(-14.7994830142892 + horizontal, 8.7576099067649 + vertical);
    glVertex2f(-14.8821037539245 + horizontal, 8.7031553283689 + vertical);
    glVertex2f(-14.9234141237422 + horizontal, 8.6299233091466 + vertical);
    glVertex2f(-14.9365583323205 + horizontal, 8.5698354985027 + vertical);
    glVertex2f(-14.9145184816347 + horizontal, 8.4996863867422 + vertical);
    glVertex2f(-14.8426711281895 + horizontal, 8.4646818298759 + vertical);
    glVertex2f(-14.7825586214218 + horizontal, 8.4568895226439 + vertical);
    glVertex2f(-14.6755519048361 + horizontal, 8.5003589674457 + vertical);
    glVertex2f(-14.147724441952 + horizontal, 8.9945676463957 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-14.0018144990693 + horizontal, 9.2585993347106 + vertical);
    glVertex2f(-13.5378361443628 + horizontal, 9.864320804921 + vertical);
    glVertex2f(-13.4625174968933 + horizontal, 9.8827951896533 + vertical);
    glVertex2f(-13.3786722100877 + horizontal, 9.8785318700997 + vertical);
    glVertex2f(-13.3104590953984 + horizontal, 9.8444253136709 + vertical);
    glVertex2f(-13.2834580708339 + horizontal, 9.789002159474 + vertical);
    glVertex2f(-13.2820369642779 + horizontal, 9.7122624075091 + vertical);
    glVertex2f(-13.3175646281786 + horizontal, 9.6241538034012 + vertical);
    glVertex2f(-13.9413396411743 + horizontal, 9.2132431912894 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-8.8097542085118 + horizontal, 8.1345310281585 + vertical);
    glVertex2f(-8.7992016306278 + horizontal, 8.1845169233986 + vertical);
    glVertex2f(-8.7653223016317 + horizontal, 8.2245056395907 + vertical);
    glVertex2f(-8.7103378168676 + horizontal, 8.2306150267867 + vertical);
    glVertex2f(-8.6448007542195 + horizontal, 8.2222840442467 + vertical);
    glVertex2f(-8.6164754135835 + horizontal, 8.1856277210706 + vertical);
    glVertex2f(-8.6114768240595 + horizontal, 8.1350864269945 + vertical);
    glVertex2f(-8.9852536375611 + horizontal, 7.3482210026817 + vertical);
    glVertex2f(-9.1911115245695 + horizontal, 7.3493710467123 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-7.7150977518009 + horizontal, 7.3551740056352 + vertical);
    glVertex2f(-7.9177763208266 + horizontal, 7.356487412193 + vertical);
    glVertex2f(-7.6881381397865 + horizontal, 8.0681298168318 + vertical);
    glVertex2f(-7.6805095592154 + horizontal, 8.1416120647248 + vertical);
    glVertex2f(-7.6302577346427 + horizontal, 8.2086144974884 + vertical);
    glVertex2f(-7.5599618512546 + horizontal, 8.2291106630463 + vertical);
    glVertex2f(-7.4897199747538 + horizontal, 8.1972115782107 + vertical);
    glVertex2f(-7.4683351887975 + horizontal, 8.138820296693 + vertical);
    glVertex2f(-7.4825586214218 + horizontal, 8.0568895226439 + vertical);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(-9.78232731488 + horizontal, 7.347532302294 + vertical);
    glVertex2f(-7.0751069304312 + horizontal, 7.3505639040683 + vertical);
    glVertex2f(-7.0156859367552 + horizontal, 7.3326960078534 + vertical);
    glVertex2f(-6.9748486410263 + horizontal, 7.2952618201019 + vertical);
    glVertex2f(-6.9510268851844 + horizontal, 7.2442152004407 + vertical);
    glVertex2f(-6.9747527643585 + horizontal, 7.1985973576251 + vertical);
    glVertex2f(-7.0167593851118 + horizontal, 7.1683135147564 + vertical);
    glVertex2f(-7.0729310291423 + horizontal, 7.1458448571442 + vertical);
    glVertex2f(-9.7905904161719 + horizontal, 7.1440363466046 + vertical);
    glVertex2f(-9.8298293037926 + horizontal, 7.1648753371292 + vertical);
    glVertex2f(-9.8749796705452 + horizontal, 7.1918770270499 + vertical);
    glVertex2f(-9.8972718815256 + horizontal, 7.2461679659728 + vertical);
    glVertex2f(-9.8972718815256 + horizontal, 7.2461679659728 + vertical);
    glVertex2f(-9.8825586214218 + horizontal, 7.2968895226439 + vertical);
    glVertex2f(-9.8320425570648 + horizontal, 7.3290987299252 + vertical);
  glEnd();
}

void keyboard(unsigned char key, int x, int y){
  printf("*** Tratamento de teclas comuns\n");
	printf(">>> Tecla pressionada: %c\n",key);
  switch (key) {
    case 27: exit(0);
    case 32: R = 0; G = 0; B = 0;
            glutPostRedisplay();
    break;
  }
}

void Special_keyboard(GLint tecla, int x, int y) {
  switch (tecla) { // GLUT_KEY_RIGHT GLUT_KEY_DOWN GLUT_KEY_PAGE_UP GLUT_KEY_PAGE_DOWN GLUT_KEY_F1...
    case GLUT_KEY_F12: R = 137; G = 0; B = 206;
        glutPostRedisplay();
        break;

    case GLUT_KEY_F11: R = 158; G = 0; B = 0;
      glutPostRedisplay();
      break;
    
    case GLUT_KEY_F10: R = 109; G = 67; B = 0;
      glutPostRedisplay();
      break;

    case GLUT_KEY_RIGHT:
      horizontal+=0.8;
      glutPostRedisplay();
      break;
    
    case GLUT_KEY_LEFT:
      horizontal-=0.8;
      glutPostRedisplay();
      break;

    case GLUT_KEY_UP:
      vertical+=0.8;
      glutPostRedisplay();
      break;
    
    case GLUT_KEY_DOWN:
      vertical-=0.8;
      glutPostRedisplay();
      break;
  }
}

void DesenhaTexto(char *string) {
  	glColor3ub(150,200,250);
  	glPushMatrix();
        // Posição no universo onde o texto será colocado
        glRasterPos2f(-0.4,-0.4);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();
	glColor3ub(255,255,255);
}
