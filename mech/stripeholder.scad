include <consts.scad>

//This is the two-part LED pcb holder that joins LEDs and fibers
//
//Print with normal PLA


CABLES_Y = 5;
BASE_PLATE_Z = 0;
STRIPE_DIST = 2;
NUM_STRIPES=4;

module stripeholder() {
   
    difference() {
    //base plate
    translate([0, (STRIPE_Y+1)/2, (BASE_PLATE_Z+LED_Z+STRIPE_Z)/2])cube([STRIPE_X+1, STRIPE_Y+1, BASE_PLATE_Z+LED_Z+STRIPE_Z], center=true);
    //led cutout
    translate([0, STRIPE_Y/2+0.5, (LED_Z+0.1)/2+BASE_PLATE_Z])cube([LED_X+0.2, STRIPE_Y, LED_Z+0.1], center=true);
    //pcb cutout
    translate([0, STRIPE_Y/2+0.5, (STRIPE_Z)/2+BASE_PLATE_Z+LED_Z+0.1])cube([STRIPE_X, STRIPE_Y, STRIPE_Z], center=true);
    //cable cutout
    translate([0, CABLES_Y/2+0.5, (LED_Z+STRIPE_Z)/2+BASE_PLATE_Z+0.5])cube([STRIPE_X+1, CABLES_Y, LED_Z+STRIPE_Z], center=true); 
    }
}


stripeholder();
translate([6,(STRIPE_Y+1)/2,0.5/2])cube([STRIPE_X+1, STRIPE_Y+1, 0.5], center=true);
