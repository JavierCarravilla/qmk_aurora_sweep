# qmk_aurora_sweep
qmk compile -kb splitkb/aurora/sweep -km debug -e CONVERT_TO=rp2040_ce
qmk flash -kb splitkb/aurora/sweep -km debug -e CONVERT_TO=rp2040_ce


Botones de pulgar:
homing space y enter. Los dos juntos esc
secundarios capas si sostenido en quick delete y tab

Capas:
Capa 0 _QUERTY-> Default.
Capa 1 _HOMEROW_MACOS-> Overlay Default.
Capa 2 _NUMBERS-> Momentary	Botón capa izq.
	- Lado izquierdo bloque numérico 3x3 más simbols operaciones 
	- Lado derecho flechas vim y desplazamientos (fin de linea etc)
Capa 3 _SYMBOLS-> Momentary Botón capa dch.
	- Simbolos como en el corne
Capa 4 _MOUSE-> Momentary Botón capa izq + doble tap en dch. Mirar layer lock.
	- Lado derecho flechas vim para el raton cuatro teclas por encima los tres botones + boton back
Capa 5 _CONFIG-> Momentary Botones capa izq + dch.
	- Como en el Corne

Me falta
	- caps word (creo que va a ser comodo en el sweep) Mirar el modo moderno de esto
	- Ver si puedo desactivar una capa toogle tras un tiempo 
		https://docs.qmk.fm/features/layer_lock
		https://www.reddit.com/r/ErgoMechKeyboards/comments/1kxi1r5/keymap_for_34key_ferris_sweep/?tl=es-419#lightbox
	- Backspace y supr
	- https://docs.qmk.fm/tap_hold#chordal-hold