#pragma once

int include_spawn_h(Lib *self, FILE *file) {

    __basedef(spawn_h, "<spawn.h>")

    __dentr(enums, Enum[])
        __predef("POSIX_SPAWN")
            EDEF_(POSIX_SPAWN,RESETIDS)
            EDEF_(POSIX_SPAWN,SETPGROUP)
            EDEF_(POSIX_SPAWN,SETSCHEDPARAM)
            EDEF_(POSIX_SPAWN,SETSCHEDULER)
            EDEF_(POSIX_SPAWN,SETSIGDEF)
            EDEF_(POSIX_SPAWN,SETSIGMASK)
        __preend("POSIX_SPAWN", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(&)
        __member(&, ..,    "o")
        __member(&, ..,    "{pid_t}")
        __enddef(&)
    __dexit(structs)
    __baseret(spawn_h)
}

int test_spawn_h(Lib *self, FILE *file) {
#   ifndef BLTN_POSIX_SPAWN
#   define BLTN_POSIX_SPAWN posix_spawn
#   endif
#   ifndef BLTN_POSIX_SPAWNP
#   define BLTN_POSIX_SPAWNP posix_spawnp
#   endif
#   ifndef BLTN_POSIX_SPAWN_ADDCLOSE
#   define BLTN_POSIX_SPAWN_ADDCLOSE posix_spawn_file_actions_addclose
#   endif
#   ifndef BLTN_POSIX_SPAWN_ADDOPEN
#   define BLTN_POSIX_SPAWN_ADDOPEN posix_spawn_file_actions_addopen
#   endif
#   ifndef BLTN_POSIX_SPAWN_ADDDUP2
#   define BLTN_POSIX_SPAWN_ADDDUP2 posix_spawn_file_actions_adddup2
#   endif
#   ifndef BLTN_POSIX_SPAWN_FILE_ACTIONS_DESTROY
#   define BLTN_POSIX_SPAWN_FILE_ACTIONS_DESTROY posix_spawn_file_actions_destroy
#   endif
#   ifndef BLTN_POSIX_SPAWN_FILE_ACTIONS_INIT
#   define BLTN_POSIX_SPAWN_FILE_ACTIONS_INIT posix_spawn_file_actions_posix_spawn_file_actions_init
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_DESTROY
#   define BLTN_POSIX_SPAWNATTR_DESTROY  posix_spawnattr_destroy
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_INIT
#   define BLTN_POSIX_SPAWNATTR_INIT posix_spawnattr_init
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_GETPGROUP
#   define BLTN_POSIX_SPAWNATTR_GETPGROUP posix_spawnattr_getpgroup
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_SETPGROUP
#   define BLTN_POSIX_SPAWNATTR_SETPGROUP posix_spawnattr_setpgroup
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_SIGMASK
#   define BLTN_POSIX_SPAWNATTR_SIGMASK posix_spawnattr_sigmask
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_GETSIGMASK
#   define BLTN_POSIX_SPAWNATTR_GETSIGMASK posix_spawnattr_getsigmask
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_GETSIGDEFAULT
#   define BLTN_POSIX_SPAWNATTR_GETSIGDEFAULT posix_spawnattr_getsigdefault
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_SETSIGDEFAULT
#   define BLTN_POSIX_SPAWNATTR_SETSIGDEFAULT posix_spawnattr_setsigdefault
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_GETFLAGS
#   define BLTN_POSIX_SPAWNATTR_GETFLAGS posix_spawnattr_getflags
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR__SETFLAGS
#   define BLTN_POSIX_SPAWNATTR_SETFLAGS posix_spawnattr_setflags
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_GETSCHEDPOLICY
#   define BLTN_POSIX_SPAWNATTR_GETSCHEDPOLICY posix_spawnattr_getschedpolicy
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_SETSCHEDPOLICY
#   define BLTN_POSIX_SPAWNATTR_SETSCHEDPOLICY posix_spawnattr_setschedpolicy
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_GETSCHEDPARAM
#   define BLTN_POSIX_SPAWNATTR_GETSCHEDPARAM posix_spawnattr_getschedparam
#   endif
#   ifndef BLTN_POSIX_SPAWNATTR_SETSCHEDPARAM
#   define BLTN_POSIX_SPAWNATTR_SETSCHEDPARAM posix_spawnattr_setschedparam
#   endif
    self->posix_spawn = BLTN_POSIX_SPAWN;
    self->posix_spawnp = BLTN_POSIX_SPAWNP;
    self->posix.spawn_file_actions.addclose=BLTN_POSIX_SPAWN_ADDCLOSE;
    self->posix.spawn_file_actions.addopen=BLTN_POSIX_SPAWN_ADDOPEN;
    self->posix.spawn_file_actions.adddup2=BLTN_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2;
    self->posix.spawn_file_actions.destroy=BLTN_POSIX_SPAWN_FILE_ACTIONS_DESTROY;
    self->posix.spawn_file_actions.init=BLTN_POSIX_SPAWN_FILE_ACTIONS_INIT;
    self->posix.spawnattr.destroy=BLTN_POSIX_SPAWNATTR_DESTROY;
    self->posix.spawnattr.init=BLTN_POSIX_SPAWNATTR_INIT;
    self->posix.spawnattr.getpgroup=BLTN_POSIX_SPAWNATTR_GETPGROUP;
    self->posix.spawnattr.setpgroup=BLTN_POSIX_SPAWNATTR_SETPGROUP;
    self->posix.spawnattr.sigmask=BLTN_POSIX_SPAWNATTR_SIGMASK;
    self->posix.spawnattr.getsigmask=BLTN_POSIX_SPAWNATTR_GETSIGMASK;
    self->posix.spawnattr.getsigdefault=BLTN_GETSIGDEFAULT;
    self->posix.spawnattr.setsigdefault=BLTN_POSIX_SPAWNATTR_SETSIGDEFAULT;
    self->posix.spawnattr.getflags=BLTN_POSIX_SPAWNATTR_GETFLAGS;
    self->posix.spawnattr.setflags=BLTN_POSIX_SPAWNATTR_SETFLAGS;
    self->posix.spawnattr.getschedpolicy=BLTN_POSIX_SPAWNATTR_GETSCHEDPOLICY;
    self->posix.spawnattr.setschedpolicy=BLTN_POSIX_SPAWNATTR_SETSCHEDPOLICY;
    self->posix.spawnattr.getschedparam =BLTN_POSIX_SPAWNATTR_GETSCHEDPARAM;
    self->posix.spawnattr.setschedparam =BLTN_POSIX_SPAWNATTR_SETSCHEDPARAM;
    
    return 0;
}