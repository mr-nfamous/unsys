#pragma once

int include_ndbm_h(Lib *self, FILE *file) {
    const char *dsize_c = (
        sizeof(((datum*)0)->dsize) == sizeof(int)
        ?   "int"
        :   "size_t");
    __basedef(ndbm_h, "<ndbm.h>")

    __dentr(enums, Enum[])
        __predef("DBM")
            EDEF_(DBM,INSERT)
            EDEF_(DBM,REPLACE)
        __preend("DBM", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(datum)
        __member(datum, dptr, "void *")
        __member(datum, dsize, dsize_c)
        __enddef(datum)
    __dexit(structs)
    __baseret(ndbm_h)
}

int test_ndbm_h(Lib *self, FILE *file) {
#   ifndef BLTN_DBM_CLEARERR
#   define BLTN_DBM_CLEARERR dbm_clearerr
#   endif
#   ifndef BLTN_DBM_DELETE
#   define BLTN_DBM_DELETE dbm_delete
#   endif
#   ifndef BLTN_DBM_ERROR
#   define BLTN_DBM_ERROR dbm_error
#   endif
#   ifndef BLTN_DBM_STORE
#   define BLTN_DBM_STORE dbm_store
#   endif
#   ifndef BLTN_DBM_DIRFNO
#   define BLTN_DBM_DIRFNO dbm_dirfno
#   endif
#   ifndef BLTN_DBM_PAGFNO
#   define BLTN_DBM_PAGFNO dbm_pagfno
#   endif
#   ifndef BLTN_DBM_RDONLY
#   define BLTN_DBM_RDONLY dbm_rdonly
#   endif
#   ifndef BLTN_DBM_CLOSE
#   define BLTN_DBM_CLOSE dbm_close
#   endif
#   ifndef BLTN_DBM_FETCH
#   define BLTN_DBM_FETCH dbm_fetch
#   endif
#   ifndef BLTN_DBM_FIRSTKEY
#   define BLTN_DBM_FIRSTKEY dbm_firstkey
#   endif
#   ifndef BLTN_DBM_NEXTKEY
#   define BLTN_DBM_NEXTKEY dbm_nextkey
#   endif
#   ifndef BLTN_DBM_OPEN
#   define BLTN_DBM_OPEN dbm_open
#   endif
    self->dbm.clearerr  = BLTN_DBM_CLEARERR;
    self->dbm.delete    = BLTN_DBM_DELETE;
    self->dbm.error     = BLTN_DBM_ERROR;
    self->dbm.store     = BLTN_DBM_STORE;
    self->dbm.dirfno    = BLTN_DBM_DIRFNO;
    self->dbm.pagfno    = BLTN_DBM_PAGFNO;
    self->dbm.rdonly    = BLTN_DBM_RDONLY;
    self->dbm.close     = BLTN_DBM_CLOSE;
    self->dbm.fetch     = BLTN_DBM_FETCH;
    self->dbm.firstkey  = BLTN_DBM_FIRSTKEY;
    self->dbm.nextkey   = BLTN_DBM_NEXTKEY;
    self->dbm.open      = BLTN_DBM_OPEN;
    return 0;
}