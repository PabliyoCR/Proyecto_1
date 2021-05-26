typedef struct ListaMenus ListaMenus;
typedef struct Menu Menu;
typedef struct QueueMenu QueueMenu;

struct Menu
{
    Dieta *dieta;
    Menu *next;
};

struct QueueMenu
{
    Menu *front;
    Menu *rear;
    int size;
};

