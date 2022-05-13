#pragma once

int include_stdio_h(Lib *self, FILE *file) {

    __basedef(stdio_h, "<stdio.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(BUFSIZ)
            EREF(L_ctermid)
            EREF(L_tmpnam)
            EREF(_IOFBF)
            EREF(_IOLBF)
            EREF(_IONBF)
            EREF(FILENAME_MAX)
            EREF(FOPEN_MAX)
            EREF(TMP_MAX)
            EREF(EOF)
        __preend("", .fmt="x")
        __predef("SEEK")
            EDEF_(SEEK,SET)
            EDEF_(SEEK,CUR)
            EDEF_(SEEK,END)
        __preend("SEEK")

    __dexit(enums)

    __baseret(stdio_h)
}

int test_stdio_h(Lib *self, FILE *file) {
#   ifndef BLTN_CLEARERR
#   define BLTN_CLEARERR clearerr
#   endif
#   ifndef BLTN_PERROR
#   define BLTN_PERROR perror
#   endif
#   ifndef BLTN_REWIND
#   define BLTN_REWIND rewind
#   endif
#   ifndef BLTN_SETBUF
#   define BLTN_SETBUF setbuf
#   endif
#   ifndef BLTN_FLOCKFILE
#   define BLTN_FLOCKFILE flockfile
#   endif
#   ifndef BLTN_FUNLOCKFILE
#   define BLTN_FUNLOCKFILE funlockfile
#   endif
#   ifndef BLTN_FMEMOPEN
#   define BLTN_FMEMOPEN fmemopen
#   endif
#   ifndef BLTN_FOPEN
#   define BLTN_FOPEN fopen
#   endif
#   ifndef BLTN_FREOPEN
#   define BLTN_FREOPEN freopen
#   endif
#   ifndef BLTN_TMPFILE
#   define BLTN_TMPFILE tmpfile
#   endif
#   ifndef BLTN_FDOPEN
#   define BLTN_FDOPEN fdopen
#   endif
#   ifndef BLTN_OPEN_MEMSTREAM
#   define BLTN_OPEN_MEMSTREAM open_memstream
#   endif
#   ifndef BLTN_POPEN
#   define BLTN_POPEN popen
#   endif
#   ifndef BLTN_FILENO
#   define BLTN_FILENO fileno
#   endif
#   ifndef BLTN_FCLOSE
#   define BLTN_FCLOSE fclose
#   endif
#   ifndef BLTN_FEOF
#   define BLTN_FEOF feof
#   endif
#   ifndef BLTN_FERROR
#   define BLTN_FERROR ferror
#   endif
#   ifndef BLTN_FFLUSH
#   define BLTN_FFLUSH fflush
#   endif
#   ifndef BLTN_FGETC
#   define BLTN_FGETC fgetc
#   endif
#   ifndef BLTN_FGETPOS
#   define BLTN_FGETPOS fgetpos
#   endif
#   ifndef BLTN_FPRINTF
#   define BLTN_FPRINTF fprintf
#   endif
#   ifndef BLTN_FPUTC
#   define BLTN_FPUTC fputc
#   endif
#   ifndef BLTN_FPUTS
#   define BLTN_FPUTS fputs
#   endif
#   ifndef BLTN_FSCANF
#   define BLTN_FSCANF fscanf
#   endif
#   ifndef BLTN_FSEEK
#   define BLTN_FSEEK fseek
#   endif
#   ifndef BLTN_FSETPOS
#   define BLTN_FSETPOS fsetpos
#   endif
#   ifndef BLTN_GETC
#   define BLTN_GETC getc
#   endif
#   ifndef BLTN_GETCHAR
#   define BLTN_GETCHAR getchar
#   endif
#   ifndef BLTN_PRINTF
#   define BLTN_PRINTF printf
#   endif
#   ifndef BLTN_PUTC
#   define BLTN_PUTC putc
#   endif
#   ifndef BLTN_PUTCHAR
#   define BLTN_PUTCHAR putchar
#   endif
#   ifndef BLTN_PUTS
#   define BLTN_PUTS puts
#   endif
#   ifndef BLTN_REMOVE
#   define BLTN_REMOVE remove
#   endif
#   ifndef BLTN_RENAME
#   define BLTN_RENAME rename
#   endif
#   ifndef BLTN_SCANF
#   define BLTN_SCANF scanf
#   endif
#   ifndef BLTN_SETVBUF
#   define BLTN_SETVBUF setvbuf
#   endif
#   ifndef BLTN_SNPRINTF
#   define BLTN_SNPRINTF snprintf
#   endif
#   ifndef BLTN_SPRINTF
#   define BLTN_SPRINTF sprintf
#   endif
#   ifndef BLTN_SSCANF
#   define BLTN_SSCANF sscanf
#   endif
#   ifndef BLTN_UNGETC
#   define BLTN_UNGETC ungetc
#   endif
#   ifndef BLTN_VFPRINTF
#   define BLTN_VFPRINTF vfprintf
#   endif
#   ifndef BLTN_VFSCANF
#   define BLTN_VFSCANF vfscanf
#   endif
#   ifndef BLTN_VPRINTF
#   define BLTN_VPRINTF vprintf
#   endif
#   ifndef BLTN_VSCANF
#   define BLTN_VSCANF vscanf
#   endif
#   ifndef BLTN_VSNPRINTF
#   define BLTN_VSNPRINTF vsnprintf
#   endif
#   ifndef BLTN_VSPRINTF
#   define BLTN_VSPRINTF vsprintf
#   endif
#   ifndef BLTN_VSSCANF
#   define BLTN_VSSCANF vsscanf
#   endif
#   ifndef BLTN_DPRINTF
#   define BLTN_DPRINTF dprintf
#   endif
#   ifndef BLTN_FSEEKO
#   define BLTN_FSEEKO fseeko
#   endif
#   ifndef BLTN_FTRYLOCKFILE
#   define BLTN_FTRYLOCKFILE ftrylockfile
#   endif
#   ifndef BLTN_GETC_UNLOCKED
#   define BLTN_GETC_UNLOCKED getc_unlocked
#   endif
#   ifndef BLTN_GETCHAR_UNLOCKED
#   define BLTN_GETCHAR_UNLOCKED getchar_unlocked
#   endif
#   ifndef BLTN_PCLOSE
#   define BLTN_PCLOSE pclose
#   endif
#   ifndef BLTN_PUTC_UNLOCKED
#   define BLTN_PUTC_UNLOCKED putc_unlocked
#   endif
#   ifndef BLTN_PUTCHAR_UNLOCKED
#   define BLTN_PUTCHAR_UNLOCKED putchar_unlocked
#   endif
#   ifndef BLTN_RENAMEAT
#   define BLTN_RENAMEAT renameat
#   endif
#   ifndef BLTN_VDPRINTF
#   define BLTN_VDPRINTF vdprintf
#   endif
#   ifndef BLTN_CTERMID
#   define BLTN_CTERMID ctermid
#   endif
#   ifndef BLTN_FTELL
#   define BLTN_FTELL ftell
#   endif
#   ifndef BLTN_FREAD
#   define BLTN_FREAD fread
#   endif
#   ifndef BLTN_FWRITE
#   define BLTN_FWRITE fwrite
#   endif
#   ifndef BLTN_FTELLO
#   define BLTN_FTELLO ftello
#   endif
#   ifndef BLTN_GETDELIM
#   define BLTN_GETDELIM getdelim
#   endif
#   ifndef BLTN_GETLINE
#   define BLTN_GETLINE getline
#   endif

    self->clearerr=BLTN_CLEARERR;
    self->perror=BLTN_PERROR;
    self->rewind=BLTN_REWIND;
    self->setbuf=BLTN_SETBUF;
    self->flockfile=BLTN_FLOCKFILE;
    self->funlockfile=BLTN_FUNLOCKFILE;
    self->fmemopen=BLTN_FMEMOPEN;
    self->fopen=BLTN_FOPEN;
    self->freopen=BLTN_FREOPEN;
    self->tmpfile=BLTN_TMPFILE;
    self->fdopen=BLTN_FDOPEN;
    self->open_memstream=BLTN_OPEN_MEMSTREAM;
    self->popen=BLTN_POPEN;
    self->fileno=BLTN_FILENO;
    self->fclose=BLTN_FCLOSE;
    self->feof=BLTN_FEOF;
    self->ferror=BLTN_FERROR;
    self->fflush=BLTN_FFLUSH;
    self->fgetc=BLTN_FGETC;
    self->fgetpos=BLTN_FGETPOS;
    self->fprintf=BLTN_FPRINTF;
    self->fputc=BLTN_FPUTC;
    self->fputs=BLTN_FPUTS;
    self->fscanf=BLTN_FSCANF;
    self->fseek=BLTN_FSEEK;
    self->fsetpos=BLTN_FSETPOS;
    self->getc=BLTN_GETC;
    self->getchar=BLTN_GETCHAR;
    self->printf=BLTN_PRINTF;
    self->putc=BLTN_PUTC;
    self->putchar=BLTN_PUTCHAR;
    self->puts=BLTN_PUTS;
    self->remove=BLTN_REMOVE;
    self->rename=BLTN_RENAME;
    self->scanf=BLTN_SCANF;
    self->setvbuf=BLTN_SETVBUF;
    self->snprintf=BLTN_SNPRINTF;
    self->sprintf=BLTN_SPRINTF;
    self->sscanf=BLTN_SSCANF;
    self->ungetc=BLTN_UNGETC;
    self->vfprintf=BLTN_VFPRINTF;
    self->vfscanf=BLTN_VFSCANF;
    self->vprintf=BLTN_VPRINTF;
    self->vscanf=BLTN_VSCANF;
    self->vsnprintf=BLTN_VSNPRINTF;
    self->vsprintf=BLTN_VSPRINTF;
    self->vsscanf=BLTN_VSSCANF;
    self->dprintf=BLTN_DPRINTF;
    self->fseeko=BLTN_FSEEKO;
    self->ftrylockfile=BLTN_FTRYLOCKFILE;
    self->getc_unlocked=BLTN_GETC_UNLOCKED;
    self->getchar_unlocked=BLTN_GETCHAR_UNLOCKED;
    self->pclose=BLTN_PCLOSE;
    self->putc_unlocked=BLTN_PUTC_UNLOCKED;
    self->putchar_unlocked=BLTN_PUTCHAR_UNLOCKED;
    self->renameat=BLTN_RENAMEAT;
    self->vdprintf=BLTN_VDPRINTF;
    self->ctermid=BLTN_CTERMID;
    self->ftell=BLTN_FTELL;
    self->fread=BLTN_FREAD;
    self->fwrite=BLTN_FWRITE;
    self->ftello=BLTN_FTELLO;
    self->getdelim=BLTN_GETDELIM;
    self->getline=BLTN_GETLINE;

    return 0;
}