# Sources

This is the work of Christian Klippel (mamalala on EEVblog) in 2012-2013, with input from other users on the forum. This repository is an attempt to collate information punlished in the main project thread, https://www.eevblog.com/forum/projects/diy-metcal-13-56-mhz-rf-supply/

I haven't attempted to build the project myself and have no specialist knowledge to bring to bear.


## richard.cs build

http://randomfunprojects.co.uk/metcal.html

### Comment in post #374

"Whilst you could use the original gerbers I would suggest a few changes:
1) Add in pads for the extra 56 pF capacitor.
2) Put some thermal relief in. I've found a lot of areas where something that carries no real current (DC or RF) like a logic pulldown is unsolderable with a small iron because one end is hard-down onto a large area of ground plane.
3) Consider swapping the LCD pinout to the standard one.
4) A little bit of BOM rationalisation would be nice. For example the Aux supply capacitor for the switcher (can't remember the number now) is currently the only 1206 10nF in the design and could have been the same as the 10nF 0805's scattered everywhere.
5) Depending on your skill with surface mount soldering the pads might benefit from tweaking slightly - they're perfect for reflow but a little tight for hand work."

### Comment in post #375

"The mounting holes on the board are 3.2 mm, this is a perfectly normal size for clearance M3 but I suspect that for many people with an electronics-only background getting four tapped holes in position to within perhaps 0.2 mm will be difficult, and being tapped the heatsink holes can't simply be opened out a little bigger. Might I suggest that loose-fitting 3.5 mm or even 4 mm holes might be preferable on a future board revision."

### Comment in post #512

"I built [my toroids] as per the schematic and notes, with 1uH, 1uH, 400n, 11 turns on a T80, 14 turns on a T50 and then 10 on the next T50. It works well and I've made no attempt to optimise it further."


## See also

- https://hackaday.com/2019/06/16/homemade-magic-makes-the-metcal-go/
- https://habr.com/en/post/451246/
- https://github.com/SergeyMax/SolderingStation
- https://www.eevblog.com/forum/reviews/metcal-mx-5200-and-mx-5000-firmware-and-data-eeprom-information/
