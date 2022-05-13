#pragma once

int include_cpio_h(Lib *self, FILE *file) {

    __basedef(cpio_h, "<cpio.h>")

    __dentr(enums, Enum[])
        __predef("C")
            EDEF_(C,IRUSR)
            EDEF_(C,IWUSR)
            EDEF_(C,IXUSR)
            EDEF_(C,IRGRP)
            EDEF_(C,IWGRP)
            EDEF_(C,IXGRP)
            EDEF_(C,IROTH)
            EDEF_(C,IWOTH)
            EDEF_(C,IXOTH)
            EDEF_(C,ISUID)
            EDEF_(C,ISGID)
            EDEF_(C,ISVTX)
            EDEF_(C,ISDIR)
            EDEF_(C,ISFIFO)
            EDEF_(C,ISREG)
            EDEF_(C,ISBLK)
            EDEF_(C,ISCHR)
            EDEF_(C,ISCTG)
            EDEF_(C,ISLNK)
            EDEF_(C,ISSOCK)
        __preend("C", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(cpio_h)
}

int test_cpio_h(Lib *self, FILE *file) {
    return 0;
}

