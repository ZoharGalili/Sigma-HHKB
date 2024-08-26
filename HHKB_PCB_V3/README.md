# **keyboard PCB**
# ***we managed to get the pcb to fully work lets go***
but it didnt go without issues of course.
at first i didnt know how to get the stm32 into bootloader
and the first time i flashed it the code didnt compile due to syntax errors
and the json was wrong so the keys werent assained properly
and i suck at soldering so a few diodes and sockets were soldered only on one side
but at the end of the daay we had a fully working pcb so we got to work on the second one
on the second pcb we had a 3v3 and GND short that we couldnt find
our solution was to take to mcu and try to solder it to a new pcb and check for shorts each time we soldered a new component
the mcu was kida beat up from all the transfering and soldering so a few of its pins were kinda lifted up from the pcb
pushing them down and putting more solder paste did the trick and it worked
