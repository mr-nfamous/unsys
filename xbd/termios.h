#pragma once

int include_termios_h(Lib *self, FILE *file) {

    __basedef(termios_h, "<termios.h>")

    __dentr(enums, Enum[])

        __predef("")
            // termios.c_cc[i]
            EREF(VEOF)      // EOF
            EREF(VEOL)      // EOL
            EREF(VERASE)    // ERASE
            EREF(VKILL)     // KILL
            EREF(VINTR)     // INTERRUPT
            EREF(VQUIT)     // QUIT
            EREF(VSTART)    // START
            EREF(VSTOP)     // STOP
            EREF(VSUSP)     // SUSPEND
            EREF(VTIME)     // TIME
        __preend("")
        __predef("")
        //c_oflag
            EREF(BRKINT)    // signal break
            EREF(ICRNL)     // map cr to nl on input
            EREF(IGNBRK)    // ignore break
            EREF(IGNCR)     // ignore cr
            EREF(IGNPAR)    // ignore parity errors
            EREF(INLCR)     // nl to cr
            EREF(INPCK)     // 
            EREF(ISTRIP)    //
            EREF(IXANY)     //
            EREF(IXOFF)     //
            EREF(IXON)      //
            EREF(PARMRK)    //
        __preend("")
        __predef("")
        // c_oflag
            EREF(OPOST) // post process output
            EREF(ONLCR) // map nl to cr-nl on output
            EREF(OCRNL) // map cr to nl on output
            EREF(ONOCR) // no cr on col#0
            EREF(ONLRET) // nl is cr
            EREF(OFDEL) // Fill is del
            EREF(NLDLY) //
            EREF(NL0) //  x
            EREF(NL1) //  x
            EREF(CRDLY) //  x
            EREF(CR0) //  x
            EREF(CR1) //  x
            EREF(CR2) //  x
            EREF(CR3) //  x
            EREF(TABDLY) //  x
            EREF(TAB0) //  x
            EREF(TAB1) //  x
            EREF(TAB2) //  x
            EREF(TAB3) //  x
            EREF(BSDLY) //  x
            EREF(OLCUC) //  x
            EREF(BS0) //  x
            EREF(BS1) //  x
            EREF(VTDLY) //  x
            EREF(VT0) //  x
            EREF(VT1) //  x
            EREF(FFDLY) //  x
            EREF(FF0) //  x
            EREF(FF1) //  x
        __preend("")
        __predef("")
        // speed_t
            EREF(B0) //  0000000
            EREF(B50) //  0000001
            EREF(B75) //  0000002
            EREF(B110) //  0000003
            EREF(B134) //  0000004
            EREF(B150) //  0000005
            EREF(B200) //  0000006
            EREF(B300) //  0000007
            EREF(B600) //  0000010
            EREF(B1200) //  0000011
            EREF(B1800) //  0000012
            EREF(B2400) //  0000013
            EREF(B4800) //  0000014
            EREF(B9600) //  0000015
            EREF(B19200) //  0000016
            EREF(B38400) //  0000017
        __preend("")
        __predef("")
            EREF(CSIZE)     //  0000060
            EREF(CS5)       //  0000000
            EREF(CS6)       //  0000020
            EREF(CS7)       //  0000040
            EREF(CS8)       //  0000060
            EREF(CSTOPB)    //  0000100
            EREF(CREAD)     //  0000200
            EREF(PARENB)    //  0000400
            EREF(PARODD)    //  0001000
            EREF(HUPCL)     //  0002000
            EREF(CLOCAL)    //  0004000
        __preend("")
        __predef("")
        // c_lflag
            EREF(ECHO)      //  0000010
            EREF(ECHOE)     //  0000020
            EREF(ECHOK)     //  0000040
            EREF(ECHONL)    //  0000100
            EREF(ICANON)    //  0000002
            EREF(IEXTEN)    //  0100000
            EREF(ISIG)      //  0000001
            EREF(NOFLSH)    //  0000200
            EREF(TOSTOP)    //  0000400
        __preend("")
        __predef("")
        // tcsetattr
            EREF(TCSANOW)   //  0
            EREF(TCSAFLUSH) //  0
            EREF(TCSADRAIN) //  1
        __preend("")
        __predef("")
        //tcflush
            EREF(TCIFLUSH)  //  0
            EREF(TCIOFLUSH) //  2
            EREF(TCOFLUSH)  //  1
        __preend("")
        __predef("")
        //tcflow
            EREF(TCIOFF)    //  2
            EREF(TCION)     //  3
            EREF(TCOOFF)    //  0
            EREF(TCOON)     //  1
        __preend("", .fmt="x")
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(termios_s)
        __member(termios_s, c_iflag, "tcflag_t")
        __member(termios_s, c_oflag, "tcflag_t")
        __member(termios_s, c_cflag, "tcflag_t")
        __member(termios_s, c_lflag, "tcflag_t")
        __member(termios_s, c_cc, "cc_t[{NCCS}]")
        __enddef(termios_s)
    __dexit(structs)
    __baseret(termios_h)
}

int test_termios_h(Lib *self, FILE *file) {
#   ifndef BLTN_CFGETISPEED
#   define BLTN_CFGETISPEED cfgetispeed
#   endif
#   ifndef BLTN_CFGETOSPEED
#   define BLTN_CFGETOSPEED cfgetospeed
#   endif
#   ifndef BLTN_CFSETISPEED
#   define BLTN_CFSETISPEED cfsetispeed
#   endif
#   ifndef BLTN_CFSETOSPEED
#   define BLTN_CFSETOSPEED cfsetospeed
#   endif
#   ifndef BLTN_TCDRAIN
#   define BLTN_TCDRAIN tcdrain
#   endif
#   ifndef BLTN_TCFLOW
#   define BLTN_TCFLOW tcflow
#   endif
#   ifndef BLTN_TCFLUSH
#   define BLTN_TCFLUSH tcflush
#   endif
#   ifndef BLTN_TCGETATTR
#   define BLTN_TCGETATTR tcgetattr
#   endif
#   ifndef BLTN_TCSENDBREAK
#   define BLTN_TCSENDBREAK tcsendbreak
#   endif
#   ifndef BLTN_TCSETATTR
#   define BLTN_TCSETATTR tcsetattr
#   endif
#   ifndef BLTN_TCGETSID
#   define BLTN_TCGETSID tcgetsid
#   endif
    self->cfgetispeed   = BLTN_CFGETISPEED;
    self->cfgetospeed   = BLTN_CFGETOSPEED;
    self->cfsetispeed   = BLTN_CFSETISPEED;
    self->cfsetospeed   = BLTN_CFSETOSPEED;
    self->tcdrain       = BLTN_TCDRAIN;
    self->tcflow        = BLTN_TCFLOW;
    self->tcflush       = BLTN_TCFLUSH;
    self->tcgetattr     = BLTN_TCGETATTR;
    self->tcsendbreak   = BLTN_TCSENDBREAK;
    self->tcsetattr     = BLTN_TCSETATTR;
    self->tcgetsid      = BLTN_TCGETSID;
    return 0;

}

