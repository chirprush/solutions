/* File unicodetex not found. */

 /* Geogebra to Asymptote conversion, documentation at artofproblemsolving.com/Wiki, go to User:Azjps/geogebra */
import graph; size(35.08cm); 
real labelscalefactor = 0.5; /* changes label-to-point distance */
pen dps = linewidth(0.7) + fontsize(20); defaultpen(dps); /* default pen style */ 
pen dotstyle = black; /* point style */ 
real xmin = -7.05, xmax = 28.03, ymin = -2.77, ymax = 17.62;  /* image dimensions */
pen wwzzff = rgb(0.4,0.6,1); 

draw((0,0)--(8.08,13.81)--(18,0)--cycle, wwzzff); 
 /* draw figures */
draw((0,0)--(8.08,13.81), wwzzff); 
draw((8.08,13.81)--(18,0), wwzzff); 
draw((18,0)--(0,0), wwzzff); 
draw(circle((4.04,6.9), 8)); 
draw((8.08,13.81)--(8.08,0), linetype("2 2")); 
draw((0,0)--(12.75,7.31)); 
draw((4.04,6.9)--(13.04,6.9)); 
 /* dots and labels */
dot((0,0),dotstyle); 
label("$A$", (0.1,0.15), NE * labelscalefactor); 
dot((18,0),dotstyle); 
label("$C$", (18.08,0.15), NE * labelscalefactor); 
dot((8.08,13.81),dotstyle); 
label("$B$", (8.18,13.94), NE * labelscalefactor); 
dot((4.04,6.9),dotstyle); 
label("$O$", (4.13,7.04), NE * labelscalefactor); 
dot((8.08,0),dotstyle); 
label("$D$", (8.18,0.15), NE * labelscalefactor); 
dot((13.04,6.9),dotstyle); 
label("$M$", (13.13,7.04), NE * labelscalefactor); 
dot((12.75,7.31),dotstyle); 
label("$E$", (12.85,7.46), NE * labelscalefactor); 
dot((12.04,6.9),dotstyle); 
label("$P$", (12.13,7.04), NE * labelscalefactor); 
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle); 
 /* end of picture */
