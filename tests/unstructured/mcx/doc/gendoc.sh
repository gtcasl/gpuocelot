#!/bin/sh

# commands to update the document pages from homepage

ROOTURL="http://mcx.sourceforge.net/cgi-bin/index.cgi?embed=1&keywords"

lynx -dont_wrap_pre -dump "$ROOTURL=Download" > Download.txt
lynx -dont_wrap_pre -dump "$ROOTURL=Doc/Installation" > INSTALL.txt
lynx -dont_wrap_pre -dump "$ROOTURL=Doc/Basics" > Get_Started.txt
lynx -dont_wrap_pre -dump "$ROOTURL=Doc/FAQ" > FAQ.txt

wget http://mcx.sourceforge.net/upload/mcx_diagram_paper.png -Omcx_workflow.png
