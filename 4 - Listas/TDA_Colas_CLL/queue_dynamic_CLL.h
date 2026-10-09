#define DQUEUE_ELEM int
#define DQUEUE_DEFAULT -1

typedef struct _Dqueue_node Dqueue_node;
typedef struct _Dqueue Dqueue;

Dqueue* Dqueue_new ();

Dqueue* Dqueue_new_with (int maxsize);

void Dqueue_free (Dqueue* q);

int Dqueue_getsize (Dqueue* q);

int Dqueue_getmaxsize (Dqueue* q);

int Dqueue_isfull (Dqueue* q);

int Dqueue_isempty (Dqueue* q);

void Denqueue (Dqueue* q, DQUEUE_ELEM elem);

DQUEUE_ELEM Ddequeue (Dqueue* q);

DQUEUE_ELEM peek (Dqueue* q);
