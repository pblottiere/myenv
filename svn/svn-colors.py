#!/usr/bin/env python

"""
 Author: Saophalkun Ponlu (http://phalkunz.com)
 Contact: phalkunz@gmail.com
 Date: May 23, 2009
 Modified: June 15, 2009
"""

import os, sys, re, subprocess

tabsize = 4

colorizedSubcommands = (
	'status',
	'add',
	'remove',
	'diff',
	'log',
)

statusColors = {
    "M"     : "31",     # red
    "\?"    : "37",     # grey
    "A"     : "32",     # green
    "X"     : "33",     # yellow
    "C"     : "30;41",  # black on red
    "-"     : "31",     # red
    "D"     : "31;1",   # bold red
    "\+"    : "32",     # green,
    "r"     : "37",     # grey
}

def colorize(line):
    for color in statusColors:
        if re.match(color, line):
            return ''.join(("\001\033[", statusColors[color], "m", line, "\033[m\002"))
    else:
        return line

def escape(s):
    s = s.replace('$', r'\$')
    s = s.replace('"', r'\"')
    s = s.replace('`', r'\`')
    return s

passthru = lambda x: x
quoted = lambda x: '"%s"' % escape(x)

if __name__ == "__main__":
    cmd = ' '.join(['svn']+[(passthru, quoted)[' ' in arg](arg) for arg in sys.argv[1:]])

    out = subprocess.PIPE
    if ("propedit" in cmd) or ("commit" in cmd):
        os.system(cmd)
        sys.exit(1)

    output = subprocess.Popen(cmd, shell=True, stdout=out)
    cancelled = False
    for line in output.stdout:
        line = line.expandtabs(tabsize)
        if(sys.argv[1] in colorizedSubcommands):
            line = colorize(line)
        try:
            sys.stdout.write(line)
        except:
            sys.exit(1)
