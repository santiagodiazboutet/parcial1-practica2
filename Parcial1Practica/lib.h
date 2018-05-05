typedef struct{
 int id;
char apellido[30];
char nombre[30];
int idCategoria;
int estado;



 }eProgramador;

 typedef struct{
    int idCategoria;
    char descripcion[50];
    float sueldoHora;
 }eCategoria;

 int eProg_init(eProgramador[],int limite);
void eCat_init(eCategoria[]);
int eProgramador_alta(eProgramador  listado[],int limite);
int eProgramador_siguienteId(eProgramador listado[],int limite);
int eProgramador_buscarLugarLibre(eProgramador listado[],int limite);
void eProg_mostrarUno(eProgramador parametro);
int eProg_mostrarListado(eProgramador[] ,int limite, eCategoria[]);
int eCat_buscarPorId(eCategoria listado[] ,int limite, int id);
void eCat_mostrarUno(eCategoria parametro);
int eProg_modificacion(eProgramador listado[] ,int limite, eCategoria categoria[]);
