r = p -> pNext;
p->pNext = r->pNext;
free(r);