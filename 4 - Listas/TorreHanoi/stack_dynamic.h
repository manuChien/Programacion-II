#define DSTACK_ELEM char
#define DSTACK_DEFAULT 'a'
#define DSTACK_DEFAULT_MAXSIZE 100

typedef struct _Dstack Dstack;
typedef struct _Dstack_node Dstack_node;

Dstack* Dstack_new();

Dstack* Dstack_new_with(int maxsize);

void Dstack_free(Dstack* s);

int Dstack_getsize(Dstack* s);

int Dstack_getmaxsize(Dstack* s);

void Dpush(Dstack* s, DSTACK_ELEM elem);

DSTACK_ELEM Dpop(Dstack* s);

DSTACK_ELEM Dtop(Dstack* s);

int Dstack_isempty(Dstack* s);

int Dstack_isfull(Dstack* s);

void Dstack_destroy(Dstack* s, void elem_free(DSTACK_ELEM));
