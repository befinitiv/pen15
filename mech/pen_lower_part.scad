$fn=128;


include <consts.scad>


SMALL_DIA_HEIGHT = 10;
SMALL_DIA_NORMAL_DIA_OVERLAP = 5;

//bottom small diameter part
module small_dia() {
difference() {
    union() {
        cylinder(d=D_I-0.3, h=SMALL_DIA_HEIGHT);
        translate([0,0,SMALL_DIA_HEIGHT])cylinder(d=D_I, h=SMALL_DIA_NORMAL_DIA_OVERLAP);
    }
    cylinder(d=D_I-1.6, h=SMALL_DIA_HEIGHT+SMALL_DIA_NORMAL_DIA_OVERLAP);
}
}

module normal_dia() {
    difference() { 
        //normal diameter cylinder
        translate([0,0,10])cylinder(d=D_O, h=PEN_LOWER_BODY_Z-SMALL_DIA_HEIGHT);
        cylinder(d=D_I, h=PEN_LOWER_BODY_Z);
    }
}

module tip() {
    //Tip of the pen
    translate([0,0,PEN_LOWER_BODY_Z])difference() {
    cylinder(d1=D_O, d2=3, h=PEN_LOWER_TIP_Z);
    cylinder(d1=D_O-1.6, d2=3-1.6, h=PEN_LOWER_TIP_Z);
    }
}

module pen_lower() {
    small_dia();
    normal_dia();
    tip();
}


pen_lower();