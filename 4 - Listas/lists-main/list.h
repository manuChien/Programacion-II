#define LIST_ELEM int
#define LIST_ELEM_DEFAULT 0
#define bool int
#define true 1
#define false 0

typedef struct _list_node list_node;
typedef struct _list list;

list* list_new(int maxsize);

void list_free(list *L);

int list_length(list *L);

int list_append(list *L, LIST_ELEM elem);

void list_insert(list *L, LIST_ELEM elem); // insert before current

LIST_ELEM list_first(list *L);

LIST_ELEM list_next(list *L);

int list_eol(list *L);

LIST_ELEM list_remove (list *L); // remove current element

LIST_ELEM list_get(list *L, int index);

bool list_isempty(list *L);

bool list_isfull(list *L);
