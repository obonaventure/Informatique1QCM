 #!/bin/bash
 
 MAX=10
 
 for i in `seq 1 $MAX`; do echo -e "MISSION=$i\ninclude ../Makefile.inc" > Mission$i/Makefile ; done
