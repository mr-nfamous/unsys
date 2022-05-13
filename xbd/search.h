
#pragma once

int include_search_h(Lib *self, FILE *file) {
#   ifndef BLTN_HCREATE
#   define BLTN_HCREATE hcreate
#   endif
#   ifndef BLTN_HDESTROY
#   define BLTN_HDESTROY hdestroy
#   endif
#   ifndef BLTN_HSEARCH
#   define BLTN_HSEARCH hsearch
#   endif
#   ifndef BLTN_INSQUE
#   define BLTN_INSQUE insque
#   endif
#   ifndef BLTN_REMQUE
#   define BLTN_REMQUE remque
#   endif
#   ifndef BLTN_LFIND
#   define BLTN_LFIND lfind
#   endif
#   ifndef BLTN_LSEARCH
#   define BLTN_LSEARCH lsearch
#   endif
#   ifndef BLTN_TDELETE
#   define BLTN_TDELETE tdelete
#   endif
#   ifndef BLTN_TFIND
#   define BLTN_TFIND tfind
#   endif
#   ifndef BLTN_TSEARCH
#   define BLTN_TSEARCH tsearch
#   endif
#   ifndef BLTN_TWALK
#   define BLTN_TWALK twalk
#   endif
    self->hcreate   =BLTN_HCREATE;
    self->hdestroy  =BLTN_HDESTROY;
    self->insque    =BLTN_INSQUE;
    self->remque    =BLTN_REMQUE;
    self->twalk     =BLTN_TWALK;
    self->hsearch   =BLTN_HSEARCH;
    self->lfind     =BLTN_LFIND;
    self->lsearch   =BLTN_LSEARCH;
    self->tdelete   =BLTN_TDELETE;
    self->tfind     =BLTN_TFIND;
    self->tsearch   =BLTN_TSEARCH;

    __basedef(search_h, "<search.h>")

    __dentr(structs, Struct[])

        __memdef(entry_s)
        __member(entry_s, key, "chars")
        __member(entry_s, data, "buffer")
        __enddef(entry_s)

    __dexit(structs)
    __baseret(search_h)
}