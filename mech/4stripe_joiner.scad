include <consts.scad>


//Holder that joins 4 stripe holder
//Put tape on the outside to actually hold the stripes in (tape is thinner than a printed layer)
//
// Use nomal filament

$fn=64;

STRIPE_PLAY_Y = 0.2;
PLAY_IN_PEN = 0.2;
STRIPE_HOLDER_X = (STRIPE_X+1)+0.4;
STRIPE_HOLDER_Y = (LED_Z+STRIPE_Z)+0.5+STRIPE_PLAY_Y;




difference() {
    cylinder(h=STRIPE_JOINER_Z, d=D_I-PLAY_IN_PEN);
    
    for(i=[0:3])rotate([0,0,90*i])translate([0,D_I/2-1.7+0.5,STRIPE_JOINER_Z/2+0.5])cube([STRIPE_HOLDER_X, STRIPE_HOLDER_Y+1, STRIPE_JOINER_Z], center=true);
}