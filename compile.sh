qmk compile --keyboard sofle --keymap climent
qmk compile --keyboard sofle --keymap climent-rp2040
qmk compile --keyboard atreyu --keymap pcb
qmk compile --keyboard atreyu --keymap pcb-rp2040
qmk compile -kb atreyu/handwired -km default
qmk compile -kb atreyu/handwired -km default -e CONVERT_TO=liatris
qmk compile -kb atreyu/handwired -km via -e CONVERT_TO=liatris
