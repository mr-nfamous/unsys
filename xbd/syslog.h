#pragma once

int include_syslog_h(Lib *self, FILE *file) {

    __basedef(syslog_h, "<syslog.h>")

    __dentr(enums, Enum[])
        __predef("LOG")
            EDEF_(LOG,PID)
            EDEF_(LOG,CONS)
            EDEF_(LOG,NDELAY)
            EDEF_(LOG,ODELAY)
            EDEF_(LOG,NOWAIT)
        __preend("LOG", .fmt="x")
        __predef("LOG")
            EDEF_(LOG,KERN)
            EDEF_(LOG,USER)
            EDEF_(LOG,MAIL)
            EDEF_(LOG,NEWS)
            EDEF_(LOG,UUCP)
            EDEF_(LOG,DAEMON)
            EDEF_(LOG,AUTH)
            EDEF_(LOG,CRON)
            EDEF_(LOG,LPR)
            EDEF_(LOG,LOCAL0)
            EDEF_(LOG,LOCAL1)
            EDEF_(LOG,LOCAL2)
            EDEF_(LOG,LOCAL3)
            EDEF_(LOG,LOCAL4)
            EDEF_(LOG,LOCAL5)
            EDEF_(LOG,LOCAL6)
            EDEF_(LOG,LOCAL7)
        __preend("LOG")
        __predef("LOG")
            EDEF_(LOG,EMERG)    // A panic condition was reported to all processes.
            EDEF_(LOG,ALERT)    // A condition that should be corrected immediately.
            EDEF_(LOG,CRIT)     // A critical condition.
            EDEF_(LOG,ERR)      // An error message.
            EDEF_(LOG,WARNING)  // A warning message.
            EDEF_(LOG,NOTICE)   // A condition requiring special handling.
            EDEF_(LOG,INFO)     // A general information message.
            EDEF_(LOG,DEBUG)    //
        __preend("LOG", .fmt="x")

    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(syslog_h)
}

int test_syslog_h(Lib *self, FILE *file) {
#   ifndef BLTN_CLOSELOG
#   define BLTN_CLOSELOG closelog
#   endif
#   ifndef BLTN_OPENLOG
#   define BLTN_OPENLOG openlog
#   endif
#   ifndef BLTN_SYSLOG
#   define BLTN_SYSLOG syslog
#   endif
#   ifndef BLTN_VSYSLOG
#   define BLTN_VSYSLOG vsyslog
#   endif
#   ifndef BLTN_SETLOGMASK
#   define BLTN_SETLOGMASK setlogmask
#   endif
    self->closelog  = BLTN_CLOSELOG;
    self->openlog   = BLTN_OPENLOG;
    self->syslog    = BLTN_SYSLOG;
    self->vsyslog   = BLTN_VSYSLOG;
    self->setlogmask= BLTN_SETLOGMASK;
    return 0;
}